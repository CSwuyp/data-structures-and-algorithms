// 快速排序.cpp: 定义控制台应用程序的入口点。
//
/*快速排序是由冒泡排序改进而得来的。在冒泡排序过程中，值对相邻的两个记录进行比较，因此每次
交换两个相邻记录时只能消除一个逆序。如果能通过两个（不相邻）记录的一次交换，消除多个逆序，
则会大大加块排序的速度。快速排序方法中的一次交换可能消除多个逆序
【算法分析】
（1）时间复杂度
从快速排序算法的递归树可知，快速排序的趟数取决于递归树的深度。
最好情况O(nlog2n)最坏情况O(n^2),平均情况O(nlog2n)
（2）空间复杂度
快速排序是递归的，执行时需要一个栈来存放相应的数据。最大递归调用次数与递归树的深度一样，
所以做好情况下的空间复杂度为O(log2n),最坏情况下为O(n)
【算法特点】
（1）记录非顺次地移动导致排序方法是不稳定的
（2）排序过程中需要定位表的下界和上界，所以适合用于顺序存储结构，很难用于链式结构。
（3）当n较大时，在平均情况下快速排序是所有内部排序方法中速度最快的一种，所以其适合初始记录
	无序、n较大时的情况*/
#include "stdafx.h"
#include<iostream>
using namespace std;

int Partition(int a[], int low, int high)
{
	a[0] = a[low];//a[0]作为辅助空间
	int key = a[low];
	while (low < high)
	{
		while (low<high&&a[high]>=key)//如果这里没有=（等号）则会陷入死循环
		{
			high--;
		}
		a[low] = a[high];
		while (low < high&&a[low] <= key)//如果这两个内循环中没有low<high则会出现地址越界
		{
			low++;
		}
		a[high] = a[low];
	}
	a[low] = a[0];//最终low与high相等所以改为a[high]=a[0]也是可以的
	return low;
}
void QSort(int a[], int low, int high)
{
	if (low < high)
	{
		int pivotloc = Partition(a, low, high);
		QSort(a, low, pivotloc - 1);//对左子表递归排序
		QSort(a, pivotloc + 1, high);//对柚子表递归排序
	}
}
int main()
{
	int num[] = { 0,4,3,5,4,6,2,22,33,3,4,7,8 };
	int n = sizeof(num) / sizeof(int);
	QSort(num, 1, n-1);
	for (int i = 1; i < n; i++)//因为num[0]作为辅助空间所以输出的下标要从1开始
	{
		cout << num[i] << " ";
	}
    return 0;
}

