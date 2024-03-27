#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;

vector<long long> tree(4 * MAXN, 0);
vector<long long> lazy(4 * MAXN, 0);

void updateRange(int node, int start, int end, int l, int r, long long val) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > r || end < l) return;

    if (start >= l && end <= r) {
        tree[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;
    }

    int mid = (start + end) / 2;
    updateRange(2 * node, start, mid, l, r, val);
    updateRange(2 * node + 1, mid + 1, end, l, r, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

long long query(int node, int start, int end, int idx) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start == end && start == idx) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    if (idx <= mid) {
        return query(2 * node, start, mid, idx);
    } else {
        return query(2 * node + 1, mid + 1, end, idx);
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        updateRange(1, 0, n - 1, i, i, arr[i]);
    }

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            updateRange(1, 0, n - 1, a - 1, b - 1, u);
        } else if (type == 2) {
            int k;
            cin >> k;
            cout << query(1, 0, n - 1, k - 1) << endl;
        }
    }

    return 0;
}
