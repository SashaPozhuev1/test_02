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

bool read_sdvig(int & sdvig) {
	bool success = false;

	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);

	char symb;
	if (stream >> sdvig && sdvig > -1) {
		success = true;
	}

	return success;
}

bool create(int ** & matrix, int & rows, int & columns) {
	bool success = true;

	matrix = new int *[rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[columns];
		
		string stroka;
		getline(cin, stroka);
		istringstream stream(stroka);
		
		for (int j = 0; j < columns; j++) {
			if (!(stream >> matrix[i][j])) {
				success = false;
			}
		}
	}
	return success;
}

void obmen(int * mass, int size, int sdvig) {
	for (int i = 0; i < (size - sdvig) / 2; i++) {
		swap(mass[i], mass[size - sdvig - 1 - i]);
	}
	for (int i = size - sdvig, j = 0; i < size - (sdvig / 2); i++, j++) {
		swap(mass[i], mass[size - 1 - j]);
	}
	for (int i = 0; i < size / 2; i++) {
		swap(mass[i], mass[size - 1 - i]);
	}
}

void change(int ** matrix, int rows, int columns, int sdvig) {
	int *mass = new int[2 * (rows + columns) - 4];
	int k = 0;
	
	for (int j = 0, i = 0; j < columns; j++) {
		mass[k] = matrix[i][j];
		k++;
	}
	for (int i = 1, j = columns - 1; i < rows - 1; i++) {
		mass[k] = matrix[i][j];
		k++;
	}
	for (int j = columns - 1, i = rows - 1; j > -1; j--) {
		mass[k] = matrix[i][j];
		k++;
	}
	for (int i = rows - 2, j = 0; i > 0; i--) {
		mass[k] = matrix[i][j];
		k++;
	}

	obmen(mass, k, sdvig);
	k--;

	for (int i = 1, j = 0; i < rows - 1; i++) {
		matrix[i][j] = mass[k];
		k--;
	}
	for (int j = 0, i = rows - 1; j < columns; j++) {
		matrix[i][j] = mass[k];
		k--;
	}
	for (int i = rows - 2, j = columns - 1; i > 0; i--) {
		matrix[i][j] = mass[k];
		k--;
	}
	for (int j = columns - 1, i = 0; j > -1; j--) {
		matrix[i][j] = mass[k];
		k--;
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
	int rows = 0, columns = 0, sdvig = 0;

	if (read(rows, columns)) {
		if (create(matrix, rows, columns)) {
			if (read_sdvig(sdvig)) {
				if (sdvig <= 2 * (rows + columns) - 4) {
					change(matrix, rows, columns, sdvig);
					write(matrix, rows, columns);
					destroy(matrix, rows);
				}
				else {
					error();
				}
			}
			else {
				error();
			}
		}
		else {
			error();
		}
	}
	else {
		error();
	}
	
	system("pause");
	return 0;
}
