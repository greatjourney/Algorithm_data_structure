#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include<algorithm>

template<class T>
class lesserX {
public:
    bool operator()(const string & a, const string & b) {
        if (a.size() == b.size()) {
            if (a == b){
                return a.size() < b.size();
            }
            else{
                return a < b;
            }
        }
        else {
            return a.size() < b.size();
        };
    }
};

int main(){
  vector<string> lines;
  for (string line; getline(cin, line); ){
    lines.push_back(line);
  }
  lesserX<double> lesserx;
  sort(lines.begin(), lines.end(), lesserX<int>());
  for (size_t i = 0; i < lines.size(); i++){
    cout << lines[i] << endl;
  }
}
