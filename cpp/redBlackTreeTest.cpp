#include "RedBlackTree.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  int null = -1;
  ods::RedBlackTree1<int> primes;
  for(int i = 2; i < 1000; i++)  primes.add(i);
  std::cout << "Tree height=" << primes.height() << std::endl;
  for(int i = 2; i < 1000; i++){
    if(primes.find(i) == i){
      std::cout << i << std::endl;
      for(int j = i + i; j < 1000; j += i){
        primes.remove(j);
      }
    }
  }
  std::cout << "Tree height=" << primes.height() << std::endl;
  std::cout << "Tree size=" << primes.size() << std::endl;
}
