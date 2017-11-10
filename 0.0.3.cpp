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
/*
void change(int ** matrix, int rows, int columns, int sdvig) {
	int *matrix1 = new int[rows + columns - 4];
	int k = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (i == 0 || i == rows - 1) {
				matrix1[k] = matrix[i][j];
				k++;
			}
		}
	}

	for (int j = 0; j < columns; j++) {
		for (int i = 0; i < rows; i++) {
			if ((j == 0 && i != 0 && i != rows - 1) ||
				(j == columns - 1 && i != 0 && i != rows - 1)) {
				matrix1[k] = matrix[i][j];
				k++;
			}
		}
	}

	

	for (int i = 0; i < rows; i++) {
		
	}
}
*/
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


int main()
{
	int ** matrix = nullptr;
	int rows = 0, columns = 0, sdvig = 0;

	if (read(rows, columns)) {
		if (create(matrix, rows, columns)) {
			if (read_sdvig(sdvig)) {
				write(matrix, rows, columns);
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
