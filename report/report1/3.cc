#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<string> lines;
    for(int i = 0; i < 42; i++) {
        string line;
        getline(cin, line);
        lines.push_back(line);
    }
    for (string line; getline(cin, line); ){
        if (line.empty()) {
            cout << lines[0] << endl;
        }
        lines.erase(lines.begin());
        lines.push_back(line);
    }
}
