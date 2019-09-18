#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  vector<string> lines;
  for (string line; getline(cin, line); ){
    lines.push_back(line);
  }
  for (size_t i = 0; i < lines.size(); i++){
    cout << lines[lines.size() -(i + 1)] << endl;
  }
}
