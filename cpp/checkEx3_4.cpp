#include <iostream>
#include "SLList.h"
int main(){
  ods::SLList<double> l;
  for (int i = 0; i < 10; i++){
    l.add(double(10 + i));
  }
  // l = [10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0]
  l.reverse();
  // l = [19.0, 18.0, 17.0, 16.0, 15.0, 14.0, 13.0, 12.0, 11.0, 10.0]
  for (int i = 0; i < 10; i++)
    std::cout << (i == 0 ? "[" : ", ") << l.remove();
  std::cout << "]" << std::endl;
  // output [19, 18, 17, 16, 15, 14, 13, 12, 11, 10]
}
