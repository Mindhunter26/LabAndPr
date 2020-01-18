#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct input {
	string info[12];
	/*
	0 - id; 
	1 - survived, 
	2 - class, 
	3 - name, 
	4 - sex, 
	5 - age,
	6 - sibsp,
	7 - parch,
	8 - ticket, 
	9 - fare, 
	10 - cabin, 
	11 - embarke
	*/
};

vector<input> inputs;

int main()
{
	setlocale(LC_ALL, "Russian");

	ifstream fin("train.csv");

	if (!fin.is_open()) {
		cout << "Не удалось открыть файл!" << endl;
		fin.close();
	}

	else {

		while (fin.good()) {
			string row;
			int start = 0;
			input inpLine;//Входная линия
			getline(fin, row, '\r');
			bool isInQuotes = false;//Проверка , находится ли символ в кавычках
			int col = 0;
			for (int i = 0; i < row.length(); i++) {
				if (row[i] == '"') 
					isInQuotes = !isInQuotes;
				if (!isInQuotes) {//Если в кавычках
					if (row[i] == ',') {
						inpLine.info[col] = row.substr(start, i - start);
						col++;
						start = i + 1;
					}
					else if (i == row.length() - 1) {
						inpLine.info[11] = row.substr(start, 1);
					}
				}
			}
			inputs.push_back(inpLine);
		}
		fin.close();

		int surv = 0, fcSurv = 0, scSurv = 0, tcSurv = 0, femSurv = 0, maleSurv = 0;//Выжившие
		int ageCount = 0, femAgeCount = 0, maleAgeCount = 0;//Кол-во исзвестных возрастов
		double averAge = 0, averFemAge = 0, averMaleAge = 0;//Средние возраста

		int C = 0, Q = 0, S = 0;//Порты
		char maxEmb = ' ';//Порт , где село больше всего пассажиров

		string kids = "";

		for (int i = 1; i < inputs.size(); i++) {

			if (inputs[i].info[1] == "1") 
				surv++;
			if (inputs[i].info[1] == "1" && inputs[i].info[2] == "1") 
				fcSurv++;
			if (inputs[i].info[1] == "1" && inputs[i].info[2] == "2") 
				scSurv++;
			if (inputs[i].info[1] == "1" && inputs[i].info[2] == "3") 
				tcSurv++;
			if (inputs[i].info[1] == "1" && inputs[i].info[4] == "female") 
				femSurv++;
			if (inputs[i].info[1] == "1" && inputs[i].info[4] == "male") 
				maleSurv++;

			if (!inputs[i].info[5].empty()) {
				averAge += stod(inputs[i].info[5]);
				ageCount++;
			}

			if (inputs[i].info[4] == "female" && !inputs[i].info[5].empty()) {
				averFemAge += stod(inputs[i].info[5]);
				femAgeCount++;
			}

			if (inputs[i].info[4] == "male" && !inputs[i].info[5].empty()) {
				averMaleAge += stod(inputs[i].info[5]);
				maleAgeCount++;
			}

			if (inputs[i].info[11] == "C") 
				C++;
			if (inputs[i].info[11] == "Q") 
				Q++;
			if (inputs[i].info[11] == "S") 
				S++;

			if (!inputs[i].info[5].empty()) {
				if (stod(inputs[i].info[5]) < 18) kids += (to_string(i) + ", ");
			}

		}

		averAge /= ageCount;
		averFemAge /= femAgeCount;
		averMaleAge /= maleAgeCount;

		if (C > Q && C > S) 
			maxEmb = 'C';
		if (Q > C && Q > S) 
			maxEmb = 'Q';
		if (S > C && S > Q) 
			maxEmb = 'S';

		kids = kids.substr(0, kids.length() - 2);

		ofstream fout;
		fout.open("output.txt");

		if (fout.is_open()) {

			fout << "Общее число выживших: " << surv << '\n';
			fout << "Число выживших из 1 класса: " << fcSurv << '\n';
			fout << "Число выживших из 2 класса: " << scSurv << '\n';
			fout << "Число выживших из 3 класса: " << tcSurv << '\n';
			fout << "Число выживших женщин: " << femSurv << '\n';
			fout << "Число выживших мужчин: " << maleSurv << '\n';
			fout << "Средний возраст пассажиров: " << averAge << '\n';
			fout << "Средний возраст пассажиров женского пола: " << averFemAge << '\n';
			fout << "Средний возраст пассажиров мужского пола: " << averMaleAge << '\n';
			fout << "Штат, в котором село больше всего пассажиров: " << maxEmb << '\n';
			fout << "Список несовершеннолетних: " << kids << '\n';
		}
		fout.close();

	}
	return 0;
}
