#include "SLList.h"
#include <iostream>
int main(){
  ods::SLList<double> l;
  for (int i = 0; i < 10; i++){
    l.add(double(10+ i));
  }
  // l = [10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0]
  l.set(5, 105.0);
  // l = [10.0, 11.0, 12.0, 13.0, 14.0, 105.0, 16.0, 17.0, 18.0, 19.0]
  l.add(2, 22.0);
  // l = [10.0, 11.0, 22.0, 12.0, 13.0, 14.0, 105.0, 16.0, 17.0, 18.0, 19.0]
  l.add(0, 20.0);
  // l = [20.0, 10.0, 11.0, 22.0, 12.0, 13.0, 14.0, 105.0, 16.0, 17.0, 18.0, 19.0]
  l.add(12, 30.0);
  // l = [20.0, 10.0, 11.0, 22.0, 12.0, 13.0, 14.0, 105.0, 16.0, 17.0, 18.0, 19.0, 30.0]
  std::cout << l.remove(1) << std::endl;;
  // output 10
  // l = [20.0, 11.0, 22.0, 12.0, 13.0, 14.0, 105.0, 16.0, 17.0, 18.0, 19.0, 30.0]
  for (int i = 0; i < l.size(); i++)
    std::cout << (i == 0 ? "[" : ", ") << l.get(i);
  std::cout << "]" << std::endl;
  // output [20, 11, 22, 12, 13, 14, 105, 16, 17, 18, 19,  30]
}