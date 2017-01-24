CPP_FLAGS=-std=c++11 -Wall -Wextra
GEN_MAT_EXE=GenericMatrixDriver
OBJECTS=Complex.o GenericMatrixDriver.o
COMPILED_HEADER=Matrix.hpp.gch
driver: Matrix.hpp GenericMatrixDriver.o Complex.o
	g++ $(CPP_FLAGS) GenericMatrixDriver.o Complex.o -o $(GEN_MAT_EXE)
	./$(GEN_MAT_EXE)
Matrix: Matrix.hpp
	g++ $(CPP_FLAGS) Matrix.hpp
GenericMatrixDriver.o: GenericMatrixDriver.cpp Matrix.hpp Complex.h
	g++ $(CPP_FLAGS) -c GenericMatrixDriver.cpp
Complex.o: Complex.h Complex.cpp
	g++ $(CPP_FLAGS) -c Complex.cpp
clean:
	rm -rf $(OBJECTS) $(GEN_MAT_EXE) $(COMPILED_HEADER)

.PHONY: driver clean Matrix
