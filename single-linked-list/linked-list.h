/*
 * Purpose: A class for linked list
 *
 * Author: Lunsheng Wang <lunsheng.wang@gmail.com>
 */
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#include<iostream>
#include<stdio.h>

class List;
class Node {
	Node *next;
	char *contents;

	public:
		friend class List; //Friend class, it can access the private members of Node
};

class List {
	Node *head;
	int size;

	public:
		List(int s) { head = NULL; size = s; }
		void insert(char *a);
		void append(char *a);
		char *get();
		void clear();
		~List() { clear(); }
};

#endif

