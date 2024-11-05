#include <stdio.h>
#include <stdlib.h>
#include "ht_lib-linear-progression-collisions.h"
//
// Created by Oskar Przybylski on 04/11/2024.
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
    if (size <= 0) {
        fprintf(stderr, "ERROR: Niepoprawna wartość size dla tablicy hash!\n");
        return NULL;
    }
    HT* ht = (HT*)malloc(sizeof(HT));
    if (ht == NULL) {
        fprintf(stderr, "ERROR: Nie udało się przypisać miejsca w pamięci dla nowej tablicy hash!\n");
        return NULL;
    }
    ht->size = size;
    ht->table = (element**)malloc(size * sizeof(element*));
    if (ht->table == NULL) {
        fprintf(stderr, "ERROR: Nie udało się przypisać miejsca w pamięci dla nowej tablicy hash!\n");
        free(ht);  // Zwolnienie pamięci dla ht w przypadku niepowodzenia
        return NULL;
    }
    // Inicjalizacja wskaźników na NULL, aby wskazywały na puste miejsca
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Funkcja wstawiająca nową parę klucz-wartość do tablicy hash
void ht_insert(HT* ht, int key, int value) {
    int index = hash(key, ht->size); // obliczanie indeksu na podstawie klucza
    int max = 0;
    // Szukanie wolnego miejsca w przypadku kolizji
    int i = 1;
    while (ht->table[index] != NULL) {
        index = (index + i * i) % ht->size; // Przesunięcie kwadratowe
        i++;
    }
    element* new_element = (element*)malloc(sizeof(element));
    if (new_element == NULL) {
        fprintf(stderr, "ERROR: Nie udało się przypisać miejsca w tablicy hash dla nowej pary { key(%d) : value(%d) }!\n", key, value);
        return;
    }
    ht->table[index] = new_element;  // Umieszczenie elementu w tablicy
    new_element->key = key;
    new_element->value = value;
}

// Funkcja wyświetlająca zawartość tablicy hash
void ht_print(HT* ht) {
    if (ht != NULL) {
        for (int i = 0; i < ht->size; i++) {
            if (ht->table != NULL) {
                if (ht->table[i] != NULL) {
                    printf("%d. key: %d value: %d \n", i, ht->table[i]->key, ht->table[i]->value);
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
    int original_index = index;  // Zapamiętujemy początkowy indeks, aby zapobiec nieskończonej pętli
    int steps = 0;               // Licznik kroków dla uniknięcia pełnego przejścia tablicy

    // Dopóki natrafiamy na istniejący element lub jest to poprawny klucz, sprawdzamy dalej
    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key) { // Znaleziono element o szukanym kluczu
            return ht->table[index]->value;
        }

        // Kolizja - przechodzimy do kolejnego miejsca
        index = (index + 1) % ht->size;

        // Zabezpieczenie przed nieskończoną pętlą
        steps++;
        if (index == original_index || steps >= ht->size) {
            break;  // Przerwij, jeśli przeszliśmy całą tablicę lub wróciliśmy do początku
        }
    }

    return -1; // Zwracamy -1, gdy nie znaleziono elementu
}

// Zwalnianie pamięci zajętej przez tablicę hash
void ht_free(HT* ht) {
    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i] != NULL) {
            free(ht->table[i]);  // Zwolnienie pamięci dla każdego elementu
            ht->table[i] = NULL;
        }
    }
    free(ht->table);  // Zwolnienie tablicy wskaźników
    free(ht);         // Zwolnienie struktury głównej tablicy hash
}

// Funkcja rozwiązująca problem "Two Sum" przy użyciu tablicy hash
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HT* ht = ht_init(numsSize); // Inicjalizacja tablicy hash o większym rozmiarze
    ht_insert_arr(ht, nums, numsSize); // Wstawienie elementów z `nums` do tablicy hash
    int* ans = (int*)malloc(2 * sizeof(int)); // Alokacja pamięci dla odpowiedzi
    for(int i = 0; i < numsSize; i++) {
        int comp = target - nums[i]; // Obliczenie komplementu, którego szukamy
        int index = ht_lookup(ht, comp); // Sprawdzenie, czy komplement istnieje
        //printf("nums[%d]=%d comp=%d lookup=%d hash(comp) = %d / %d\n",i,nums[i],comp,ht_lookup(ht,comp),hash(comp,ht->size),ht->size);
        if(index != -1 && index != i) { // Sprawdzenie, czy znaleziono komplement
            ans[0] = i;
            ans[1] = index;
            *returnSize = 2;
            ht_free(ht); // Zwolnienie tablicy hash
            return ans;  // Zwrócenie indeksów
        }
    }

    *returnSize = 0;  // Jeśli nie znaleziono wyników
    free(ans);
    ht_free(ht);
    return NULL;
}


