#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int main(){
    string str, line;
    unordered_map<string, string> m;

    while(getline(cin, line) && !line.empty()) {
        istringstream ss(line);
        string key;
        ss >> str;
        ss >> key;
        m[key]=str;
    }

    while(getline(cin, line) && !line.empty()) {
        istringstream ss(line);
        ss >> str;
        if(m.find(str) != m.end()) cout << m[str] << endl;
        else cout << "eh" << endl;
    }
    
    return 0;
}
