#include "sort.h"
#include "others.h"

int main()
{
	char n;
	printf("��ѡ���������ͻ��ȡ�����ļ���\n1.��������\n2.����С������\n3.��ȡ�ļ�\n0.�˳�ϵͳ\n");
	do
	{
		n = _getch();
	} while (n < '0' && n > '3');
	while (1)
	{
		printf("\n");
		n = n - '0';
		switch (n)
		{
		case 0:
			exit(0);
		case 1:
			Big_data_run();
			break;
		case 2:
			LargeSmall_data_run();
			break;
		case 3:
			readdata();
			break;
		}
		_getch();
		system("cls");
		printf("��ѡ���������ͻ��ȡ�����ļ���\n1.��������\n2.����С������\n3.��ȡ�ļ�\n0.�˳�ϵͳ"); 
		do
		{
			n = _getch();
		} while (n < '0' && n > '3');
	}
}