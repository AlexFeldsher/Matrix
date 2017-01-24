#ifndef MATRIX_MATRIX_HPP
#define MATRIX_MATRIX_HPP

#include <iostream>
#include <vector>
#include <stdexcept>	// std::out_of_range
#include "Complex.h"

/**
 * @def DEFAULT_CTOR_ROWS 1
 * @brief the number of rows in the matrix initialized by the default constructor
 */
#define DEFAULT_CTOR_ROWS 1
/**
 * @def DEFAULT_CTOR_COLS 1
 * @brief the number of columns in the matrix initialized by the default constructor
 */
#define DEFAULT_CTOR_COLS 1
/**
 * @def DEFAULT_CTOR_ELEM 0
 * @brief the default elements in the matrix initialized by the default constructor
 */
#define DEFAULT_CTOR_ELEM 0
/**
 * @def OUT_OF_RANGE_MSG "Requested element (col, row) are out of the matrix range."
 * @brief the message to input to the out of range exception
 */
#define OUT_OF_RANGE_MSG "Requested element (col, row) are out of the matrix range."
/**
 * @def ROWS_COLS_CTOR_EXCEPTION_MSG "the given matrix dimensions are invalid."
 * @brief the message to add to a invalid row and column arguments exception
 */
#define ROWS_COLS_CTOR_EXCEPTION_MSG "the given matrix dimensions are invalid."
/**
 * @def CELLS_CTOR_EXCEPTION_MSG "the given matrix dimensions don't fit the given vector size."
 * @brief the message to add to a matrix vector constructor exception
 */
#define CELLS_CTOR_EXCEPTION_MSG "the given matrix dimensions don't fit the given vector size."
/**
 * @def ADDITION_EXCEPTION_MSG "cannot addition matrices of different sizes."
 * @brief the message to add to an addition exception
 */
#define ADDITION_EXCEPTION_MSG "cannot addition matrices of different sizes."
/**
 * @def SUBTRACTION_EXCEPTION_MSG "cannot subtract matrices of different sizes."
 * @brief the message to add to a subtraction exception
 */
#define SUBTRACTION_EXCEPTION_MSG "cannot subtract matrices of different sizes."
/**
 * @def TRANSPOSE_EXCEPTION_MSG "cannot transpose non square matrix."
 * @brief the message to add to a transpose exception
 */
#define TRANSPOSE_EXCEPTION_MSG "cannot transpose non square matrix."
/**
 * @def MULTIPLICATION_EXCEPTION_MSG "cannot multiply with the given matrix row dimension."
 * @brief the message to add to a multiplication exception
 */
#define MULTIPLICATION_EXCEPTION_MSG "cannot multiply with the given matrix row dimension."
/**
 * @def MIN_MATRIX_INDEX 0
 * @brief the minimum matrix row and column index
 */
#define MIN_MATRIX_INDEX 0
/**
 * @def TAB_CHAR '\t'
 * @brief Tab character
 */
#define TAB_CHAR '\t'
/**
 * @def NEWLINE_CHAR '\n'
 * @brief new line character
 */
#define NEWLINE_CHAR '\n';

template <class T>
class Matrix
{
	/**
	 * @brief bidirectional iterator class declaration
	 */
	class BidiConstIterator;

	/**
	 * @brief vector of type T, represents a matrix.
	 */
	std::vector<T> matrix;

	/**
	 * @brief the number of columns in the matrix;
	 */
	unsigned int nCols;

	/**
	 * @brief the number of rows in the matrix;
	 */
	unsigned int nRows;

public:

	/**
	 * @brief iterator type definition
	 */
	typedef BidiConstIterator const_iterator;

	/**
	 * @brief default constructor
	 * initializes a matrix of size 1x1 with a single element 0
	 */
	Matrix();

	/**
	 * @brief Matrix constructor, creates a matrix with the given row and column sizes initialized to zeroes
	 * @param rows number of rows
	 * @param cols number of columns
	 */
	Matrix(unsigned int rows, unsigned int cols);

