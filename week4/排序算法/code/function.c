#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include "head.h"

//函数具体操作
void insertSort(int *a,int n)
{
    int i, j, temp;
    for(i = 1; i < n; i++)
    {
        temp = a[i];
        for(j = i - 1; j >= 0 && a[j] > temp; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    int k = begin;
    int left_begin = begin, left_end = mid;
    int right_begin = mid + 1, right_end = end;

    while(left_begin <= left_end && right_begin <= right_end)
    {
        if(a[left_begin] < a[right_begin])
        {
            temp[k++] = a[left_begin++];
        }
        else
        {
            temp[k++] = a[right_begin++];
        }
    }

    while(left_begin <= left_end)
    {
        temp[k++] = a[left_begin++];
    }
    while(right_begin <= right_end)
    {
        temp[k++] = a[right_begin++];
    }

    for(k = begin; k <= end; k++)
    {
        a[k] = temp[k];
    }
}

void MergeSort(int *a,int begin,int end,int *temp)
{
    if(begin >= end)
    {
        return;
    }
    else
    {
        int mid = (begin + end) / 2;
        MergeSort(a, begin, mid, temp);
        MergeSort(a, mid + 1, end, temp);
        MergeArray(a, begin, mid, end, temp);
    }
}

void QuickSort_Recursion(int *a, int begin, int end)
{
    int i = begin, j = end;
    int temp;
    int pivot = a[begin]; //选取第一个元素为基准点
    
    while(i <= j)
    {
        //找到左边大于基准点的元素
        while(a[i] < pivot)
        {
            i++;
        }
        //找到右边小于基准点的元素
        while(a[j] > pivot)
        {
            j--;
        }

        //当左边下标小于右边时，互换元素
        if(i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            //互换后i, j继续靠近
            i++;
            j--;
        }
    }

    //左边进行递归
    if(i < end)
    {
        QuickSort_Recursion(a, i, end);
    }
    //右边进行递归
    if(begin < j)
    {
        QuickSort_Recursion(a, begin, j);
    }
}

int PartitionQuickSort(int *a, int begin, int end)
{
    int i = begin, j = end;
    int temp;
    int pivot = NumberOfThree(a, begin, end); //三数取中作为基准元素
    
    while(i <= j)
    {
        //找到左边大于基准点的元素
        while(a[i] < pivot)
        {
            i++;
        }
        //找到右边小于基准点的元素
        while(a[j] > pivot)
        {
            j--;
        }

        //当左边下标小于右边时，互换元素
        if(i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            //互换后i, j继续靠近
            i++;
            j--;
        }
    }

    //左边进行递归
    if(i < end)
    {
        QuickSort_Recursion(a, i, end);
    }
    //右边进行递归
    if(begin < j)
    {
        QuickSort_Recursion(a, begin, j);
    }
}

int NumberOfThree(int *arr,int begin,int end)
{
	int mid = (begin + end) / 2 + begin;
 
	if (arr[mid] > arr[end])
	{
		Swap(&arr[mid], &arr[end]);
	}
	if (arr[begin] > arr[end])
	{
		Swap(&arr[begin], &arr[end]);
	}
	if (arr[mid] > arr[begin]) 
	{
		Swap(&arr[mid], &arr[begin]);
	}
	//此时arr[mid] <= arr[begin] <= arr[end]
	return arr[begin];
}

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void CountSort(int *a, int size , int max)
{
    int i;
    int *count, *sorted;
    
    //给计数器和已排序数组分配空间
    count = (int *)malloc(sizeof(int) * (max + 1));
    sorted = (int *)malloc(sizeof(int) * size);
    if(count == NULL || sorted == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(0);
    }
    
    //计数数组初始化为0
    for(i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    //收集原数组中每种值的个数
    for(i = 0; i < size; i++)
    {
        count[a[i]]++;
    }
    //统计所有小于等于该值的元素个数
    for(i = 1; i < max + 1; i++)
    {
        count[i] += count[i - 1];
    }
    //将所有元素按收集表分配到对应位置，反向填充目标数组
    for(i = size - 1; i >= 0; i--)
    {
        //先将计数数组中对应值-1
        count[a[i]]--;
        sorted[count[a[i]]] = a[i];
    }
    //已排序数组替代原数组
    for(i = 0; i < size; i++)
    {
        a[i] = sorted[i];
    }

    //释放内存
    free(count);
    free(sorted);
}

/* void RadixCountSort(int *a,int size)
{
    int base = 10; //基数设为10
    int i, n, index, max, maxnum, pval;
    int *count, *sorted;
    
    //计算数组中的最大值
    max = arrayMax(a, size);
    //计算数据最高位
    maxnum = getDigitNum(max);
    
    //给计数器和已排序数组分配空间
    count = (int *)malloc(sizeof(int) * base); 
    sorted = (int *)malloc(sizeof(int) * size);
    if(count == NULL || sorted == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(0);
    }

    for(n = 0; n < maxnum; n++)
    {
        //计数数组初始化为0
        for(i = 0; i < base; i++)
        {
            count[i] = 0;
        }
        //计算位置值
        pval = pow(base, n);
        //统计当前位上每个数值出现的次数
        for(i = 0; i < size; i++)
        {
            index = a[i] / pval % base;
            count[index]++;
        }
        //统计所有小于等于该值的元素个数
        for(i = 1; i < base; i++)
        {
            count[i] += count[i - 1];
        }
        //将所有元素按收集表分配到对应位置
        for(i = size - 1; i >= 0; i--)
        {
            index = a[i] / pval % base;
            count[index]--;
            sorted[count[index]] = a[i];
        }
        //已排序数组替代原数组
        for(i = 0; i < size; i++)
        {
            a[i] = sorted[i];
        }
    }

    //释放内存
    free(count);
    free(sorted);
} */

//优化后的基数排序
void RadixCountSort(int *a,int size)
{
    int i, index, max;
    int rad = 1; //从个位开始
    int *count, *sorted;
    
    //计算数组中的最大值
    max = arrayMax(a, size);
    
    //给计数器和已排序数组分配空间
    count = (int *)malloc(sizeof(int) * 10); 
    sorted = (int *)malloc(sizeof(int) * size);
    if(count == NULL || sorted == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(0);
    }

    while(max / rad > 0)
    {
        //计数数组初始化为0
        for(i = 0; i < 10; i++)
        {
            count[i] = 0;
        }
        //统计当前位上每个数值出现的次数
        for(i = 0; i < size; i++)
        {
            index = a[i] / rad % 10;
            count[index]++;
        }
        //统计所有小于等于该值的元素个数
        for(i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        //将所有元素按收集表分配到对应位置
        for(i = size - 1; i >= 0; i--)
        {
            index = a[i] / rad % 10;
            count[index]--;
            sorted[count[index]] = a[i];
        }
        //已排序数组替代原数组
        for(i = 0; i < size; i++)
        {
            a[i] = sorted[i];
        }
        rad *= 10; //位数乘10
    }

    //释放内存
    free(count);
    free(sorted);
}

int arrayMax(int *arr, int size)
{
    int i, max = arr[0];
    for(i = 0; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int getDigitNum(int x)
{
    if(x == 0)
    {
        return 1;
    }
    else
    {
        int res;//数据最高位
        while(x != 0)
        {
            x /= 10;
            res++;
        }
        return res;
    }
}

void ColorSort(int *a, int size)
{
    int p, p0, p2;
    p = 0;
    p0 = 0;
    p2 = size - 1;
    for( ; p < p2; )
    {
        if(a[p] == 2)
        {
            Swap(&a[p], &a[p2]);
            p2--;
        }
        else if(a[p] == 0)
        {
            Swap(&a[p], &a[p0]);
            p0++;
            p++;
        }
        else
        {
            p++;
        }
    }
}

int FindKNum(int *a, int n, int k)
{
    if(k <= 0 || k > n)
    {
        return -1;
    }
    int left = 0, right = n - 1;
    int index;
    k = n - k + 1;
    while(left <= right)
    {
        index = Partition(a, left, right);
        if(index == k - 1)
        {
            return a[index];
        }
        else if(index < k - 1)
        {
            left = index + 1;
        }
        else
        {
            right = index - 1;
        }
    }
}

int Partition(int *a, int left, int right)
{
    int mid = (left + right) / 2;
    Swap(&a[mid], &a[right]);
    int p = left, i;
    for(i = left; i < right; i++)
    {
        if(a[i] < a[right])
        {
            if(i > p)
            {
                Swap(&a[i], &a[p]);
            }
            ++p;
        }
    }
    Swap(&a[p], &a[right]);
    return p;
}