#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

enum Order {
	ASC,
	DESC
};
bool inOrder(int *arr, int size, Order order) { //проверка упорядоченности для обычного массива интов, а также для трех отдельных чисел 
	for (int i = 1; i < size; i++) {
		if (order == ASC) {
			if (arr[i] >= arr[i - 1]) continue;
			else 
				return false;
		}
		if (order == DESC) {
			if (arr[i] <= arr[i - 1]) continue;
			else 
				return false;
		}
	}
}
bool inOrder(vector<int> arr, int size, Order order) { //проверка упорядоченности для vector 
	for (int i = 1; i < size; i++) {
		if (order == ASC) {
			if (arr[i] >= arr[i - 1]) continue;
			else 
				return false;
		}
		if (order == DESC) {
			if (arr[i] <= arr[i - 1]) continue;
			else 
				return false;
		}
	}
}
void BozoSort(int *arr, int size, Order order = ASC) { // Обычный массив интов 
	srand(unsigned(time(0)));
	while (!inOrder(arr, size, order)) {
		int s1 = rand() % size;
		int s2 = rand() % size;
		if (s1 == s2)
			s2 = s2 / 2;

		int t = arr[s2];
		arr[s2] = arr[s1];
		arr[s1] = t;
	}
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void BozoSort(vector<int> arr, int size, Order order = ASC) { // std::vector 
	srand(unsigned(time(0)));
	while (!inOrder(arr, size, order)) {
		int s1 = rand() % size;
		int s2 = rand() % size;
		if (s1 == s2) 
			s2 = s2 / 2;

		int t = arr[s2];
		arr[s2] = arr[s1];
		arr[s1] = t;
	}
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void BozoSort(int a, int b, int c, Order order = ASC) { // три отдельных числа 
	srand(unsigned(time(0)));
	int arr[3] = { a,b,c };
	while (!inOrder(arr, 3, order)) {
		int s1 = rand() % 3;
		int s2 = rand() % 3;
		if (s1 == s2)
			s2 = s2 / 2;

		int t = arr[s2];
		arr[s2] = arr[s1];
		arr[s1] = t;
	}
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
    int size;
	cin >> size;

	int *arr = new int[size];
	vector<int> Varr(size);

	for (int i = 0; i < size; i++) {
		cin >> arr[i];
		Varr[i] = arr[i];
	}

	cout << endl;

	BozoSort(arr, size);
	BozoSort(arr, size, DESC);
	cout << endl;
	BozoSort(Varr, size);
	BozoSort(Varr, size, DESC);
	cout << endl;
	if (size == 3) {
		BozoSort(arr[0], arr[1], arr[2]);
		BozoSort(arr[0], arr[1], arr[2], DESC);
	}
}


