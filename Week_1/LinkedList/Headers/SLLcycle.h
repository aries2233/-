#include <stdio.h>
#include <stdlib.h>

void cycleSLL(SLL* L)
{
	printf("  是否形成临时循环链表？（Y / N）\n");
	char n=0;
	SLL p = *L;
	int flag = 0;
	do
	{
		n = _getch();
	} while (n != 'Y' && n != 'y' && n != 'N' && n != 'n');
	//形成循环链表
	if (n == 'Y' || n == 'y')
	{
		flag = 1;
		while (p->next)
			p = p->next;
		p->next = *L;
	}
	//检测链表是否成环
	SLL fast = *L;
	SLL slow = *L;
	while(fast && fast->next)
	{
		fast = (fast->next)->next;
		slow = slow->next;
		if (fast == slow)
		{
			printf("  链表成环！\n");
			break;
		}
	}
	if (fast==NULL || fast->next==NULL)
		printf("  链表不成环！\n");
	//恢复链表原状
	if (flag == 1)
		p->next = NULL;
}