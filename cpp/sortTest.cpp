#include "array.h"
using namespace ods;
#include "ArrayStack.h"
#include "BinaryHeap.h"
#include "Algorithms.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main(){
  std::vector<int> v(1000000);
  for (int i = 0; i < 1000000; i++) v[i] = rand() % 100;
  for (int n = 1000; n <= 1000000; n *= 10){
    array<int> a(n);
    for (int i = 0; i < n; i++) a[i] = v[i];
    clock_t start, stop;
    {
      start = clock();
      mergeSort(a);
      stop = clock();
      std::cout << "mergeSort(size = " << n << ") : " << ((double)(stop-start))/CLOCKS_PER_SEC << " sec" << std::endl;
    }
    {
      start = clock();
      quickSort(a);
      stop = clock();
      std::cout << "quickSort(size = " << n << ") : " << ((double)(stop-start))/CLOCKS_PER_SEC << " sec" << std::endl;
    }
    {
      start = clock();
      heapSort(a);
      stop = clock();
      std::cout << "heapSort(size = " << n << ") : " << ((double)(stop-start))/CLOCKS_PER_SEC << " sec" << std::endl;
    }
    {
      start = clock();
      countingSort(a, 100);
      stop = clock();
      std::cout << "countingSort(size = " << n << ") : " << ((double)(stop-start))/CLOCKS_PER_SEC << " sec" << std::endl;
    }
    {
      start = clock();
      radixSort(a);
      stop = clock();
      std::cout << "radixSort(size = " << n << ") : " << ((double)(stop-start))/CLOCKS_PER_SEC << " sec" << std::endl;
    }
  }
}
