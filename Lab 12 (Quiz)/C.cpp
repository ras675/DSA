#include <iostream>
#include <stack>
using namespace std;
int main() {
    string s;
    cin >> s;

    stack<char> res;

    for (char ch : s) {
        if (ch == 'a' || (ch >= 'b' && ch <= 'z')) {
        
            res.push(ch);
        } else if (ch == '<' && !res.empty()) {
        
            res.pop();
        }
    }

    while (!res.empty()) {
        cout << res.top();
        res.pop();
    }

    return 0;
}
