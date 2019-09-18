#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int main(){
  for (string line; getline(cin, line); ){
    if (line == "{") {
        cout << line<< endl;
        }
  }
}
