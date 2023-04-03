#include "sort.h"
#include "others.h"

int main()
{
	char n;
	printf("请选择数据类型或读取数据文件：\n1.大数据量\n2.大量小数据量\n3.读取文件\n0.退出系统\n");
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
		printf("请选择数据类型或读取数据文件：\n1.大数据量\n2.大量小数据量\n3.读取文件\n0.退出系统"); 
		do
		{
			n = _getch();
		} while (n < '0' && n > '3');
	}
}