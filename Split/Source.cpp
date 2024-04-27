#include <iostream>

using namespace std;
#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void sort(int arr[], const int n);

int main() {
	setlocale(LC_ALL, "");
	int n = 10; 
	int *numbers = new int[n];

	FillRand(numbers, n);
	Print(numbers, n);
	sort(numbers, n);

	delete[] numbers;
	return 0;
}


void FillRand(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
}

void sort(int arr[], int n) {
	int countOdd = 0;
	int countEven = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			countEven++;
		}
		else {
			countOdd++;
		}
	}
	int* odd = new int[countOdd];
	int* even = new int[countEven];
	countOdd = 0;
	countEven = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			even[countEven] = arr[i];
			countEven++;
		}
		else {
			odd[countOdd] = arr[i];
			countOdd++;
		}
	}
	
	cout << "Нечётные чила: "; Print(odd, countOdd);
	cout << "Чётные чила: "; Print(even, countEven);

	delete[] odd;
	delete[] even;
}


void Print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << tab;
	}
	cout << endl;
}
