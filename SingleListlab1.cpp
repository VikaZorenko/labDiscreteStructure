#include <stdio.h>
#include <iostream>
using namespace std;

struct SingleNode {
	SingleNode *next;
	int val;
};

class SingleLinkedList {
	public:
		SingleNode *start;
		int size;
		int pos;
	public:
		SingleLinkedList() {
			this->start = NULL;
			this->size = 0; 
		}
		void addNode(int v);
		void sort();
		void del(int pos);
		void printList();
		void insert(int pos, int v);
	public:
		void swap(SingleNode *a, SingleNode *b);
		~SingleLinkedList() {}
};

void SingleLinkedList::addNode(int v) {
	if (this->start == NULL) {
		this->start = new SingleNode();
		this->start->next = NULL;
		this->start->val = v;
		size++;
		pos = size;
		return;
	}
	SingleNode *node = this->start;
	while (node->next != NULL) {
		node = node->next;
	}
	node->next = new SingleNode();
	node->next->next = NULL;
	node->next->val = v;
	size++;
	pos = size;
}

void SingleLinkedList::printList() {
	SingleNode *node = this->start;
	while (node != NULL) {
		printf("%d ", node->val);
		node = node->next;
	}
	printf("\n");
}

void SingleLinkedList::swap(SingleNode *a, SingleNode *b) {
	SingleNode *preA = this->start;
	SingleNode *preB = this->start;
	if (a == this->start) {
		while (preB != NULL && preB->next != b) {
			preB = preB->next;
		}
		this->start = b;
		preB->next = a;
		SingleNode *tmp = b->next;
		b->next = a->next;
		a->next = tmp;
		return;
	}
	if (b == this->start) {
		while (preA != NULL && preA->next != a) {
			preA = preA->next;
		}
		this->start = a;
		preB->next = b;
		SingleNode *tmp = b->next;
		b->next = a->next;
		a->next = tmp;
		return;
	}
	while (preA != NULL && preA->next != a) {
		preA = preA->next;
	}
	while (preB != NULL && preB->next != b) {
		preB = preB->next;
	}
	if (preA == NULL || preB == NULL) {
		return;
	}
	preA->next = b;
	preB->next = a;
	SingleNode *tmp = b->next;
	b->next = a->next;
	a->next = tmp;
}

void SingleLinkedList::sort() {
	SingleNode *i = this->start->next;
	SingleNode *preI = this->start;
	while (i != NULL) {
		if (preI->val > i->val) {
			this->swap(i, preI);
			i = start;
		};
		preI = i;
		i = i->next;
	}
}

void SingleLinkedList::del(int pos) {
	SingleNode *tmp = new SingleNode;
	SingleNode *node = this->start;
	int count = 0;
	if (this->start == NULL) {
		cout << "error, no list\n";
		return;
	}
	if (pos == 0) {
		tmp = node;
		this->start = node->next;
		size--;
		delete tmp;
		return;
	}
	if (pos > size || pos < 0) {
		cout << "error, wrong pos, no el for delete\n";
		return;
	}
	while(count != pos-1) {
		node = node->next;
		count++;
	}
		tmp = node->next;
		node->next= tmp->next;
		size--;
		delete tmp;
}

void SingleLinkedList::insert(int pos, int v) {
	SingleNode *tmp = new SingleNode;
	tmp->val = v; 
	int count = 0;
	SingleNode *el = this->start;
	if (pos > size || pos < 0) {
		cout << "error, wrong pos\n";
		return;
	}
	if (pos == 0) {
		this->start = tmp;
		tmp->next = el;
	} else {
		while(count != pos-1) {
			el = el->next;
			count++;
		}
		tmp->next = el->next;
		el->next = tmp;
	}
	size++;
}

int main() {
  SingleLinkedList slist;
  slist.addNode(1);
  slist.addNode(-3);
  slist.printList();
  slist.sort();
  slist.printList();
  slist.del(0);
  slist.del(0);
  slist.del(0);
  slist.del(0);
  slist.del(0);
  slist.printList();
  slist.insert(4,100);
  slist.printList();
  }