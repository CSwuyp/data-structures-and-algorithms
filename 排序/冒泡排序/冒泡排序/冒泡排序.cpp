// 冒泡排序.cpp: 定义控制台应用程序的入口点。
//
/*冒泡排序（Bubble Sort）是一种最简单的交换排序的方法，它通过两两比较相邻记录的关键字，
如果发生逆序，则进行交换，从而使关键字小的记录如气泡一般逐渐往上“漂浮”（左移）或者使
关键字大的记录如石块一样逐渐往下“坠落”（右移）
【算法思想】
（1）时间复杂度
最好O(n),最坏O(n^2)平均O(n^2)
（2）空间复杂度
冒泡排序只有两个记录交换位置时需要一个辅助空间用做暂存记录，所以空间复杂度为O(1)
【算法特点】
（1）是稳定的。
（2）可用于链式存储结构
（3）移动记录次数较多，算法平均时间性能比直接插入排序差。当初始记录无序，n较大时，
此算法不易采用*/
#include "stdafx.h"
#include<iostream>
using namespace std;

void BubbleSort(int a[], int n)
{
	int flag = 1;
	while (n > 0 && flag == 1)
	{
		flag = 0;
		for (int j = 0; j <= n-2; j++)//因为循环内用到了a[j+1]所以j最大值只能到j+2
		{
			if (a[j] > a[j + 1])
			{
				flag = 1;
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
		n--;
	}
}
int main()
{
	int num[] = { 2,3,6,77,5,4,3,2,8 };
	int n = sizeof(num) / sizeof(int);
	BubbleSort(num, n);
	for (int i = 0; i < n; i++)
	{
		cout << num[i] << " ";
	}
    return 0;
}

