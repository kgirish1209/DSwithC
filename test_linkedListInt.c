#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "linkedListInt.h"

int main()
{
	ll_int* list1 = NULL;

	// create a linked list 1
	create_LL_int_list(&list1);

	//display linked List 1
	 displayList_ll_int(list1);

	 return 0;
}

