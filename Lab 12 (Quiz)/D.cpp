#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string processTextEditor(const string& line) {
    stack<char> stack;
    int cursorPosition = 0;

    for (char c : line) {
        if (c == '<') {
            if (!stack.empty() && cursorPosition > 0) {
                cursorPosition--;
                stack.pop();
            }
        } else if (c == '[') {
            cursorPosition = 0;
            stack = stack(); // Clear the stack
        } else if (c == ']') {
            cursorPosition = stack.size();
        } else {
            stack.emplace(stack.begin() + cursorPosition, c);
            cursorPosition++;
        }
    }

    return string(stack.begin(), stack.end());
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Consume the newline character after reading t

    vector<string> inputLines(t);
    for (int i = 0; i <
