#include <bits/stdc++.h>
using namespace std;

// singly linked list
// la actualice mucho en la mañana

template <class T>
struct node
{
	T data;
	node *next = NULL;
};

template <class T>
class linkedList
{
public:
	int size = 0;
	node<T> *head = new node<T>();

	bool pushOnEmpty(T val)
	{
		if (size == 0)
		{
			(*head).data = val;
			size++;
			return true;
		}
		return false;
	}

	node *pushFront(T val)
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

	node<T> *insert(node<T> *after, T val)
	{
		if (pushOnEmpty(val))
			return head;
		node<T> *newNode = new node<T>();
		(*newNode).data = val;
		(*newNode).next = (*after).next;
		(*after).next = newNode;
		size++;
		return newNode;
	}

	void pushBack(T val)
	{
		if (pushOnEmpty(val))
			return;
		node<T> *cur = head;
		while ((*cur).next != NULL)
			cur = (*cur).next;
		node<T> *newNode = new node<T>();
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

	void erase(node<T> *x)
	{
		node *cur = head;
		while (cur->next != x)
			cur = cur->next;
		cur->next = x->next;
		delete x;
	}

	void erase(T val)
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
	linkedList<int> *l = new linkedList<int>();
	node<int> *n1 = l->pushFront(1); // O(n)
	l->printList();					 // O(n)

	l->insert(n1, 7);				// O(1)
	l->insert(l->insert(n1, 6), 3); // O(1)
	l->popFront();					//(1)
	l->pushBack(8);					// O(n)
	l->erase(7);
	l->erase(6);

	l->printList(); // O(n)
}