#include <bits/stdc++.h>
using namespace std;

// singly linked list
// la actualice mucho en la mañana

struct node
{
	int data;
	node *next = NULL;
};

class linkedList
{
public:
	int size = 0;
	node *head = new node();

	bool pushOnEmpty(int val)
	{
		if (size == 0)
		{
			(*head).data = val;
			size++;
			return true;
		}
		return false;
	}

	node *pushFront(int val)
	{
		if (pushOnEmpty(val))
			return head;
		node *newNode = new node();
		(*newNode).data = val;
		(*newNode).next = head;
		head = newNode;
		size++;
		return newNode;
	}

	void printList()
	{
		if (size == 0)
		{
			cout << "empty" << '\n';
			return;
		}
		node *cur = head;
		while (cur != NULL)
		{
			cout << (*cur).data << " ";
			cur = (*cur).next;
		}
		cout << '\n';
	}

	node *insert(node *after, int val)
	{
		if (pushOnEmpty(val))
			return head;
		node *newNode = new node();
		(*newNode).data = val;
		(*newNode).next = (*after).next;
		(*after).next = newNode;
		size++;
		return newNode;
	}

	void pushBack(int val)
	{
		if (pushOnEmpty(val))
			return;
		node *cur = head;
		while ((*cur).next != NULL)
			cur = (*cur).next;
		node *newNode = new node();
		(*cur).next = newNode;
		(*newNode).data = val;
	}

	void popFront()
	{
		if (size == 0)
			return;
		node *headPtr = head;
		head = (*head).next;
		size--;
		delete headPtr;
	}

	void erase(node *x)
	{
		node *cur = head;
		while (cur->next != x)
			cur = cur->next;
		cur->next = x->next;
		delete x;
	}

	void erase(int val)
	{
		node *cur = head;
		if (cur->data == val)
		{
			head = cur->next;
			delete cur;
			return;
		}
		while (cur->next->data != val)
			cur = cur->next;
		node *toDel = cur->next;
		cur->next = cur->next->next;
		delete toDel;
		size--;
	}
};

int main()
{
	linkedList *l = new linkedList();
	node *n1 = l->pushFront(1); // O(n)
	l->printList();				// O(n)

	l->insert(n1, 7);				// O(1)
	l->insert(l->insert(n1, 6), 3); // O(1)
	l->popFront();					//(1)
	l->pushBack(8);					// O(n)
	l->erase(7);
	l->erase(6);

	l->printList(); // O(n)

	list<int> linked;
	linked.insert(3);
}