// Pr1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <ctime>
#define G -9.8
using namespace std; //Используется для дальнейшего использования имен из пространства std без приписывания "std::"


void task1() {
	cout << "Результат выполнения 2+2*2=" << 2 + 2 * 2 << endl;
}
void task2() {
	int z = 3, b = 3.14;
	double c = 3, d = 3.14;
	cout << z << endl << b << endl << c << endl << d << endl; //ИЗ дробной переменной b выводит только целую часть , так как тип переменной integer
}
void task3() {
	int e, f;
	cin >> e >> f;
	cout << e + f << endl << e - f << endl << e * f << endl << e / f << endl; //Деление выводит только целую часть от получившегося результата т.к. тип перепенных int, если сделать хотя бы одну переменную double , то резульат будет дробным
}
void task4() {
	int k, h, j,way;
	cout << "Выберите способ решения (1 с доп. переменной , 2 без доп. переменной)" << endl;
	cin >> way;
	switch (way) {
	case 1 :
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
		cout << k << endl << h<< endl;
		break;
	default:
		cout << "Wrong case" << endl;
	}
}
void task5() {
	double x, x0, v0, t, a;
	cout << "Введите: x0,v0,t" << endl;
	cin >> x0 >> v0 >> t;
	a = G;
	cout << x0 + v0 * t + (a*t*t) / 2 << endl;
	cout << x0 + v0 * t + 1 / 2 * a*t*t << endl; // Неверный ответ так как числа 1 и 2 позиционируются как int и значение выражения 1 / 2 = 0
}
void task6() {
	double a,b,c,x1,x2;
	cout << "Введите коэффициенты" << endl;
	cin >> a>>b>>c;
	double D = b * b - 4 * a*c;
	x1 = (-b - sqrt(D)) / 2*a;
	x2 = (-b + sqrt(D)) / 2*a;
	cout << "x1="<<x1<<endl<<"x2="<<x2<<endl;

}
void task7() {
	double a, b, c, x1, x2, x3, y1, y2, y3, p, S;
	int way;
	cout << "Выберите способ(1 - через длины сторон , 2 - через координаты )" << endl;
	cin >> way;
	switch (way) {
	case 1 : 
		cout << "Введите длины сторон" << endl;
		cin >> a >> b >> c;
		p = 0.5*(a + b + c);
		S = sqrt(p*(p-a)*(p-b)*(p-c));
		cout << "S=" << S << endl;
		break;
	case 2:
		cout << "Введите координаты вершин треугольника" << endl;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		S = 0.5*abs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
		cout << "S=" << S << endl;
		break;
	default:
		cout << "Wrong case" << endl;
	}
}
void task8() {
	double a, b, result;
	char op;

	cin>> a>> op>> b;

	switch (op) {
	case '+':
		result = a + b;
		cout<<result<< endl;
		break;

	case '-':
		result = a - b;
		cout<< result << endl;
		break;

	case '*':
		result = a * b;
		cout<<result<< endl;
		break;

	case '/':
		result = a / b;
		cout <<result<< endl;
		break;

	default:
		cout<< "Неверный оператор"<<endl;
		break;
	}
}
void task9() {
	bool checkResult=false;
	int n,x;
	srand(unsigned(time(0)));
	replay:
	n = rand() % 101; 
	cout << "Попробуйте угадать число "<< endl;
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
	if (checkResult==false) 
	cout << "Вы проиграли, загаданное число было "<<n << endl;
	
		int a;
		cout << "ХОЧЕШЬ ЕЩЕ?(1- ДА , 2- Нет)"<<endl;
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
	int n,res=1;
	cout << "Введите число для нахождения его факториала" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		res *= i;
	}
	cout << res<<endl;
}
void task12() {
	int n, i;
	bool Prime = true;
	cout << "Введите число "<<endl;
	cin >> n;
	for (i = 2; i <= (sqrt(abs(n))); i++) {
		if (n%i == 0) {
			Prime = false;
			break;
		}
	}
	if (Prime==true)
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
	cout << k<<endl;
}
void task14() {
	bool res = false;
	int s, l1, l2, r1, r2, x1=NULL, x2=NULL;
	cin >> s >> l1 >> r1 >> l2 >> r2;
	for (int i = l1; i <= r1; i++)
	{
		for (int j = l2; j <= r2; j++)
		{
			if (s==i+j)
			{
				if (i < x1 || x1 == NULL) {
					x1 = i;
					x2 = j;
				}
				res = true;
				break;

			}
			
		}
	}
	if (!res) {
		cout << -1 << endl;
	}
	else cout << x1 << endl << x2 << endl;
	
}
/*
void task15() {
	int n, i, a, min = 1000001;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a;
		if (a < min)
		{
			min = a;
		}
		
	}
	
	cout << min << endl;
}
*/





int main()
{
	setlocale(LC_ALL, "Russian"); //Устраняет проблемы с выводом на экран русского языка
	int tasks;
	cout << "Введите номер задания(1-15)" << endl;
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
	default: 
		cout << "Неверный номер" << endl;
	}
	system("PAUSE");
}
