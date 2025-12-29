#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CONST 1

int delete_k(double* ptr_arr, int size, int k) {
    if (k < 0 || k >= size) {
        return size;
    }
    for (int i = k; i < size - 1; i++) {
        ptr_arr[i] = ptr_arr[i + 1];
    }
    return size - 1;
}
double* full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        double r = (double)rand() / RAND_MAX;
        ptr_array[i] = r * 2.0 - 1.0;
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

double* insert(double* arr, int* size, int index, double value) {
    (*size)++;
    arr = realloc(arr, (*size) * sizeof(double));

    if (!arr) {
        puts("Ошибка realloc");
        return NULL;
    }

    for (int i = *size - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    return arr;
}

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
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
    ptr_array = new_array;

    int k;
    printf("\nВведите индекс элемента для удаления: ");
    scanf("%d", &k);
    size = delete_k(ptr_array, size, k);
    ptr_array = realloc(ptr_array, size * sizeof(double));
    if (ptr_array == NULL && size > 0) {
        puts("Ошибка realloc");
        return -1;
    }

    int index = rand() % size;
    ptr_array = insert(ptr_array, &size, index, -999.0);


    printf("\nМассив после вставки -999 случайным образом:\n");
    put_elements(ptr_array, size);

    free(ptr_array);
    //free(new_array);

    system("pause");
    return 0;
}