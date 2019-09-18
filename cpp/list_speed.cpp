#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

uint64_t cputime(){
  unsigned int ax,dx;
  asm volatile("rdtsc\nmovl %%eax,%0\nmovl %%edx,%1":"=g"(ax),"=g"(dx): :"eax","edx");
  return (uint64_t(dx)<<32)+uint64_t(ax);
}

void f(std::vector<int> &v, int n){
  for (int i = 0; i < n; i++) v.push_back(i);
  for (int i = 0; i < n; i++) v.pop_back();
}

int main(int ac, char **ag){
  int n = 1000;
  if (ac > 1) n = atoi(ag[1]);
  std::vector<int> v;
  clock_t clk1 = clock();
  uint64_t cpu1 = cputime();
  f(v, n);
  uint64_t cpu2 = cputime();
  clock_t clk2 = clock();
  std::cout << "cycle : " << cpu2 - cpu1 << std::endl;
  std::cout << "clock : " << clk2 - clk1 << std::endl;
  std::cout << "sec   : " << (double)(clk2 - clk1)/CLOCKS_PER_SEC << std::endl;
}
