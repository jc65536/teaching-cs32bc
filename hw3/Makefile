CXXFLAGS = -std=c++17

.PHONY: all clean publish submission autograder

all: main

main: translate.h

clean:
	rm -f *.o main

publish: clean
	python ../rm_impl.py translate.h
	cd .. && zip hw3.zip -r hw3 --exclude "*.orig" "autograder/*"
	mv translate.h.orig translate.h

test: main
	./main

submission: clean
	zip submission.zip -r .

autograder:
	cd autograder && zip autograder.zip -r .
