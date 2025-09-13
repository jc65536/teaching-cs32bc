CXXFLAGS = -std=c++17

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)

.PHONY: all test clean publish submission autograder

all: main

main: main.o route.o
	g++ $^ -o $@

$(SOURCES): $(HEADERS)

clean:
	rm -f *.o main

publish: clean
	python ../rm_impl.py $(HEADERS) $(SOURCES)
	cd .. && zip project.zip -r project --exclude "*.orig" "project/autograder/*"
	for f in $(HEADERS) $(SOURCES); do mv $$f.orig $$f; done

submission: clean
	zip submission.zip -r .

autograder:
	cd autograder && zip autograder.zip -r .
