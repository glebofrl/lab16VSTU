#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CONST 1

double* full_elements(double* ptr_array, int n) {
    double x, dx;
    x = 0.1;
    dx = 0.01;
    for (int i = 0; i < n; i++) {
        *(ptr_array + i) = pow(x, 2) + 5 * sin(x);
        x += dx;
    }

    return ptr_array;
}

double* calc_elements(double* ptr_array, int size) {
    double* result = (double*)malloc(size * sizeof(double));
    if (result == NULL) {
        puts("Ошибка выделения памяти");
        return NULL;
    }

    for (int i = 0; i < size; i++)
        result[i] = *(ptr_array + i) - CONST;

    return result;
}


int put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++)
        printf("%lf\n", *(ptr_array + i));

    return 0;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int size;
    double* ptr_array;
    double* new_array;

    printf("Введите размер массива: ");
    scanf("%d", &size);


    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("error");
        return -1;
    }


    full_elements(ptr_array, size);


    new_array = calc_elements(ptr_array, size);
    if (new_array == NULL) {
        free(ptr_array);
        return -1;
    }


    printf("Исходный массив:\n");
    put_elements(ptr_array, size);

    printf("Измененный массив:\n");
    put_elements(new_array, size);


    free(ptr_array);
    free(new_array);

    system("pause");
    return 0;
}