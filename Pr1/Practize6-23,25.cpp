#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <map>
#include <vector>

#define G -9.8
using namespace std;

void task6() {
double a, b, c, D;
	cin >> a >> b >> c;
	if (a == 0 && b == 0) cout << "x - любое" << endl;
	else if (a == 0 && c == 0 || b == 0 && c == 0) cout << "x = " << 0 << endl;
	else if (a == 0) cout << "x = " << -c/b << endl;
	else if (b == 0) {
		if (c > 0)	cout << "Нет корней" << endl;
		else cout << "x1 = " << sqrt(-c/a) << endl << "x2 = " << -sqrt(-c/a) << endl;
	}
	else if (c == 0) cout << "x1 = " << 0 << endl << "x2 = " << -b/a << endl;
	else {
		D = b * b - 4 * a * c;
		if (D < 0) {
			cout << "Нет корней" << endl;
		}
		else {
			cout << "x1 = " << (-b + sqrt(D)) / (2 * a) << endl;
			cout << "x2 = " << (-b - sqrt(D)) / (2 * a) << endl;
		}
	}
}

void task7() {
	double a, b, c, x1, x2, x3, y1, y2, y3, p, S;
	int way;
	cout << "Выберите способ(1 - через длины сторон , 2 - через координаты )" << endl;
	cin >> way;
	switch (way) {
	case 1: 
		{
			cout << "Введите длины сторон" << endl;
			cin >> a >> b >> c;
			if (a + b > c && a + c > b && b + c > a) {
				p = 0.5*(a + b + c);
				S = sqrt(p*(p - a)*(p - b)*(p - c));
				cout << "S=" << S << endl;
			}
			else cout << "Doesn't exist\n";
			break;
		}

		case 2:
		{
			cout << "Введите координаты вершин треугольника" << endl;
			cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
			int a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
			int b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
			int c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
			if (a + b > c && a + c > b && b + c > a) {
				S = 0.5*abs((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1));
				cout << "S=" << S << endl;
			}
			else cout << "Doesn't exist\n";
			break;
		}
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
	int deg;
	double num;
	cout << "Введите число и степень" << endl;
	cin >> num >> deg;
	double count = num;
	if (deg == 0) 	cout << 1 << '\n';
	if (deg == 1) cout << num << '\n';
	if (deg == -1) cout << 1 / num << '\n';
	if (deg > 1) {
		for (int i = 1; i < deg; i++) 
			num *= count;
		cout << num << endl;
	}
	if (deg < -1) {
		if (num == 0) cout << 0 << '\n';
		else {
			for (int i = -1; i > deg; i--)
				num = 1 / (count*num);
			cout << num << endl;
		}
	}
}

void task11() {
	long long int n, res = 1;
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
	vector<int> A;
	int counter = 0;
	int pow = 1;
	while (n != 1) {
		for (int i = 2; i <= n; i++) {
			if (!(n%i)) {
				n /= i;
				A.push_back(i);
				counter++;
				break;
			}
		}
	}
	for (auto it = A.begin(); it != A.end(); it++) {
		if (it != A.end() - 1 && *it == *(it + 1))pow++;
		else if (pow > 1) {
			cout << *it << "^" << pow;
			pow = 1;
		}
		else cout << *it;
		if ((it != A.end() - 1) && (pow <= 1)) cout << "*";
	}
}
//for task16
void task16() {
	int a;
	cin >> a;
	factorization(a);
}

double BMI(double weight, double height) {

	return weight / (height*height);
}
void printBMI(double BMI) {
	if (BMI < 18.5)        
		cout << "Underweight\n";
	else if (BMI < 25.0)    
		cout << "Normal\n";
	else if (BMI < 30.0)    
		cout << "Overweight\n";
	else                    
		cout << "Obesity\n";
}
//for task17

void task17() {
	double weight, height;
	cout << "Введите вес (в кг) и рост (в см)\n";
	cin >> weight >> height;
	printBMI(BMI(weight, height / 100));
}

void task18() {
	srand(unsigned(time(0)));
	int n[20];
	for (int i = 0; i < 20; i++) {
		n[i] = (rand() % 201) - 100;
		cout << n[i] << endl;
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

	bool winCheck = false;
	int tries = 0;
	while (!winCheck) {
		int iGuess, jGuess;
		cin >> iGuess >> jGuess;
		if (Matrix[iGuess][jGuess] > 0) {
			cout << "Вы угадали!" << endl;
			winCheck = true;
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


void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
int msort(int* n1, int* n2, int* n3) {
	if (*n1 > *n2) swap(n1, n2);
	if (*n2 > *n3) swap(n2, n3);
	if (*n1 > *n2) swap(n1, n2);
	return *n3;
}
void info(const int* n) {
	cout << "Адрес: "<< n << endl;
	cout << "Значение: " << *n << endl;
}
int* add(int* a, const int* b) {
	*a = *a + *b;
	return a;
}
void task22() {
	void swap(int*, int*); 
	int msort(int*, int*, int*);
	void info(const int*);
	int* add(int*, const int*);

	int a=1;
	int v=2;
	int b=3;
	info(&a);
	info(&v);
	info(&b);
	cout << "max: " << msort(&a, &v, &b) << endl;
	info(add(&a, add(&v, &b)));
}

bool check_palindrom(string word)
{
	if (!word.empty()) {
		int len = word.length();
		for (int i = 0; i < len / 2; ++i)
		{
			if (word[i] != word[len - i - 1])
			{
				return false;
			}
		}
		return true;
	}
	else return false;
}
void task23() {
	string str;
	string fex;
	cout << "Введите слово: ";
	cin.ignore();
	getline(cin, str);

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			str[i] = str[i] + 32;
		}
		if ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 97 && str[i] <= 122)) {
			fex += str[i];
		}
	}

	if (check_palindrom(fex))
		cout << "Палиндром\n";
	else
		cout << "Не палиндром\n";
}

struct Student { 
	string name;
	int group;
	int sec[5];
};
void task25() {
	Student stud[] = {
		{"Denisenko V.A.",2,{1,2,3,2,1}},
		{"Zavyalov I.V.",1,{5,5,5,5,5}},
		{"Fedorov A.A.",1,{4,3,3,4,3}},
		{"Balabanov N.P.",1,{4,5,3,5,3}},
		{"Ivanov A.F.",2,{5,3,4,4,4}},
		{"Petrov S.A.",1,{3,3,3,2,5}},
		{"Sidorov F.F.",2,{5,4,3,4,3}},
		{"Filipenko D.I.",3,{4,5,4,5,3}},
		{"Moskalenko O.V.",1,{2,2,2,1,1}},
		{"Selezneva E.I.",3,{4,5,4,5,3}}
	};
	bool check = true;
	Student mas[10];
	int count = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			if (stud[i].sec[j] < 3) {
				check = false;
				mas[count] = stud[i];
				count++;
				break;
			}
			if (check) {
				cout << "Таких студентов нет\n";
			}
		}
	}
	for (int i = 0; i < count; i++) { 
		for (int j = 0; j < count - i - 1; j++) {
			if (mas[j].name[0] > mas[j + 1].name[0]) {
				Student t = mas[j + 1];
				mas[j + 1] = mas[j];
				mas[j] = t;
			}
		}
	}

	for (int i = 0; i < count; i++) {
		cout << mas[i].name << " " << mas[i].group << endl;
	}

}


int main()
{
	setlocale(LC_ALL, "Russian"); //Устраняет проблемы с выводом на экран русского языка
	int tasks;
	cout << "Введите номер задания(6-25)" << endl;
	cin >> tasks;
	switch (tasks) {
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
	case 22: 
		task22();
		break;
	case 23:
		task23();
		break;
	case 24:
		task24();
		break;
	case 25:
		task25();
		break;
	default:
		cout << "Неверный номер" << endl;
	}
	system("PAUSE");
}
