// 4 Вариант
#include <iostream>
#include <fstream>

using namespace std;


const int N = 14;
int arr1[N];
int arr2[N];



int main()
{
    setlocale(LC_ALL, "ru");

    

    ifstream fin1("lb1.txt");
    if (!fin1)
        cout << "Error!" << endl;
    else
    {
        int i = 0;
        while (i < N && fin1 >> arr1[i])
            ++i;
    }

    fin1.close();

    ifstream fin2("lb2.txt");
    if (!fin2)
        cout << "Error!" << endl;
    else
    {
        int i = 0;
        while (i < N && fin2 >> arr2[i])
            ++i;
    }

    fin2.close();
    
   

    int minValue = 1000;
    int result = 1000;
    int a = 0;
    


    int lengthArr1 = sizeof(arr1) / sizeof(arr1[0]);
    int lengthArr2 = sizeof(arr2) / sizeof(arr2[0]);


    for (int i = 0; i < lengthArr1; i++) {

        if (minValue > arr1[i]) {
            minValue = arr1[i];
            a = 1;

            for (int j = 0; j < lengthArr2; j++) {
                if (arr1[i] == arr2[j]) {
                    a = 0;
                    break;
                }
                         
            }
            if (a == 1 && result > arr1[i]) {
                result = arr1[i];
            }

        }
    };

    cout << "Результат : " << result;

    



}


