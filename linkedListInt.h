#ifndef LINKEDLISTINTHEADER
#define LINKEDLISTINTHEADER

#include "linkedList.h"
#include <stdbool.h>

struct __linkedListInt
{
	int value;
	struct __linkedListInt* next;
};

typedef struct __linkedListInt ll_int;

extern unsigned int total_nodes_ll_int;

unsigned int get_ll_node_tracker();

ll_int* get_new_node_ll_int();

ll_create_e create_LL_int_list(ll_int** head_node);

bool insert_new_node_ll_int(ll_int* node);

void insertNode_ll_int(ll_int* node,ll_int* next_node);

void displayNode_ll_int(ll_int* node);

void displayList_ll_int(ll_int* head_node);

void appendNode_ll_list(ll_int* head_node,ll_int* node);

unsigned int getNumNodes_ll_int(ll_int* head_node);

#endif
