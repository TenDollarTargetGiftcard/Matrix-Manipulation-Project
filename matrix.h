#ifndef MATRIX_H
#define MATRIX_H


#include <iostream>
#include <vector>

using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
class Matrix
{
public:
	// constructors
	Matrix(int size);
	// accessor function
	size_t getSize() const;
	// setter for a specific element
	void setData(int i, int j, T value);
	// overloaded operators
	Matrix<T> operator+(const Matrix<T>& other) const; // adds two matrices
	Matrix<T> operator-(const Matrix<T>& other) const; // subtracts second matrix from first
	Matrix<T> operator*(const Matrix<T>& other) const; // multiplies two matrices
	Matrix<T> operator~() const; // transposes matrix
	Matrix<T> operator^(int exp) const; // puts matrix to the power of inputted exponent
	// declaring friends
	template<typename U>
	friend Matrix<U>& operator++(Matrix<U>& m); // increments all elements of matrix by one
	template<typename U>
	friend Matrix<U>& operator--(Matrix<U>& m); // decrements all elements of matrix by one
	template<typename U>
	friend ostream& operator<<(ostream& out, const Matrix<U>& m); // formats matrix for some form of output
private:
	// private getter for a specific element
	T& getData(int i, int j) const;
	int size; // size of matrix
	T** data; // dynamically allocated matrix
};
// prototypes for friend functions
template<typename U>
ostream& operator<<(ostream& out, const Matrix<U>& m);
template<typename U>
Matrix<U>& operator++(Matrix<U>& m);
template<typename U>
Matrix<U>& operator--(Matrix<U>& m);
#include "matrix.tpp"
#endif // MATRIX_H