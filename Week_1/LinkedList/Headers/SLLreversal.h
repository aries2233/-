#include <stdio.h>
#include <stdlib.h>

//·ÇµÝ¹é
void reversalSLL1(SLL* L)
{
	SLL p = (*L)->next;
	SLL q;
	(*L)->next = NULL;
	while (p)
	{
		q = p->next;
		p->next = (*L)->next;
		(*L)->next = p;
		p = q;
	}
}

//µÝ¹é
SLL reversalSLL2(SLL L)
{
	SLL p = L;
	if (!p->next)
		return p;
	SLL phead = reversalSLL2(p->next);
	(p->next)->next = p;
	p->next = NULL;
	return phead;
}