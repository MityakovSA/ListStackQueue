#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


struct Stack
{
	int val;
	Stack* next;
};


int StackAdd(Stack* &st, int val)
{
	Stack* p = new Stack;
	p->val = val;
	if (st == NULL)
	{
		st = p;
		p->next = NULL;
	}
	else
	{
		p->next = st;
		st = p;
	}
	return 0;
}


int StackDel(Stack* &st)
{
	if (st == NULL)
	{
		cout << "Error: stack is empty" << endl;
		return 1;
	}
	st = st->next;
	return 0;
}


int StackGet(Stack* st)
{
	if (st == NULL)
	{
		cout << "Error: stack is empty" << endl;
		return 1;
	}
	cout << st->val << endl;
	return 0;
}


void main()
{
	int n, val;
	string func;
	Stack* st = NULL;
	cout << "Enter commands:" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> func;
		if (func == "add")
		{
			cin >> val;
			StackAdd(st, val);
		}
		else
		{
			if (func == "del")
				StackDel(st);
			if (func == "get")
				StackGet(st);
		}
	}
	system("pause");
}