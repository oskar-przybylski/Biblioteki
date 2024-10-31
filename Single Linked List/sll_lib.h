#ifndef SLL_LIB_H
#define SLL_LIB_H
typedef struct node {
    double value;
    struct node* next_node;
}node;

node* make_head(double);
node* make_next_node(node*, double);
void  print_list(node*);
node* append_node(node*, double);
node* insert_node(node*, double, node*);
node* array_to_list(double*, int);
node* append_array_to_list(node*,double*,int);
node* append_after_value(node*,double,double);
node* reverse_list(node*);
int list_length(node*);
double* list_to_array(node*);
void free_list(node*);
void delete_value(node* ,double);
void list_pop(node*);

#endif //SLL_LIB_H
