#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;
int main()
{
    int var, n, m, i, j;//объявляем переменные
    cout << "How will we fill the array?" << endl << "1. Random matrix." << endl << "2. Your matrix." << endl << "3. Default matrix." << endl << "Choose the variant: " << endl;
B:
    cin >> var;//вводим номер варианта заполнения матрицы
    if (var < 1 || var > 3)
    {
        cout << "Wrong! Choose 1 or 2, or 3: " << endl;
        cin.clear();
        while (cin.get() != '\n');
        goto B;
    }
    if (var == 1) {//при выборе варианта 1 будет происходить это
        cout << "You are given a random integer matrix: " << endl;
        srand(static_cast<unsigned int>(time(NULL)));
        n = rand() % 9 + 1;//генерируем случайное количество строк в дипазоне от 0 до 10
        m = rand() % 9 + 1;//генерируем случайное количество столбцов в дипазоне от 0 до 10
        int** mat = new int* [n];//создаем двумерный массив
        for (int i = 0; i < n; i++)
            mat[i] = new int[m];
        for (int i = 0; i < n; i++)//заполняем матрицу случайными числами
            for (int j = 0; j < m; j++)
                mat[i][j] = rand() % 20 - 10;
        for (i = 0; i < n; i++)//выводим получившуюся матрицу
        {
            for (j = 0; j < m; j++)
                cout << mat[i][j] << "    ";
            cout << endl;
        }
        int* kol = NULL;//создание динамического массива
        kol = new int[n];//в котором будут храниться значения повторений в каждой строке
        for (i = 0; i < n; i++)
            kol[i] = 0;

        int max, a;
        for (i = 0; i < n; i++)//находим максимальное количество повторений в строке
            for (j = 0; j < m; j++) {
                a = mat[i][j];
                max = 0;
                for (int k = 0; k < m; k++)
                    if (mat[i][k] == a)
                        max++;
                if (max > kol[i])
                    kol[i] = max;
            }
        for (i = 0; i < n - 1; i++)//сортируем строки по возрастанию количества повторяющихся элементов
            for (j = i + 1; j < n; j++)//методом "пузырька"
                if (kol[i] > kol[j]) {
                    mat[-1] = mat[i];
                    mat[i] = mat[j];
                    mat[j] = mat[-1];
                }

        cout << "Sorted matrix: " << endl;
        for (i = 0; i < n; i++)//выводим отсортированную матрицу
        {
            for (j = 0; j < m; j++)
                cout << mat[i][j] << "    ";
            cout << endl;
        }
        for (i = 0; i < n; i++)//освобождение памяти двумерного массива
        {
            delete[] mat[i];
        }
        delete[] mat;
    }
    if (var == 2) {//при выборе варианта 2 будет выполняться это
        cout << "Enter the number of lines: ";
        cin >> n;//вводим количество строк
        cout << "Enter the number of columns: ";
        cin >> m;//вводим количество столбцов
        int** mat = new int* [n];//создаем двумерный массив
        for (int i = 0; i < n; i++)
            mat[i] = new int[m];
        for (int i = 0; i < n; i++)//заполняем матрицу целыми числами
            for (int j = 0; j < m; j++) {
                cout << "Enter number on " << i + 1 << " line and " << j + 1 << " column: ";
            C://ввод чисел
                if (!(cin >> mat[i][j]))
                {
                    cout << "Wrong type! Try again: " << endl;
                    cin.clear();
                    while (cin.get() != '\n');
                    goto C;
                };
            }
        cout << "Your matrix: " << endl;
        for (i = 0; i < n; i++)//вывод получившейся матрицы
        {
            for (j = 0; j < m; j++)
                cout << mat[i][j] << "    ";
            cout << endl;
        }
        int* kol = NULL;//создание динамического массива
        kol = new int[n];//для подсчета максимального количества повторений в строке
        for (i = 0; i < n; i++)
            kol[i] = 0;

        int max, a;
        for (i = 0; i < n; i++)//расчет количества повторений в каждой строке
            for (j = 0; j < m; j++) {
                a = mat[i][j];
                max = 0;
                for (int k = 0; k < m; k++)
                    if (mat[i][k] == a)
                        max++;
                if (max > kol[i])
                    kol[i] = max;
            }
        for (i = 0; i < n - 1; i++)//сортировка матрицы
             for (j = i + 1; j < n ; j++)//методом "пузырька"
                 if (kol[i] > kol[j]) {
                     mat[-1] = mat[i];
                     mat[i] = mat[j];
                     mat[j] = mat[-1];
                 }

        cout << "Sorted" << endl;
        for (i = 0; i < n; i++)//вывод отсортированной матрицы
        {
            for (j = 0; j < m; j++)
                cout << mat[i][j] << "    ";
            cout << endl;
        }
        for (i = 0; i < n; i++){//освобождение памяти двумерного массива
            delete[] mat[i];
        }
        delete[] mat;
    }

    if (var == 3) {//при выборе варианта 3 будет выполняться это
        n = 2;
        m = 3;
        int** mat = new int* [2];//создаем двумерный массив 2х3 - матрица по умолчанию
        for (int i = 0; i <= 1; i++)
            mat[i] = new int[3];
        cout << "You selected the default matrix, used for example" << endl;
        mat[0][0] = 5; mat[0][1] = 3; mat[0][2] = 5;//значения матрицы по умолчанию
        mat[1][0] = 3; mat[1][1] = 2; mat[1][2] = 5;
        for (i = 0; i <= 1; i++)//вывод этой матрицы
        {
            for (j = 0; j <= 2; j++)
                cout << mat[i][j] << "    ";
            cout << endl;
        }

        int* kol = NULL;//создание динамического массива
        kol = new int[2];//для подсчета максимального количества повторений в строке
        for (i = 0; i < 2; i++)
            kol[i] = 0;

        int max, a;
        for (i = 0; i < 2; i++)//расчет количества повторений в каждой строке
            for (j = 0; j < 3; j++) {
                a = mat[i][j];
                max = 0;
                for (int k = 0; k < 3; k++)
                    if (mat[i][k] == a)
                        max++;
                if (max > kol[i])
                    kol[i] = max;
            }
        for (i = 0; i < 1; i++)//отсортировка матрицы
            for (j = i + 1; j < 2; j++)//методом "пузырька"
                if (kol[i] > kol[j]) {
                    mat[-1] = mat[i];
                    mat[i] = mat[j];
                    mat[j] = mat[-1];
                }

        cout << "Sorted" << endl;
        for (i = 0; i < 2; i++)//вывод отсортированной матрицы по умолчанию
        {
            for (j = 0; j < 3; j++)
                cout << mat[i][j] << "    ";
            cout << endl;
        }
        for (i = 0; i < n; i++)//освобождение памяти двумерного массива
        {
            delete[] mat[i];

        }
        delete[] mat;
    } 
}
 