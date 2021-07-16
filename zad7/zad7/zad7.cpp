#include <fstream> // для работы с файлами
#include <iostream>
using namespace std;
int main()//метод с привязкой к количеству элементов
{
    int i, n, b = 0;
    unsigned int a;
    string filename = "INPUT.dat";//создаем файл
    string filename1 = "OUTPUT.dat";//создаем файл
    cout << "Enter the number of numbers: ";
    cin >> n;//вводим количество элементов
    int* array = new int[n];
    ofstream fout(filename);//окрываем файл для ввода
    for (i = 0; i < n; i++) {
        //ввод чисел
        if (!(cin >> a))//при превышении  границы  диапазона  записываем  вместо элемента 0. 
        {
            a = b;
        }
        array[i] = a;//добавляем в массив
        fout << a << "  ";//вводим в файл
    }
    fout.close();//закрываем файл
    ofstream fout1(filename1);//окрываем файл для ввода результатов
    for (i = 0; i < n; i++) {
        array[i] = array[i] * array[i];
        fout1 << array[i] << "  ";//записываем результаты в другой файл
    }
    fout1.close();//закрываем файл с результатами
}


