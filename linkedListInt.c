#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "linkedListInt.h"

#define LL_DATA_AUTO_FUN

unsigned int total_nodes_ll_int = 0;


unsigned int get_ll_node_tracker()
{
	return total_nodes_ll_int++;
}

ll_int* get_new_node_ll_int()
{
	ll_int* node = (ll_int*) malloc(sizeof(ll_int));
	if(node!=NULL)
	{
		memset((void*)node,0,sizeof(ll_int));
	}
	return node;
}

ll_create_e create_LL_int_list(ll_int** head_node)
{
	unsigned int num_nodes = 0, cur_node = 0;
	printf("\nEnter the number of nodes in linkedList");
	scanf("%d",&num_nodes);
	if(num_nodes == 0)
	{
		printf("\n Incorrect num of nodes, Returning head node as NULL");
		*head_node = NULL;
		return LL_CREATE_FAIL_NUM_NODE;
	}

	*head_node = (ll_int*)malloc(sizeof(ll_int));

	if(*head_node == NULL)
	{
		printf("\n Mem alloc for head_node failed. Aborting creating linked list");
		return LL_CREATE_FAIL_HEAD_NODE;
	}
	
	memset((void*)(*head_node),0,sizeof(ll_int));
	#ifdef LL_DATA_AUTO_FUN
	(*head_node)->value = LL_CREATE_DATA_FUN1(get_ll_node_tracker());
	#else
	printf("\n Enter the data for node = %d", cur_node);
	scanf("%d",&(*head_node->value));
	#endif

	num_nodes--;
	cur_node++;

	ll_int* node=*head_node;
	ll_int* new_node= NULL;

	while(num_nodes!=0 && node != NULL)
	{
		new_node = get_new_node_ll_int();
		if(new_node == NULL)
		{
			node->next = NULL;
			return LL_CREATE_FAIL_ALL_NODE;
		}

		#ifdef LL_DATA_AUTO_FUN
		new_node->value = LL_CREATE_DATA_FUN1(get_ll_node_tracker());
		#else
		printf("\n Enter the data for node = %d",cur_node);
		scanf("%d",&(new_node->value));
		#endif

		node->next = new_node;
		node = new_node;
		num_nodes--;
		cur_node++;
	}

	return LL_CREATE_PASS;
}

bool insert_new_node_ll_int(ll_int* node)
{
	ll_int* new_node=NULL;
	new_node = (ll_int*) malloc(sizeof(ll_int));
	if(new_node == NULL)
	{
		printf("\n Inserting new node failed.");
		return FALSE;
	}

	#ifdef LL_DATA_AUTO_FUN
	new_node->value = LL_CREATE_DATA_FUN1(get_ll_node_tracker());
	#else
	printf("\n Enter the data for node = %d",cur_node);
	scanf("%d",&(new_node->value));
	#endif

	new_node->next = node->next;
	node->next = new_node;
	return TRUE;
}

void insertNode_ll_int(ll_int* node,ll_int* next_node)
{
	if(node!=NULL && next_node != NULL)
	{
		next_node->next = node->next;
		node->next = next_node;
	}
}
	
void displayNode_ll_int(ll_int* node)
{
	if(node!=NULL)
	{
		printf("\n Node addr = 0x%x, Node value = %d, next Node = 0x%x",(unsigned int)node,node->value,(unsigned int)(node->next));
	}
}

void displayList_ll_int(ll_int* head_node)
{
	printf("\n======= Linker List details are ::====== ");
	printf("\n Head Node is 0x%x",(unsigned int)head_node);
	unsigned int num_nodes = 0;
	while(head_node!=NULL)
	{
		num_nodes++;	
		displayNode_ll_int(head_node);
		head_node = head_node->next;
	}
	printf("\n Total number of nodes = %d",num_nodes);
	printf("\n===================\n");
}

void appendNode_ll_list(ll_int* head_node,ll_int* node)
{
	if(node == NULL || head_node == NULL)
	{
		printf("\n Either Head Node or Append node is NULL, Append Failed");
	}

	while(head_node->next!=NULL)
	{
		head_node = head_node->next;
	}
	
	insertNode_ll_int(head_node,node);
}

unsigned int getNumNodes_ll_int(ll_int* head_node)
{
	unsigned int num_nodes=0;
	while(head_node!=NULL)
	{
		num_nodes++;
		head_node = head_node->next;
	}

	return num_nodes;
}




	
