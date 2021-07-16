#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
#define lenght 50//макроопределение размера массива
int kol = 0, i, ind, num;//объявляем глобальные переменные
float minn;

int kol0(float* array) {//функция нахождения кольчества элементов равных 0
    for (i = 1; i <= num; i++)
        if (array[i] == 0)
            kol = kol + 1;//счетчик количества "0"
    return kol;//возвращаем значение переменной kol (количества "0")
}

float summ(float* array) {//функция нахождения суммы элементов после минимального числа
    float sum = 0;
    minn = array[1];
    for (i = 1; i <= num; i++) {//нахождение минимального элемента массива и его индекса
        if (array[i] <= minn)
        //используем <=, чтобы выбрать последний из повторяющихся минимальных элементов
        {
            minn = array[i];
            ind = i;
        }
    }

    for (i = ind + 1; i <= num; i++)
        sum = array[i] + sum;//нахождение суммы элементов после минимального числа 

    return sum;//возвращаем значение переменной sum (сумма элементов после минимального числа)
}

void na(float* array) {//функция сортировки по возрастанию модулей
    for (int j = 1; j < num; j++)//сортировка по возрастанию модулей чисел массива
        for (i = 1; i <= num - 1; i++)
            if (abs(array[i]) > abs(array[i + 1]))
                swap(array[i], array[i + 1]);//перемена местами двух элементов     
}
int main()
{
    int var;
    float array[lenght];//объявляем массив и переменную
    srand(static_cast<unsigned int>(time(NULL)));//обьявление быза для случайных чисел
    cout << "Number of array elements must be <= 50. Enter the number: " << endl;
A:
    cin >> num;//ввод количества элементов
    if (num < 1 || num > 50)//из-за макроопределения, введенное число должно быть от 1 до 50
    {
        cout << "Wrong! Try again: " << endl;
        cin.clear();
        while (cin.get() != '\n');
        goto A;
    }
    cout << "How will we fill the array?" << endl << "1. Random numbers" << endl << "2. Your numbers" << endl << "Choose the variant: " << endl;
    // выбор способа заполнения массива
B:
    cin >> var;//ввод варианта заполнения
    if (var < 1 || var > 2)//имеем возможность ввести без ошибки только 1 или 2
    {
        cout << "Wrong! Choose 1 or 2: " << endl;
        cin.clear();
        while (cin.get() != '\n');
        goto B;
    }
    if (var == 1) {//первый вариант
        for (i = 1; i <= num; i++) // заполнение массива случайными числами
            array[i] = rand()% 200 - 100;
    }
    if (var == 2) {
        for (i = 1; i <= num; i++)//ввод элементов массива вручную
        {
            cout << "Enter the array element under the number " << i << ": " << endl;
        C:
            if (!(cin >> array[i]))//ввод чисел
            {
                cout << "Wrong type! Try again: " ;
                cin.clear();
                while (cin.get() != '\n');
                goto C;
            }          
        }
    }             
    cout << "Full array: " << endl;//вывод получившегося массива
    for (i = 1; i <= num; i++)
        cout << array[i] << " ";
    
    cout << endl << "Number of digits '0': " << kol0(array) << endl;
    //вывод количества элементов равных 0
    cout << "Sum of elements after minimum: " << summ(array) << endl;
    //вывод суммы чисел после минимального
    na(array);
    //сортировка массива функцией
    cout << "New array: " << endl;
    for (i = 1; i <= num; i++)//вывод отсортированного массива
        cout << array[i] << " ";
}
