#ifndef MATRIX_TPP
#define MATRIX_TPP

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//constructors
template<typename T>
Matrix<T>::Matrix(int d)
{
	size = d;
	data = new T * [d];
	for (int i = 0; i < d; i++)
	{
		data[i] = new T[d];
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
size_t Matrix<T>::getSize() const { return size; }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void Matrix<T>::setData(int i, int j, T value) { data[i][j] = value;}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
T& Matrix<T>::getData(int i, int j) const { return data[i][j]; }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const
{
	Matrix result(size);
	if (size != other.size)
	{
		cout << "Matrix dimensions do not match!";
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				result.setData(i, j, getData(i, j) + other.getData(i, j));
			}
		}
	}
	return result;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const
{
	Matrix result(size);
	if (size != other.size)
	{
		cout << "Matrix dimensions do not match!";
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				result.setData(i, j, getData(i, j) - other.getData(i, j));
			}
		}
	}
	return result;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const
{
	Matrix result(size);
	if (size != other.size)
	{
		cout << "Matrix dimensions do not match!";
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < other.size; j++)
			{
			T sum = 0;
				for (int k = 0; k < size; k++)
				{
					sum += getData(i, k) * other.getData(k, j);
				}
				result.setData(i, j, sum);
			}
		}
	}
	return result;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
Matrix<T> Matrix<T>::operator~() const
{
	Matrix<T> result(size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			result.setData(i, j, getData(j, i));
		}
	}
	return result;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
Matrix<T> Matrix<T>::operator^(int exp) const
{
	Matrix<T> result = *this;

	for(int i = 1; i < exp; i++)
	{	
		result = result * (*this);
	}

	return result;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename U>
Matrix<U>& operator++(Matrix<U>& m)
{
	for (int i = 0; i < m.size; ++i)
	{
		for (int j = 0; j < m.size; ++j)
		{
			++m.getData(i, j);
		}
	}

	return m;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename U>
Matrix<U>& operator--(Matrix<U>& m)
{
	for (int i = 0; i < m.size; ++i)
	{
		for (int j = 0; j < m.size; ++j)
		{
			--m.getData(i, j);
		}
	}

	return m;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename U>
ostream& operator<<(ostream& out, const Matrix<U>& m)
{
	out << "{ ";
	for (int i = 0; i < m.getSize(); i++)
	{
		for (int j = 0; j < m.getSize(); j++)
		{
			out << m.getData(i, j);
			if (j != m.getSize() - 1)
			{
				out << ", ";
			}
		}
		if (i == m.getSize() - 1)
		{
			out << " }" << endl;
		}
		out << endl << "  ";
	}

	return out;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // MATRIX_TPP