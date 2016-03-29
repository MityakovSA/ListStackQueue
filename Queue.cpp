#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


struct Queue
{
	int val;
	Queue* next;
};


struct DynQueue
{
	Queue* head;
	Queue* tail;
};


void ConstructQueue(DynQueue &DQ)
{
	DQ.head = NULL;
}


bool CheckEmpty(DynQueue &DQ)
{
	return (DQ.head == NULL);
}


int Enqueue(DynQueue &DQ, int val)
{
	Queue* q = new Queue;
	q->val = val;
	q->next = NULL;
	if (CheckEmpty(DQ))
	{
		DQ.head = q;
		DQ.tail = q;
	}
	else
	{
		DQ.tail->next = q;
		DQ.tail = q;
	}
	return 0;
}


int Dequeue(DynQueue &DQ)
{
	if (CheckEmpty(DQ))
	{
		cout << "Error: queue is empty" << endl;
		return 1;
	}
	DQ.head = DQ.head->next;
	return 0;
}


int QueueGet(DynQueue &DQ)
{
	if (CheckEmpty(DQ))
	{
		cout << "Error: queue is empty" << endl;
		return 1;
	}
	cout << DQ.head->val << endl;
	return 0;
}


void main()
{
	int n, val;
	string func;
	DynQueue DQueue;
	ConstructQueue(DQueue);
	cout << "Enter commands:" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> func;
		if (func == "add")
		{
			cin >> val;
			Enqueue(DQueue, val);
		}
		else
		{
			if (func == "del")
				Dequeue(DQueue);
			if (func == "get")
				QueueGet(DQueue);
		}
	}
	system("pause");
}