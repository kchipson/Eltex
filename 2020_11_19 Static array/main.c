#include <stdio.h>

/* Вывод матрицы */
void outMatrix(int size, int array[][size]){
    for (int i = 0 ; i < size ; i++){
        for (int j = 0 ; j < size ; j++)
            printf("%d\t", array[i][j]);
        printf("\n");
    }
}


/* Вывод массива размерности n */
void outArray(int size, int array[size]){
    for (int i = 0 ; i < size ; i++)
        printf("%d\t", array[i]);
    printf("\n");
}


/* Вывод массива размерности n в обратном порядке */
void outReverseArray(int size, int array[size]){
    for (int i = size ; i > 0 ; i--)
        printf("%d\t", array[i - 1]);
    printf("\n");
}


/* Формирование матрицы, у которой верхний треугольник 0, а нижний 1 */
void triangleMatrix(int size, int array[][size]){
    for (int i = 0 ; i < size ; i++){
        for (int j = 0 ; j < size - i - 1 ; j++)
            array[i][j] = 0;
        for (int j = size - i - 1 ; j < size ; j++)
            array[i][j] = 1;
    }
}

/* Формирование "улиточной" матрицы */
void snailMatrix(int size, int array[][size]){
    int upperLeft = 0;
    int lowerRight = size - 1;
    int num = 1;
    while(num <= size * size){
        for (int i = upperLeft ; i <= lowerRight ; i++) // ➡
            array[upperLeft][i] = num++;
        for (int i = upperLeft + 1 ; i <= lowerRight ; i++) // ⬇
            array[i][lowerRight] = num++;

        for (int i = lowerRight - 1 ; i >= upperLeft ; i--) // ⬅
            array[lowerRight][i] = num++;
        for (int i = lowerRight - 1 ; i >= upperLeft+1 ; i--) // ⬆
            array[i][upperLeft] = num++;
        upperLeft++;
        lowerRight--;
    }
}



int main(){
    int n = 5;
    int arr[n][n];

    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++)
            arr[i][j] = i * n + j + 1;

    printf("Task1:\n");
    outMatrix(n, arr);

    printf("\nTask2:\n");
    printf("Original array : ");
    outArray(n, arr[0]);
    printf("Reverse array  : ");
    outReverseArray(n, arr[0]);

    printf("\nTask3:\n");
    triangleMatrix(n, arr);
    outMatrix(n, arr);

    printf("\nTask4:\n");
    snailMatrix(n, arr);
    outMatrix(n, arr);
}