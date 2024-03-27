#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct SegmentTreeNode {
    int minVal;
};


void buildSegmentTree(vector<int>& arr, vector<SegmentTreeNode>& segmentTree, int node, int start, int end) {
    if (start == end) {
        segmentTree[node].minVal = arr[start];
    } else {
        int mid = (start + end) / 2;
        buildSegmentTree(arr, segmentTree, 2 * node + 1, start, mid);
        buildSegmentTree(arr, segmentTree, 2 * node + 2, mid + 1, end);
        segmentTree[node].minVal = min(segmentTree[2 * node + 1].minVal, segmentTree[2 * node + 2].minVal);
    }
}

 
int querySegmentTree(vector<SegmentTreeNode>& segmentTree, int node, int start, int end, int left, int right) {
    if (right < start || left > end) {
        return INT_MAX; 
    }

    if (left <= start && right >= end) {
        return segmentTree[node].minVal; 
    }

    int mid = (start + end) / 2;
    return min(querySegmentTree(segmentTree, 2 * node + 1, start, mid, left, right),
               querySegmentTree(segmentTree, 2 * node + 2, mid + 1, end, left, right));
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

   
    vector<SegmentTreeNode> segmentTree(4 * n);
    buildSegmentTree(arr, segmentTree, 0, 0, n - 1);

    for (int i = 0; i < q; ++i) {
        int query;
        cin >> query;

        if (query == 2) {
            int a, b;
            cin >> a >> b;
            cout << querySegmentTree(segmentTree, 0, 0, n - 1, a - 1, b - 1) << endl;
        } else {
            int k, u;
            cin >> k >> u;
            arr[k - 1] = u;

            buildSegmentTree(arr, segmentTree, 0, 0, n - 1);
        }
    }

    return 0;
}
