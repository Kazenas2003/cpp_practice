#include <fstream> // для работы с файлами
#include <iostream> // для ввода/вывода

// Функция изменения размера выделенной памяти для символьного массива
char* arr_size_upd(char* arr, int len, int new_len) {
    // Выделение нового размера массива
    char* new_arr = new char[new_len];
    // Копирование старого массива в новую память
    for (size_t i = 0; i < len; i++)
    {
        new_arr[i] = arr[i];
    }
    // Освобождение памяти старого массива
    // delete[] arr;
    // Возврат указателя на новый массив
    return new_arr;
}

// Функция ввода
char* input() {
    char tmp = '\0';
    char* str;
    int index = 0, len = 2;

    // Созание массива для ввода одного символа
    str = new char[len];

    // Ввод одного символа
    std::cin.get(tmp);
    // Посимвольное чтение с проверкой нажатия энтера
    while (tmp != '\n') {
        // Проверка доступного места в памяти для записи в массив
        if (index + 1 == len) {
            // Если места нет, то выделить новую память
            str = arr_size_upd(str, len, 2 * len);
            len = len * 2;
        }
        // Запись в массив
        str[index] = tmp;
        // Увеличение индекса текущего элемента в массиве
        index++;
        // Посимвольное чтение
        std::cin.get(tmp);
    }
    // Запись в последний элемент массива нуль-терминатора
    str[index] = '\0';
    // Возврат указателя на начало массива символов (начало строки)
    return str;
}

// Функция вычисления длины массива символов
int	ft_strlen(char* str)
{
    int len = 0;

    while (str[len] != '\0')
        len = len + 1;

    return (len);
}

// Функция проверки символа на верхний регистр
bool is_uppercase(char c) {
    if (c >= 65 && c <= 90)
        return true;
    else return false;
}

// Функция проверки символа на нижний регистр
bool is_lowercase(char c) {
    if (c >= 97 && c <= 122)
        return true;
    else return false;
}

// Функция проверки корректности ввода
bool is_valid(char* str, int* num_words) {
    int num_ch_in_word = 0, i = 1, len;

    // Вычисление длины массива символов
    len = ft_strlen(str);

    // Проверка того, что строка начинается со слова и заканчивается точкой
    if (is_uppercase(str[0]) && str[len] == '.')
        return false;

    // Посимволный проход строки для проверки дополнительных условий
    while (str[i] != '.') {
        // Является ли символ строчной буквой
        if (is_lowercase(str[i])) {
            // Если да, то:
            // Увеличение количество подряд идущих букв на 1
            num_ch_in_word++;
            // Проверка того, что больше 5 подряд идущих букв нет
            if (num_ch_in_word > 5)
                return false;
        }
        // Является ли символ пробелом
        else if (str[i] == ' ') {
            // Если да, то:
            // Обнуление количества подряд идущих букв
            num_ch_in_word = 0;
            // Проверка того, что предыдущий символ не пробел
            if (str[i - 1] != ' ')
                // Если да, то увеличиваем количество слов на 1
                (*num_words)++;
            // Если нет, то ничего не делаем
            // Идея в том, что если больше одного прбела между словами, то считать это как один разделитель
            // Проврка того, что количество слов не больше 5
            if (*num_words > 4)
                return false;
        }
        // Если символ не буква и не пробел, то ввод некорректный
        else return false;
        i++;
    }
    // Количество разделителей между словами всегда на один меньше, чем слов
    (*num_words)++;
    // Если все условия корректны, то возвращается true
    return true;
}

// Функция преобразования буквы в порядковый номер по алфавиту
int8_t char2num(char c) {
    if (c >= 97 && c <= 122)
        return (c - 96);
    else
        return (c - 64);
}

// Функция преобразования строки в двумерный массив целых чисел
// Каждое число - порядковый номер буквы в алфавите
int8_t** str2intarr(char* str, int num_words) {
    // Выделение памяти под буффер-строку
    char* strtmp = new char[6];
    // Инициализация переменных счетчика
    // n - счетчик количества слов
    // i, j, k - различные счетчики
    int         i = 0, j = 0, n = 0, k = 0;
    // Выделение памяти для определенного количества слов
    int8_t** intarr = new int8_t * [num_words];

    // Выделение памяти для каждого слова
    // Выделяется не по количеству символов в слове, а максимально возможное
    // По памяти не принципиально, так как 1 байт на символ выделяется (макс. 30 байт)
    // Можно выделить интом, но тогда память сразу возрастет до 6*4*5 = 120 байт (макс.)
    for (k = 0; k < num_words; k++)
        intarr[k] = new int8_t[6];

    // Цикл перевода строки в двумерный массив целых чисел
    while (str[i] != '\0') {
        // Проверка условия, что текущий символ - буква
        if (str[i] != ' ' && str[i] != '.') {
            // Если да, то:
            // Копируем символ в буффер-строку
            strtmp[j] = str[i];
            j++;
        }
        // Если нет, то:
        // Проверка условия, что текущий символ - первый после слова пробел или точка 
        else if (str[i] == ' ' && str[i - 1] != ' ' || str[i] == '.') {
            // Если да, то:
            // Закрываем буффер строку признаком конца строки
            strtmp[j] = '\0';
            j = 0;
            // Каждый символ буфер строки с помощью отдельной функции переводим в порядковый номер в алфавите
            while (strtmp[j] != '\0') {
                intarr[n][j] = char2num(strtmp[j]);
                j++;
            }
            // Закрываем массив числом 0 (в данном случае аналог '\0' в строке)
            intarr[n][j] = 0;
            // Увеличиваем счетчик текущего слова
            n++;
            j = 0;
        }
        // Увеличиваем счетчик прохода по исходной строке
        i++;
    }
    // Освобождаем память буфер-строки
    delete[] strtmp;
    // Возвращаем двумерный массив чисел
    return intarr;
}

bool prov1(int8_t** intarr, int num_words, int i) {
    if ((int)intarr[i] != (int)intarr[num_words])
        return true;
    else return false;
    
}

bool alf(int8_t** intarr, int num_words) {
    int j, a;
    for (int i = 1; i < num_words; i++) {
        j = 0;
        a = 0;
        while (intarr[i][j] != 0) {
            j++;
            a = intarr[i][j - 1];
            if (intarr[i][j - 1] >= intarr[i][j])
                return true;
            else return false;
        }
        if (a == intarr[i][0])
            return true;
        else return false;
    }
    return true;

}

int main() {
    char* instr;
    int8_t** intarr;
    int i = 0, num_words = 0, j = 0;

    instr = input();

    if (is_valid(instr, &num_words))
        std::cout << std::endl << "INPUT IS TRUE: " << num_words << std::endl;
    else
        std::cout << std::endl << "INPUT IS WRONG: " << num_words << std::endl;

    intarr = str2intarr(instr, num_words);
    
    for (int i = 0; i < num_words - 1; i++) 
        if (prov1(intarr, num_words, i)) {
            j = 0;
            while (intarr[i][j] != 0) {
                std::cout << "[" << (int)intarr[i][j] << "]";
                j++;
            }
            std::cout << std::endl;
        }
}