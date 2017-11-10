#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>

using namespace std;

bool read(int & rows, int & columns) {
	bool success = false;

	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);

	char symb;
	if (stream >> rows && rows > 0 &&
		stream >> symb && symb == ',' &&
		stream >> columns && columns > 0) {
		success = true;
	}

	return success;
}

void create(int ** & matrix, int rows, int columns) {
	
	matrix = new int *[rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[columns];
	}

	int k = 1, r = 0, c = 0;
	
	while (k < rows * columns + 1) {
		for (int j = c;	j < columns - c; j++) {
			if (k > rows * columns) {
				break;
			}
			else {
				matrix[r][j] = k;
				k++;
			}
		}
		for (int i = r + 1;	i < rows - r; i++) {
			if (k > rows * columns) {
				break;
			}
			else {
				matrix[i][columns - 1 - c] = k;
				k++;
			}
		}
		for (int j = columns - 2 - c; j > c - 1; j--) {
			if (k > rows * columns) {
				break;
			}
			else {
				matrix[rows - 1 - r][j] = k;
				k++;
			}
		}
		for (int i = rows - 2 - r; i > r; i--) {
			if (k > rows * columns) {
				break;
			}
			else {
				matrix[i][c] = k;
				k++;
			}
		}
		c++;
		r++;
	}
}

void write(int ** matrix, int rows, int columns) {
	cout << '\n';
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << matrix[i][j];
			if (j != columns - 1) {
				cout << ' ';
			}
			else {
				cout << '\n';
			}
		}
	}
}

void error() {
	cout << "An error has occured while reading input data.\n";
}

void destroy(int ** & matrix, int rows) {
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main()
{
	int ** matrix = nullptr;
	int rows = 0, columns = 0;

	if (read(rows, columns)) {
		create(matrix, rows, columns);
		write(matrix, rows, columns);
		destroy(matrix, rows);
	}
	else {
		error();
	}
	
	system("pause");
	return 0;
}