	/**
	 * @brief Matrix copy constructor
	 * @param other the matrix to copy
	 */
	Matrix(const Matrix<T>& other) : matrix(other.matrix), nCols(other.nCols), nRows(other.nRows) {};

	/**
	 * @brief Matrix move constructor
	 * @param other the matrix to copy
	 */
	Matrix(const Matrix<T> && other) : matrix(other.matrix), nCols(other.nCols), nRows(other.nRows) {};

	/**
	 * @brief Constructs a matrix from a given vector and row and column numbers
	 * @param rows number of rows
	 * @param cols number of columns
	 * @param cells the element to populate the matrix with
	 */
	Matrix(unsigned int rows, unsigned int cols, const std::vector<T>& cells);

	/**
	 * @brief Matrix destructor
	 */
	~Matrix() {};

	/**
	 * @brief Assigns the content of the given matrix
	 * @param rhs matrix whose values to assign
	 * @return *this
	 */
	Matrix<T>& operator=(const Matrix<T>& rhs);

	/**
	 * @brief Binary addition operator
	 * @param rhs the matrix to add to this
	 * @return A matrix that equals (this + rhs)
	 */
	Matrix<T> operator+(const Matrix<T>& rhs) const;

	/**
	 * @brief Binary subtraction operator
	 * @param rhs the matrix to subtract from this
	 * @return A matrix that equals (this - rhs)
	 */
	Matrix<T> operator-(const Matrix<T>& rhs) const;

	/**
	 * @brief Matrix multiplication operator
	 * @param rhs the matrix to multiply with this
	 * @return A matrix that equals (this * rhs)
	 */
	Matrix<T> operator*(const Matrix<T>& rhs) const;

	/**
	 * @brief compare the contents of this matrix with the given matrix
	 * @param rhs the matrix to compare its content to this matrix
	 * @return true if all the elements are equal, otherwise false
	 */
	bool operator==(const Matrix<T>& rhs) const;

	/**
	 * @brief compare the contents of this matrix with the given matrix
	 * @param rhs the matrix to compare its content to this matrix
	 * @return false if all the elements are equal, otherwise true
	 */
	bool operator!=(const Matrix<T>& rhs) const;

	/**
	 * @brief returns the a transpose matrix of this matrix
	 * @return transpose matrix
	 */
	Matrix<T> trans() const;

	/**
	 * @brief returns true if the matrix is square, otherwise false
	 * @return true if the matrix is square, otherwise false
	 */
	bool isSquareMatrix() const
	{
		return (nCols == nRows);
	}

	/**
	 * @brief output operator
	 * @param os output stream
	 * @param matrix the matrix to output
	 * @return output stream
	 */
	template <typename P>
	friend std::ostream& operator<<(std::ostream& os, const Matrix<P>& matrix);

	/**
	 * @brief returns a constant of the element in the given matrix position
	 * @param row the row number
	 * @param col the column number
	 * @return the element in the given row and column number
	 */
	const T& operator()(unsigned int row, unsigned int col) const;

	/**
	 * @brief returns the element in the given matrix position
	 * @param row the row number
	 * @param col the column number
	 * @return the element in the given row and column number
	 */
	T& operator()(unsigned int row, unsigned int col);

	/**
	 * @brief Returns the iterator to the first element of the matrix
	 * @return iterator to the first element of the matrix
	 */
	const_iterator begin() const
	{
		return const_iterator(&(matrix.front()));
	}

	/**
	 * @brief Returns the iterator to the element following the last element of the matrix
	 * @return iterator to the element following the last element of the matrix
	 */
	const_iterator end() const
	{
		return const_iterator(&(matrix.back()) + 1);
	}

	/**
	 * @brief returns the number of columns in the matrix
	 * @return the number of columns in the matrix
	 */
	unsigned int cols() const;

