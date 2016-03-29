#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


struct List
{
	int val;
	List* next;
};


struct DynList
{
	List* head;
	int n;
};


void ConstructList(DynList &DL)
{
	DL.head = NULL;
	DL.n = 0;
}


bool CheckEmpty(DynList DL)
{
	return (DL.head == NULL);
}


int ListAdd(DynList &DL, int ind, int val)
{
	if (ind > DL.n)
	{
		cout << "Error with index of command 'add'" << endl;
		return 1;
	}
	List* p = DL.head;
	List* l = new List;
	l->val = val;
	if (CheckEmpty(DL))
	{
		l->next = NULL;
		DL.head = l;
		DL.n = 1;
	}
	else
	{
		if (ind == 0)
		{
			l->next = DL.head;
			DL.head = l;
			DL.n += 1;
		}
		else
		{
			for (int i = 1; i < ind; i++)
				p = p->next;
			l->next = p->next;
			p->next = l;
			DL.n += 1;
		}
	}
	return 0;
}


int ListDel(DynList &DL, int ind)
{
	if (CheckEmpty(DL))
	{
		cout << "Error: list is empty" << endl;
		return 1;
	}
	if (ind > (DL.n - 1))
	{
		cout << "Error with index of command 'del'" << endl;
		return 1;
	}
	List* p = DL.head;
	if (ind == 0)
	{
		DL.head = DL.head->next;
		DL.n -= 1;
	}
	else
	{
		for (int i = 1; i < ind; i++)
			p = p->next;
		p->next = p->next->next;
		DL.n -= 1;
	}
	return 0;
}


int ListGet(DynList &DL, int ind)
{
	List* p = DL.head;
	if (CheckEmpty(DL))
	{
		cout << "Error: list is empty" << endl;
		return 1;
	}
	if (ind > (DL.n - 1))
	{
		cout << "Error with index of command 'get'" << endl;
		return 1;
	}
	for (int i = 0; i < ind; i++)
		p = p->next;
	cout << p->val << endl;
	return 0;
}


void main()
{
	int n, ind, val;
	string func;
	DynList DList;
	ConstructList(DList);
	cout << "Enter commands:" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> func;
		if (func == "add")
		{
			cin >> ind >> val;
			ListAdd(DList, ind, val);
		}
		else
		{
			cin >> ind;
			if (func == "del")
				ListDel(DList, ind);
			if (func == "get")
				ListGet(DList, ind);
		}
	}
	system("pause");
}