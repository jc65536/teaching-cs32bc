from io import BufferedReader
from subprocess import run, Popen, PIPE
from http.server import HTTPServer, BaseHTTPRequestHandler


def make_cpp():
    proc = run(["make"])
    if proc.returncode != 0:
        raise Exception("Error compiling C++ project")


def run_cpp():
    return Popen(["./main"], text=True, stdin=PIPE, stdout=PIPE, stderr=PIPE)


def make_handler():
    make_cpp()
    proc = run_cpp()

    class Handler(BaseHTTPRequestHandler):
        def handle_generic(self):
            print(self.path, file=proc.stdin, flush=True)

            lines: list[str] = []
            while line := proc.stdout.readline().rstrip("\n"):
                lines.append(line)

            if self.path.startswith("/search"):
                with open("html/search.html") as f:
                    html = f.read()
                    response = html.replace("REPLACE", "".join(f"<li>{l}</li>" for l in lines))
            elif self.path.startswith("/cart"):
                with open("html/cart.html") as f:
                    html = f.read()
                    response = html.replace("REPLACE", "".join(f"<li>{l}</li>" for l in lines))
            else:
                response = "<br/>".join(lines)

            return response

        def do_GET(self):
            response = self.handle_generic()
            if proc.returncode is None:
                self.send_response(200)
                self.send_header("Content-Type", "text/html")
                self.end_headers()
                self.wfile.write(response.encode())
            else:
                self.send_response(500)
                self.end_headers()
                self.wfile.write(b"C++ program terminated unexpectedly")

        def do_POST(self):
            self.handle_generic()
            self.send_response(301)
            self.send_header("Location", "/cart")
            self.end_headers()

    return Handler


def main():
    httpd = HTTPServer(("", 8000), make_handler())
    httpd.serve_forever()


if __name__ == "__main__":
    main()
