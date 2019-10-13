#include "pch.h"
#include <iostream>
#include <limits>
#include <math.h>
#include <cmath>
#define Infinity std::numeric_limits<double>::infinity()
using namespace std;
double a, b;
double f(double x) {
	if (x <= a) {
		return log(x);
	}
	else if ((a < x) && (x < b)) {
		return 1;
	}
	else if (x >= b) {
		return exp(x);
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	double x1, x2, dx;
	cout << "Введите a, b, xнач, xкон, dx: ";
	cin >> a >> b >> x1 >> x2 >> dx;

	double max = -Infinity, min = Infinity;//Несмотря на красную линию , программа работает верно
	for (double x = x1; x <= (x2+dx); x += dx) {
		double value = f(x);
		if (value < min)
			min = value;
		if (value > max) 
			max = value;

		cout << "f(" << x << ") = " << value << endl;
	}
	cout << "---------------" << endl;
	cout << "min= " << min << endl << "max= " << max << endl;

	return 0;
}

