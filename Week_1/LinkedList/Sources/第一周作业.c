#include <stdio.h>
#include <stdlib.h>
#include "Run.h"

void main()
{
	char n;
	printf("\n  ʦ��ʦ���Ǻã�����ָ��~~\n");
	printf("  ��ѡ��ģ�飺\n  1.������\n  2.˫������\n  0.�˳�ϵͳ\n");
	do
	{
		n = _getch();
	} while (n != '1' && n != '2' && n!='0');
	n = n - '0';
	switch (n)
	{
	case 0:
		exit(0);
	case 1:
		runSLL();
		break;
	case 2:
		runDLL();
		break;
	}
}