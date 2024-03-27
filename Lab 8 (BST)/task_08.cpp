#include<iostream>
using namespace std;

struct Node{
    int data;
    Node * parent;
    Node * left;
    Node * right;
};

Node * createNode(int val){
    Node * newNode = new Node();
    newNode->data = val;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node * root = NULL;

Node * search(int val){
    Node * temp = root;
    while(temp != NULL && temp->data != val){
        if(temp->data > val) temp = temp->left;
        else temp = temp->right;
    }
    return temp;
}

void insert(int n, int m){
    Node * z = search(n);
    Node * node1 = NULL;
    if(z == NULL){
        node1 = createNode(n);
        root = node1;
    }
    else node1 = z;
    Node * node2 = createNode(m);

    node2->parent = node1;
    if(n > m) node1->left = node2;
    else node1->right = node2;
}

void deletion(int x){
    Node * z = search(x);
    if(z == NULL) return;

    Node * zp = z->parent;
    if(z->left == NULL && z->right == NULL){
        if(z == root){
            root == NULL;
            delete z;
            return;
        }
        if(z == zp->left) zp->left = NULL;
        else zp->right = NULL;
        delete z;
        return;
    }

    if(z == zp->right){
        if(z->left == NULL && z->right != NULL){
            zp->right = z->right;
            z->right->parent = zp;
            delete z;
            return;
        }
        else if(z->right == NULL && z->left != NULL){
            zp->right = z->left;
            z->left->parent = zp;
            delete z;
            return;
        }
    }
    else{
        if(z->left == NULL && z->right != NULL){
            zp->left = z->right;
            z->right->parent = zp;
            delete z;
            return;
        }
        else if(z->right == NULL && z->left != NULL){
            zp->left = z->left;
            z->left->parent = zp;
            delete z;
            return;
        }
    }


}

void print_inorder(Node * x){
    if(x == NULL) return;
    print_inorder(x->left);
    cout << x->data << " ";
    print_inorder(x->right);
}

int main(){
    int t;  cin >> t;
    while(--t){
        int n, m;
        cin >> n >> m;
        insert(n, m);
    }
    int x;  cin >> x;
    deletion(x);
    print_inorder(root);
    return 0;
}