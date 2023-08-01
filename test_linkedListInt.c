#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "linkedListInt.h"

int main()
{
	ll_int* list1 = NULL;
	ll_int* list2 = NULL;
	ll_int* list3 = NULL;

	// create a linked list 1
	create_LL_int_list(&list1);

	//display linked List 1
	 displayList_ll_int(list1);

	 //Reverse the list 1
	 reverseList_ll_int(&list1);

	 //display the reversed list 1
	 displayList_ll_int(list1);

	 //Reverse the list 1 again
	 reverseList_ll_int(&list1);

	 //display the reversed list 1 again
	 displayList_ll_int(list1);
	
	 //display last node in list1
	 displayNode_ll_int(getLastNode_ll_int(list1));

	 //create Linked List 2
	 create_LL_int_list(&list2);

	 //display Linked List 2
	 displayList_ll_int(list2);

	 //append List2 to List1
	 appendList_ll_int(list1,list2);

	 //display List1 post append
	 displayList_ll_int(list1);
	
	 //create Linked List 3
	 create_LL_int_list(&list3);

	 //display Linked List 3
	 displayList_ll_int(list3);

	 //Merge List1 and List3 with a merge factor of 2, ie, After every 2 nodes in list1, add a node from list3
	 mergeList_ll_int(list1,list3, 1);
	
	 //display List1 post merge
	 displayList_ll_int(list1);



	 return 0;
}

