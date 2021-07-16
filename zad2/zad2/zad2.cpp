

#include <iostream>
using namespace std;
int main()
{
    float max, number, b, c;//объявление переменных
    int i, a;
    max = 0;//инициализация переменной, в которой будет храниться максимум массива
    cout << "First enter the amount of numbers, then enter the positive numbers one at a time." << endl;
    cout << "Number of numbers: ";
    A://ввод количества чисел в массиве
        cin >> a;
        if (a < 1)
        {
            cout << "Wrong! Try again: " << endl;
            cin.clear();
            while (cin.get() != '\n');
            goto A;
        }

    for (i = 1; i <= a; i++) {//с помощью цикла заполняем массив
        cout << "Enter the sequence element under the number " << i  << ": " << endl;
    B:
        cin >> b;//ввод чисел
        if (!(b >= 0))
        {
            cout << "Wrong! Try again: " << endl;
            cin.clear();
            while (cin.get() != '\n');
            goto B;
        }
        if (b > max) {//находим максимальное число в массиве
            max = b;
            number = i;
        }
        if (max == 0)
            number = 1;//переменная в которой хранится номер максимума в массиве
    }
    cout << "Maximum: " << max << endl << "Number of maximum: " << number;
}//вывод максимального значения массива и его номера
    

