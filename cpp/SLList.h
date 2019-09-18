/*
 * SLList.h
 *
 *  Created on: 2011-11-25
 *      Author: morin
 *       FIXME: This code is completely untested (but was ported from tested Java code)
 */

#ifndef SLLIST_H_
#define SLLIST_H_
#include <stdlib.h>

namespace ods {

template<class T>
class SLList {
	T null;
protected:
	class Node {
	public:
		T x;
		Node *next;
		Node(T x0) {
			x = x0;
			next = NULL;
		}
	};
	Node *head;
	Node *tail;
	int n;

public:

	SLList() {
		null = (T)NULL;
		n = 0;
		head = tail = NULL;
	}

	virtual ~SLList() {
		Node *u = head;
		while (u != NULL) {
			Node *w = u;
			u = u->next;
			delete w;
		}
	}

	int size() {
		return n;
	}

	T peek() {
		return head->x;
	}


	bool add(T x) {
		Node *u = new Node(x);
		if (n == 0) {
			head = u;
		} else {
			tail->next = u;
		}
		tail = u;
		n++;
		return true;
	}

	T push(T x) {
		Node *u = new Node(x);
		u->next = head;
		head = u;
		if (n == 0)
			tail = u;
		n++;
		return x;
	}

	T remove() {
		if (n == 0)	return null;
		T x = head->x;
		Node *u = head;
		head = head->next;
		delete u;
		if (--n == 0) tail = NULL;
		return x;
	}

	T pop() {
		if (n == 0)	return null;
		T x = head->x;
		Node *u = head;
		head = head->next;
		delete u;
		if (--n == 0) tail = NULL;
		return x;
	}

	T secondLast() {
		Node *u = head;
		while (true) {
			if (u->next == tail) break;
			u = u->next;
		}
		return u->x;
	}

	T get(int i) {
		Node *u = head;
		for (int j = 0; j < i; j++) u = u->next;
		return u->x;
	}

	T set(int i, T x){
		Node *u = head;
		for (int j = 0; j < i; j++) u = u->next;
		u->x = x;
		return x;
	}

	void add(int i, T x){
		if (i == 0) {
			push(x);
		}
		else {
			Node *u = head;
			for (int j = 0; j < i-1; j++) u = u->next;
			Node *t = new Node(x);
			t->next = u->next;
			u->next = t;
			n++;
		}		
	}

	T remove(int i){
		if (n == 0)	return null;
		if (i == 0) {
			return pop();
		}
		else {
			Node *u = head;
			for (int j = 0; j < i-1; j++) u = u->next;
			T x = (u->next)->x;
			u->next = (u->next)->next;
			n--;
			return x;
		}
	}

	void reverse() { 
        Node *u = head; 
		Node *p = NULL; 
        Node *f = head;

        while (u != NULL) { 
            f = u->next; 
            u->next = p; 
            p = u; 
            u = f; 
        } 
        head = p; 
    } 
};

} /* namespace ods */
#endif /* SLLIST_H_ */
