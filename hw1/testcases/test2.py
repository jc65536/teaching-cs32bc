import sys
from subprocess import Popen, PIPE
from common import Expected, SearchResults, AddedItem, ClearedCart, Checkout

queries = [
    "/search?query=cOF",
    "/search?query=abc",
    "/cart/clear",
    "/cart/clear",
    "/cart/checkout",
    "/search?query=ea&min_price=4.2",
    "/search?query=ea&max_price=4.2",
]

expected: list[Expected] = [
    SearchResults((1008, 1009, 1021, 1025)),
    SearchResults([]),
    ClearedCart(),
    ClearedCart(),
    Checkout(0),
    SearchResults((1015, 1025, 1029, 1032)),
    SearchResults((1027, 1030, 1031, 1034, 1035, 1036, 1040)),
]


def main():
    proc = Popen(sys.argv[1], text=True, stdin=PIPE, stdout=PIPE)

    for q, ans in zip(queries, expected):
        print(q, file=proc.stdin, flush=True)

        lines: list[str] = []
        while line := proc.stdout.readline().rstrip("\n"):
            lines.append(line)

        ans.verify(lines)

    print("Test 2 passed")


if __name__ == "__main__":
    main()
