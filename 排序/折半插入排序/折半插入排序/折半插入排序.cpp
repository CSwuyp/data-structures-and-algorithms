// 折半插入排序.cpp: 定义控制台应用程序的入口点。
//
/*算法分析：
（1）时间复杂度
	从时间上比较，折半查找比顺序查找快，所以就平均性能来说，折半插入排序优于直接插入排序
折半插入排序所需的关键字比较次数与待排序序列的初始排列无关，仅依赖于记录的个数。
不论初始序列情况如何，在插入第i个记录时，需要经过log2i+1（向下取整加1）次比较，
才能确定它应该插入的位置。所以当记录的初始序列为正序或接近正序时，直接插入排序
比折半插入排序执行的关键字比较次数要少
	折半插入排序的对象移动次数与直接插入排序相同，依赖于对象的初始排序。
	在平均情况下，折半插入排序仅减少关键字的比较次数，而记录的移动次数不变。
	因此，折半插入排序的时间复杂度仍为O(n^2)

(2)空间复杂度
	折半插入排序所需附加存储空间和直接插入排序相同，只需要一个记录的辅助空间r[0]，
所以空间复杂度为O(1)
【算法特点】
（1）是稳定排序
（2）因为要进行折半查找，所以只能用于顺序存储结构，不能用于链式存储结构。
（3）适合初始记录无序，n较大时的情况
*/
#include "stdafx.h"
#include<iostream>
using namespace std;
void BInsertSort(int a[], int n)
{
	for (int i = 2; i < n; i++)
	{
		a[0] = a[i];//a[0]作为辅助空间
		int low = 1;
		int high = i - 1;//注意这里是从i-1开始，因为此时已经排好序的元素个数是i-1个
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (a[0] >= a[mid])
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
		for (int j = i - 1; j >=high + 1; j--)//已经排好序的下标最高是i-1，从i-1开始依次往后移动元素,最后一位是high+1,即把high+1后移一位
		{
			a[j + 1] = a[j];
		}
		a[high + 1] = a[0];
	}
}
int main()
{
	int num[] = { 0,3,4,6,78,8,5,4,3,7,8 };//0下标作为辅助空间
	int n = sizeof(num) / sizeof(int);
	BInsertSort(num, n);
	for (int i = 1; i < n; i++)//下标从1开始
	{
		cout << num[i] << " ";
	}
    return 0;
}

