#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1005;

vector<int> adj[MAXN];
vector<pair<int, int>> criticalEdges;
vector<bool> visited;

void dfs(int u, int parent) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, u);
        }
    }
}

void findCriticalEdges(int u, int parent) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            findCriticalEdges(v, u);
        } else if (v != parent) {
            criticalEdges.push_back({min(u, v), max(u, v)});
        }
    }
}

int main() {
    int n;
    cin >> n;

    visited.resize(n + 1, false);

    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    findCriticalEdges(1, 0);

    int days = criticalEdges.size();
    cout << days << endl;

    for (auto edge : criticalEdges) {
        cout << edge.first << " " << edge.second << " ";

        // Find a city not connected to edge.second to build a new road
        for (int i = 1; i <= n; ++i) {
            if (i != edge.first && i != edge.second && !visited[i]) {
                cout << i << " " << edge.second << endl;
                break;
            }
        }
    }

    return 0;
}
