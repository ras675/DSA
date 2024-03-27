#include <iostream>
#include <string>

using namespace std;

bool canRotateToMatch(string S, string T) {
    if (S.length() != T.length()) {
        return false;
    }

    string rotatedS = S + S;

    if (rotatedS.find(T) != string::npos) {
        return true;
    }

    return false;
}

int main() {
    string S, T;
    cin >> S >> T;

    if (canRotateToMatch(S, T)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

