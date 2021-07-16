#include <iostream>
#include <math.h>
using namespace std;
double a, b, h, I, s = 0;//объявляем переменные и инициализируем сумму
int n, i;
double fun(double x)//объявляем подынтегральную функцию
{
	return (0.1 + sqrt(x)) / (1 + log(x) * log(x));
}
double pryamoug(double a, double b)//объявляем функцию метода левых прямоугольников
{
	h = 0.01;//диаметр разбиения
	n = (b - a) / h;//количество участков разбиения
	for (i = 0; i <= n - 1; i++)
	{
		s = s + fun(a + i*h);//находим сумму вертикальных рёбер
	}
	I = h * s;//находим площадь под графиком функции
	cout << I << endl;//выводим результат
	return 0;
}
double trapec(double a, double b)//объявляем функцию метода трапеций
{
	h = 0.01;//диаметр разбиения
	n = (b - a) / h ;//количество участков разбиения
	s = fun(a) + fun(b);
	for (int i = 1; i < n; i++) { 
		s += 2 * (fun(a + h * i));
	}
	I = (b - a) / (2 * n) * s;//находим интеграл по данному алгоритму
	cout << I;//выводим результат
	return 0;
}
double simpson(double a, double b)//объявляем функцию метода Симпсона
{
	double sum1 = 0, sum2 = 0, sum = 0;
	h = 0.01;//диаметр разбиения
	n = (b - a) / (2 * h);//количество участков разбиения
	for (i = 1; i <= 2 * n - 1; i += 2)
	{
		sum2 = sum2 + fun(a + h * i);
		sum1 = sum1 + fun(a + h * (i + 1));
	}
	sum = fun(a) + 4 * sum2 + 2 * sum1 - fun(b); 
	I = (h / 3) * sum;
	cout << I << endl;
	//согласно алгоритму Симпсона находим интеграл и выводим его
	return 0;
}
int main()
{
	int var;//объявление переменных
	double c, d = 0, e = 0;
	cout << "Enter the left limit of integration: ";
A://ввод нижней границы интегрирования
	if (!(cin >> a))
	{
		cout << "Wrong! Try again: " << endl;
		cin.clear();
		while (cin.get() != '\n');
		goto A;
	}
	cout << "Enter the right limit of integration: ";
B://ввод верхней границы интегрирования
	if (!(cin >> b))
	{
		cout << "Wrong! Try again: " << endl;
		cin.clear();
		while (cin.get() != '\n');
		goto B;
	}
	cout << "Choose the integration method:" << endl << "1. Left rectangle method" << endl << "2. Trapezoidal method" << endl << "3. Simpson's method" << endl << "4. All methods";
	cout << endl << "Enter 1 or 2, or 3, or 4: ";
С://выбор метода решения
	cin >> var;
	if (var < 1 || var > 4) {
		cout << "Wrong! Try again: " << endl;
		cin.clear();
		while (cin.get() != '\n');
		goto С;
	}
	if (var == 1) {//при выборе 1-го метода выполняется это
		cout << "The integral by the method of left rectangles is ";
		c = pryamoug(a, b);
	}
	if (var == 2) {//при выборе 2-го метода выполняется это
		cout << "The integral by the Trapezoidal method ";
		c = trapec(a, b);
	}
	if (var == 3){//при выборе 3-го метода выполняется это
		cout << "The integral by the Simpson's method ";
		c = simpson(a, b);
	}
	if (var == 4) {//при выборе 4-го метода выполняется это
		cout << "The integral by the method of left rectangles: ";
		c = pryamoug(a, b);
		cout << "             by the Trapezoidal method: ";
		d = trapec(a, b);
		cout << endl << "             by the Simpson's method: ";
		e = simpson(a, b);
	}
}

