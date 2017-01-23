#include <iostream>
#include "Matrix.hpp"
#include "assert.h"

bool testDefaultCtor()
{
	std::cout << "DEFAULT CTOR TEST:" << std::endl;
	Matrix<int> matrix;
	assert(matrix.cols() == DEFAULT_CTOR_COLS);
	std::cout << "Num of columns == 1" << std::endl;
	assert(matrix.rows() == DEFAULT_CTOR_ROWS);
	std::cout << "Num of rows == 1" << std::endl;

	assert(matrix(0, 0) == DEFAULT_CTOR_ELEM);
	std::cout << "element (0,0) == 0" << std::endl;
	return true;
}

bool testFunctorException()
{
	std::cout << "FUNCTOR THROW EXCEPTION TEST:" << std::endl;
	Matrix<int> matrix;
	try
	{
		int i = matrix(100,100);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception thrown." << std::endl;
		std::string msg = OUT_OF_RANGE_MSG;
		assert(msg == e.what());
		std::cout << "Exception msg is correct." << std::endl;
		return true;
	}

	return false;
}

int main() {
	if (!testDefaultCtor())
	{
		std::cout << "FAILED TEST DEFAULT CTOR\n";
	}
	if (!testFunctorException())
	{
		std::cout << "FAILED TEST FUNCTOR EXCEPTION\n";
	}

	std::cout << "DONE TESTING." << std::endl;
	return 0;
}