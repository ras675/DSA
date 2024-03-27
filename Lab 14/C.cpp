#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    // Compute prefix XOR
    vector<int> prefixXOR(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixXOR[i + 1] = prefixXOR[i] ^ values[i];
    }

    // Process queries
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        
        // Calculate XOR sum for the range [a, b]
        int result = prefixXOR[b] ^ prefixXOR[a - 1];
        cout << result << endl;
    }

    return 0;
}
