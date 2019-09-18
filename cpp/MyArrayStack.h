/*
 * MyArrayStack.h
 *
 *  Created on: 2011-11-23
 *      Author: morin
 */

#ifndef MYArrayStack_H_
#define MYArrayStack_H_
#include "array.h"
#include "utils.h"

namespace ods {

template<class T>
class DualArrayDeque;

template<class T>
class MyArrayStack {
protected:
	friend class DualArrayDeque<T>;
	array<T> a;
	int n;
	virtual void resize();
public:
	MyArrayStack();
	virtual ~MyArrayStack();
	int size();
	T get(int i);
	T set(int i, T x);
	virtual void add(int i, T x);
	virtual void addAll1(int i, MyArrayStack<T>& x);
	virtual void addAll2(int i, MyArrayStack<T>& x);
	virtual void add(T x) { add(size(), x); }
	virtual T remove(int i);
	virtual void clear();
};

template<class T> inline
int MyArrayStack<T>::size() {
	return n;
}

template<class T> inline
T MyArrayStack<T>::get(int i) {
	return a[i];
}

template<class T> inline
T MyArrayStack<T>::set(int i, T x) {
	T y = a[i];
	a[i] = x;
	return y;
}

template<class T>
void MyArrayStack<T>::clear() {
	n = 0;
	array<T> b(1);
	a.swap(b);
}

template <class T>
MyArrayStack<T>::MyArrayStack() : a(1) {
	n = 0;
}

template<class T>
MyArrayStack<T>::~MyArrayStack() {
}


template<class T>
void MyArrayStack<T>::resize() {
	array<T> b(max(2 * n, 1));
	for (int i = 0; i < n; i++)
		b[i] = a[i];
	a.swap(b);
}

template<class T>
void MyArrayStack<T>::add(int i, T x) {
	if (n + 1 > a.length) resize();
	for (int j = n; j > i; j--)
		a[j] = a[j - 1];
	a[i] = x;
	n++;
}

template<class T>
void MyArrayStack<T>::addAll1(int i, MyArrayStack<T>& x) {
	for (int j = 0; j < x.size(); j++){
		add(i + j, x.get(j));
	}
}

template<class T>
void MyArrayStack<T>::addAll2(int i, MyArrayStack<T>& x) {
	if (a.length < n + x.size()) {
		array<T> b(max(n + x.size(), 1));
		for (int j = 0; j < n; j++) b[j] = a[j];
	a.swap(b);
	}
	for (int j = i; j < n; j++) { 
		a[j + x.size()] = a[j];
	}
	for (int j = i; j < i + x.size(); j++){
		a[j] = x.get(j - i);
	}
	n += x.size() ;
}


template<class T>
T MyArrayStack<T>::remove(int i) {
    T x = a[i];
	for (int j = i; j < n - 1; j++)
		a[j] = a[j + 1];
	n--;
	if (a.length >= 3 * n) resize();
	return x;
}

} /* namespace ods */

#endif /* MyArrayStack_H_ */
