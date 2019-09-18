#include "SLList.h"
#include <iostream>
int main(){
  ods::SLList<double> l;
  for (int i = 0; i < 10; i++){
    l.add(double(i));
  }
  // l = [0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0]
  std::cout << l.secondLast() << std::endl;
  // output "8"
}
