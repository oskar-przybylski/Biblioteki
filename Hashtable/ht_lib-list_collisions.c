#include <stdio.h>
#include <stdlib.h>
#include "ht_lib-list_collisons.h"
//
// Created by Oskar Przybylski on 05/11/2024.
//
#define FNV_OFFSET_BASIS 2166136261u
#define FNV_prime 16777619
// Funkcja hashująca, która przyjmuje klucz int i rozmiar tablicy hash
unsigned int hash(int key, int tableSize) {
    unsigned int hash = FNV_OFFSET_BASIS;
    // Konwersja int na bajty i haszowanie
    unsigned char* p = (unsigned char*)&key; // traktujemy int jako strumień bajtów
    for (size_t i = 0; i < sizeof(int); i++) {
        hash ^= p[i];      // XOR z bieżącym bajtem
        hash *= FNV_prime; // Mnożenie przez liczbę pierwszą dla większej entropii
        hash /= 3;         // Dodatkowe dzielenie w celu uniknięcia nadmiaru liczb
    }
    return hash % tableSize; // wynik hashowania w zakresie tablicy hash
}

// Inicjalizacja nowej tablicy hash
HT* ht_init(int size) {
    HT* ht = (HT*)malloc(sizeof(HT));
    if(ht == NULL){
        fprintf(stderr,"ERROR: Nie udało się przypisać pamięci dla nowej tablicy hash\n");
        return NULL;
    }
    ht->size = size;
    ht->table = (element**)malloc(size * sizeof(element*));
    if(ht->table == NULL) {
        fprintf(stderr,"ERROR: Nie udało się przypisać pamięci dla nowej tablicy hash\n");
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Funkcja wstawiająca nową parę klucz-wartość do tablicy hash
void ht_insert(HT* ht, int key, int value) {
    if(ht != NULL) {
        int index = hash(key,ht->size);
        if(ht->table[index]==NULL) {
            element* new_element = (element*)malloc(sizeof(element));
            new_element->key = key;
            new_element->value = value;
            new_element->next_in_bucket = NULL;
            ht->table[index] = new_element;
            return;
        }else {
            element* current_element = ht->table[index];
            while(current_element->next_in_bucket!=NULL) {
                current_element = current_element->next_in_bucket;
            }
            element* next_element = (element*)malloc(sizeof(element));
            next_element->key = key;
            next_element->value = value;
            next_element->next_in_bucket = NULL;
            current_element->next_in_bucket = next_element;
            return;
        }
    }else {
        fprintf(stderr,"ERROR: Tablica hash jest pusta!\n");
        return;
    }
}

// Funkcja wyświetlająca zawartość tablicy hash
void ht_print(HT* ht) {
    if (ht != NULL) {
        for (int i = 0; i < ht->size; i++) {
            if (ht->table != NULL) {
                if (ht->table[i] != NULL) {
                    element* current_element = ht->table[i];
                    printf("%d. key: %d value: %d ", i, current_element->key, current_element->value);
                    while(current_element->next_in_bucket!=NULL) {
                        current_element = current_element->next_in_bucket;
                        printf("\t |-> NB. key: %d value: %d ", current_element->key, current_element->value);
                    }
                    printf("\n");
                } else {
                    printf("%d. key: - value: - \n", i);
                }
            } else {
                fprintf(stderr, "ERROR: Tablica hash jest pusta!\n");
                return;
            }
        }
    } else {
        fprintf(stderr, "ERROR: Tablica hash jest pusta!\n");
    }
}

// Wstawianie elementów z tablicy `arr` do tablicy hash
void ht_insert_arr(HT* ht, int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        ht_insert(ht, arr[i], i); // Wstawienie pary {key: arr[i], value: i}
    }
}

// Funkcja wyszukująca wartość w tablicy hash na podstawie klucza
int ht_lookup(HT* ht, int key) {
    int index = hash(key, ht->size);
    // Dopóki natrafiamy na istniejący element lub jest to poprawny klucz, sprawdzamy dalej
    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key) { // Znaleziono element o szukanym kluczu
            return ht->table[index]->value;
        }else {
            element* current_element = ht->table[index];
            while (current_element->next_in_bucket!=NULL) {
                if (current_element->next_in_bucket->key == key) {
                    return current_element->next_in_bucket->value;
                }
                current_element = current_element -> next_in_bucket;
            }
            return -1;
        }
    }
    return -1; // Zwracamy -1, gdy nie znaleziono elementu
}

// Zwalnianie pamięci zajętej przez tablicę hash
void ht_free(HT* ht) {
    for (int i = 0; i < ht->size; i++) {
        element* current_element = ht->table[i];
        while (current_element != NULL) {
            element* temp = current_element;
            current_element = current_element->next_in_bucket;
            free(temp); // Zwolnienie każdego elementu listy
        }
    }
    free(ht->table); // Zwolnienie tablicy wskaźników
    free(ht);        // Zwolnienie struktury tablicy hash
}

