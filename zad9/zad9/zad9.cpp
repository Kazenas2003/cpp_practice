#include <cstdlib> // для функций rand() и srand()
#include <string> // для работы со строками
#include <fstream> // для работы с файлами
#include <iostream> // для ввода/вывода
using namespace std;

int main() {
    cout << "Enter the number of numbers: ";
    int nb, k = 0, i, j;//объявляем переменные
A://вводим количество элементов массива
    cin >> nb;
    if (nb < 1) {
        cout << "Wrong! Try again: ";
        cin.clear();
        while (cin.get() != '\n');
        goto A;
    }
    int *array = new int[nb];//создаем динамический массив
    srand(time(NULL));
    // Заполнение созданного массива случайными числами
    for (int i = 0; i < nb; i++) {
        array[i] = rand() % 200 - 100;
        cout << array[i] << "    ";//вывод массива в консоль
    }
    for (i = 0; i < nb; i += 2)//нахождение количества четных чисел
        if (array[i] % 2 == 0) //на нечетных местах
            k = k + 1;//k - число элементов
    
    string filename = "INPUT.txt";//создаем файл
    string str = "Our array: ";// создаем 1-ю строку с элементами массива
    for (int i = 0; i < nb; i++)
         str = str + to_string(array[i]) + " ";
    string str1 = "The number of even numbers in odd places: ";
    //создаем 2-ю строку с числом элементо, подходящих под условие
    str1 = str1 + to_string(k);
    ofstream fout(filename);//окрываем файл для ввода
    if (fout.is_open()) {//проверка открытия файла
        // Считывание в файл двух строк
        fout << str << endl;
        fout << str1;
        // Закрывание файла
        fout.close();
    }
    else {
        cout << "ERROR!!! File not opened!";
    }
    delete[] array;//удаляем память динамического массива
}
