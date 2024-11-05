//
// Created by Oskar Przybylski on 05/11/2024.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "bst_lib.h"

// Funkcja bt_make_node - Tworzy nowy węzeł drzewa binarnego
// Parametr 'value' - Wartość, która zostanie przypisana do węzła
// Zwraca wskaźnik do nowo utworzonego węzła
node* bt_make_node(double value) {
    node* head = (node*)malloc(sizeof(node));
    head->value = value;
    head->lewy_node = NULL;
    head->prawy_node = NULL;
    return head;
}

// Funkcja bt_insert - Wstawia nową wartość do drzewa binarnego
// Parametry: 'head' - wskaźnik do korzenia drzewa, 'new_value' - wartość do wstawienia
// Jeśli wskaźnik na korzeń drzewa jest pusty, wyświetlany jest komunikat o błędzie
void bt_insert(node* head, double new_value) {
    if (head == NULL) {
        fprintf(stderr, "ERROR: Wskaźnik na głowe drzewa jest pusty!");
        return;
    }
    node* new_node = bt_make_node(new_value);  // Tworzymy nowy węzeł
    if (head->value > new_value) {  // Wartość mniejsza, więc wstawiamy po lewej stronie
        if (head->lewy_node == NULL) {
            head->lewy_node = new_node;  // Wstawiamy nowy węzeł jako lewe dziecko
            return;
        } else {
            bt_insert(head->lewy_node, new_value);  // Rekurencyjnie wstawiamy w lewym poddrzewie
        }
    } else {  // Wartość większa lub równa, więc wstawiamy po prawej stronie
        if (head->prawy_node == NULL) {
            head->prawy_node = new_node;  // Wstawiamy nowy węzeł jako prawe dziecko
            return;
        } else {
            bt_insert(head->prawy_node, new_value);  // Rekurencyjnie wstawiamy w prawym poddrzewie
        }
    }
}

// Funkcja bt_print - Wyświetla strukturę drzewa binarnego w graficzny sposób
// Parametry: 'head' - wskaźnik do korzenia drzewa, 'space' - ilość odstępów, 'pr' - kierunek (0 dla korzenia, 1 dla prawego, -1 dla lewego)
// Wypisuje węzły drzewa w formacie przypominającym strukturę drzewa
void bt_print(node* head, int space, int pr) { // head pr = 0 , prawy pr = 1 , lewy pr = -1
    if (head == NULL) return;

    space += 5;  // Zwiększamy odstęp dla każdego poziomu

    bt_print(head->prawy_node, space, 1);  // Rekurencyjnie wyświetlamy prawe poddrzewo

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    if (pr == 0) {
        printf("%3.1lf\n", head->value);  // Korzeń
    } else if (pr == 1) {
        printf(" ⋰ %3.1lf\n", head->value);  // Prawe dziecko
    } else if (pr == -1) {
        printf(" ⋱ %3.1lf\n", head->value);  // Lewe dziecko
    }

    bt_print(head->lewy_node, space, -1);  // Rekurencyjnie wyświetlamy lewe poddrzewo
}

// Funkcja bt_insert_array - Wstawia wartości z tablicy do drzewa binarnego
// Parametry: 'arr' - wskaźnik do tablicy, 'arrSize' - rozmiar tablicy
// Zwraca wskaźnik do korzenia drzewa
node* bt_insert_array(double* arr, int arrSize) {
    if (arr != NULL) {
        node* head = bt_make_node(*arr);  // Tworzymy korzeń z pierwszego elementu tablicy
        arr++;
        arrSize--;
        while (arrSize--) {
            bt_insert(head, *arr);  // Wstawiamy pozostałe elementy do drzewa
            arr++;
        }
        return head;
    } else {
        return NULL;  // Jeśli tablica jest pusta, zwracamy NULL
    }
}

// Funkcja bt_search - Szuka wartości w drzewie binarnym
// Parametry: 'head' - wskaźnik do korzenia drzewa, 'key' - wartość do wyszukania
// Zwraca 'true' jeśli wartość została znaleziona, w przeciwnym wypadku 'false'
bool bt_search(node* head, double key) {
    if (head == NULL) {
        printf("\r                            \r");  // Czyszczenie linii
        return false;  // Nie znaleziono węzła
    }
    if (head->value == key) {  // Jeśli wartość jest równa szukanej
        printf("%3.1lf \n", key);  // Wyświetlamy wartość
        return true;
    }
    if (head->value < key) {  // Jeśli szukana wartość jest większa, przechodzimy do prawego poddrzewa
        if (head->prawy_node != NULL) {
            printf("R -> ");  // Wskazanie przejścia w prawo
            return bt_search(head->prawy_node, key);
        } else {
            printf("\r                            \r");  // Czyszczenie linii
            return false;  // Nie znaleziono węzła
        }
    } else {  // Jeśli szukana wartość jest mniejsza, przechodzimy do lewego poddrzewa
        if (head->lewy_node != NULL) {
            printf("L -> ");  // Wskazanie przejścia w lewo
            return bt_search(head->lewy_node, key);
        } else {
            printf("\r                            \r");  // Czyszczenie linii
            return false;  // Nie znaleziono węzła
        }
    }
    return false;
}