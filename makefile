test: main.cpp Matrix.hpp
	g++ -std=c++11 -g -Wall -Wextra -Wvla main.cpp -o test.out
	valgrind --leak-check=full --show-possibly-lost=yes --show-reachable=yes --undef-value-errors=yes ./test.out
	rm -rf test.out

.PHONY: test
