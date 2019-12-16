#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

enum Order {
	ASC,
	DESC
};
bool inOrder(int *arr, int s, Order order) { //проверка упорядоченности для обычного массива интов, а также для трех отдельных чисел 

	if (order == ASC)
		for (int i = 1; i < s; i++)
			if (arr[i] <= arr[i - 1]) return false;

	if (order == DESC)
		for (int i = 1; i < s; i++)
			if (arr[i] >= arr[i - 1]) return false;

	return true;
}
bool inOrder(vector<int> arr, int s, Order order) { //проверка упорядоченности для vector 

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
	while (!inOrder(arr, s, order)) {
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
	while (!inOrder(arr, s, order)) {
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
	int m[3] = { a,b,c };
	while (!inOrder(m, 3, order)) {
		int s1 = rand() % 3;
		int s2 = rand() % 3;
		if (s1 == s2) s2 /= 2;

		int t = m[s2];
		m[s2] = m[s1];
		m[s1] = t;
	}
	for (int i = 0; i < 3; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL,"Rus");
	srand(unsigned(time(0)));
	int s;
	cin >> s;

	int *m = new int[s];
	vector<int> vm(s);

	for (int i = 0; i < s; i++) {
		cin >> m[i];
		vm[i] = m[i];
	}

	cout << endl;

	BozoSort(m, s);
	BozoSort(m, s, DESC);
	cout << endl;

	BozoSort(vm, s);
	BozoSort(vm, s, DESC);
	cout << endl;

	if (s == 3) {
		BozoSort(m[0], m[1], m[2]);
		BozoSort(m[0], m[1], m[2], DESC);
	}
  
  return 0;
}
