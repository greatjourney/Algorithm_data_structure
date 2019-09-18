#include "SkiplistList.h"
#include <iostream>

int main(){
  int n = 10;
  ods::SkiplistList<int> sl;
  for (int i = 0; i < n; i++){
    sl.add(i, i); 
  }
  // [0 1 2 3 4 5 6 7 8 9]
  for (int i = 0; i < n; i++){
    sl.add(i, -i); 
    sl.remove(0);
    sl.set(i, i * i);
    // [0 1 2 3 4 5 6 7 8 9]
    // [-1 1 2 3 4 5 6 7 8 9]
    // [1 -2 2 3 4 5 6 7 8 9]
    // [2 2 -3 3 4 5 6 7 8 9]
    // 
    // [-5, 25, -6, 36, -7, 49, -8, 64 -9, 81]
  }
  for (int i = 0; i < sl.size(); i++){
    std::cout << sl.get(i) << std::endl;
  }
   for (int i = 0; i < 3; i++){
    sl.add(4, i * 3);
    std::cerr << sl.get(5) << (i == 2 ? "\n" : ",");
    sl.remove(5);			      
  }
  return 0;
}
