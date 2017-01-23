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

template<class T>
class Matrix
{
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
	 * @brief default constructor
	 * initializes a matrix of size 1x1 with a single element 0
	 */
	Matrix();

	/**
	 * @brief returns the element in the given matrix position
	 * @param row the row number
	 * @param col the column number
	 * @return the element in the given row and column number
	 */
	const T& operator()(unsigned int row, unsigned int col) const;



	std::iterator begin() const
	{
		return _BidiConstIterator(_matrix);
	}

	std::iterator end() const
	{
		return _BidiConstIterator((&_matrix) + (_cols * _rows));
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

	/**
	 * @brief bidirectional const iterator class
	 */
	class _BidiConstIterator : public std::iterator<std::bidirectional_iterator_tag, T, std::ptrdiff_t, T*, T&>
	{
		T* _ptr;
	public:
		/**
		 * @brief Bidirectional iterator constructor
		 * @param ptr the element the iterator should point to
		 */
		_BidiConstIterator(T* ptr) : _ptr(ptr) {};

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
			T* tmp = _ptr++;
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
			T* tmp = _ptr--;
			return *tmp;
		}
	};
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

//-------------------------- Iterator methods ---------------------------

#endif //MATRIX_MATRIX_HPP
