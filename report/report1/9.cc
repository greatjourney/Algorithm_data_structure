#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int main(){
  vector<string> lines;
  for (string line; getline(cin, line); ){
    lines.push_back(line);
  }
  random_shuffle( lines.begin(), lines.end());
  for (size_t i = 0; i < lines.size(); i++){
    cout << lines[i] << endl;
  }
}
