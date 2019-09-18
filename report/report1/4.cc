#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  vector<string> lines;
  for (string line; getline(cin, line); ){
    if(find(lines.begin(),lines.end(),line) == lines.end()) {
        cout << line << endl;
        lines.push_back(line);
    }
  }
}
