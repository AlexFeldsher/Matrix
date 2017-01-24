#ifndef MATRIX_MATRIX_HPP
#define MATRIX_MATRIX_HPP

#include <iostream>
#include <iterator>
#include <vector>
#include <stdexcept>	// std::out_of_range

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
	class _BidiConstIterator;

	/**
	 * @brief vector of type T, represents a matrix.
	 */
	std::vector<T> _matrix;

	/**
	 * @brief the number of columns in the matrix;
	 */
	unsigned int _cols;

	/**
	 * @brief the number of rows in the matrix;
	 */
	unsigned int _rows;

public:

	/**
	 * @brief iterator type definition
	 */
	typedef _BidiConstIterator iterator;

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
	Matrix(unsigned int rows, unsigned int cols) : _matrix(std::vector<T>(rows * cols)), _cols(cols),
												   _rows(rows) {};

	/**
	 * @brief Matrix copy constructor
	 * @param other the matrix to copy
	 */
	Matrix(const Matrix<T>& other) : _matrix(other._matrix), _cols(other._cols), _rows(other._rows) {};

	/**
	 * @brief Matrix move constructor
	 * @param other the matrix to copy
	 */
	Matrix(const Matrix<T>&& other) : _matrix(other._matrix), _cols(other._cols), _rows(other._rows) {};

	/**
	 * @brief Constructs a matrix from a given vector and row and column numbers
	 * @param rows number of rows
	 * @param cols number of columns
	 * @param cells the element to populate the matrix with
	 * TODO: maybe throw exception if the values don't add up
	 */
	Matrix(unsigned int rows, unsigned int cols, const std::vector<T>& cells) : _matrix(cells), _cols(cols),
																				_rows(rows) {};

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
		return (_cols == _rows);
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
	iterator begin() const
	{
		return iterator(&(_matrix.front()));
	}

	/**
	 * @brief Returns the iterator to the element following the last element of the matrix
	 * @return iterator to the element following the last element of the matrix
	 */
	iterator end() const
	{
		return iterator(&(_matrix.back()) + 1);
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

	/**
	 * FOR TESTING
	 * TODO: remove before submition
	 */
	std::vector<std::vector<T>> getMatrix() {return _matrix;};

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
		return (row*_cols + col);
	}


};

/**
 * @brief default constructor
 * initializes a matrix of size 1x1 with a single element 0
 */
template <typename T>
Matrix<T>::Matrix() : _cols(DEFAULT_CTOR_COLS), _rows(DEFAULT_CTOR_ROWS)
{
	/* initialize a new vector with a single element 0 */
	std::vector<T> zero(_cols, DEFAULT_CTOR_ELEM);
	_matrix = zero;
}

/**
 * @brief Assigns the content of the given matrix
 * @param rhs matrix whose values to assign
 * @return *this
 */
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
{
	_matrix = rhs._matrix;
	_cols = rhs._cols;
	_rows = rhs._rows;

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
	// TODO: add size comparison and throw and exception
	Matrix<T>::iterator rhsBegin = rhs.begin();
	Matrix<T>::iterator rhsEnd = rhs.end();
	Matrix<T>::iterator thisBegin = begin();

	std::vector<T> newMatrixVec(_cols * _rows);

	int i;
	for (i = 0; rhsBegin != rhsEnd; ++rhsBegin, ++thisBegin, ++i)
	{
		newMatrixVec[i] = *thisBegin + *rhsBegin;
	}

	Matrix<T> newMatrix(_rows, _cols, newMatrixVec);
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
	// TODO: add size comparison and throw and exception
	// TODO: maybe make a single function for addition and subtraction
	iterator rhsBegin = rhs.begin();
	iterator rhsEnd = rhs.end();
	iterator thisBegin = begin();

	std::vector<T> newMatrixVec(_cols * _rows);

	int i;
	for (i = 0; rhsBegin != rhsEnd; ++rhsBegin, ++thisBegin, ++i)
	{
		newMatrixVec[i] = *thisBegin - *rhsBegin;
	}

	Matrix<T> newMatrix(_rows, _cols, newMatrixVec);
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
	Matrix<T> result(_rows, rhs._cols);
	// TODO: add matrix size verification
	// this nxm, rhs mxp
	unsigned int i, j, k;
	for (i = 0; i < _rows; ++i)
	{
		for (j = 0; j < rhs._cols; ++j)
		{
			T sum = 0;
			for (k = 0; k < _cols; ++k)
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
	if (_cols != rhs._cols || _rows != rhs._rows)
	{
		return false;
	}

	iterator thisBegin = this->begin();
	iterator thisEnd = this->end();
	iterator rhsBegin = rhs.begin();

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
	//TODO: throw exception if matrix isn't square
	unsigned int i, j;
	Matrix<T> transMatrix(_rows, _cols);

	for (i = 0; i < _rows; ++i)
	{
		for (j = 0; j < _cols; ++j)
		{
			transMatrix(j, i) = (*this)(i, j);
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
	if (row >= _rows || row < MIN_MATRIX_INDEX || col >= _cols || col < MIN_MATRIX_INDEX)
	{
		throw std::out_of_range(OUT_OF_RANGE_MSG);
	}

	/* matrix indexes start at 1, but vector indexes start at 0 */
	return _matrix[_getIndex(row, col)];
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
	if (row >= _rows || row < MIN_MATRIX_INDEX || col >= _cols || col < MIN_MATRIX_INDEX)
	{
		throw std::out_of_range(OUT_OF_RANGE_MSG);
	}

	/* matrix indexes start at 1, but vector indexes start at 0 */
	return _matrix[_getIndex(row, col)];
}


/**
 * @brief returns the number of columns in the matrix
 * @return the number of columns in the matrix
 */
template <typename T>
unsigned int Matrix<T>::cols() const
{
	return _cols;
}

/**
 * @brief returns the number of rows in the matrix
 * @return the number of rows in the matrix
 */
template <typename T>
unsigned int Matrix<T>::rows() const
{
	return _rows;
}

//-------------------------- Iterator class implementation ---------------------------

/**
 * @brief bidirectional const iterator class
 */
template<class T>
class Matrix<T>::_BidiConstIterator : public std::iterator<std::bidirectional_iterator_tag, T, std::ptrdiff_t, T*, T&>
{
	/**
	 * @brief pointer to the element
	 */
	const T* _ptr;

public:
	/**
	 * @brief Bidirectional iterator constructor
	 * @param ptr the element the iterator should point to
	 */
	_BidiConstIterator(const T* ptr) : _ptr(ptr) {};

	/**
	 * @brief Iterator constructor
	 * @param iterator to copy
	 */
	_BidiConstIterator(const _BidiConstIterator& other) : _ptr(other._ptr) {};

	/**
	 * @brief Destructor
	 */
	~_BidiConstIterator() {};

	/**
	 * @brief assign operator
	 * @param rhs the object to assign to this one
	 * @return this
	 */
	_BidiConstIterator& operator=(const _BidiConstIterator& rhs)
	{
		_ptr = rhs._ptr;
		return *this;
	}

	/**
	 * @brief equals operator
	 * @param rhs the object to test this against
	 * @return true if rhs equals this, otherwise false
	 */
	bool operator==(const _BidiConstIterator& rhs) const
	{
		return (_ptr == rhs._ptr);
	}

	/**
	 * @brief not-equals operator
	 * @param rhs the object to test this against
	 * @return true if rhs doesn't equal this, otherwise false
	 */
	bool operator!=(const _BidiConstIterator& rhs) const
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