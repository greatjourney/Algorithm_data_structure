#include "ArrayStack.h"

template<class T>
class MyRandomQueue {
protected:
  ods::ArrayStack<T> as;
public:
  MyRandomQueue();
  int size();
  void add(T x);
  T remove();
  T remove_random();
};

template <class T>
MyRandomQueue<T>::MyRandomQueue() : as() {
}

template<class T> inline
int MyRandomQueue<T>::size() {
  return as.size();
}

template<class T> inline
void MyRandomQueue<T>::add(T x) {
  as.add(x);
}

template<class T> inline
T MyRandomQueue<T>::remove() {
// replace this function
  return as.remove(as.size() - 1);
}

template<class T> inline
T MyRandomQueue<T>::remove_random() {
// replace this function
  return as.remove_random();
}