	/**
	 * @brief returns the number of rows in the matrix
	 * @return the number of rows in the matrix
	 */
	unsigned int rows() const;

private:

	/**
	 * @brief returns the vector index of the given matrix position
	 * the row and column values validity should be done by the calling function
	 * @param row number of row
	 * @param col number of column
	 * @return the appropriate index of the element in the vector
	 */
	unsigned int _getIndex(unsigned int row, unsigned int col) const
	{
		return (row*nCols + col);
	}


};

/**
 * @brief default constructor
 * initializes a matrix of size 1x1 with a single element 0
 */
template <typename T>
Matrix<T>::Matrix() : nCols(DEFAULT_CTOR_COLS), nRows(DEFAULT_CTOR_ROWS)
{
	/* initialize a new vector with a single element 0 */
	std::vector<T> zero(nCols, DEFAULT_CTOR_ELEM);
	matrix = zero;
}
/**
 * @brief Matrix constructor, creates a matrix with the given row and column sizes initialized to zeroes
 * @param rows number of rows
 * @param cols number of columns
 */
template <typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols)
{
	if (rows < 0 || cols < 0)
	{
		throw std::invalid_argument(ROWS_COLS_CTOR_EXCEPTION_MSG);
	}
	nRows = rows;
	nCols = cols;

	std::vector<T> vec(rows * cols);
	matrix = vec;
}

/**
 * @brief Constructs a matrix from a given vector and row and column numbers
 * @param rows number of rows
 * @param cols number of columns
 * @param cells the element to populate the matrix with
 */
template <typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols, const std::vector<T>& cells)
{
	// throw exception if given vector size doesn't fit the matrix
	if (cells.size() != (rows * cols) || rows < 0 || cols < 0)
	{
		throw std::invalid_argument(CELLS_CTOR_EXCEPTION_MSG);
	}
	nCols = cols;
	nRows = rows;
	matrix = cells;
}


/**
 * @brief Assigns the content of the given matrix
 * @param rhs matrix whose values to assign
 * @return *this
 */
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
{
	matrix = rhs.matrix;
	nCols = rhs.nCols;
	nRows = rhs.nRows;

	return *this;
}

/**
 * @brief Binary addition operator
 * @param rhs the matrix to add to this
 * @return A matrix that equals (this + rhs)
 */
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const
{
	// throw an exception if matrices dimensions differ
	if (rows() != rhs.rows() || cols() != rhs.cols())
	{
		throw std::invalid_argument(ADDITION_EXCEPTION_MSG);
	}

	Matrix<T>::const_iterator rhsBegin = rhs.begin();
	Matrix<T>::const_iterator rhsEnd = rhs.end();
	Matrix<T>::const_iterator thisBegin = begin();

	std::vector<T> newMatrixVec(cols() * rows());

	int i;
	for (i = 0; rhsBegin != rhsEnd; ++rhsBegin, ++thisBegin, ++i)
	{
		newMatrixVec[i] = *thisBegin + *rhsBegin;
	}

	Matrix<T> newMatrix(nRows, nCols, newMatrixVec);
	return newMatrix;
}

/**
 * @brief Binary subtraction operator
 * @param rhs the matrix to subtract from this
 * @return A matrix that equals (this - rhs)
 */
template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs) const
{
	// throw an exception if matrices dimensions differ
	if (cols() != rhs.rows() || cols() != rhs.cols())
	{
		throw std::invalid_argument(SUBTRACTION_EXCEPTION_MSG);
	}
	const_iterator rhsBegin = rhs.begin();
	const_iterator rhsEnd = rhs.end();
	const_iterator thisBegin = begin();

	std::vector<T> newMatrixVec(nCols * nRows);

	int i;
	for (i = 0; rhsBegin != rhsEnd; ++rhsBegin, ++thisBegin, ++i)
	{
		newMatrixVec[i] = *thisBegin - *rhsBegin;
	}

	Matrix<T> newMatrix(nRows, nCols, newMatrixVec);
	return newMatrix;
}

