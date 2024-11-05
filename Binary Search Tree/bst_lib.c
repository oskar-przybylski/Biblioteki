//
// Created by Oskar Przybylski on 05/11/2024.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "bst_lib.h"
node* bt_make_node(double value) {
    node* head = (node*)malloc(sizeof(node));
    head->value = value;
    head->lewy_node = NULL;
    head->prawy_node = NULL;
    return head;
}

void bt_insert(node* head, double new_value) {
    if(head == NULL) {
        fprintf(stderr,"ERROR: Wskaźnik na głowe drzewa jest pusty!");
        return;
    }
    node* new_node = bt_make_node(new_value);
    if(head->value > new_value) {
        if(head->lewy_node == NULL) {
            head->lewy_node = new_node;
            return;
        }else {
            bt_insert(head->lewy_node,new_value);
        }
    }else {
        if(head->prawy_node == NULL) {
            head->prawy_node = new_node;
            return;
        }else {
            bt_insert(head->prawy_node,new_value);
        }
    }
}

void bt_print(node* head, int space,int pr) { //head pr = 0 ,prawy pr = 1 , lewy pr = -1;
    if (head == NULL) return;

    space += 5;

    bt_print(head->prawy_node, space,1);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    if(pr == 0) {
        printf("%3.1lf\n", head->value);
    }else if( pr == 1 ){
        printf(" ⋰ %3.1lf\n", head->value);
    }else if( pr == -1 ){
        printf(" ⋱ %3.1lf\n", head->value);
    }

    bt_print(head->lewy_node, space,-1);
}

node* bt_insert_array(double* arr, int arrSize) {
    if(arr != NULL) {
        node* head = bt_make_node(*arr);
        arr++;
        arrSize--;
        while(arrSize--) {
            bt_insert(head,*arr);
            arr++;
        }
        return head;
    }else {
        return NULL;
    }
}

bool bt_search(node* head,double key) {
    if(head==NULL) {
        printf("\r                            \r");
        return false;
    }
    if(head->value == key) {
        printf("%3.1lf \n",key);
        return true;
    }
    if(head->value < key) {
        if(head->prawy_node != NULL) {
            printf("R -> ");
            return bt_search(head->prawy_node,key);
        }else {
            printf("\r                            \r");
            return false;
        }
    }else {
        if(head->lewy_node != NULL) {
            printf("L -> ");
            return bt_search(head->lewy_node,key);
        }else {
            printf("\r                            \r");
            return false;
        }
    }
    return false;
}
