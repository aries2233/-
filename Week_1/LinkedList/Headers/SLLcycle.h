#include <stdio.h>
#include <stdlib.h>

void cycleSLL(SLL* L)
{
	printf("  �Ƿ��γ���ʱѭ��������Y / N��\n");
	char n=0;
	SLL p = *L;
	int flag = 0;
	do
	{
		n = _getch();
	} while (n != 'Y' && n != 'y' && n != 'N' && n != 'n');
	//�γ�ѭ������
	if (n == 'Y' || n == 'y')
	{
		flag = 1;
		while (p->next)
			p = p->next;
		p->next = *L;
	}
	//��������Ƿ�ɻ�
	SLL fast = *L;
	SLL slow = *L;
	while(fast && fast->next)
	{
		fast = (fast->next)->next;
		slow = slow->next;
		if (fast == slow)
		{
			printf("  ����ɻ���\n");
			break;
		}
	}
	if (fast==NULL || fast->next==NULL)
		printf("  �����ɻ���\n");
	//�ָ�����ԭ״
	if (flag == 1)
		p->next = NULL;
}