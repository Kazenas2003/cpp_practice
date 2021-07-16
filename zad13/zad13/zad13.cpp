#include <iostream>
using namespace std;
int n, m, i, j;//объявляем глобальные переменные
int** summ(int** a, int** b, int n, int m) {//функция нахождения суммы двух матриц
    int** c = new int* [n];//создаем двумерный массив
    for (int i = 0; i < n; i++)
        c[i] = new int[m];
    for (i = 0; i < n; i++)//суммируем матрицы
        for (j = 0; j < m; j++)
            c[i][j] = a[i][j] + b[i][j];
    return c;//возвращает функция указатель
}

int main()
{
    int ukaz;
    int** l;//объявляем переменную и двумерный массив
    cout << "Enter the number of lines: "; 
    cin >> n;//вводим количество строк
    cout << "Enter the number of columns: ";
    cin >> m;//вводим количество столбцов
    int** a = new int* [n];//создаем двумерный массив
    for (int i = 0; i < n; i++)
        a[i] = new int[m];
    for (int i = 0; i < n; i++)//заполняем первую матрицу целыми числами
        for (int j = 0; j < m; j++) {
            cout << "Enter number on " << i + 1 << " line and " << j + 1 << " column: ";
        A://ввод чисел
            if (!(cin >> a[i][j]))
            {
                cout << "Wrong type! Try again: " << endl;
                cin.clear();
                while (cin.get() != '\n');
                goto A;
            };
        }
    int** b = new int* [n];//создаем двумерный массив
    for (int i = 0; i < n; i++)
        b[i] = new int[m];
    for (int i = 0; i < n; i++)//заполняем вторую матрицу целыми числами
        for (int j = 0; j < m; j++) {
            cout << "Enter number on " << i + 1 << " line and " << j + 1 << " column: ";
        C://ввод чисел
            if (!(cin >> b[i][j]))
            {
                cout << "Wrong type! Try again: " << endl;
                cin.clear();
                while (cin.get() != '\n');
                goto C;
            };
        }
    cout << "Your first matrix: " << endl;
    for (i = 0; i < n; i++)//вывод получившейся первой матрицы
    {
        for (j = 0; j < m; j++)
            cout << a[i][j] << "    ";
        cout << endl;
    }
    cout << "Your second matrix: " << endl;
    for (i = 0; i < n; i++)//вывод получившейся второй матрицы
    {
        for (j = 0; j < m; j++)
            cout << b[i][j] << "    ";
        cout << endl;
    }
    l = summ(a, b, n, m);//в l присваем результат работы функции
    cout << "Ukazatel: " << summ(a, b, n, m) << endl;//вывод указаталя
    cout << "Result" << endl;
    for (i = 0; i < n; i++)//вывод получившейся матрицы
    {
        for (j = 0; j < m; j++)
            cout << l[i][j] << "    ";
        cout << endl;
    }
    for (i = 0; i < n; i++){//освобождение памяти двумерных массивов
        delete[] a[i];
        delete[] b[i];
        delete[] l[i];
    }
    delete[] a;
    delete[] b;
    delete[] l;
}

