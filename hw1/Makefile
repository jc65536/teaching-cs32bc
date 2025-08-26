CXXFLAGS = -std=c++20
SOURCES = $(wildcard *.cpp)
TESTS = $(wildcard testcases/test*.py)

.PHONY: all clean publish submission

all: main

main: main.o router.o search.o cart.o
	$(CXX) $(LDFLAGS) $^ -o $@

clean:
	rm -f *.o main
	rm -fr testcases/__pycache__

publish: clean
	python ../rm_impl.py $(SOURCES)
	cd .. && zip hw1.zip -r hw1 --exclude \*.orig
	for f in $(SOURCES); do mv $$f.orig $$f; done

test%: testcases/test%.py main
	python $<

test: $(TESTS:testcases/%.py=%)

submission: main
	zip submission.zip $(SOURCES) report.txt
