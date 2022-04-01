#include "stdio.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "string"
#include "conio.h"
#include "iostream"
using std::cout;
using std::cin;
using std::endl;

void inputArray(char* str1, char* str2) {                    // объявление строк и переменных
    cout << "введите строку1: ";
    cin >> str1;
    cout << "введите строку2: ";
    cin >> str2;
}

int how_many_simvol_in_str(char simb, char* str)
{
    int result = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] == simb)
            result++;
    return result;
}


bool checkArray(char* str1, char* str2) {    // первая проверка
    if (strlen(str1) != strlen(str2))
        return false;
    for (int i = 0; str1[i]; i++)
        if (how_many_simvol_in_str(str1[i], str1) != how_many_simvol_in_str(str1[i], str2))
            return false;
    return true;
}


bool checkArray2(char* str1, char* str2) {       // вторая проверка
    if (strlen(str1) != strlen(str2))
        return false;

    int chars1[256], chars2[256];
    memset(chars1, 0, sizeof(chars1));
    memset(chars2, 0, sizeof(chars2));

    for (int i = 0; str1[i]; i++) {
        chars1[str1[i]]++;
        chars2[str2[i]]++;
    }

    for (int i = 0; i < 256; i++)
        if (chars1[i] != chars2[i])
            return false;
    return true;
}


int main() {
    setlocale(LC_ALL, "Russian");
    char str1[1000], str2[1000];
    int l, x;
    inputArray((char*)&str1, (char*)&str2);

    if (checkArray((char*)&str1, (char*)&str2) && checkArray2((char*)&str1, (char*)&str2)) {
        cout << "Можно" << endl;
    }
    else {
        cout << "Нельзя" << endl;
    }

    return 0;
}
