class Expected:
    def verify(self, response: list[str]):
        raise NotImplementedError()

class SearchResults(Expected, set[int]):
    def verify(self, response: list[str]):
        ids = set(int(line.split(".")[0]) for line in response)
        ok = len(response) == len(self) and self == ids
        if not ok:
            raise Exception(f"Expected ids {self}, got {ids}")

class AddedItem(Expected, int):
    def verify(self, response: list[str]):
        added = int(response[0].removeprefix("Added item "))
        ok = len(response) == 1 and self == added
        if not ok:
            raise Exception(f"Expected added {self}, got {added}")

class ClearedCart(Expected):
    def verify(self, response: list[str]):
        ok = response == ["Cleared cart"]
        if not ok:
            raise Exception("Response is not 'Cleared cart'")

class Checkout(Expected, float):
    def verify(self, response: list[str]):
        total = float(response[0].removeprefix("Your total is: $"))
        ok = len(response) == 1 and abs(self - total) < 1e-9
        if not ok:
            raise Exception(f"Expected total {self}, got {total}")
