#ifndef LINKEDLISTHEADER
#define LINKEDLISTHEADER

#include "comdef.h"

typedef enum
{
	LL_CREATE_PASS,
	LL_CREATE_FAIL_NUM_NODE,
	LL_CREATE_FAIL_HEAD_NODE,
	LL_CREATE_FAIL_ALL_NODE,
	LL_CREATE_MAX
}ll_create_e;

#define LL_CREATE_DATA_FUN1(num) (num)
#define LL_CREATE_DATA_FUN2(num) (2*num)
#define LL_CREATE_DATA_FUN3(num) (2*num+1)

#endif
