#include "matrix.h"
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream in("input.txt"); // open file;

	int d;
	in >> d;

	Matrix<int> m(d);
	//cout << m.getSize();
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < d; j++)
		{
			int value;
			in >> value;

			//cout << value;
			m.setData(i, j, value);
		}
	}
	cout << m;

	string op;
	getline(in, op); // skip a line first
	getline(in, op); // read the operator

	Matrix<int> other(d); // instantiating a new matrix for operations

	// reading which operation to use and calling the appropriate fxn
	if (op == "op 1") // adding
	{
		cout << "Operator '+' chosen. Reading second matrix." << endl;
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < d; j++)
			{
				int value;
				in >> value;

				//cout << value;
				other.setData(i, j, value);
			}
		}
		cout << other;
		
		cout << "Sum of the two matrices: " << endl << (m + other) << endl << endl;
	}
	else if (op == "op 2") // subtracting
	{
		cout << "Operator '-' chosen. Reading second matrix." << endl;
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < d; j++)
			{
				int value;
				in >> value;

				//cout << value;
				other.setData(i, j, value);
			}
		}
		cout << other;

		cout << "Difference of the two matrices: " << endl << (m - other) << endl << endl;
	}
	else if (op == "op 3") // multiplying
	{
		cout << "Operator '*' chosen. Reading second matrix." << endl;
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < d; j++)
			{
				int value;
				in >> value;

				//cout << value;
				other.setData(i, j, value);
			}
		}
		cout << other;

		cout << "Product of the two matrices: " << endl << (m * other) << endl << endl;
	}
	else if (op == "op 4") // incrementing
	{
		cout << "Operator '++' chosen. Incrementing all elements once." << endl;
		cout << "Incremented matrix: " << endl << ++m;
	}
	else if (op == "op 5") // decrementing
	{
		cout << "Operator '--' chosen. Decrementing all elements once." << endl;
		cout << "Decremented matrix: " << endl << --m;
	}
	else if (op == "op 6") // transposing 
	{
		cout << "Operator '~' chosen. Transposing the matrix." << endl;
		cout << "Transposed matrix: " << endl << ~m;
	}
	else if (op == "op 7") // exponential
	{
		cout << "Operator '^' chosen. Reading exponent value." << endl;
		int exponent;
		in >> exponent;
		cout << "Matrix to the " << exponent << " power: " << endl << (m ^ exponent);
	}
	else
	{
		cout << "No operation instructions detected. Program ending." << endl;
	}
	


	return 0;
}