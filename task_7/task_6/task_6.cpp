

#include <iostream>

int** createAndFillArray(int h, int w) {
    int** array = new int* [h];
    for (int i = 0; i < h; i++)
    {
        array[i] = new int[w];
        for (int j = 0; j < w; j++) {
            printf("Введите array[%d][%d] : ", i, j);
            scanf_s("%d", &array[i][j]);
        }
    }
    return array;
}
void printArray(int** arr, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j)
            std::cout << arr[i][j] << ' ';
        std::cout << std::endl;
    }
}
int** staticArray() {
    int arrayS[5][7] = {
        {1, 0, 2, 2, 3, 3, 7},
        {1, 5, 5, 0, 3, 3, 7},
        {0, 5, 0, 4, 8, 0, 7},
        {9, 9, 6, 0, 7, 8, 0},
        {9, 2, 4, 8, 8, 0, 0},
    };
    int** array = new int* [5];
    for (int i = 0; i < 5; i++)
    {
        array[i] = new int[7];
        for (int j = 0; j < 7; j++) {
            array[i][j] = arrayS[i][j];
        }
    }
    return array;
}

bool sosediRavni(int** arr, int i, int j, bool n1, bool n2, bool n3, bool n4, bool n5, bool n6, bool n7, bool n8) {
    int count = 0;
    if (n1) { count += (arr[i][j] == arr[i - 1][j - 1]) ? 1 : 0; }
    if (n2) { count += (arr[i][j] == arr[i - 1][j]) ? 1 : 0; }
    if (n3) { count += (arr[i][j] == arr[i - 1][j + 1]) ? 1 : 0; }
    if (n4) { count += (arr[i][j] == arr[i][j + 1]) ? 1 : 0; }
    if (n5) { count += (arr[i][j] == arr[i + 1][j + 1]) ? 1 : 0; }
    if (n6) { count += (arr[i][j] == arr[i + 1][j]) ? 1 : 0; }
    if (n7) { count += (arr[i][j] == arr[i + 1][j - 1]) ? 1 : 0; }
    if (n8) { count += (arr[i][j] == arr[i][j - 1]) ? 1 : 0; }
    return count >= 2;
}

bool supportingSolion(int** arr, int rows, int columns, int i, int j) {
    if (i == 0 && j == 0) {
        if (sosediRavni(arr, i, j, false, false, false, true, true, true, false, false)) return true;

    }
    else if (i == 0 && j == columns - 1) {
        if (sosediRavni(arr, i, j, false, false, false, false, false, true, true, true)) return true;

    }
    else if (i == rows - 1 && j == 0) {
        if (sosediRavni(arr, i, j, false, true, true, true, false, false, false, false)) return true;

    }
    else if (i == rows - 1 && j == columns - 1) {
        if (sosediRavni(arr, i, j, true, true, false, false, false, false, false, true)) return true;

    }
    else if (i == 0) {
        if (sosediRavni(arr, i, j, false, false, false, true, true, true, true, true)) return true;

    }
    else if (j == 0) {
        if (sosediRavni(arr, i, j, false, true, true, true, true, true, false, false)) return true;

    }
    else if (i == rows - 1) {
        if (sosediRavni(arr, i, j, true, true, true, true, false, false, false, true)) return true;

    }
    else if (j == columns - 1) {
        if (sosediRavni(arr, i, j, true, true, false, false, false, true, true, true)) return true;

    }
    else {
        if (sosediRavni(arr, i, j, true, true, true, true, true, true, true, true)) return true;
    }
    return false;
}

int** solition(int** arr, int rows, int columns) {
    int** array = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            if (supportingSolion(arr, rows, columns, i, j)) { array[i][j] = 1; }
            else { array[i][j] = 0; }
        }
    }
    return array;
}

void run(int** arr, int rows, int columns) {
    printf("\nВходной массив:\n\n");
    printArray(arr, rows, columns);
    printf("\n");
    arr = solition(arr, rows, columns);
    printf("Выходной массив:\n\n");
    printArray(arr, rows, columns);
    delete[] arr;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    printf("Хотите ввести вручную или использовать пример? ( 1 / 2 )\n");
    int choose;
    scanf_s("%d", &choose);
    int rows, columns;
    if (choose == 1) {
        printf("Введите высоту массива : ");
        scanf_s("%d", &rows);
        printf("Введите ширину массива : ");
        scanf_s("%d", &columns);
        run(createAndFillArray(rows, columns), rows, columns);
    }
    else if (choose == 2) {
        rows = 5;
        columns = 7;
        run(staticArray(), rows, columns);
    }
    else {
        printf("Ввод неверный");
    }
}