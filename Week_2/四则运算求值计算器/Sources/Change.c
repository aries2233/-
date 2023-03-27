#include "Change.h"
#include "ADTLinkStack.h"
#include "run.h"

Status change_1(char* str,int *i,LinkStack *s1, result* R1)
{
	int n;
	node temp;
	temp.flag = 0;
	temp.mark = 0;
	temp.num = 0;
	R1->s[0].flag = 0;
	R1->s[0].mark = 0;
	R1->s[0].num = 0;
	R1->L = 0;
	int j;
	for (j = 0; j < *i;)
	{
		if (str[j] >= '0' && str[j] <= '9')
		{
			temp.flag = 1;
			temp.num = str[j] - '0';
			j++;
			while (j < i && str[j] >= '0' && str[j] <= '9')
			{
				temp.num = temp.num * 10 + (str[j] - '0');
				j++;
			}
			R1->s[R1->L] = temp;
			(R1->L)++;
		}
		else
		{
			temp.flag = 0;
			temp.mark = str[j];
			if (temp.mark == '(')
				pushLStack(s1, temp);
			else if (temp.mark == ')')
			{
				ElemType e;
				getTopLStack(s1, &e);
				while (e.mark != '(')
				{
					R1->s[R1->L] = e;
					R1->L++;
					popLStack(s1,&e);
					getTopLStack(s1, &e);
				}
				popLStack(s1, &e);
			}
			else if (isEmptyLStack(s1))
			{
				pushLStack(s1, temp);
			}
			else
			{
				ElemType e;
				getTopLStack(s1, &e);
				while (!isEmptyLStack(s1) && ((temp.mark == '+' || temp.mark == '-') && (e.mark == '+' || e.mark == '-' || e.mark == '*' || e.mark == '/')))
				{
					R1->s[R1->L] = e;
					R1->L++;
					popLStack(s1, &e);
					getTopLStack(s1, &e);
				}
				pushLStack(s1, temp);
			}
			j++;
		}
	}
	while (!isEmptyLStack(s1))
	{
		ElemType e;
		popLStack(s1, &e);
		R1->s[R1->L] = e;
		R1->L++;
	}
	printf("后缀表达式为：\n");
	for (j = 0; j < R1->L; j++)
	{
		if (R1->s[j].flag)
			printf(" %d",R1->s[j].num);
		else
			printf(" %c",R1->s[j].mark);
	}
}

Status change_2(LinkStack* s1, result* R1)
{
	node n1, n2;
	node temp,num;
	int j;
	for (j = 0; j < R1->L; j++)
	{
		temp = R1->s[j];
		if (temp.flag == 1)
			pushLStack(s1, temp);
		else
		{
			popLStack(s1, &n1);
			popLStack(s1, &n2);
			num.flag = 1;
			if (temp.mark == '+')
				num.num = n2.num + n1.num;
			else if (temp.mark == '-')
				num.num = n2.num - n1.num;
			else if (temp.mark == '*')
				num.num = n2.num * n1.num;
			else if (temp.mark == '/')
				num.num = n2.num / n1.num;
			pushLStack(s1, num);
		}
	}
	popLStack(s1, &num);
	printf("\n最终结果为：%d", num.num);
}