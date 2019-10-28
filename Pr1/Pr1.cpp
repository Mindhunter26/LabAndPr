#include "pch.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <map>
#define G -9.8
using namespace std; //Используется для дальнейшего использования имен из пространства std без приписывания "std::"


void task1() {
	cout << "Результат выполнения 2+2*2=" << 2 + 2 * 2 << endl;
}
//сдал
void task2() {
	int z = 3, b = 3.14;
	double c = 3, d = 3.14;
	cout << z << endl << b << endl << c << endl << d << endl; //ИЗ дробной переменной b выводит только целую часть , так как тип переменной integer
}
//сдал
void task3() {
	int e, f;
	cin >> e >> f;
	cout << e + f << endl << e - f << endl << e * f << endl << e / f << endl; //Деление выводит только целую часть от получившегося результата т.к. тип перепенных int, если сделать хотя бы одну переменную double , то резульат будет дробным
}
//сдал
void task4() {
	int k, h, j, way;
	cout << "Выберите способ решения (1 с доп. переменной , 2 без доп. переменной)" << endl;
	cin >> way;
	switch (way) {
	case 1:
		cout << "Введите 2 числовых значения" << endl;
		cin >> k >> h;
		j = k;
		k = h;
		h = j;
		cout << k << endl << h << endl;
		break;
	case 2:
		cout << "Введите 2 числовых значения" << endl;
		cin >> k >> h;
		k = k + h;
		h = k - h;
		k = k - h;
		cout << k << endl << h << endl;
		break;
	default:
		cout << "Wrong case" << endl;
	}
}
//сдал
void task5() {
	double x, x0, v0, t, a;
	cout << "Введите: x0,v0,t" << endl;
	cin >> x0 >> v0 >> t;
	a = G;
	cout << x0 + v0 * t + (a*t*t) / 2 << endl;
	cout << x0 + v0 * t + 1 / 2 * a*t*t << endl; // Неверный ответ так как числа 1 и 2 позиционируются как int и значение выражения 1 / 2 = 0
}
//сдал
void task6() {
	double a, b, c, x1, x2;
	cout << "Введите коэффициенты" << endl;
	cin >> a >> b >> c;
	double D = b * b - 4 * a*c;
	x1 = (-b - sqrt(D)) / 2 * a;
	x2 = (-b + sqrt(D)) / 2 * a;
	cout << "x1=" << x1 << endl << "x2=" << x2 << endl;

}

void task7() {
	double a, b, c, x1, x2, x3, y1, y2, y3, p, S;
	int way;
	cout << "Выберите способ(1 - через длины сторон , 2 - через координаты )" << endl;
	cin >> way;
	switch (way) {
	case 1:
		cout << "Введите длины сторон" << endl;
		cin >> a >> b >> c;
		p = 0.5*(a + b + c);
		S = sqrt(p*(p - a)*(p - b)*(p - c));
		cout << "S=" << S << endl;
		break;
	case 2:
		cout << "Введите координаты вершин треугольника" << endl;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		S = 0.5*abs((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1));
		cout << "S=" << S << endl;
		break;
	default:
		cout << "Wrong case" << endl;
	}
}

void task8() {
	double a, b, result;
	char op;

	cin >> a >> op >> b;

	switch (op) {
	case '+':
		result = a + b;
		cout << result << endl;
		break;

	case '-':
		result = a - b;
		cout << result << endl;
		break;

	case '*':
		result = a * b;
		cout << result << endl;
		break;

	case '/':
		result = a / b;
		cout << result << endl;
		break;

	default:
		cout << "Неверный оператор" << endl;
		break;
	}
}

void task9() {
	bool checkResult = false;
	int n, x;
	srand(unsigned(time(0)));
replay:
	n = rand() % 101;
	cout << "Попробуйте угадать число " << endl;
	for (int i = 0; i < 5; i++) {
		cin >> x;
		if (i < 4) {
			if (x > n) {
				cout << "Загаданное число меньше" << endl; continue;
			}
			if (x < n) {
				cout << "Загаданное число больше" << endl; continue;
			}
		}
		if (x == n) {
			checkResult = true;
			cout << "Ура вы выиграли!!!!" << endl; break;
		}

	}
	if (checkResult == false)
		cout << "Вы проиграли, загаданное число было " << n << endl;

	int a;
	cout << "ХОЧЕШЬ ЕЩЕ?(1- ДА , 2- Нет)" << endl;
	cin >> a;
	switch (a) {
	case 1:
		system("CLS");
		goto replay;
		break;
	case 2:
		cout << "Удачи!" << endl;
		break;

	default:
		cout << "Сказано же 1 или 2!!!" << endl;
		break;
	}
}

void task10() {
	int n, a;
	cout << "Введите число и степень" << endl;
	cin >> n >> a;
	int res = n;
	if (a == 0) {
		cout << 1;
	}
	for (int i = 1; i < a; i++)
	{
		n *= res;
	}
	cout << n;
}

void task11() {
	int n, res = 1;
	cout << "Введите число для нахождения его факториала" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		res *= i;
	}
	cout << res << endl;
}

void task12() {
	int n, i;
	bool Prime = true;
	cout << "Введите число " << endl;
	cin >> n;
	for (i = 2; i <= (sqrt(n)); i++) {
		if (n%i == 0) {
			Prime = false;
			break;
		}
	}
	if (Prime == true)
		cout << "Простое" << endl;
	else
		cout << "Составное" << endl;

}

