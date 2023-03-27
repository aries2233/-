#include "run.h"

void clear()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void run(char *str,LinkStack *s1, result* R1)
{
	char ch;
	int i = 0;
	int flag = 1;
	while (1)
	{
		printf("\n请输入一个算式（算式长度在100以内）：\n");
		flag = 1;
		while ((ch = getchar()) != '\n')
		{
			if (ch == 40 || ch == 41 || ch == 42 || ch == 43 || ch == 45 || ch == 47 || (ch >= 48 && ch <= 57))
			{
				if (i < 100)
				{
					if ((ch == 42 || ch == 43 || ch == 45 || ch == 47) && (str[i - 1] == 42 || str[i - 1] == 43 || str[i - 1] == 45 || str[i - 1] == 47))
					{
						printf("无法识别两个连续的符号！");
						i = 0;
						clear();
						flag = 0;
						break;
					}
					str[i++] = ch;
				}
				else
				{
					printf("\n算式长度超出范围！");
					i = 0;
					clear();
					flag = 0;
					break;
				}
			}
			else
			{
				printf("\n请重新输入正确的数字和符号！");
				i = 0;
				clear();
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			str[i] = ch;
			if (str[i - 1] == 42 || str[i - 1] == 43 || str[i - 1] == 45 || str[i - 1] == 47)
			{
				printf("\n不可以以符号结尾！请重新输入");
				i = 0;
				clear();
			}
			else
			{
				change_1(str, &i, s1, &R1);
				change_2(s1, &R1);
				exit();
			}
		}
	}
}