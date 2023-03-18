#include <stdio.h>
#include <stdlib.h>
#include "Run.h"

void main()
{
	char n;
	printf("\n  师兄师姐们好！请多多指教~~\n");
	printf("  请选择模块：\n  1.单链表\n  2.双向链表\n  0.退出系统\n");
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