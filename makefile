test: main.cpp Matrix.hpp
	g++ -std=c++11 -g -Wall -Wextra -Wvla main.cpp -o test.out
	valgrind --leak-check=full --show-possibly-lost=yes --show-reachable=yes --undef-value-errors=yes ./test.out
	rm -rf test.out
driver: clean GenericMatrixDriver.o Complex.o
	g++ -std=c++11 -g -Wall -Wextra -Wvla GenericMatrixDriver.o Complex.o -o test.out
	./test.out
GenericMatrixDriver.o: GenericMatrixDriver.cpp Matrix.hpp
	g++ -std=c++11 -g -Wall -Wextra -Wvla -c GenericMatrixDriver.cpp
Complex.o: Complex.h Complex.cpp
	g++ -std=c++11 -g -Wall -Wextra -Wvla -c Complex.cpp

clean:
	rm -rf test.out Complex.o GenericMatrixDriver.o

.PHONY: test driver clean
