//
// Created by Oskar Przybylski on 05/11/2024.
//
#include "sll_lib.c"

int main(void){
    double array[]={1,2,3,4,5};
    int array_size =  sizeof array / sizeof array[0];

    node* list1 = array_to_list(array,array_size);
    printf("Lista 1: \n");
    print_list(list1);

    node* reversed_list1 = reverse_list(list1);

    printf("Odwrócona Lista 1: \n");
    print_list(reversed_list1);

}