/**
 * @brief Matrix multiplication operator
 * Using the iterative algorithm
 * @param rhs the matrix to multiply with this
 * @return A matrix that equals (this * rhs)
 */
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs) const
{
	Matrix<T> result(nRows, rhs.nCols);
	if (cols() != rhs.rows())
	{
		throw std::invalid_argument(MULTIPLICATION_EXCEPTION_MSG);
	}
	unsigned int i, j, k;
	for (i = 0; i < nRows; ++i)
	{
		for (j = 0; j < rhs.nCols; ++j)
		{
			T sum = 0;
			for (k = 0; k < nCols; ++k)
			{
				sum = sum + ((*this)(i, k) * rhs(k, j));
			}
			result(i, j) = sum;
		}
	}
	return result;
}

/**
 * @brief compare the contents of this matrix with the given matrix
 * @param rhs the matrix to compare its content to this matrix
 * @return true if all the elements are equal, otherwise false
 */
template <typename T>
bool Matrix<T>::operator==(const Matrix<T>& rhs) const
{
	if (nCols != rhs.nCols || nRows != rhs.nRows)
	{
		return false;
	}

	const_iterator thisBegin = this->begin();
	const_iterator thisEnd = this->end();
	const_iterator rhsBegin = rhs.begin();

	for (; thisBegin != thisEnd; ++thisBegin, ++rhsBegin)
	{
		if (*thisBegin != *rhsBegin)
		{
			return false;
		}
	}

	return true;
}

/**
 * @brief compare the contents of this matrix with the given matrix
 * @param rhs the matrix to compare its content to this matrix
 * @return false if all the elements are equal, otherwise true
 */
template <typename T>
bool Matrix<T>::operator!=(const Matrix<T>& rhs) const
{
	return !(*this == rhs);
}

/**
 * @brief returns the a transpose matrix of this matrix
 * @return transpose matrix
 */
template <typename T>
Matrix<T> Matrix<T>::trans() const
{
	if (cols() != rows())
	{
		throw std::logic_error(TRANSPOSE_EXCEPTION_MSG);
	}

	unsigned int i, j;
	Matrix<T> transMatrix(nRows, nCols);

	for (i = 0; i < nRows; ++i)
	{
		for (j = 0; j < nCols; ++j)
		{
			transMatrix(j, i) = (*this)(i, j);
		}
	}

	return transMatrix;
}

/**
 * @brief specialized transpose method for matrices over the complex field
 * Conjugate transpose
 * @return the transposed matrix
 */
template <>
Matrix<Complex> Matrix<Complex>::trans() const
{
	if (cols() != rows())
	{
		throw std::logic_error(TRANSPOSE_EXCEPTION_MSG);
	}

	unsigned int i, j;
	Matrix<Complex> transMatrix(nRows, nCols);

	for (i = 0; i < nRows; ++i)
	{
		for (j = 0; j < nCols; ++j)
		{
			transMatrix(j, i) = matrix[_getIndex(i, j)].conj();
		}
	}

	return transMatrix;
}

/**
 * @brief output operator
 * outputs each matrix element seperated by a tab and every row seperated by a new line
 * @param os output stream
 * @param matrix the matrix to output
 * @return output stream
 */
template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
{
	unsigned int i, j;
	/** iterate over matrix elements */
	for (i = 0; i < matrix.rows(); ++i)
	{
		for (j = 0; j < matrix.cols(); ++j)
		{
			os << matrix(i, j) << TAB_CHAR;
		}
		os << NEWLINE_CHAR;
	}
	return os;
}

/**
 * @brief returns the element in the given matrix position
 * @param row the row number
 * @param col the column number
 * @return the element in the given row and column number
 */
template <typename T>
const T& Matrix<T>::operator()(unsigned int row, unsigned int col) const
{
	if (row >= nRows || row < MIN_MATRIX_INDEX || col >= nCols || col < MIN_MATRIX_INDEX)
	{
		throw std::out_of_range(OUT_OF_RANGE_MSG);
	}

	/* matrix indexes start at 1, but vector indexes start at 0 */
	return matrix[_getIndex(row, col)];
}

