SOURCES = $(wildcard *.cpp)
TESTS = $(wildcard testcases/test*.py)

.PHONY: all clean publish submission autograder

all: main

main: main.o router.o search.o cart.o
	$(CXX) $(LDFLAGS) $^ -o $@

clean:
	rm -f *.o main
	rm -fr testcases/__pycache__

publish: clean
	python ../rm_impl.py $(SOURCES)
	cd .. && zip hw1.zip -r hw1 --exclude \*.orig autograder
	for f in $(SOURCES); do mv $$f.orig $$f; done

test%: testcases/test%.py main
	python $< ./main

test: $(TESTS:testcases/%.py=%)

submission: clean
	zip submission.zip -r .

autograder:
	cd autograder && zip autograder.zip -r .
