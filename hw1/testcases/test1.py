import sys
from subprocess import Popen, PIPE
from common import Expected, SearchResults, AddedItem, ClearedCart, Checkout

queries = [
    "/search",
    "/cart/add/1001",
    "/cart/add/1002",
    "/cart/add/1001",
    "/cart/checkout",
    "/cart/clear",
    "/cart/checkout",
    "/search?query=coffee",
]

expected: list[Expected] = [
    SearchResults(range(1001, 1051)),
    AddedItem(1001),
    AddedItem(1002),
    AddedItem(1001),
    Checkout(10.45),
    ClearedCart(),
    Checkout(0),
    SearchResults((1008, 1009, 1021, 1025)),
]


def main():
    proc = Popen(sys.argv[1], text=True, stdin=PIPE, stdout=PIPE)

    for q, ans in zip(queries, expected):
        print(q, file=proc.stdin, flush=True)

        lines: list[str] = []
        while line := proc.stdout.readline().rstrip("\n"):
            lines.append(line)

        ans.verify(lines)

    print("Test 1 passed")


if __name__ == "__main__":
    main()
