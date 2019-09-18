#include "MyArrayStack.h"
#include <iostream>

uint64_t cputime(){
  unsigned int ax,dx;
  asm volatile("rdtsc\nmovl %%eax,%0\nmovl %%edx,%1":"=g"(ax),"=g"(dx): :"eax","edx");
  return (uint64_t(dx)<<32)+uint64_t(ax);
}

int main(){
  int n = 20;
  ods::MyArrayStack<int> as, bs, cs;
  for (int i = 0; i < n; i++){
    as.add(i, i); 
    cs.add(i, i);
  }
  for (int i = 0; i < n * 4; i++){
    bs.add(i, 1000 - i); 
  }
  uint64_t cpu1 = cputime();
  cs.addAll1(10,bs);
  uint64_t cpu2 = cputime();
  as.addAll2(10,bs);
  uint64_t cpu3 = cputime();
  std::cout << "addAll1 time " << cpu2 - cpu1 << std::endl;
  std::cout << "addAll2 time " << cpu3 - cpu2 << std::endl;
  for (int i = 0; i < as.size(); i++){
		std::cout << "as[" << i << "]=" <<as.get(i) << std::endl; 		
	}
  return 0;
}
