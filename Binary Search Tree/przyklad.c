//
// Created by Oskar Przybylski on 05/11/2024.
//
#include "bst_lib.c"
int main(void) {
    double arr[] = {1,2,3,2.5,1.5,3.5,1.7,1.4,0.9};
    int size = sizeof arr / sizeof arr[0];

    node* head = bt_insert_array(arr,size);

    bt_search(head,1.4);
    bt_print(head,10,0);

    return 0;
}