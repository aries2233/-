#pragma once

#include "ADTLinkStack.h"

typedef struct result
{
	node s[100];
	int L;
}result;




Status change_1(char* str,int *i,LinkStack *s1, result* R1);//中缀转后缀
Status change_2(LinkStack* s, result* R1);//后缀得结果
