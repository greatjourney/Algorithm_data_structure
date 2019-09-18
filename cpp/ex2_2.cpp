#include "SlowRandomQueue.h"
#include "MyRandomQueue.h"
#include <iostream>

uint64_t cputime(){
  unsigned int ax,dx;
  asm volatile("rdtsc\nmovl %%eax,%0\nmovl %%edx,%1":"=g"(ax),"=g"(dx): :"eax","edx");
  return (uint64_t(dx)<<32)+uint64_t(ax);
}

int main(){
  int n = 100;
  {
    SlowRandomQueue<int> as;
    uint64_t cpu1 = cputime();
    for (int i = 0; i < n * 100; i++){
      as.add(i);
    }
    int r = 0;
    for (int i = 0; i < n * 100; i++){
      r += as.remove();
    }
    uint64_t cpu2 = cputime();
    std::cout << "SlowRandomQueue time=" << (cpu2 - cpu1) << std::endl;
    for (int i = 0; i < n; i++){
      as.add(i);
    }
    for (int i = 0; i < n; i++){
      std::cout << as.remove() << ",";
    }
    std::cout << std::endl;
  }
  {
    MyRandomQueue<int> as;
    uint64_t cpu1 = cputime();
    for (int i = 0; i < n * 100; i++){
      as.add(i);
    }
    int r = 0;
    for (int i = 0; i < n * 100; i++){
      r += as.remove_random();
    }
    uint64_t cpu2 = cputime();
    std::cout << "MyRandomQueue time=" << (cpu2 - cpu1) << std::endl;
    for (int i = 0; i < n; i++){
      as.add(i);
    }
    for (int i = 0; i < n; i++){
      std::cout << as.remove_random() << ",";
    }
    std::cout << std::endl;
  }
}
