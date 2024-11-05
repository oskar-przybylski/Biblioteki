//
// Created by Oskar Przybylski on 05/11/2024.
//

#ifndef BST_LIB_H
#define BST_LIB_H

typedef struct NODE{
    double value;
    struct NODE* lewy_node;
    struct NODE* prawy_node;
}node;

node* bt_make_node(double);
void bt_insert(node*, double);
void bt_print(node*, int, int);
node* bt_insert_array(double*, int);
bool bt_search(node*, double);

#endif //BST_LIB_H
