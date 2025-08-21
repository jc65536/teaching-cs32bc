CXXFLAGS = -std=c++20

all: main

main: main.o router.o search.o cart.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o main
