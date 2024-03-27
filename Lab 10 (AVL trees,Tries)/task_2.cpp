#include<iostream>
using namespace std;

struct Node{
    int data;
    Node * left;
    Node * right;
    Node * parent;
    int height;
};

Node * createNode(int val){
    Node * newNode = new Node();
    newNode -> data = val;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> parent = NULL;
    newNode -> height = -1;
    return newNode;
}

Node * root = NULL;

int height(Node * x){
    if(x == NULL) return -1;
    return x->height;
}

void update_height(Node * x){
    x->height = max(height(x->left), height(x->right)) + 1;
}

void right_rotate(Node * y){
    cout << "right_rotate(" << y->data << ")";
    Node * x = y->left;
    Node * xR = x->right;

    x->parent = y->parent;
    if(y == root) root = x;
    else{
        if(y->parent->left == y) y->parent->left = x;
        else y->parent->right = x;
    }
    
    x->right = y;
    y->parent = x;

    y->left = xR;
    if(xR != NULL) xR->parent = y;

    Node * temp = y;
    while (temp != NULL){
        update_height(temp);
        temp = temp->parent;
    }
    
}

void left_rotate(Node * y){
    cout << "Left_rotate(" << y->data << ")";
    Node * x = y->right;
    Node * xL = x->left;

    x->parent = y->parent;
    if(y == root) root = x;
    else{
        if(y->parent->left == y) y->parent->left = x;
        else y->parent->right = x;
    }
    
    x->left = y;
    y->parent = x;

    y->right = xL;
    if(xL != NULL) xL->parent = y;

    Node * temp = y;
    while (temp != NULL){
        update_height(temp);
        temp = temp->parent;
    }
    
}

int balance_factor(Node * x){
    return height(x->left) - height(x->right);
}

void balance_node(Node * x, int bf, Node * newNode){
    if(bf > 1 && x->left->data > newNode->data){
        cout << "LL case" << endl;
        right_rotate(x);
        cout << endl;
    }
    else if(bf > 1 && x->left->data < newNode->data){
        cout << "LR case" << endl;
        left_rotate(x->left);
        cout << ", ";
        right_rotate(x);
        cout << endl;
    }
    else if(bf < -1 && x->right->data < newNode->data){
        cout << "RR case" << endl;
        left_rotate(x);
        cout << endl;
    }
    else if(bf < -1 && x->right->data > newNode->data){
        cout << "RL case" << endl;
        right_rotate(x->right);
        cout << ", ";
        left_rotate(x);
        cout << endl;
    }
}

void print(Node * x){
    if(x == NULL) return;
    print(x->left);
    cout << x->data << "(" << balance_factor(x) << ") ";
    print(x->right);
}

void insertion(int val){
    cout << val << endl; ////////////////////////////////
    Node * cur = root;
    Node * newNode = createNode(val);
    if(cur == NULL){
        root = newNode;
        root->height++;
    }
    else{
        Node * parent;
        while (cur != NULL){   
            parent = cur;
            if (val > cur -> data)	cur = cur -> right;
            else cur = cur -> left;
        }

        newNode->parent = parent; 
        if (val > parent -> data) parent -> right = newNode;
        else parent -> left = newNode;
    }
    Node * temp = newNode;
    while(temp != NULL){
        update_height(temp);
        temp = temp->parent;
    }

    print(root);
    cout << endl;

    bool balance = true;
    temp = newNode;
    while(temp != NULL){
        int bf = balance_factor(temp);
        if(bf < -1 || bf > 1){
            cout << "Imbalance at node: " << temp->data << endl;
            balance_node(temp, bf, newNode);
            balance = false;
            break;
        }
        temp = temp->parent;
    }
    if(balance) cout << "Balanced" << endl;
    else{
        cout << "Status: ";
        print(root);
        cout << endl;
    }
    
    cout << "Root=" << root->data << endl << endl;
}

int main(){
    int n = 0;
    while(cin >> n){
        if(n == -1){
            cout << "Status: ";
            print(root);
        }
        else insertion(n);
    }
    return 0;
}