#include <iostream>
using namespace std;
double square(double r1, double r2)
{
    double sq;
    sq = acos(-1.0) * (r1 * r1 - r2 * r2);//формула площади кольца
    return sq;//функция возвращает значение sq
}
int main()
{
    double r1, r2, S;//объявление переменных
    cout << "Both radius must be >0! Be careful!" << endl;
    cout << "Outer radius: ";
A:
    cin >> r1;//ввод внешного радиуса
    if (r1 <= 0)
    {
        cout << "Wrong! Try again: " << endl;
        cin.clear();
        while (cin.get() != '\n');
        goto A;
    }
    cout << "Inner radius must be smaller than outer radius!" << endl;
    cout << "Inner radius: ";
B:
    cin >> r2;//ввод внутренного радиуса
    if (r2 >= r1 || r2 <= 0)
    {
        cout << "Wrong! Try again: " << endl;
        cin.clear();
        while (cin.get() != '\n');
        goto B;
    }
    cout << "Ring area with outer radius " << r1 << " and inner radius " << r2 << " : " << square(r1, r2);
}//вывод радиусов и площади кольца
