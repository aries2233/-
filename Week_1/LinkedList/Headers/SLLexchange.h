#include <stdio.h>
#include <stdlib.h>

void exchangeSLL(SLL* L)
{
	if (!*L || ! (*L)->next)
	{
		printf("  ���������ϵ���������\n");
		return 0;
	}
	SLL p = *L;
	while (p->next && (p->next)->next)
	{
		SLL q = (p->next)->next;
		(p->next)->next = q->next;
		q->next = p->next;
		p->next = q;
		p = q->next;
	}
	printf("  ��������ż������ɣ�\n");
	return 0;
}