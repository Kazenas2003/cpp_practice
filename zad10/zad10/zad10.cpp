#include <iostream> 
#include <string>

using namespace std;

double fun(double x, double y)//объявляем дифференциальное уравнение
{
    return (log(x) - y) / x;
}
int main()
{
    double x0, y0, xn;
    int i, j, n;//объявление переменных
    cout << "Enter x0=";
A://ввод х0
    if (!(cin >> x0))
    {
        cout << "Wrong type! Try again: " << endl;
        cin.clear();
        while (cin.get() != '\n');
        goto A;
    };
    cout << endl;
    cout << "Enter y0=";
B://ввод у0
    if (!(cin >> y0))
    {
        cout << "Wrong type! Try again: " << endl;
        cin.clear();
        while (cin.get() != '\n');
        goto B;
    };
    cout << endl;
    cout << "Enter xn=";
C://вводим правый конец отрезка 
    if (!(cin >> xn))
    {
        cout << "Wrong type! Try again: " << endl;
        cin.clear();
        while (cin.get() != '\n');
        goto C;
    };
    cout << endl;
    cout << "Enter n=";
D://вводим количество отрезков разбиения
    cin >> n;
    if (n < 1)
    {
        cout << "Wrong! Try again: " << endl;
        cin.clear();
        while (cin.get() != '\n');
        goto D;
    };
    cout << endl;
    double* X = new double[n + 1];//массив значений х
    double* Y = new double[n + 1];//массив значений у
    double h = (xn - x0) / n;//находим шаг разбиения

    for (i = 0; i <= n; i++)//заполняем массив значений х и выводим их
    {
        X[i] = x0 + i * h;
        cout << "i = " << i << "    " << "x = " << X[i] << endl;
    }
    cout << endl;
    Y[0] = y0;
    cout << "i = " << 0 << "    " << "y = " << Y[0] << endl;
    for (i = 1; i <= n; i++)//заполняем массив значений У по методу Эйлера и выводим их
    {
        Y[i] = Y[i - 1] + h * fun(X[i - 1], Y[i - 1]);
        cout << "i = " << i << "    " << "y = " << Y[i] << "    " << log(X[i]) - 1 - 1 / X[i] << endl;
    }
    delete[] X;//удаляем память для Х и У
    delete[] Y;
}

