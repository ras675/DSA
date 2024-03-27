#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void findPairs(vector<int>& nums, int target) {
    unordered_map<int, int> numCount;

    for (int num : nums) {
        int complement = target - num;

        if (numCount.find(complement) != numCount.end() && numCount[complement] > 0) {
            cout << "(" << complement << "," << num << ") ";
            numCount[complement]--;
        }
        numCount[num]++;
    }

    if (numCount.empty()) {
        cout << "No pairs found" << endl;
    }
}

int main() {
    vector<int> nums;
    int num;

    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }
        nums.push_back(num);
    }

    int target;
    cin >> target;
    findPairs(nums, target);

    return 0;
}
