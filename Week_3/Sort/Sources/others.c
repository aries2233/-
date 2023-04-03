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
    // 获取当前时间
    time(&t);
    localtime_s(&tm_info, & t);
    // 创建文件名
    sprintf(filename, "data_%04d%02d%02d_%02d%02d%02d.txt", tm_info.tm_year + 1900, tm_info.tm_mon + 1, tm_info.tm_mday, tm_info.tm_hour, tm_info.tm_min, tm_info.tm_sec);
    // 打开文件
    FILE* fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("创建文件失败！\n");
        return 1;
    }
    // 写入数组到文件
    fwrite(&size, sizeof(int), 1, fp);
    for (i = 0; i < size; i++)
    {
        fwrite(&a[i], sizeof(int), 1, fp);
    }
    // 关闭文件
    fclose(fp);
    return 0;
}

int Big_data(int** a)
{
    printf("请输入一个数字n（1~20），以生成n万个数据！\n");
    int n;
    do
    {
        while (scanf_s("%d", &n) != 1)
        {
            printf("  输入的类型错误，请重新输入！\n");
            clear();
        }
    } while (n < 0 && n > 20);
    n = n * 10000;
    *a = (int*)malloc(n * sizeof(int));
    int i;
    srand(time(NULL));  // 设置随机数种子为当前时间
    for (i = 0; i < n; i++)
    {
        (* a)[i] = rand();  // 生成随机数
    }
    return n;
}

void Big_data_run()
{
    int* a;
    int size = Big_data(&a);
    int max = getMax(a, size);
    savedata(a, size);
    printf("\n大数据量数组已生成！\n");
    printf("\n请选择排序算法：\n1.插入排序\n2.归并排序\n3.快速排序\n4.计数排序\n5.基数计数排序\n0.返回上一级\n");
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
            printf("大数据量插入排序算法用时：%d ms\n", diff-start);
            break;
        }
        case 2:
        {
            int* temp = (int*)malloc(size * sizeof(int));
            clock_t start = clock();
            MergeSort(p, 0, size - 1, temp);
            clock_t diff = clock();
            printf("大数据量合并排序算法用时：%d ms\n", diff - start);
            free(temp);
            break;
        }
        case 3:
        {
            clock_t start = clock();
            QuickSort_Recursion(p, 0, size - 1);
            clock_t diff = clock();
            printf("大数据量快速排序算法（递归版）用时：%d ms\n", diff - start);
            break;
        }
        case 4:
        {
            clock_t start = clock();
            CountSort(p, size, max);
            clock_t diff = clock();
            printf("大数据量计数排序算法用时：%d ms\n", diff - start);
            break;
        }
        case 5:
        {
            clock_t start = clock();
            RadixCountSort(p, size);
            clock_t diff = clock();
            printf("大数据量基数计数排序算法用时：%d ms\n", diff - start);
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
    printf("请输入一个数字n（1~5），以生成n百个数据！\n");
    int n;
    do
    {
        while (scanf_s("%d", &n) != 1)
        {
            printf("  输入的类型错误，请重新输入！\n");
            clear();
        }
    } while (n < 0 && n > 5);
    n = n * 100;
    *a = (int*)malloc(n * sizeof(int));
    int i;
    srand(time(NULL));  // 设置随机数种子为当前时间
    for (i = 0; i < n; i++)
    {
        (*a)[i] = rand() % 100 + 1;  // 生成随机数
    }
    return n;
}


void LargeSmall_data_run()
{
    int* a;
    int size = LargeSmall_data(&a);
    int max = getMax(a, size);
    savedata(a, size);
    printf("\n大量小数据量数组已生成！\n");
    printf("\n100k次排序\n请选择排序算法：\n1.插入排序\n2.归并排序\n3.快速排序\n4.计数排序\n5.基数计数排序\n0.返回上一级\n");
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
            printf("大量小数据量插入排序算法用时：%d ms\n", diff - start);
            break;
        }
        case 2:
        {
            int* temp = (int*)malloc(size * sizeof(int));
            clock_t start = clock();
            for (i = 0; i < 1000000; i++)
                MergeSort(p, 0, size - 1, temp);
            clock_t diff = clock();
            printf("大量小数据量合并排序算法用时：%d ms\n", diff - start);
            free(temp);
            break;
        }
        case 3:
        {
            clock_t start = clock();
            for (i = 0; i < 1000000; i++)
                QuickSort_Recursion(p, 0, size - 1);
            clock_t diff = clock();
            printf("大量小数据量快速排序算法（递归版）用时：%d ms\n", diff - start);
            break;
        }
        case 4:
        {
            clock_t start = clock();
            for (i = 0; i < 1000000; i++)
                CountSort(p, size, max);
            clock_t diff = clock();
            printf("大量小数据量计数排序算法用时：%d ms\n", diff - start);
            break;
        }
        case 5:
        {
            clock_t start = clock();
            for (i = 0; i < 1000000; i++)
                RadixCountSort(p, size);
            clock_t diff = clock();
            printf("大量小数据量基数计数排序算法用时：%d ms\n", diff - start);
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
    printf("请输入文件名：");
    scanf("%s", filename);
    // 打开文件
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("找不到文件！");
        return 0;
    }
    // 读取数组大小
    fread(&size, sizeof(int), 1, fp);
    // 定义并初始化数组
    int* a;
    int i;
    a = (int*)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        a[i] = 0;
    }
    // 读取数组数据
    for (i = 0; i < size; i++)
    {
        fread(&a[i], sizeof(int), 1, fp);
    }
    // 关闭文件
    fclose(fp);
    int max = getMax(a, size);
    printf("\n文件已读取！\n");
    printf("\n请选择排序算法：\n1.插入排序\n2.归并排序\n3.快速排序\n4.计数排序\n5.基数计数排序\n0.返回上一级\n");
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
            printf("插入排序算法用时：%d ms\n", diff - start);
            break;
        }
        case 2:
        {
            int* temp = (int*)malloc(size * sizeof(int));
            clock_t start = clock();
            for (i = 0; i < 10000; i++)
                MergeSort(p, 0, size - 1, temp);
            clock_t diff = clock();
            printf("合并排序算法用时：%d ms\n", diff - start);
            free(temp);
            break;
        }
        case 3:
        {
            clock_t start = clock();
            for (i = 0; i < 10000; i++)
                QuickSort_Recursion(p, 0, size - 1);
            clock_t diff = clock();
            printf("快速排序算法（递归版）用时：%d ms\n", diff - start);
            break;
        }
        case 4:
        {
            clock_t start = clock();
            for (i = 0; i < 10000; i++)
                CountSort(p, size, max);
            clock_t diff = clock();
            printf("计数排序算法用时：%d ms\n", diff - start);
            break;
        }
        case 5:
        {
            clock_t start = clock();
            for (i = 0; i < 10000; i++)
                RadixCountSort(p, size);
            clock_t diff = clock();
            printf("基数计数排序算法用时：%d ms\n", diff - start);
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