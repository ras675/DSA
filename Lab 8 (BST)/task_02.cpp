#include<iostream>
using namespace std;

struct Node{
    int data;
    Node * parent;
    Node * left;
    Node * right;
    int subtree_size;
};

Node * createNode(int val){
    Node * newNode = new Node();
    newNode->data = val;
    newNode->subtree_size = 0;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node * root = NULL;

void insert(int val){
    Node * node = createNode(val);
    Node * temp = root;
    Node * target = NULL;
    if(temp == NULL) root = node;
    else{
        while(temp != NULL){
            target = temp;
            if(node->data < temp->data) temp = temp->left;
            else temp = temp->right;
        }
        node->parent = target;
        if(node->data < target->data) target->left = node;
        else target->right = node;

        while(target != NULL){
            target->subtree_size = target->subtree_size + 1;
            target = target->parent;
        }
    }
}

int search(int val){
    Node * temp = root;
    while(temp != NULL && temp->data != val){
        if(temp->data > val) temp = temp->left;
        else temp = temp->right;
    }
    int a1 = 0, a2 = 0, a = 0;
    if(temp->left != NULL) a1 = temp->left->subtree_size;
    if(temp->right != NULL) a2 = temp->right->subtree_size + 1;

    while(temp->parent != NULL && temp->data > temp->parent->data){
        temp = temp->parent;
    }
    int b = temp->subtree_size;

    return (b-a2);
}

int main(){
    int x;
    while(cin >> x && x != -1){
        insert(x);
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << search(n) << endl;
    }
    return 0;
}