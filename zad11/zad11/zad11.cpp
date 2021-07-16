#include <iostream>
using namespace std;
double a, b, *c, eps, X, l;
double fun(double x);
double fun(double x)//объявляем уравнение
{
	return 2 * x * x * x - x * x + 1.9908 * x + 0.0184;
}
int metod(double a, double b, double *c, double eps)
{
	do//цикл соответсвует алгоритму нахождения решения
	{
		*c = (a + b) / 2;
		if (fun(*c) * fun(a) < 0) 
			b = *c;
		else a = *c;	
	} 	
	while (abs(a - b) >= 2 * eps);
	//при невыполнении условия получаем, что a - корень

	return a;
}
int main()
{
	eps = 0.000001;//значение погрешности
    cout << "Enter segment boundaries."<< endl <<  "Enter left side: ";
	//просим на вввод границы поиска корня уравнения
A://ввод левой границы
	if (!(cin >> a))
	{
		cout << "Wrong type! Try again: " << endl;
		cin.clear();
		while (cin.get() != '\n');
		goto A;
	}
    cout << "Enter right side:";
B://ввод правой границы
	if (!(cin >> b))
	{
		cout << "Wrong type! Try again: " << endl;
		cin.clear();
		while (cin.get() != '\n');
		goto B;
	}
    cout << endl;
	
	l = metod(a, b, &X, eps);//находим значение корня и выводим его
	cout << "The resulting root " << X;
}
