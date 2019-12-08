#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

enum Order {
	ASC,
	DESC
};
bool inOrder(int *m, int s, Order ord) { //проверка упорядоченности для обычного массива интов, а также для трех отдельных чисел 
	for (int i = 1; i < s; i++) {
		if (ord == ASC) {
			if (m[i] >= m[i - 1]) continue;
			else return false;
		}
		if (ord == DESC) {
			if (m[i] <= m[i - 1]) continue;
			else return false;
		}
	}
}
bool inOrder(vector<int> m, int s, Order ord) { //проверка упорядоченности для vector 
	for (int i = 1; i < s; i++) {
		if (ord == ASC) {
			if (m[i] >= m[i - 1]) continue;
			else return false;
		}
		if (ord == DESC) {
			if (m[i] <= m[i - 1]) continue;
			else return false;
		}
	}
}
void BozoSort(int *m, int s, Order ord = ASC) { // Обычный массив интов 
	srand(unsigned(time(0)));
	while (!inOrder(m, s, ord)) {
		int s1 = rand() % s;
		int s2 = rand() % s;
		if (s1 = s2) s2 /= 2;

		int t = m[s2];
		m[s2] = m[s1];
		m[s1] = t;
	}
	for (int i = 0; i < s; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
}
void BozoSort(vector<int> m, int s, Order ord = ASC) { // std::vector 
	srand(unsigned(time(0)));
	while (!inOrder(m, s, ord)) {
		int s1 = rand() % s;
		int s2 = rand() % s;
		if (s1 = s2) s2 /= 2;

		int t = m[s2];
		m[s2] = m[s1];
		m[s1] = t;
	}
	for (int i = 0; i < s; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
}
void BozoSort(int a, int b, int c, Order ord = ASC) { // три отдельных числа 
	srand(unsigned(time(0)));
	int m[3] = { a,b,c };
	while (!inOrder(m, 3, ord)) {
		int s1 = rand() % 3;
		int s2 = rand() % 3;
		if (s1 = s2) s2 /= 2;

		int t = m[s2];
		m[s2] = m[s1];
		m[s1] = t;
	}
	for (int i = 0; i < 3; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
}

int main()
{
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
}


