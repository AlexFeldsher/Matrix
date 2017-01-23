test: main.cpp Matrix.hpp
	g++ -std=c++11 -Wall -Wextra -Wvla main.cpp -o test.out
	./test.out
	rm -rf test.out

.PHONY: test
