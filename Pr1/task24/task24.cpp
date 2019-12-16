#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

size_t mystrlen(const char* string) {
	int len = 0;
	int i = 0;
	while (string[i] != '\0') {
		len++;
		i++;
	}
	return len;
}

int mystrcmp(const char* string1, const char* string2) {
	int i = -1;
	while (string1[i] != '\0' && string2[i] != '\0')
	{
		i++;
		if (string1[i] > string2[i]) { cout << "Строка 1 больше строки 2" << endl; break; }
		if (string1[i] < string2[i]) { cout << "Строка 2 больше строки 1" << endl; break; }
		if (string1[i] == string2[i]) { cout << "Строки равны" << endl; break; }
	}
	return 0;
}

char* mystrstr(char* string1, const char* string2) {
	for (int i = 0; i < mystrlen(string1); i++)
	{
		int l = 0;
		if (string1[i] == string2[l])
		{
			int k = 1;
			l++;

			while ((string1[i + l] == string2[l]) && (l < mystrlen(string2))) {
				k++;
				l++;
			}
			if (k == mystrlen(string2)) {
				return &string1[i];
			}
		}
	}
	return nullptr;
}

char* mystrcat(char* destptr, const char* srcptr) {
	int len = mystrlen(destptr);
	for (int i = 0; i < mystrlen(srcptr); i++)
		destptr[len + i] = srcptr[i];
	destptr[len + mystrlen(srcptr)] = '\0';
	return destptr;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	char input1[51];
	char input2[51];

	cin.getline(input1, 51, '\n');
	cin.getline(input2, 51, '\n');
	cout << mystrlen(input1) << " " << mystrlen(input2) << '\n';
	mystrcmp(input1, input2);

	int i = 0;
	if (mystrstr(input1, input2)) while (&input1[i] != mystrstr(input1, input2)) i++;
	else i = -1;
	cout << i << endl;

	cout << mystrcat(input1, input2);

}
