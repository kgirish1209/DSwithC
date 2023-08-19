#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "comdef.h"

typedef enum
{
	STK_OP_CREATE_FAILED,
	STK_OP_CREATE_PASS,
	STK_OP_PUSH_FAILED,
	STK_OP_POP_FAILED,
	STK_OP_OVERFLOW,
	STK_OP_UNDERFLOW,
	STK_OP_SEEK_FAILED,
	STK_OP_SUCCESS,
	STK_OP_MAX
}stackOpStatus_e;

struct __stackMetaInfo
{
	bool isEmpty;
	bool isFull;
	unsigned int curr_size;
	unsigned int stack_size;
	int top;
};
typedef struct __stackMetaInfo stackMetaInfo;

struct __stackInt 
{
	struct __stackMetaInfo stackMeta;
	int* stack;
};

typedef struct __stackInt stackInt;

#define STACK_DEFAULT_SIZE 10

stackOpStatus_e createStackInt(stackInt** s, unsigned int size);

void initStackInt(stackInt* s, unsigned int size);

stackOpStatus_e pushStackInt(stackInt* s,int data);

int popStackInt(stackInt* s);

bool isStackEmpty(stackMetaInfo* sMeta);

bool isStackFull(stackMetaInfo* sMeta);

unsigned int getStackSize(stackMetaInfo* sMeta);

int seekStackInt(stackInt* s);

void displayStackMeta(stackMetaInfo* sMeta);

void displayStackInt(stackInt* s);
