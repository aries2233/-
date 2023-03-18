#include <stdio.h>
#include <stdlib.h>

void middleSLL(SLL* L)
{
	SLL fast = *L;
	SLL slow = *L;
	while (fast && fast->next)
	{
		fast = (fast->next)->next;
		slow = slow->next;
	}
	printf("  �е�����Ϊ%d\n", slow->data);
	return 0;
}