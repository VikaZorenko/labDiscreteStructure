#include <stdio.h>
#include <iostream>
using namespace std;

struct DoubleNode {
	DoubleNode *next, *prev;
	int val;
};

class DoubleLinkedList {
	public:
		DoubleNode *start;
		DoubleNode *end;
		int size;
		int pos;
	public:
		DoubleLinkedList() {
			this->start = NULL;
			this->end = NULL;
			this->size = 0; 
		}
		void addNode(int v);
		void del(int pos);
		void printList();
		void insert(int pos, int v);
    DoubleNode *mergeHelper(DoubleNode *head);
    DoubleNode *split(DoubleNode *head);
	public:
		~DoubleLinkedList() {}
    void mergeSort();
};

DoubleNode *merge(DoubleNode *first, DoubleNode *second) {
    // If first linked list is empty
    if (!first) {
        return second;
    }
 
    // If second linked list is empty
    if (!second) {
        return first;
    }
 
    // Pick the smaller value
    if (first->val < second->val) {
        first->next = merge(first->next,second); //викликаємо цю саму функцію для наступного елементу
        first->next->prev = first; // для наступного за фірст елементом в попереднє записуємо фірст
        first->prev = NULL; // для фірста записуємо в попереднє нал
        return first;
    } else {
        second->next = merge(first,second->next); // викликаємо цю саму функцію для наступного елементу але іншого списку
        second->next->prev = second; // для наступного за секонд елементом в попереднє записуємо секонд
        second->prev = NULL; //для секонда записуємо в попереднє нал
        return second;
    }
}

DoubleNode *DoubleLinkedList::split(DoubleNode *head) // ділимо список навпіл
{
    DoubleNode *fast = head,*slow = head;
    while (fast->next && fast->next->next) // поки є список робимо ділення
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    DoubleNode *temp = slow->next;
    slow->next = NULL;
    return temp;
}

DoubleNode *DoubleLinkedList::mergeHelper(DoubleNode *head)
{
    if (!head || !head->next) // якщо не існує списку повертаємо пустоту
        return head;

    DoubleNode *second = split(head);
 
    // рекурсією викликаємо для лівої і правої половини
    head = this->mergeHelper(head);
    second = this->mergeHelper(second);
 
    // зливаємо два списка
    return merge(head,second);
}

void DoubleLinkedList::mergeSort() {
  this->mergeHelper(this->start);
}

void DoubleLinkedList::addNode(int v) {
	if (this->start == NULL) {
		this->start = new DoubleNode();
		this->start->next = NULL;
		this->start->prev = NULL;
		this->start->val = v;
		size++;
		pos = size;
		return;
	}
	DoubleNode *node = this->start;
	while (node->next != NULL) {
		node = node->next;
	}
	node->next = new DoubleNode();
	node->next->prev = node;
	node->next->next = NULL;
	node->next->val = v;
	size++;
	pos = size;
}

void DoubleLinkedList::printList() {
	DoubleNode *node = this->start;
	while (node != NULL) {
		printf("%d ", node->val);
		node = node->next;
	}
	printf("\n");
}

void DoubleLinkedList::del(int pos) {
	DoubleNode *tmp = new DoubleNode;
	DoubleNode *node = this->start;
	int count = 0;
	if (pos == 0) {
		tmp = node;
		this->start = node->next;
		node->prev = NULL;
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
		node->next = tmp->next;
		node->prev = tmp->prev;
		size--;
		delete tmp;
}

void DoubleLinkedList::insert(int pos, int v) {
	DoubleNode *tmp = new DoubleNode;
	tmp->val = v; 
	int count = 0;
	DoubleNode *el = this->start;
	if (pos > size || pos < 0) {
		cout << "error, wrong pos\n";
		return;
	}
	if (pos == 0) {
		this->start = tmp;
		tmp->prev = NULL;
		tmp->next = el;
	} else {
		while(count != pos-1) {
			el = el->next;
			count++;
		}
		tmp->next = el->next;
		tmp->prev = el->prev;
		el->next = tmp;
	}
	size++;
}

int main() {
  DoubleLinkedList slist;
  slist.addNode(1);
  slist.addNode(3);   
  slist.addNode(11);
  slist.addNode(9);
  slist.addNode(10);
  slist.addNode(2);
  slist.addNode(29);
  slist.addNode(5);
  slist.addNode(8);
  slist.addNode(7);
  slist.printList();
  slist.mergeSort();
  slist.printList();
}