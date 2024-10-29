#include "sll_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

//robi nowy węzeł / głowę;
node* make_head(double value) {
    node* result = (node*)malloc(sizeof(node));
    if(result == NULL) {
        fprintf(stderr,"ERROR: Nie udało się przypisać pamięci dla nowego węzła! \n");
        return NULL;
    }
    result->value = value;
    result->next_node = NULL;
    return result;
}

// tworzy nowy węzeł po podanym węźle, gorsza wersja append'a
node* make_next_node(node* initial_last_node, double new_node_value) {
    node* new_node = make_head(new_node_value);
    initial_last_node->next_node = new_node;
    return new_node;
}

// dodaje nowy węzeł na koniec listy
node* append_node(node* head, double new_node_value) {
    node* current_node = head;
    while (current_node->next_node != NULL) {
        current_node = current_node->next_node;
    }
    node* new_node = make_head(new_node_value);
    current_node->next_node = new_node;
    return new_node;
}

// wstawia nowy węzeł pomiędzy dwa inne
node* insert_node(node* node_before, double new_node_value, node* node_after) {
    node* new_node = make_head(new_node_value);
    node_before->next_node = new_node;
    new_node->next_node = node_after;
    if(new_node == NULL) {
        fprintf(stderr,"ERROR: Nie udało się wstawić nowego węzła! \n");
        return NULL;
    }
    return new_node;
}

//tworzy nową listę łączoną z tablicy
node* array_to_list(double* array, int array_length) {
    if (array_length <= 0) return NULL;

    node* head = make_head(array[0]);
    node* current_node = head;

    for (int i = 1; i < array_length; i++) {
        current_node->next_node = make_head(array[i]);
        current_node = current_node->next_node;
    }
    return head;
}

//dodaje węzły zgodnie z tablicą do listy
node* append_array_to_list(node* head, double* array, int array_length) {
    node* current_node = head;
    while (current_node->next_node != NULL) {
        current_node = current_node->next_node;
    }

    for (int i = 0; i < array_length; i++) {
        current_node->next_node = make_head(array[i]);
        current_node = current_node->next_node;
    }
    return head;
}

//tworzy nowy węzeł po podanej wartosci w liscie
node* append_after_value(node* head,double value_before, double new_value) {
    if(head->value==value_before) {
        node* new_node = make_head(new_value);
        new_node->next_node = head->next_node;
        head->next_node = new_node;
        return new_node;
    }else if(head->value!=value_before && head->next_node!=NULL){
        append_after_value(head->next_node,value_before,new_value);
    }else {
        fprintf(stderr,"ERROR: Nie udało się wstawić nowego węzła! \n");
        return NULL;
    }
    return NULL;
}

// zwraca ilosc węzłów w liscie
int list_length(node* head) {
    int length = 0;
    while(head!=NULL) {
        length++;
        head = head->next_node;
    }
    return length;
}

// zamienia liste na tablice
double* list_to_array(node* head){
    int length = list_length(head);
    double *array = (double*)malloc(length * sizeof(double));
    for(int i=0; i<length; i++) {
        array[i] = head->value;
        head = head->next_node;
    }
    return array;
}

//zwraca poczatek odwroconej listy
node* reverse_list(node* head) {
    node* node_before = NULL;
    node* current_node = head;
    node* node_after = NULL;

    while (current_node != NULL) {
        node_after = current_node->next_node;
        current_node->next_node = node_before;
        node_before = current_node;
        current_node = node_after;
    }
    return node_before;
}

// zwalnia pamiec zajeta przez liste
void free_list(node* head) {
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next_node;
        free(temp);
    }
}

// wyświetla całą listę
void print_list(node* head) {
    printf("%d ",list_length(head));
    while(head) {
        printf("[%3.2lf] -> ",head->value);
        head = head->next_node;
    }
    printf("NULL\n");
}