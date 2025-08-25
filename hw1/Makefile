CXXFLAGS = -std=c++20

SOURCES = $(wildcard *.cpp)

.PHONY: all clean publish

all: main

main: main.o router.o search.o cart.o
	$(CXX) $(LDFLAGS) $^ -o $@

clean:
	rm -f *.o main

publish: clean
	python ../rm_impl.py $(SOURCES)
	zip hw1.zip $(shell find . -type f -not -name "*.orig")
	for f in $(SOURCES); do mv $$f.orig $$f; done
