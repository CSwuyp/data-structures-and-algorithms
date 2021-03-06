// 归并排序.cpp: 定义控制台应用程序的入口点。
//
/*归并排序（Merging）就是将两个或两个以上的有序表合并成一个有序表的过程
【算法分析】
（1）时间复杂度
当有n个记录时，需进行log2n（向上取整），每一趟归并，其他关键字比较次数不超过n，
元素移动次数都是n，因此，归并排序的时间复杂度为O(nlog2n)
（2）空间复杂度
用顺序表实现归并排序时，需要和待排序记录个数相等的辅助空间，所以空间复杂度为O(n)
【算法特点】
（1）是稳定排序
（2）可用于链式结构，且不需要附加存储空间，但递归实现时仍需要开辟相应的递归工作栈*/
#include "stdafx.h"
#include<iostream>
using namespace std;

void Merge(int num[], int temp[], int low,int mid, int high)
{
	int s1 = low;
	int s2 = mid+1;
	int k = low;
	while (s1 <=mid&&s2 <=high)
	{
		if (num[s1] <= num[s2])
		{
			temp[k++] = num[s1++];
		}
		if (num[s1] >= num[s2])
		{
			temp[k++] = num[s2++];
		}
	}
	while (s1 <= mid)
	{
		temp[k++] = num[s1++];
	}
	while (s2 <= high)
	{
		temp[k++] = num[s2++];
	}
	for (int i = low; i <= high; i++)
	{
		num[i] = temp[i];//更新数组，结束后要记得更新数组
	}
}

void MergeSort(int num[], int temp[], int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int mid = (low + high) / 2;
	MergeSort(num, temp, low, mid);
	MergeSort(num, temp, mid + 1, high);
	Merge(num, temp, low, mid, high);
}
int main()
{
	int num[21] = { 3,4,6,6,4,4,3,43,43,4,34,34,3,456,5,543,3,345,6,43,99 };
	int temp[21];
	MergeSort(num, temp, 0, 20);//注意这里是20 不是21
	for (int i = 0; i < 21; i++)
	{
		//cout << num[i] << " ";
		cout << num[i] << " ";
	}
    return 0;
}

