#include<iostream>
#include<vector>
using namespace std;

int BS(int *arr, int n, int target);

int main()
{
    int n;
    cin >> n;
    
    int *berries = new int[n];
    
    for (int i = 0; i < n; i++) {
        cin >> berries[i];
    }

    vector<int> sums(n, 0);
    sums[0] = berries[0];
    
    for (int i = 1; i < n; i++) {
        sums[i] = berries[i] + sums[i - 1];
    }

    int m;
    cin >> m;
    
    int *q = new int[m];
    
    for (int i = 0; i < m; i++) {
        cin >> q[i];
        cout << BS(sums.data(), n, q[i]) << endl;
    }

    delete[] berries;
    delete[] q;

    return 0;
}

int BS(int *arr, int n, int target)
{
    int left = 0;
    int right = n - 1;
    int ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}
