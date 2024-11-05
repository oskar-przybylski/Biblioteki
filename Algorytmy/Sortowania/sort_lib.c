//
// Created by Oskar Przybylski on 05/11/2024.
//
#include <stdbool.h>
#include <stdio.h>

int is_sorted(double* array, int arraySize) {
    for(int i = 0; i<arraySize-1; i++) {
        if(array[i]>array[i+1]) {
            return false;
        }
    }
    return true;
}

void swap(double* n1, double* n2) {
    double tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void print_array(double* array, int arraySize) {
    printf("%d [ ",arraySize);
    while (arraySize--) {
        printf("%lf ",*array);
        array++;
    }
    printf("]\n");
}

double* bubble_sort(double* array, int arraySize) { //Złożoność czasowa O(n) - najlepszy przypadek, O(n^2) - przeciętny,najgorszy | Pamięciowa O(1)
    for (int j = 0; j < arraySize - 1; j++) {
        bool swapped = false;  // Flaga śledząca, czy doszło do zamiany

        for (int i = 0; i < arraySize - 1 - j; i++) {  // Skrócenie pętli o j iteracji
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
                swapped = true;  // Ustawienie flagi, jeśli zamiana miała miejsce
            }
        }

        // Jeśli w tej iteracji nie było zamiany, zakończ sortowanie
        if (!swapped) {
            break;
        }
    }
    return array;  // Opcjonalnie zwróć wskaźnik do posortowanej tablicy
}

int main(void) {
    double arr[]={5,3,1};
    int size = sizeof arr / sizeof arr[0];



    print_array(arr,size);
    bubble_sort(arr,size);
    print_array(arr,size);

    return 0;
}