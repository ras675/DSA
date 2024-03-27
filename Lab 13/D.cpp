#include <iostream>
#include <string>

using namespace std;

string makePalindrome(const string& input) {
    string palindrome = input;

    
    int n = input.length();

    
    bool isPalindrome = true;
    for (int i = 0; i < n / 2; ++i) {
        if (palindrome[i] != palindrome[n - i - 1]) {
            isPalindrome = false;
            break;
        }
    }

    if (!isPalindrome) {
       
        for (int i = n - 1; i >= 0; --i) {
            palindrome += input[i];
        }
    }

    return palindrome;
}

int main() {
    string input;

   
    while (cin >> input) {
        string palindrome = makePalindrome(input);
        cout << palindrome << endl;
    }

    return 0;
}
