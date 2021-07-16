#include <iostream>
#include <malloc.h>
using namespace std;
int siz, i;
float sum = 0, sum1 = 0;

float sumarr(double* a) {
    for (i = 0; i < siz; i += 2)//нахождение суммы элементов с нечетными номерами
        sum1 += a[i];
    return sum1;//возвращение значение переменной sum1
}
float sumar(double* a) {//функция вычисления суммы чисел между первым и последним отрицательными элементами
    int first = 0, last = 0;
    for (i = 0; i < siz; i++)//нахождение первого отрицательного элемента
        if (a[i] < 0) {
            first = i;
            break;
        }
    for (i = siz; i >=0; i--)//нахождение последнего отрицательного элемента
        if (a[i] < 0) {
            last = i;
            break;
        }
    for (i = first + 1; i < last-1; i++)//вычисление суммы чисел между первым и последним отрицательными элементами
        sum = sum + a[i];
    return sum;//возвращение значение переменной sum
}
void na(double* a) {//функция сжатия массива, удаляя из него все элементы, модуль которых не превышает 1
    int k = 0;
    for (i = 0; i < siz; i++)//считаем количество элементов с модулем меньше 1
        if (abs(a[i]) <= 1)
            k = k + 1;
    double* b = new double[siz - k];//создаем новый динамический массив
    //сортируем по убыванию первый массив
    for (i = 0; i < siz - 1; i++)
        if (abs(a[i]) < abs(a[i + 1])) {
            int l = a[i+1];
            a[i+1] = a[i];
            a[i] = l;
        }
            /*swap(a[i], a[i + 1]);*/
    for (i = 0; i < siz - k; i++)
        b[i] = a[i];
    //записываем в новый массив все элементы кроме k элементов, у которых модуль меньше 1
    cout << "The elements of the new array: ";
    for (i = 0; i < siz - k; i++)//вывод нового массива
        cout << " " << b[i];
    delete[] b;//освобождение памяти

}
int main(void)
{
    int k;
    cout << "Size of array = ";
A:
    cin >> siz;//ввод количества элементов массива
    if (siz < 1)
    {
        cout << "Wrong! Try again: " << endl;
        cin.clear();
        while (cin.get() != '\n');
        goto A;
    }


    double* a = NULL;//создание динамического массива
    a = new double[siz];

    for (i = 0; i < siz; i++)//ввод элементов массива
    {
        cout << "a[" << i + 1 << "] = ";
        cin >> a[i];
    }
    k = 0;
    for (i = 0; i < siz; i++)//считаем количество элементов с модулем меньше 1
        if (abs(a[i]) <= 1)
            k = k + 1;
    cout << "Sum of odd elements " << sumarr(a) << endl;
    //вывод суммы элементов с нечетными номерами
    cout << "The sum between the first and the last negative: " << sumar(a) << endl;
    //вывод суммы чисел между перым и последним отрицательными элементами
    na(a);
    //вывод нового массива без чисел с модулем меньше 1
    delete[] a;//освобождение памяти        
    return 0;           
}
