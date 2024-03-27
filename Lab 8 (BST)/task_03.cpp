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

    }
}

Node * search(int val){
    Node * temp = root;
    while(temp != NULL && temp->data != val){
        if(temp->data > val) temp = temp->left;
        else temp = temp->right;
    }
    return temp;
}

int answer(int n, int m){
    Node * temp = root;
    bool up = false;
    while(temp != NULL && temp->data != n){
        if(temp->data == m) up = true;
        if(temp->data > n) temp = temp->left;
        else temp = temp->right;
    }

    int mx = 0;
    if(up){
        while(temp->data != m){
            mx = max(mx, temp->data);
            temp = temp->parent;
        }
        mx = max(mx, m);
    }
    else{
        while(temp != NULL && temp->data != m){
            mx = max(mx, temp->data);
            if(temp->data > m) temp = temp->left;
            else temp = temp->right;
        }
        if(temp == NULL){
            temp = search(m);
            mx = m;
            while(temp->parent != NULL && temp == temp->parent->left){
                mx = max(mx, temp->parent->data);
                temp = temp->parent;
            }
        }
        else mx = max(mx, m);
    }
    return mx;
}

int main(){
    int x;
    while(cin >> x && x != -1){
        insert(x);
    }
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        cout << answer(n, m) << endl;
    }
    return 0;
}