#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

   
    for (int i = 0; i < q; ++i) {
        int query;
        cin >> query;

        if (query == 2) {
            int a, b;
            cin >> a >> b;

            
            int minVal = arr[a - 1];
            for (int j = a; j < b; ++j) {
                if (arr[j] < minVal) {
                    minVal = arr[j];
                }
            }
            cout << minVal << endl;
        } else {
            int k, u;
            cin >> k >> u;

            
            arr[k - 1] = u;
        }
    }

    return 0;
}
