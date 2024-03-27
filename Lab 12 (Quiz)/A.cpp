#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int n;
    Node* left;
    Node* right;

    Node(int x) : n(x), left(NULL), right(NULL) {}
};

void insert(Node* root, int n) {
    if (root == NULL) {
        root = new Node(n);
        return;
    }

    if (n < root->n) {
        insert(root->left, n);
    } else {
        insert(root->right, n);
    }
}

void traverseInOrder(Node* root, vector<int> order) {
    if (root == NULL) {
        return;
    }

    traverseInOrder(root->left, order);
    order.push_back(root->n);
    traverseInOrder(root->right, order);
}

void speechOrderEven(Node* root, vector<int> evenOrder) {
    if (root == NULL) {
        return;
    }

    speechOrderEven(root->right, evenOrder);
    evenOrder.push_back(root->n);
    speechOrderEven(root->left, evenOrder);
}

int main() {
    int N;
    cin >> N;

    Node* root = NULL;

    for (int i = 0; i < N; ++i) {
        int id;
        cin >> id;
        insert(root, id);
    }

    vector<int> oddOrder;
    traverseInOrder(root, oddOrder);

    vector<int> evenOrder;
    speechOrderEven(root, evenOrder);

    for (int i = 0; i < N; ++i) {
        cout << evenOrder[i] << "\n";
    }

    return 0;
}
