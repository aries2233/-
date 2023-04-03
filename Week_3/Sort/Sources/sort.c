#include "sort.h"
#include "others.h"
#include <stdio.h>
#include <stdlib.h>

//���������㷨
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

//�鲢�����㷨
void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
    int i = begin; 
    int j = mid + 1; 
    int k = 0; 
    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++]; // ����벿�������Ԫ�ط�����ʱ������
        }
        else
        {
            temp[k++] = a[j++]; // ���Ұ벿�������Ԫ�ط�����ʱ������
        }
    }
    // ��ʣ���Ԫ�����η�����ʱ������
    while (i <= mid) 
    {
        temp[k++] = a[i++];
    }
    while (j <= end)
    {
        temp[k++] = a[j++];
    }
    // ����ʱ�����е�Ԫ�ظ��ƻ�ԭ������
    for (i = 0; i < k; i++)
    {
        a[begin + i] = temp[i];
    }
}

void MergeSort(int* a, int begin, int end, int* temp)
{
    if (begin < end) {
        int mid = (begin + end) / 2; // �����м�λ��

        MergeSort(a, begin, mid, temp); // ����벿��������еݹ�����
        MergeSort(a, mid + 1, end, temp); // ���Ұ벿��������еݹ�����
        MergeArray(a, begin, mid, end, temp); // �ϲ���������������
    }
}

//���������㷨
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

//���������㷨
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
        result[temp[a[i]] - 1] = a[i]; // ��Ԫ�ط���������
        temp[a[i]]--; 
    }
    for (int i = 0; i < size; i++)
    {
        a[i] = result[i]; 
    }
    free(temp);
}

//�������������㷨
void RadixCountSort(int* a, int size)
{
    int max = getMax(a, size);
    //����ÿһλ
    int exp;
    for (exp = 1; max / exp > 0; exp *= 10)
    {
        int i;
        int count[10] = { 0 };
        int* result;
        result = (int*)malloc(size * sizeof(int));
        // ͳ��ÿ�����ֵĳ��ִ���
        for (i = 0; i < size; i++) 
        {
            count[(a[i] / exp) % 10]++;
        }
        // �������������
        for (i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        // ����ǰ׺�ͽ�������
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
