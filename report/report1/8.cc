#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  vector<string> lines;
  for (string line; getline(cin, line); ){
    lines.push_back(line);
  }
  for (size_t i = 0; (2 * i) < lines.size(); i++){
    cout << lines[2 * i] << endl;
  }
  for (size_t i = 0; (2 * i) + 1 < lines.size(); i++){
    cout << lines[(2 * i) + 1] << endl;
  }
}
