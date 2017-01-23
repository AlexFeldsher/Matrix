#include <iostream>
#include "Matrix.hpp"
#include "assert.h"

void testDefaultCtor()
{
	std::cout << "========DEFAULT CTOR TEST========" << std::endl;
	Matrix<int> matrix;
	assert(matrix.cols() == DEFAULT_CTOR_COLS);
	std::cout << "Num of columns == 1" << std::endl;
	assert(matrix.rows() == DEFAULT_CTOR_ROWS);
	std::cout << "Num of rows == 1" << std::endl;

	assert(matrix(0, 0) == DEFAULT_CTOR_ELEM);
	std::cout << "element (0,0) == 0" << std::endl;
	Matrix<int>::iterator b = matrix.begin();
	Matrix<int>::iterator e = matrix.end();
	std::cout << "Iterator first element: " << *b << std::endl;
	++b;
	std::cout << "That was the last element: " << (b == e) << std::endl;
}

void testCtorRowCol()
{
	std::cout << "========DEFAULT CTOR TEST========" << std::endl;
	unsigned int rows = 1332;
	unsigned int cols = 3234;
	Matrix<int> matrix(rows, cols);
	assert(matrix.cols() == cols);
	std::cout << "Correct column number" << std::endl;
	assert(matrix.rows() == rows);
	std::cout << "Correct row number" << std::endl;

	Matrix<int>::iterator b = matrix.begin();
	Matrix<int>::iterator e = matrix.end();
	int i;
	for (i = 0; b != e; ++b, ++i)
	{
		assert(*b == 0);
	}
	std::cout << "All the elements initialized to 0" << std::endl;
	assert(i == rows*cols);
	std::cout << "The right number of elements" << std::endl;
}

void testFunctorException()
{
	std::cout << "========FUNCTOR THROW EXCEPTION TEST========" << std::endl;
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
	}

}

int main() {
	testDefaultCtor();
	testCtorRowCol();
	testFunctorException();
	return 0;
}