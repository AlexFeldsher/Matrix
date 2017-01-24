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
	std::cout << "========ROW COL CTOR TEST========" << std::endl;
	unsigned int rows = 1332;
	unsigned int cols = 3234;
	Matrix<int> matrix(rows, cols);
	assert(matrix.cols() == cols);
	std::cout << "Correct column number" << std::endl;
	assert(matrix.rows() == rows);
	std::cout << "Correct row number" << std::endl;

	Matrix<int>::iterator b = matrix.begin();
	Matrix<int>::iterator e = matrix.end();
	unsigned int i;
	for (i = 0; b != e; ++b, ++i)
	{
		assert(*b == 0);
	}
	std::cout << "All the elements initialized to 0" << std::endl;
	assert(i == rows*cols);
	std::cout << "The right number of elements" << std::endl;
}

void testCopyCtor()
{
	std::cout << "========COPY CTOR========" << std::endl;
	unsigned int rows = 1332;
	unsigned int cols = 3234;
	Matrix<int> matrix1(rows, cols);
	Matrix<int> matrix = matrix1;

	assert(matrix.cols() == cols);
	std::cout << "Correct column number" << std::endl;
	assert(matrix.rows() == rows);
	std::cout << "Correct row number" << std::endl;

	Matrix<int>::iterator b = matrix.begin();
	Matrix<int>::iterator e = matrix.end();
	unsigned int i;
	for (i = 0; b != e; ++b, ++i)
	{
		assert(*b == 0);
	}
	std::cout << "All the elements initialized to 0" << std::endl;
	assert(i == rows*cols);
	std::cout << "The right number of elements" << std::endl;
}

void testMoveCtor()
{
	std::cout << "========MOVE CTOR========" << std::endl;
	unsigned int rows = 1332;
	unsigned int cols = 3234;
	Matrix<int> matrix1(rows, cols);
	Matrix<int> matrix = std::move(matrix1);

	assert(matrix.cols() == cols);
	std::cout << "Correct column number" << std::endl;
	assert(matrix.rows() == rows);
	std::cout << "Correct row number" << std::endl;

	Matrix<int>::iterator b = matrix.begin();
	Matrix<int>::iterator e = matrix.end();
	unsigned int i;
	for (i = 0; b != e; ++b, ++i)
	{
		assert(*b == 0);
	}
	std::cout << "All the elements initialized to 0" << std::endl;
	assert(i == rows*cols);
	std::cout << "The right number of elements" << std::endl;
}

void testVectorCtor()
{
	std::cout << "========VECTOR CTOR TEST========" << std::endl;
	std::vector<int> vec;
	int i;
	for (i = 0; i < 1000; ++i)
	{
		vec.push_back(i);
	}

	Matrix<int> matrix(100, 100, vec);
	Matrix<int>::iterator b = matrix.begin();
	Matrix<int>::iterator e = matrix.end();
	for (i = 0; b != e; ++b, ++i)
	{
		assert(*b == vec[i]);
	}
	std::cout << "All elements copied correctly" << std::endl;
}

void testAssignOp()
{
	std::cout << "========ASSIGN OPERATOR TEST========" << std::endl;
	std::vector<int> vec;
	int i;
	for (i = 0; i < 1000; ++i)
	{
		vec.push_back(i);
	}

	Matrix<int>* matrix1 = new Matrix<int>(100, 100, vec);
	Matrix<int> matrix;
	matrix = *matrix1;
	delete matrix1;

	Matrix<int>::iterator b = matrix.begin();
	Matrix<int>::iterator e = matrix.end();
	for (i = 0; b != e; ++b, ++i)
	{
		assert(*b == vec[i]);
	}
	std::cout << "All elements assigned correctly" << std::endl;
}

void testAddOp()
{
	std::cout << "========ADDITION OPERATOR TEST========" << std::endl;
	std::vector<int> vec;
	int i;
	for (i = 0; i < 10000; ++i)
	{
		vec.push_back(i);
	}

	Matrix<int> matrix1(100, 100, vec);
	Matrix<int> matrix2(100, 100, vec);
	Matrix<int> matrix;
	matrix = matrix1 + matrix2;

	Matrix<int>::iterator b = matrix.begin();
	Matrix<int>::iterator e = matrix.end();
	for (i = 0; b != e; ++b, ++i)
	{
		assert(*b == (vec[i] * 2));
	}
	std::cout << "Addition test passed" << std::endl;
}

void testSubOp()
{
	std::cout << "========SUBTRACTION OPERATOR TEST========" << std::endl;
	std::vector<int> vec;
	int i;
	for (i = 0; i < 10000; ++i)
	{
		vec.push_back(i);
	}

	Matrix<int> matrix1(100, 100, vec);
	Matrix<int> matrix2(100, 100, vec);
	Matrix<int> matrix;
	matrix = matrix1 - matrix2;

	Matrix<int>::iterator b = matrix.begin();
	Matrix<int>::iterator e = matrix.end();
	for (i = 0; b != e; ++b, ++i)
	{
		assert(*b == 0);
	}
	std::cout << "Addition test passed" << std::endl;
}

void testMultOp()
{
	std::cout << "========MULTIPLICATION OPERATOR TEST========" << std::endl;
	std::vector<int> vec;
	int i;
	for (i = 0; i < 1000; ++i)
	{
		vec.push_back(1);
	}

	Matrix<int> matrix1(10, 100, vec);
	Matrix<int> matrix2(100, 10, vec);
	Matrix<int> matrix;
	matrix = matrix1 * matrix2;

	Matrix<int>::iterator b = matrix.begin();
	Matrix<int>::iterator e = matrix.end();
	for (i = 0; b != e; ++b, ++i)
	{
		assert(*b == 100);
	}
	std::cout << "Multiplication test passed" << std::endl;
}

void testEQOp()
{
	std::cout << "========EQUAL OPERATOR TEST========" << std::endl;
	std::vector<int> vec;
	int i;
	for (i = 0; i < 1000; ++i)
	{
		vec.push_back(1);
	}

	Matrix<int> matrix1(100, 100, vec);
	Matrix<int> matrix2(100, 100, vec);
	assert((matrix1 == matrix2) == true);
	matrix2(1,1) = 3;
	assert((matrix1 == matrix2) == false);
	std::cout << "Equal test passed" << std::endl;
}

void testNotEQOp()
{
	std::cout << "========NOT EQUAL OPERATOR TEST========" << std::endl;
	std::vector<int> vec;
	int i;
	for (i = 0; i < 1000; ++i)
	{
		vec.push_back(1);
	}

	Matrix<int> matrix1(100, 100, vec);
	Matrix<int> matrix2(100, 100, vec);
	assert((matrix1 != matrix2) == false);
	matrix2(1,1) = 3;
	assert((matrix2 != matrix1) == true);
	std::cout << "Not equal test passed" << std::endl;
}

void testTrans()
{
	std::cout << "========TRANSPOSE TEST========" << std::endl;
	std::vector<int> vec = {1,2,3,4};
	Matrix<int> matrix1(2, 2, vec);
	Matrix<int> matrix2 = matrix1.trans();
	assert(matrix2(0,0) == 1);
	assert(matrix2(0,1) == 3);
	assert(matrix2(1,0) == 2);
	assert(matrix2(1,1) == 4);
	std::cout << "Transpose test passed" << std::endl;
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
	testCopyCtor();
	testMoveCtor();
	testVectorCtor();
	testAssignOp();
	testAddOp();
	testSubOp();
	testMultOp();
	testEQOp();
	testNotEQOp();
	testTrans();
	testFunctorException();
	return 0;
}