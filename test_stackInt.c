#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "stackInt.h"

int main()
{
	stackInt* stack1 = NULL;
	int dataOp = 0;
	unsigned int stack_size = STACK_DEFAULT_SIZE;

	// create the stack with default size
	createStackInt(&stack1,stack_size);

	// push some elements into stack
	pushStackInt(stack1,10);
	pushStackInt(stack1,20);
	pushStackInt(stack1,30);
	pushStackInt(stack1,40);
	
	//Display the stack
	displayStackInt(stack1);
	
	// Pop some elements from stack
	dataOp = popStackInt(stack1);
	printf("\n Data popped from stack is %d",dataOp);
	dataOp = popStackInt(stack1);
	printf("\n Data popped from stack is %d",dataOp);
	
	//display the stack post Pop
	displayStackInt(stack1);
	
	// Push data to stack until Stack is FULL to check isFULL funtion;
	int i=0;
	for(i=0;i<stack_size+1;i++)
	{
	  pushStackInt(stack1,i*10);
	}
	
	//Display the stack
	displayStackInt(stack1);
	


	// Pop data from stack until Stack is Empty to check isEmpty funtion;
	for(i=stack_size-1;i>=-1;i--)
	{
	  dataOp = popStackInt(stack1);
	  printf("\n Poped Data = %d", dataOp);
	}
	
	//Display the stack
	displayStackInt(stack1);
	return 0;
}