/**
 * @brief returns the element in the given matrix position
 * @param row the row number
 * @param col the column number
 * @return the element in the given row and column number
 */
template <typename T>
T& Matrix<T>::operator()(unsigned int row, unsigned int col)
{
	// TODO: maybe make a single function for const and non const
	if (row >= nRows || row < MIN_MATRIX_INDEX || col >= nCols || col < MIN_MATRIX_INDEX)
	{
		throw std::out_of_range(OUT_OF_RANGE_MSG);
	}

	/* matrix indexes start at 1, but vector indexes start at 0 */
	return matrix[_getIndex(row, col)];
}


/**
 * @brief returns the number of columns in the matrix
 * @return the number of columns in the matrix
 */
template <typename T>
unsigned int Matrix<T>::cols() const
{
	return nCols;
}

/**
 * @brief returns the number of rows in the matrix
 * @return the number of rows in the matrix
 */
template <typename T>
unsigned int Matrix<T>::rows() const
{
	return nRows;
}

//-------------------------- Iterator class implementation ---------------------------

/**
 * @brief bidirectional const iterator class
 */
template<class T>
class Matrix<T>::BidiConstIterator
{
	/**
	 * @brief pointer to the element
	 */
	const T* _ptr;

public:

	/**
	 * @brief default constructor
	 * initialized the pointer to nullptr
	 */
	BidiConstIterator() : _ptr(nullptr) {};
	/**
	 * @brief Bidirectional iterator constructor
	 * @param ptr the element the iterator should point to
	 */
	BidiConstIterator(const T* ptr) : _ptr(ptr) {};

	/**
	 * @brief Iterator constructor
	 * @param iterator to copy
	 */
	BidiConstIterator(const BidiConstIterator& other) : _ptr(other._ptr) {};

	/**
	 * @brief Destructor
	 */
	~BidiConstIterator() {};

	/**
	 * @brief assign operator
	 * @param rhs the object to assign to this one
	 * @return this
	 */
	BidiConstIterator& operator=(const BidiConstIterator& rhs)
	{
		_ptr = rhs._ptr;
		return *this;
	}

	/**
	 * @brief equals operator
	 * @param rhs the object to test this against
	 * @return true if rhs equals this, otherwise false
	 */
	bool operator==(const BidiConstIterator& rhs) const
	{
		return (_ptr == rhs._ptr);
	}

	/**
	 * @brief not-equals operator
	 * @param rhs the object to test this against
	 * @return true if rhs doesn't equal this, otherwise false
	 */
	bool operator!=(const BidiConstIterator& rhs) const
	{
		return !(*this == rhs);
	}

	/**
	 * @brief accesses the contained value
	 * @return the contained value
	 */
	const T& operator*() const
	{
		return *_ptr;
	}

	/**
	 * @bried accesses the contained value
	 * @return the contained value
	 */
	const T* operator->() const
	{
		return _ptr;
	}

	/**
	 * @brief pre increment the operator
	 * @return the element the iterator points to after incrementing it
	 */
	const T& operator++()
	{
		return *(++_ptr);
	}

	/**
	 * @brief post increment the operator
	 * @return the element the iterator pointed to before incrementing it
	 */
	const T& operator++(int i)
	{
		const T* tmp = _ptr++;
		return *tmp;
	}

	/**
	 * @brief pre increment the operator
	 * @return the element the iterator points to after incrementing it
	 */
	const T& operator--()
	{
		return *(--_ptr);
	}

	/**
	 * @brief post increment the operator
	 * @return the element the iterator pointed to before incrementing it
	 */
	const T& operator--(int i)
	{
		const T* tmp = _ptr--;
		return *tmp;
	}
};

#endif //MATRIX_MATRIX_HPP