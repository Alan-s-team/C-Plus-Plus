/*
 * Purpose: demostrate the basic operation of single linked list
 *	    with the usage of friend class
 *
 * Author: Lunsheng Wang <lunsheng.wang@gmail.com>
 */
#include "linked-list.h"

void List::insert(char *a)
{
	Node *temp;
	temp = new Node;

	temp->contents = new char[size];
	for (int i = 0; i < size; i++)
		temp->contents[i] = a[i];

	if (head) {
		temp->next = head;
		head = temp;
	} else {
		temp->next = NULL;
		head = temp;
	}
}

void List::append(char *a)
{
	Node *prev, *cur, *newnode;

	if (head) {
		prev = head;
		cur = prev->next;
		while (cur != NULL) { //Traverse to last node
			prev = cur;
			cur = cur->next;
		} //Now prev points to last node

		newnode = new Node;
		newnode->contents = new char[size];
		for (int i = 0; i < size; i++)
			newnode->contents[i] = a[i];

		newnode->next = NULL;
		prev->next = newnode;
	} else {
		head = new Node;
		head->contents = new char[size];
		for (int i = 0; i < size; i++)
			head->contents[i] = a[i];

		head->next = NULL;
	}
}

char *List::get()
{
	if (!head) {
		printf("Error: get() from empty list\n");
		return NULL;
	} else {
		char *res;
		res = head->contents;
		head->contents = NULL;
		head = head->next;
		return res;
	}
}

void List::clear()
{
	Node *l = head;

	if (NULL == l)
		return;

	do {
		Node *ll = l;
		l = l->next;
		delete ll->contents;
		delete ll;
	} while (NULL != l);
}

int main()
{
	List my_list(6);
	float t, *r;
	r = &t;
	t = 1.5;
	my_list.insert((char *)r);
	t = 2.5;
	my_list.insert((char *)r);
	t = 3.5;
	my_list.insert((char *)r);
	t = 6.0;
	my_list.append((char *)r);
	//for (int i = 0; i < 4; i++) {
	while (r = (float *)my_list.get()) {
		printf("%f\n", *r);
	}
	printf("\n");

	//my_list.clear(); //No need here because my_list.get() already release
	return 0;
}
