

#include <iostream>
using namespace std;

bool solution(string str1, string str2) {
    bool res = false;
    int n = (int)str2.size();
    bool* infostr2 = new bool[n];
    for (int i = 0; i < n; i++) {
        infostr2[i] = false;
    }

    for (int i = 0; i < str1.size(); i++) {
        for (int j = 0; j < n; j++) {

            if (infostr2[j]) {
                continue;
            }
            if (str1[i] == str2[j]) {
                infostr2[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < str2.size(); i++) {
        if (infostr2[i]) {
            res = true;
        }
        else {
            res = false;
            break;
        }
    }
    return res;
}


void main()
{
    setlocale(LC_ALL, "Rus");
    string str1, str2;
    printf("Введите первое слово: ");
    cin >> str1;
    printf("Введите второе слово: ");
    cin >> str2;
    if (solution(str1, str2)) {
        printf("Да, можно");
    }
    else {
        printf("Нет, нельзя");
    }
}