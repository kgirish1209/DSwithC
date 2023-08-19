#include "stackInt.h"
#include<string.h>


void initStackInt(stackInt* s,unsigned int size)
{
	if(s == NULL)
	{
		printf(" Stack is NULL, no INIT done");
		return;
	}

	s->stackMeta.isEmpty = TRUE;
	s->stackMeta.isFull = FALSE;
	s->stackMeta.curr_size = 0;
	s->stackMeta.stack_size = size;
	s->stackMeta.top = -1;

	memset((void*)s->stack,0,(sizeof(int)*size));
}

stackOpStatus_e createStackInt(stackInt** s, unsigned int size)
{
	*s = (stackInt*)malloc(sizeof(stackInt));

	if(*s == NULL)
	{
		printf("\n Stack Creation failed ");
		return STK_OP_CREATE_FAILED;
	}

	(*s)->stack = (int*)malloc(sizeof(int)*size);

	if((*s)->stack == NULL)
	{
		printf("\n Stack DB creation failed for size %d",size);
		return STK_OP_CREATE_FAILED;
	}

	initStackInt(*s,size);
	
	return STK_OP_SUCCESS;
}


stackOpStatus_e pushStackInt(stackInt* s,int data)
{
	if(s==NULL)
	{
		printf("\n Stack is NULL, Push failed");
		return STK_OP_PUSH_FAILED;
	}

	if(s->stackMeta.isFull)
	{
		printf("\n Stack overflow detected. Stack is FULL. PUSH Failed");
		return STK_OP_OVERFLOW;
	}

	s->stackMeta.top++;
	s->stack[s->stackMeta.top]=data;
	s->stackMeta.isEmpty = 0;
	s->stackMeta.curr_size++;
	
	if(s->stackMeta.top >= s->stackMeta.stack_size)
	{
		s->stackMeta.isFull = 1;
	}

	return STK_OP_SUCCESS;
}

int popStackInt(stackInt* s)
{
  
	if(s==NULL)
	{
		printf("\n Stack is NULL, Pop failed");
		return STK_OP_POP_FAILED;
	}
	
	if(s->stackMeta.isEmpty)
	{
		printf("\n Stack Underflow Detected. Stack is Empty. Pop Failed");
		return 0;
	}

	int pop_data = s->stack[s->stackMeta.top];
	s->stackMeta.top--;
	s->stackMeta.isFull = 0;
	s->stackMeta.curr_size--;
	
	if(s->stackMeta.top == -1)
	{
		s->stackMeta.isEmpty=1;
	}
	
	return pop_data;
}

int seekStackInt(stackInt* s)
{
	
	if(s==NULL)
	{
		printf("\n Stack is NULL, Pop failed");
		return STK_OP_SEEK_FAILED;
	}

	if(s->stackMeta.isEmpty)
	{
		printf("\n Stack is empty . Seek Failed");
		return 0;
	}

	return s->stack[s->stackMeta.top];
}

bool isStackEmpty(stackMetaInfo* sMeta)
{
	return (sMeta!=NULL)? sMeta->isEmpty : FALSE;
}


bool isStackFull(stackMetaInfo* sMeta)
{
	return (sMeta!=NULL)? sMeta->isFull : FALSE;
}

 
void displayStackMeta(stackMetaInfo* sMeta)
{
	printf("\n Stack Meta is == : ");
	printf("\n Stack Pointer= %d \n Stack Total size = %d \n Stack Current size = %d \n isEmpty= %d \n isFull=%d \n",sMeta->top,sMeta->stack_size,sMeta->curr_size,sMeta->isEmpty,sMeta->isFull); 
}

void displayStackInt(stackInt* s)
{
  displayStackMeta(&(s->stackMeta));
  printf("\n Contents of the stack are ");
  for(int i=0;i < s->stackMeta.curr_size;i++)
  {
	printf("\n Stack[%d] = %d",i,s->stack[i]);
  }
}
