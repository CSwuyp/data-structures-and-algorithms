// 反转链表.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cassert>
using namespace std;
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node,*PNode;
typedef struct
{
	PNode first;
	PNode last;
	int size;
}List;

void InitList(List *list)
{
	list->first = list->last = new Node;
	assert(list != NULL);
	list->first->next = NULL;
	list->size = 0;
}

void push_back(List *list, ElemType x)
{
	PNode s = new Node;
	assert(s != NULL);
	s->data = x;
	s->next = NULL;

	list->last->next = s;
	list->last = s;
	//list->last->next = NULL;因为前面有了s->next = NULL;这里就不需要了
	list->size++;
}

void display(List *list)
{
	Node *p = list->first->next;
	while (p != NULL)
	{
		cout << p->data << "->";
		p = p->next;
	}
	cout << " Nul"<<endl;
}

void resver(List *list)
{
	PNode p, q, temp;
	p=list->first->next;
	q = NULL;
	list->first->next = NULL;
	if (p)
	{
		list->last = p;
	}
	while (p)
	{
		temp = p->next;//保存节点
		p->next = q;//断开链表
		q = p;//向前移动节点
		p = temp;
	}
	list->first->next = q;//first是不存放数据的但是last是有存放数据的
}
int main()
{
	List mylist;
	int x;
	InitList(&mylist);
	cout << "请输入单链表的数据：";
	while (cin >> x,x!=-1)
	{
		push_back(&mylist,x);
	}
	display(&mylist);
	cout << "反转单链表：" << endl;
	resver(&mylist);
	display(&mylist);
	return 0;
}