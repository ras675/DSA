#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    vector<int> parent, size;

    UnionFind(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB) {
            if (size[rootA] < size[rootB]) {
                swap(rootA, rootB);
            }
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    UnionFind uf(n);
    int components = n;
    int largestComponent = 1;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        uf.unite(a, b);

        if (uf.getSize(a) == 1 && uf.getSize(b) == 1) {
            components--;  // If both cities were in different components, merge them
        }

        largestComponent = max(largestComponent, max(uf.getSize(a), uf.getSize(b)));

        cout << components << " " << largestComponent << "\n";
    }

    return 0;
}
