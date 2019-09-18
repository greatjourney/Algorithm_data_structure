#include "SLList.h"
#include <iostream>

int main(){
  ods::SLList<int> l;
  for (int i = 0; i < 10; i++){
    l.add(i);
  }
  // [0 1 2 3 4 5 6 7 8 9]
  for (int i = 10; i < 20; i++){
    l.push(i);
  }
  // [19 18 17 16 15 14 13 12 11 10 0 1 2 3 4 5 6 7 8 9]
  std::cerr << l.pop() << std::endl;
  // [18 17 16 15 14 13 12 11 10 0 1 2 3 4 5 6 7 8 9]
  for (int i = 0; i < 10; i++){
    std::cerr << l.remove() << std::endl;
  }
  // [1 2 3 4 5 6 7 8 9]
   for (int i = 0; i < 3; i++){
    std::cerr << l.pop() << (i == 2 ? "\n" : ",");
  }
  return 0;
}
  