void task13() {
	int n;
	cin >> n;
	int k = 0;
	for (int i = 1; i <= n; i *= 2)
		k++;
	cout << k << endl;
}

void task14() {
	int s;
	int l1, l2, r1, r2;
	int x1 = 0, x2 = 0;

	bool found = false;
	cout << "Введите s, l1, r1, l2, r2" << endl;
	cin >> s >> l1 >> r1 >> l2 >> r2;
	for (int i = l1; i <= r1; i++) {
		for (int j = l2; j <= r2; j++) {
			if (i + j == s) {
	
				x1 = i;
				x2 = j;
				found = true;
				break; 
			}
		}
		if (found) break;
	}
	if (!found) {
		cout << -1 << endl;
	}
	else cout << x1 << " " << x2 << endl;

}

void task15() {
	int n;
	cin >> n;

	int *mas1 = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> mas1[i];
	}

	for (int i = 1; i <= n; i++) {


		int *mas2 = new int[i];

		for (int j = 0; j < i; j++) {
			mas2[j] = mas1[j];

		}

		for (int j = 0; j < i; j++) {
			for (int k = 0; k < i - j - 1; k++) {
				if (mas2[k] > mas2[k + 1]) {
					int t = mas2[k + 1];
					mas2[k + 1] = mas2[k];
					mas2[k] = t;
				}
			}
		}
		int s = i;
		if (s > 5) s = 5;
		for (int j = s - 1; j >= 0; j--) {
			cout << mas2[j] << " ";
		}

		delete[] mas2;
		cout << endl;
	}

	delete[] mas1;
}

void factorization(int n) {

}
//for task16
void task16() {

}

double BMI(double weight, double height) {

	return weight / (height*height);
}
void printBMI(double BMI) {
	if (BMI < 18.5)         cout << "Underweight\n";
	else if (BMI < 25.0)    cout << "Normal\n";
	else if (BMI < 30.0)    cout << "Overweight\n";
	else                    cout << "Obesity\n";
}
//for task17

void task17() {
	double w, h;
	cin >> w >> h;
	printBMI(BMI(w, h / 100));
}

void task18() {
	srand(unsigned(time(0)));
	int n[20];
	for (int i = 0; i < 20; i++) {
		n[i] = (rand() % 201) - 100;
		cout << n[i] <<endl;
	}
	cout << endl;
	int min = n[1];
	int max = n[1];
	for (int i = 1; i < 20; i++) {
		if (n[i] > max) 
			max = n[i];
		if (n[i] < min) 
			min = n[i];
	}
	cout << min << endl;
	cout << max << endl;
}

void task19() {
	int n;
	cin >> n;
	int *a = new int[n];
	int num[10];
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < 10; i++) 
		num[i] = 0;

	for (int i = 0; i < n; i++) {
		num[a[i]]++;
	}

	for (int i = 0; i < 10; i++) {
		if (num[i] > 0) {
			cout << i << ": " << num[i] << endl;
		}
	}
	delete[] a;

}

void bubblik(int *a, int length) {
	for (int i = 0; i < length; i++) { //сортировка пузырьком
		for (int j = 0; j < length - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				int t = a[j + 1];
				a[j + 1] = a[j];
				a[j] = t;
			}
		}
	}

	for (int i = 0; i < length; i++) {
		cout << a[i] << endl;
	}
}
//for task20
void task20() { 
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	bubblik(a, n);
}

void task21() {
	srand(unsigned(time(0)));
	int Matrix[10][8];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 8; j++) {
			Matrix[i][j] = 0;
		}
	}
	int iRand = rand() % 10;
	int jRand = rand() % 8;

	Matrix[iRand][jRand] = 1;

	bool win = false;
	int tries = 0;
	while (!win) {
		int iGuess, jGuess;
		cin >> iGuess >> jGuess;
		if (Matrix[iGuess][jGuess] > 0) {
			cout << "Вы угадали!" << endl;
			win = true;
		}
		else if (Matrix[iGuess][jGuess] < 0) {
			cout << "Этот уже проверяли." << endl;
		}
		else if (Matrix[iGuess][jGuess] == 0) {
			cout << "Нет" << endl;
			Matrix[iGuess][jGuess] = -1;
			tries++;
		}
		if (tries > 5) {
			cout << "GAME OVER.";
			break;
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Russian"); //Устраняет проблемы с выводом на экран русского языка
	int tasks;
	cout << "Введите номер задания(1-21)" << endl;
	cin >> tasks;
	switch (tasks) {
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	case 4:
		task4();
		break;
	case 5:
		task5();
		break;
	case 6:
		task6();
		break;
	case 7:
		task7();
		break;
	case 8:
		task8();
		break;
	case 9:
		task9();
		break;
	case 10:
		task10();
		break;
	case 11:
		task11();
		break;
	case 12:
		task12();
		break;
	case 13:
		task13();
		break;
	case 14:
		task14();
		break;
	case 15:
		task15();
		break;
	case 16:
		task16(); 
		break;
	case 17:
		task17();
		break;
	case 18:
		task18();
		break;
	case 19:
		task19();
		break;
	case 20:
		task20();
		break;
	case 21:
		task21();
		break;
	default:
		cout << "Неверный номер" << endl;
	}
	system("PAUSE");
}