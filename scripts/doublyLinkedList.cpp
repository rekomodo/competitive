#include <iostream>
using namespace std;

// doubly linked list

struct node {
	int data;
	node *next = NULL;
	node *prev = NULL;
};

class linkedList {
	int size = 0;
	node* head = new node();
	node* tail = head;

	private:
	node* addBetween(node* n1, node* n2, int val){
		node* newNode = new node();
		newNode->data = val;
		newNode->next = n2;
		newNode->prev = n1;
		if(n1 != NULL) n1->next = newNode;
		if(n1 == tail) tail = newNode;
		if(n2 != NULL) n2->prev = newNode;
		if(n2 == head) head = newNode;
		return newNode;
	}

	bool pushOnEmpty(int val) {
		if (size == 0) {
			(*head).data = val;
			size++;
			return true;
		}
		return false;
	}

	public:

	node* getHead() {return head;}
	node* getTail() {return tail;}
	int size() {return size;}
	bool empty() {return size == 0;}

	node* pushFront(int val) {
		if (pushOnEmpty(val)) return head;
		node *newNode = new node();
		newNode->data = val;
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		size++;
		return newNode;
	}

	node* pushBack(int val) {
		if (pushOnEmpty(val)) return head;
		node *newNode = new node();
		newNode->data = val;
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
		size++;
		return newNode;
	}

	void printList() {
		if (size == 0) {
			cout << "empty" << '\n';
			return;
		}
		node *cur = head;
		while (cur != NULL) {
			cout << (*cur).data << " ";
			cur = (*cur).next;
		}
		cout << '\n';
	}

	node* insertAfter(node *after, int val) {
		if (pushOnEmpty(val)) return head;
		node* newNode = addBetween(after, after->next, val);
		size++;
		return newNode;
	}

	node* insertBefore(node *before, int val) {
		if (pushOnEmpty(val)) return head;
		node* newNode = addBetween(before->prev, before, val);
		size++;
		return newNode;
	}

	void popFront() {
		if (size == 0) return;
		node *headPtr = head;
		head = (*head).next;
		if(size == 1){
			head = new node();
			tail = head;
		}
		size--;
		delete headPtr;
	}

	void popBack() {
		if (size == 0) return;
		node *tailPtr = tail;
		tail = tail->prev;
		if(size == 1){
			head = new node();
			tail = head;
		}
		size--;
		delete tailPtr;
	}

	void remove(node* n){
		node* prev = n->prev;
		node* next = n->next;
		if(prev != NULL) prev->next = next;
		if(next != NULL) next->prev = prev;
		delete n;
	}

	void changeValue(node* n, int val){
		n->data = val;
	}
};

int main() {
	linkedList l1;
	node *n1 = l1.pushFront(1); // O(1)
	l1.insertAfter(n1, 7);              // O(1)
	l1.insertAfter(l1.insertAfter(n1, 6), 3); // O(1)
	l1.popFront();                 //(1)
	l1.pushBack(8);                // O(1)
	cout << "l1 "; l1.printList(); // O(n)

	linkedList l2;
	l2.pushBack(5);
	node *n2 = l2.pushFront(3);
	l2.pushBack(7);
	l2.insertBefore(n2, 1);
	l2.remove(n2);
	cout << "l2 "; l2.printList();

	linkedList l3;
	l3.insertBefore(l3.getHead(), 1);
	l3.insertAfter(l3.getTail(), 2);
	cout << "l3 "; l3.printList();
}