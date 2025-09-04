CXXFLAGS = -std=c++17

SOURCES = $(wildcard *.cpp)

.PHONY: all clean publish submission autograder

clean:
	rm -f *.o main
	rm -fr testcases/__pycache__

publish: clean
	python ../rm_impl.py $(SOURCES)
	cd .. && zip hw1.zip -r hw1 --exclude \*.orig autograder
	for f in $(SOURCES); do mv $$f.orig $$f; done
