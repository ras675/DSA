#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

vector<string> buildArray(vector<int>& target, int n) {
    vector<string> ans;
    stack<int> s;

    int i = 1, j = 0;
    while (i <= n && j < target.size()) {
        s.push(i);
        ans.push_back("Push");
        i++;

        if (!s.empty() && target[j] == s.top()) {
            j++;
        } else {
            s.pop();
            ans.push_back("Pop");
        }
    }
    return ans;
}

int main() {
    int targetArr[] = {2, 3, 4};
    vector<int> target(targetArr, targetArr + sizeof(targetArr) / sizeof(targetArr[0]));
    int n = 4;

    vector<string> ans = buildArray(target, n);
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

