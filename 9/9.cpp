#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

int to_hex(int A, int q)
{
	int B = 0;
	for (int i = 0; A > 0; i++)
	{
		B = B + (A % 10 * pow(q, i));
		A = A / 10;
	}
	return B;
}

string to_reverse(int a, int q)
{
	int rem = 0;
	double ned = 0;
	int* mas = new int[50];
	int j = 0;
	while (a > 0)
	{
		ned = floor(a / q);
		rem = a - (ned * q);
		a = ned;
		mas[j] = rem;
		j++;
	}
	string temp = "";
	for (int i = j - 1; i >= 0; i--)
	{
		temp += to_string(mas[i]);
	}
	return temp;
}

int check(int h, int p)
{
	int a;
	for (int i = 0; h > 0; i++)
	{
		a = h % 10;
		if (a >= p)
		{
			cout << "Нарушены правила заданной системы счисления!" << endl;
			system("pause");
			exit(0);
		}
		else h = h / 10;
	}
	return 0;
}


int main()
{
	setlocale(0, "");
	int h1, h2;
	int p1, p2;
	char* name = new char[10];
	cout << "Введите название файла, который требуется открыть: ";
	cin >> name;
	ofstream fout("end.txt");
	ifstream fin;
	int mas[5];
	fin.open(name);
	if (!fin)
	{
		cout << "Исходный файл не найден!" << endl;
		fout << "Исходный файл не найден!" << endl;
		system("pause");
		return 0;
	}
	if (fin.peek() == EOF)
	{
		cout << "Открыт пустой файл." << endl;
		fout << "Открыт пустой файл." << endl;
		fin.close();
		system("pause");
		return 0;
	}
	else
	{
		int i = 0;
		while (fin)
		{
			fin >> mas[i];
			if (i > 4)
			{
				cout << "Ошибка в файле данных!" << endl;
				fout << "Ошибка в файле данных!" << endl;
				system("pause");
				return 0;
			}
			i++;
		}
		h1 = mas[0];
		p1 = mas[1];
		h2 = mas[2];
		p2 = mas[3];
	}
	cout << "P1 = " << p1 << ", " << "H1 = " << h1 << endl;
	fout << "P1 = " << p1 << ", " << "H1 = " << h1 << endl;
	cout << "P2 = " << p2 << ", " << "H2 = " << h2 << endl;
	fout << "P2 = " << p2 << ", " << "H2 = " << h2 << endl;
	if (p1 > 16 || p1 == 7 || p1 == 9 || p1 == 11 || p1 == 13 || p1 == 14 || p1 == 15)
	{
		cout << "Ошибка при вводе системы счисления." << endl;
		fout << "Ошибка при вводе системы счисления." << endl;
		system("pause");
		return 0;
	}
	check(h1, p1);
	if (p2 > 16 || p2 == 7 || p2 == 9 || p2 == 11 || p2 == 13 || p2 == 14 || p2 == 15)
	{
		cout << "Ошибка при вводе системы счисления." << endl;
		fout << "Ошибка при вводе системы счисления." << endl;
		system("pause");
		return 0;
	}
	check(h2, p2);
	int sum = 0;
	sum = to_hex(h1, p1) + to_hex(h2, p2);
	cout << "Сумма в";
	fout << "Сумма в";
	switch (p1)
	{
	case 2:
		cout << " двоичном ";
		fout << " двоичном ";
		break;
	case 3:
		cout << " троичном ";
		fout << " троичном ";
		break;
	case 4:
		cout << " четверичном ";
		fout << " четверичном ";
		break;
	case 5:
		cout << " пятеричном ";
		fout << " пятеричном ";
		break;
	case 6:
		cout << " шестиричном ";
		fout << " шестиричном ";
		break;
	case 8:
		cout << " восьмиричном ";
		fout << " восьмиричном ";
		break;
	case 10:
		cout << " десятиричном ";
		fout << " десятиричном ";
		break;
	case 12:
		cout << " двенадцатиричном ";
		fout << " двенадцатиричном ";
		break;
	case 16:
		cout << " шестнадцатиричном ";
		fout << " шестнадцатиричном ";
		break;
	}
	cout << "виде: " << to_reverse(sum, p1) << endl;
	fout << "виде: " << to_reverse(sum, p1) << endl;
	if (p1 != p2)
	{
		cout << "Сумма в";
		fout << "Сумма в";
		switch (p2)
		{
		case 2:
			cout << " двоичном ";
			fout << " двоичном ";
			break;
		case 3:
			cout << " троичном ";
			fout << " троичном ";
			break;
		case 4:
			cout << " четверичном ";
			fout << " четверичном ";
			break;
		case 5:
			cout << " пятеричном ";
			fout << " пятеричном ";
			break;
		case 6:
			cout << " шестиричном ";
			fout << " шестиричном ";
			break;
		case 8:
			cout << " восьмиричном ";
			fout << " восьмиричном ";
			break;
		case 10:
			cout << " десятиричном ";
			fout << " десятиричном ";
			break;
		case 12:
			cout << " двенадцатиричном ";
			fout << " двенадцатиричном ";
			break;
		case 16:
			cout << " шестнадцатиричном ";
			fout << " шестнадцатиричном ";
			break;
		}
		cout << "виде: " << to_reverse(sum, p2) << endl;
		fout << "виде: " << to_reverse(sum, p2) << endl;
	}
	else
	{
		system("pause");
		return 0;
	}
	system("pause");
	return 0;
}