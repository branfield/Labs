#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <fstream>
#include <cstring> 
#include <cmath>
#include <math.h>
using namespace std;

void checkForCoord(double x1, double x2, double x3, double y1, double y2, double y3)
{
	if (x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x3 == x1 && y3 == y3)
	{
		cout << "Ошибка! Точки совпадают." << endl;
		system("pause");
		exit(0);
	}
}

bool checkForTriangle(double a, double b, double c)
{
	if (round(pow(c, 2)) == round((pow(a, 2) + pow(b, 2))))
	{
		cout << "Треугольник является прямоугольным. " << endl;
		return 1;
	}
	else if (a == b && b == c)
	{
		cout << "Треугольник является равносторонним. " << endl ;
		return 0;
	}
	else if (a == b)
	{
		cout << "Треугольник является равнобедренным. " << endl;
		return 0;
	}
	else
	{
		cout << "Треугольник является разносторонним. " << endl;
		return 0;
	}
}

int main()
{
	setlocale(0, "");
	double x1, x2, x3, y1, y2, y3;
	char* name = new char[10];
	cout << "Введите название файла, который требуется открыть: ";
	cin >> name;
	ofstream fout("output.txt");
	ifstream fin;
	double mas[10];
	fin.open(name);
	if (!fin)
		cout << "Файл не найден!" << endl;
	else
	{
		int i = 0;
		while (fin)
		{
			fin >> mas[i];
			if (i > 6)
			{
				cout << "Ошибка в файле данных! Введено слишком много координат." << endl;
				break;
				system("pause");
				return 0;
			}
			i++;
		}
		x1 = mas[0];
		y1 = mas[1];
		x2 = mas[2];
		y2 = mas[3];
		x3 = mas[4];
		y3 = mas[5];
	}
	cout << "Введенные координаты: " << endl << "A: (" << x1 << ", " << y1 << ")" << endl;
	cout << "B: (" << x2 << ", " << y2 << ")" << endl;
	cout << "C: (" << x3 << ", " << y3 << ")" << endl;
	checkForCoord(x1, x2, x3, y1, y2, y3);
	double S = 0;
	double a = 0, b = 0, c = 0;
	double a1 = 0, b1 = 0, c1 = 0;
	a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
	c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	if (a > b && a > c) { c1 = a; a1 = c; b1 = b; }
	else if (b > a && b > c) { c1 = b; b1 = c; a1 = a; }
	else { c1 = c; b1 = b; a1 = a; }
	double Lab = 0, Lac = 0, Lbc = 0;
	if (checkForTriangle(a1, b1, c1) == 1)
	{
		S = 0.5 * a1 * b1;
		cout << "Площадь треугольника равна: " << S << endl;
		Lab = sqrt(2) * (a1*b1 / (a1 + b1));
		cout << "Биссектриса ab равна: " << Lab << endl;
		Lac = a1 * sqrt(2 * c1 / (a1 + c1));
		cout << "Биссектриса ac равна: " << Lac << endl;
		Lbc = b * sqrt(2 * c1 / (b1 + c1));
		cout << "Биссектриса bc равна: " << Lbc << endl;
	}
	system("pause");
	return 0;
}