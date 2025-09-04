CXXFLAGS = -std=c++17

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
TESTS = $(SOURCES:%.cpp=%)

.PHONY: all test clean publish submission autograder

$(TESTS): $(HEADERS)

run-%: %
	./$< | diff expected/$<.txt - && echo "Test passed."

test: $(TESTS:%=run-%)

clean:
	rm -f *.o $(TESTS)

publish: clean
	python ../rm_impl.py $(HEADERS)
	cd .. && zip hw2.zip -r hw2 --exclude \*.orig hw2/autograder/
	for f in $(HEADERS); do mv $$f.orig $$f; done

submission: clean
	zip submission.zip -r .

autograder:
	cd autograder && zip autograder.zip -r .
