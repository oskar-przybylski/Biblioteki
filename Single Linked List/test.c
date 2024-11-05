#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "sll_lib.h"

int main(void){
    //test make head
    //1.1
    node* t1_1 = make_head(-0);
    if(t1_1 != NULL && t1_1->next_node == NULL && t1_1->value == -0) {
        printf("\033[1;32mTest make head 1.1 poprawny!\033[0m\n");
    }else {
        printf("\033[1;31mERROR: Test make head 1.1 niepoprawny!\033[0m\n");
    }
    //1.2
    node* t1_2 = make_head(DBL_MAX);
    if(t1_2 != NULL && t1_2->next_node == NULL && t1_2->value == DBL_MAX) {
        printf("\033[1;32mTest make head 1.2 poprawny!\033[0m\n");
    }else {
        printf("\033[1;31mERROR: Test make head 1.2 niepoprawny!\033[0m\n");
    }
    //1.3
    node* t1_3 = make_head(DBL_MIN);
    if(t1_3 != NULL && t1_3->next_node == NULL && t1_3->value == DBL_MIN) {
        printf("\033[1;32mTest make head 1.3 poprawny!\033[0m\n");
    }else {
        printf("\033[1;31mERROR: Test make head 1.3 niepoprawny!\033[0m\n");
    }

    //test make_next_node
    //2.1
    node* t2_1_1 = make_head(0);
    node* t2_1_2 = make_next_node(t2_1_1,1);
    if(t2_1_1->value==0 && t2_1_1->next_node==t2_1_2 && t2_1_2->value==1 && t2_1_2->next_node==NULL) {
        printf("\033[1;32mTest make next node 2.1 poprawny!\033[0m\n");
    }else {
        printf("\033[1;31mERROR: Test make next node  2.1 niepoprawny!\033[0m\n");
    }

    //2.2
    node* t2_2_1 = make_head(DBL_MAX);
    node* t2_2_2 = make_next_node(t2_2_1,DBL_MIN);
    if(t2_2_1->value==DBL_MAX && t2_2_1->next_node==t2_2_2 && t2_2_2->value==DBL_MIN && t2_2_2->next_node==NULL) {
        printf("\033[1;32mTest make next node 2.2 poprawny!\033[0m\n");
    }else {
        printf("\033[1;31mERROR: Test make next node  2.2 niepoprawny!\033[0m\n");
    }

    //test append_node()
    //3.1
    node* t3_1_1 = make_head(DBL_MAX);
    node* t3_1_2 = append_node(t3_1_1,DBL_MIN);
    node* t3_1_3 = append_node(t3_1_1,0);

    if(t3_1_1->value==DBL_MAX && t3_1_1->next_node == t3_1_2 && t3_1_2->value == DBL_MIN && t3_1_2->next_node == t3_1_3 && t3_1_3->value == 0 && t3_1_3->next_node==NULL) {
        printf("\033[1;32mTest append node 3.1 poprawny!\033[0m\n");
    }else {
        printf("\033[1;31mERROR: Test append node 3.1 niepoprawny!\033[0m\n");
    }

    //test insert_node()
    //4.1

    node* t4_1_1 = make_head(0);
    node* t4_1_2 = append_node(t4_1_1,1);
    node* t4_1_3 = insert_node(t4_1_1,0.5,t4_1_2);

    print_list(t4_1_1);

    if(t4_1_1->value == 0 &&  t4_1_1->next_node==t4_1_3 && t4_1_3 == 0.5 && t4_1_3->next_node==t4_1_2 && t4_1_2->value == 1 && t4_1_2->next_) {
        printf("\033[1;32mTest insert node 4.1 poprawny!\033[0m\n");
    }else {
        printf("\033[1;31mERROR: Test insert node 4.1 niepoprawny!\033[0m\n");
    }





    return 0;
}