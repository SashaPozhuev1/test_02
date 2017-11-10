#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>

using namespace std;

bool read(int & size) {
	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);

	bool success = true;

	if (stream >> size && size > 0) {

	}
	else {
		success = false;
	}

	return success;
}

bool create(double * & mass, int resultsize) {
	bool success = true;

	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);

	int size = 0;
	int element;
	
	mass = new double[resultsize];
	int i = 0;
	while (stream >> element) {
		if (size < resultsize) {
			mass[i] = element;
			i++;
			size++;
		}
		else {
			success = false;
			break;
		}
	}
	
	if (resultsize > size) {
		success = false;
	}

	return success;
}


void obmen(double * mass, int size, int rev) {
	for (int i = 0; i < (size - rev) / 2; i++) {
		swap(mass[i], mass[size - rev - 1 - i]);
	}
	for (int i = size - rev, j = 0; i < ( size + rev ) / 2; i++, j++) {
		swap(mass[i], mass[size - 1 - j]);
	}
	for (int i = 0; i < size / 2; i++) {
		swap(mass[i], mass[size - 1 - i]);
	}
}

void write(double * mass, int size) {
	for (int i = 0; i < size; i++) {
		cout << mass[i];
		if (i != size - 1) {
			cout << ' ';
		}
		else {
			cout << '\n';
		}
	}
}

void error() {
	cout << "An error has occured while reading input data.\n";
}


int main()
{

	int size = 0;
	double * mass = nullptr;

	int schet = 0;
	if (read(size)) {
		if (create(mass, size)) {
			int rev = 0;
			if (read(rev)) {
			    if (size >= rev) {
				    obmen(mass, size, rev);
				    write(mass, size);
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
