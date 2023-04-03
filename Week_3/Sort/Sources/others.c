#include "others.h"
#include "sort.h"


void clear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getMax(int* a, int size)
{
    int i;
    int max = a[0];
    for (i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

void savedata(int* a, int size)
{
    time_t t;
    struct tm tm_info;
    char filename[100];
    int i;
    // ��ȡ��ǰʱ��
    time(&t);
    localtime_s(&tm_info, & t);
    // �����ļ���
    sprintf(filename, "data_%04d%02d%02d_%02d%02d%02d.txt", tm_info.tm_year + 1900, tm_info.tm_mon + 1, tm_info.tm_mday, tm_info.tm_hour, tm_info.tm_min, tm_info.tm_sec);
    // ���ļ�
    FILE* fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("�����ļ�ʧ�ܣ�\n");
        return 1;
    }
    // д�����鵽�ļ�
    fwrite(&size, sizeof(int), 1, fp);
    for (i = 0; i < size; i++)
    {
        fwrite(&a[i], sizeof(int), 1, fp);
    }
    // �ر��ļ�
    fclose(fp);
    return 0;
}

int Big_data(int** a)
{
    printf("������һ������n��1~20����������n������ݣ�\n");
    int n;
    do
    {
        while (scanf_s("%d", &n) != 1)
        {
            printf("  ��������ʹ������������룡\n");
            clear();
        }
    } while (n < 0 && n > 20);
    n = n * 10000;
    *a = (int*)malloc(n * sizeof(int));
    int i;
    srand(time(NULL));  // �������������Ϊ��ǰʱ��
    for (i = 0; i < n; i++)
    {
        (* a)[i] = rand();  // ���������
    }
    return n;
}

void Big_data_run()
{
    int* a;
    int size = Big_data(&a);
    int max = getMax(a, size);
    savedata(a, size);
    printf("\n�����������������ɣ�\n");
    printf("\n��ѡ�������㷨��\n1.��������\n2.�鲢����\n3.��������\n4.��������\n5.������������\n0.������һ��\n");
    char n;
    do
    {
        n = _getch();
    } while (n < '0' && n > '5');
    while (1)
    {
        int* p = (int*)malloc(size * sizeof(int));
        int i;
        for (i = 0; i < size; i++)
        {
            p[i] = a[i];
        }
        printf("\n");
        n = n - '0';
        switch (n)
        {
        case 0:
            return 0;
            break;
        case 1:
        {
            clock_t start = clock();
            insertSort(p, size);
            clock_t diff = clock();
            printf("�����������������㷨��ʱ��%d ms\n", diff-start);
            break;
        }
        case 2:
        {
            int* temp = (int*)malloc(size * sizeof(int));
            clock_t start = clock();
            MergeSort(p, 0, size - 1, temp);
            clock_t diff = clock();
            printf("���������ϲ������㷨��ʱ��%d ms\n", diff - start);
            free(temp);
            break;
        }
        case 3:
        {
            clock_t start = clock();
            QuickSort_Recursion(p, 0, size - 1);
            clock_t diff = clock();
            printf("�����������������㷨���ݹ�棩��ʱ��%d ms\n", diff - start);
            break;
        }
        case 4:
        {
            clock_t start = clock();
            CountSort(p, size, max);
            clock_t diff = clock();
            printf("�����������������㷨��ʱ��%d ms\n", diff - start);
            break;
        }
        case 5:
        {
            clock_t start = clock();
            RadixCountSort(p, size);
            clock_t diff = clock();
            printf("���������������������㷨��ʱ��%d ms\n", diff - start);
            break;
        }
        }
        free(p);
        do
        {
            n = _getch();
        } while (n < '0' && n > '5');
    }
    free(a);
}

int LargeSmall_data(int** a)
{
    printf("������һ������n��1~5����������n�ٸ����ݣ�\n");
    int n;
    do
    {
        while (scanf_s("%d", &n) != 1)
        {
            printf("  ��������ʹ������������룡\n");
            clear();
        }
    } while (n < 0 && n > 5);
    n = n * 100;
    *a = (int*)malloc(n * sizeof(int));
    int i;
    srand(time(NULL));  // �������������Ϊ��ǰʱ��
    for (i = 0; i < n; i++)
    {
        (*a)[i] = rand() % 100 + 1;  // ���������
    }
    return n;
}


void LargeSmall_data_run()
{
    int* a;
    int size = LargeSmall_data(&a);
    int max = getMax(a, size);
    savedata(a, size);
    printf("\n����С���������������ɣ�\n");
    printf("\n100k������\n��ѡ�������㷨��\n1.��������\n2.�鲢����\n3.��������\n4.��������\n5.������������\n0.������һ��\n");
    char n;
    do
    {
        n = _getch();
    } while (n < '0' && n > '5');
    while (1)
    {
        int* p = (int*)malloc(size * sizeof(int));
        int i;
        for (i = 0; i < size; i++)
        {
            p[i] = a[i];
        }
        printf("\n");
        n = n - '0';
        switch (n)
        {
        case 0:
            return 0;
            break;
        case 1:
        {
            clock_t start = clock();
            for(i=0;i<1000000;i++)
                insertSort(p, size);
            clock_t diff = clock();
            printf("����С���������������㷨��ʱ��%d ms\n", diff - start);
            break;
        }
        case 2:
        {
            int* temp = (int*)malloc(size * sizeof(int));
            clock_t start = clock();
            for (i = 0; i < 1000000; i++)
                MergeSort(p, 0, size - 1, temp);
            clock_t diff = clock();
            printf("����С�������ϲ������㷨��ʱ��%d ms\n", diff - start);
            free(temp);
            break;
        }
        case 3:
        {
            clock_t start = clock();
            for (i = 0; i < 1000000; i++)
                QuickSort_Recursion(p, 0, size - 1);
            clock_t diff = clock();
            printf("����С���������������㷨���ݹ�棩��ʱ��%d ms\n", diff - start);
            break;
        }
        case 4:
        {
            clock_t start = clock();
            for (i = 0; i < 1000000; i++)
                CountSort(p, size, max);
            clock_t diff = clock();
            printf("����С���������������㷨��ʱ��%d ms\n", diff - start);
            break;
        }
        case 5:
        {
            clock_t start = clock();
            for (i = 0; i < 1000000; i++)
                RadixCountSort(p, size);
            clock_t diff = clock();
            printf("����С�������������������㷨��ʱ��%d ms\n", diff - start);
            break;
        }
        }
        free(p);
        do
        {
            n = _getch();
        } while (n < '0' && n > '5');
    }
    free(a);
}

void readdata()
{
    int size=0;
    FILE* fp;
    char filename[100];
    printf("�������ļ�����");
    scanf("%s", filename);
    // ���ļ�
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("�Ҳ����ļ���");
        return 0;
    }
    // ��ȡ�����С
    fread(&size, sizeof(int), 1, fp);
    // ���岢��ʼ������
    int* a;
    int i;
    a = (int*)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        a[i] = 0;
    }
    // ��ȡ��������
    for (i = 0; i < size; i++)
    {
        fread(&a[i], sizeof(int), 1, fp);
    }
    // �ر��ļ�
    fclose(fp);
    int max = getMax(a, size);
    printf("\n�ļ��Ѷ�ȡ��\n");
    printf("\n��ѡ�������㷨��\n1.��������\n2.�鲢����\n3.��������\n4.��������\n5.������������\n0.������һ��\n");
    char n;
    do
    {
        n = _getch();
    } while (n < '0' && n > '5');
    while (1)
    {
        int* p = (int*)malloc(size * sizeof(int));
        int i;
        for (i = 0; i < size; i++)
        {
            p[i] = a[i];
        }
        printf("\n");
        n = n - '0';
        switch (n)
        {
        case 0:
            return 0;
            break;
        case 1:
        {
            clock_t start = clock();
            for(i=0;i<10000;i++)
                insertSort(p, size);
            clock_t diff = clock();
            printf("���������㷨��ʱ��%d ms\n", diff - start);
            break;
        }
        case 2:
        {
            int* temp = (int*)malloc(size * sizeof(int));
            clock_t start = clock();
            for (i = 0; i < 10000; i++)
                MergeSort(p, 0, size - 1, temp);
            clock_t diff = clock();
            printf("�ϲ������㷨��ʱ��%d ms\n", diff - start);
            free(temp);
            break;
        }
        case 3:
        {
            clock_t start = clock();
            for (i = 0; i < 10000; i++)
                QuickSort_Recursion(p, 0, size - 1);
            clock_t diff = clock();
            printf("���������㷨���ݹ�棩��ʱ��%d ms\n", diff - start);
            break;
        }
        case 4:
        {
            clock_t start = clock();
            for (i = 0; i < 10000; i++)
                CountSort(p, size, max);
            clock_t diff = clock();
            printf("���������㷨��ʱ��%d ms\n", diff - start);
            break;
        }
        case 5:
        {
            clock_t start = clock();
            for (i = 0; i < 10000; i++)
                RadixCountSort(p, size);
            clock_t diff = clock();
            printf("�������������㷨��ʱ��%d ms\n", diff - start);
            break;
        }
        }
        free(p);
        do
        {
            n = _getch();
        } while (n < '0' && n > '5');
    }
    free(a);
}