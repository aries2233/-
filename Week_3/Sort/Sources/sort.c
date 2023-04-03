#include "sort.h"
#include "others.h"
#include <stdio.h>
#include <stdlib.h>

//插入排序算法
void insertSort(int* a, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

//归并排序算法
void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
    int i = begin; 
    int j = mid + 1; 
    int k = 0; 
    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++]; // 将左半部分数组的元素放入临时数组中
        }
        else
        {
            temp[k++] = a[j++]; // 将右半部分数组的元素放入临时数组中
        }
    }
    // 将剩余的元素依次放入临时数组中
    while (i <= mid) 
    {
        temp[k++] = a[i++];
    }
    while (j <= end)
    {
        temp[k++] = a[j++];
    }
    // 将临时数组中的元素复制回原数组中
    for (i = 0; i < k; i++)
    {
        a[begin + i] = temp[i];
    }
}

void MergeSort(int* a, int begin, int end, int* temp)
{
    if (begin < end) {
        int mid = (begin + end) / 2; // 计算中间位置

        MergeSort(a, begin, mid, temp); // 对左半部分数组进行递归排序
        MergeSort(a, mid + 1, end, temp); // 对右半部分数组进行递归排序
        MergeArray(a, begin, mid, end, temp); // 合并左右两部分数组
    }
}

//快速排序算法
void QuickSort_Recursion(int* a, int begin, int end)
{
    if (begin < end)
    {
        int i = begin, j = end, p = a[begin];
        while (i < j) {
            while (i < j && a[j] >= p) {
                j--;
            }
            if (i < j) {
                a[i++] = a[j];
            }
            while (i < j && a[i] < p) {
                i++;
            }
            if (i < j) {
                a[j--] = a[i];
            }
        }
        a[i] = p;
        QuickSort_Recursion(a, begin, i - 1);
        QuickSort_Recursion(a, i + 1, end);
    }
}

//计数排序算法
void CountSort(int* a, int size, int max)
{

    int len;
    len = max + 1;
    int* temp;
    temp = (int*)malloc(len * sizeof(int));
    int i;
    for (i = 0; i < len; i++) 
    {
        temp[i] = 0;
    }
    for (i = 0; i < size; i++)
    { 
        temp[a[i]]++;
    }
    for (i = 1; i < len; i++) 
    {
        temp[i] += temp[i - 1];
    }
    int* result;
    result = (int*)malloc(size * sizeof(int));
    for ( i = size - 1; i >= 0; i--) 
    {
        result[temp[a[i]] - 1] = a[i]; // 将元素放入结果数组
        temp[a[i]]--; 
    }
    for (int i = 0; i < size; i++)
    {
        a[i] = result[i]; 
    }
    free(temp);
}

//基数计数排序算法
void RadixCountSort(int* a, int size)
{
    int max = getMax(a, size);
    //遍历每一位
    int exp;
    for (exp = 1; max / exp > 0; exp *= 10)
    {
        int i;
        int count[10] = { 0 };
        int* result;
        result = (int*)malloc(size * sizeof(int));
        // 统计每个数字的出现次数
        for (i = 0; i < size; i++) 
        {
            count[(a[i] / exp) % 10]++;
        }
        // 与计数排序类似
        for (i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        // 根据前缀和进行排序
        for (i = size - 1; i >= 0; i--)
        {
            result[count[(a[i] / exp) % 10] - 1] = a[i];
            count[(a[i] / exp) % 10]--;
        }
        for (i = 0; i < size; i++)
        {
            a[i] = result[i];
        }
    }
}
