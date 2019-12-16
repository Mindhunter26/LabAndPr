#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

enum Order {
	ASC,
	DESC
};
bool isInOrder(int *arr, int s, Order order) { //проверка упорядоченности для обычного массива интов, а также для трех отдельных чисел 

	if (order == ASC)
		for (int i = 1; i < s; i++)
			if (arr[i] <= arr[i - 1]) 
				return false;

	if (order == DESC)
		for (int i = 1; i < s; i++)
			if (arr[i] >= arr[i - 1]) 
				return false;

	return true;
}
bool isInOrder(vector<int> arr, int s, Order order) { //проверка упорядоченности для vector 

	if (order == ASC)
		for (int i = 1; i < s; i++)
			if (arr[i] <= arr[i - 1]) 
				return false;

	if (order == DESC)
		for (int i = 1; i < s; i++)
			if (arr[i] >= arr[i - 1]) 
				return false;

	return true;
}
void BozoSort(int *arr, int s, Order order = ASC) { // Сортировка обычного массива интов 
	while (!isInOrder(arr, s, order)) {
		int s1 = rand() % s;
		int s2 = rand() % s;
		if (s1 == s2) s2 /= 2;

		int t = arr[s2];
		arr[s2] = arr[s1];
		arr[s1] = t;
	}
	for (int i = 0; i < s; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void BozoSort(vector<int> arr, int s, Order order = ASC) { // Сортировка для vector
	while (!isInOrder(arr, s, order)) {
		int s1 = rand() % s;
		int s2 = rand() % s;
		if (s1 == s2) s2 /= 2;

		int t = arr[s2];
		arr[s2] = arr[s1];
		arr[s1] = t;
	}
	for (int i = 0; i < s; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void BozoSort(int a, int b, int c, Order order = ASC) { // Сортировка для трех отдельных чисел 
	int arr[3] = { a,b,c };
	while (!isInOrder(arr, 3, order)) {
		int s1 = rand() % 3;
		int s2 = rand() % 3;
		if (s1 == s2) s2 /= 2;

		int t = arr[s2];
		arr[s2] = arr[s1];
		arr[s1] = t;
	}
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL,"Rus");
	srand(unsigned(time(0)));
	int s;
	cin >> s;

	int *arr = new int[s];
	vector<int> varr(s);

	for (int i = 0; i < s; i++) {
		cin >> arr[i];
		varr[i] = arr[i];
	}

	cout << endl;

	BozoSort(arr, s);
	BozoSort(arr, s, DESC);
	cout << endl;

	BozoSort(varr, s);
	BozoSort(varr, s, DESC);
	cout << endl;

	if (s == 3) {
		BozoSort(arr[0], arr[1], arr[2]);
		BozoSort(arr[0], arr[1], arr[2], DESC);
	}

	return 0;
}
