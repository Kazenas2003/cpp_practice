

#include <iostream>
using namespace std;
int main()
{
    double a, b, mod, faz;//объявляем переменные
    cout << "Real part a: ";
A:
    if (!(cin >> a)) //проверка ввода, чтобы а было числом
    {
        cout << "Wrong type" << endl;
        cout << "Try again: ";
        cin.clear();//очистка ввода
        while (cin.get() != '\n');//переходит к следующей строке 
        goto A;//возвращает на начальный этап
    }
    cout << "Imaginary part b: ";
B://ввод мнимой части
    if (!(cin >> b))
    {
        cout << "Wrong type" << endl;
        cout << "Try again ";
        cin.clear();
        while (cin.get() != '\n');
        goto B;
    }
    
    faz = atan(b / a);// вычисление фазы комплексного числа в радианах
    cout << "Modul of complex number: " << sqrt(a*a + b*b) << endl << "Phase of complex number: " << faz;// вывод модуля и фазы числа
}

