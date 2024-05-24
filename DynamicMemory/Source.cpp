#include <iostream>

using namespace std;

void insert_row(string arr[], string x, int n);
void print(string arr[], int n);
void FillRand(string arr[], int n);
int** Allocate(int rows, int cols);
void Clear(int** array, int rows);

int main() {
	const int SIZE = 10;
	string arr[SIZE];
	
	FillRand(arr, SIZE);
	insert_row(arr, "insert", 2);
	print(arr, SIZE);

	return 0;
}

void FillRand(string arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
}

void print(string arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}
}

void insert_row(string arr[], string x, int n) {
	arr[n] = x;
}

int** Allocate(int rows, int cols) {
	int** array = new int* [rows];

	for (int i = 0; i < rows; ++i) {
		array[i] = new int[cols];
	}

	return array;
}

void Clear(int** array, int rows) {
	for (int i = 0; i < rows; ++i) {
		delete[] array[i];
	}
	delete[] array;
}