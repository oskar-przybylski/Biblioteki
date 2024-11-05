//
// Created by Oskar Przybylski on 05/11/2024.
//

#ifndef HT_LIB_H
#define HT_LIB_H

typedef struct ELEMENT {
    int key;    //value in array
    int value;  // index in array
    struct ELEMENT* next_in_bucket; //Obsługa kolizjii na zasadzie listy łączonej
}element;

typedef struct HT {
    int size;
    element** table;
}HT;

unsigned int hash(int ,int);
HT* ht_init(int);
void ht_insert(HT*, int, int);
void ht_print(HT*);
void ht_insert_arr(HT*, int* , int);
int ht_lookup(HT*, int);
void ht_free(HT*);

#endif //HT_LIB_H
