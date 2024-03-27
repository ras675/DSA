#include<iostream>
#include<stack>
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

void print_inorder(){
    stack<Node*> s;
    Node * cur = root;

    while(cur != NULL || !s.empty()){
        while (cur != NULL){
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        cout << cur->data << " ";
        cur = cur->right;
    }
}

bool checkValidity(Node * node){
    stack<Node*> s;
    Node * cur = root;

    while(cur != NULL || !s.empty()){
        while (cur != NULL){
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        if(cur->data - 3 <= node->data && cur->data + 3 >= node->data) return true;
        s.pop();
        cur = cur->right;
    }
    return false;
}

void insert(int val){
    Node * node = createNode(val);
    Node * temp = root;
    Node * target = NULL;
    if(temp == NULL){
        root = node;
        cout << node->data << endl;
    }
    else{
        bool error = checkValidity(node);
        if(!error){
            while(temp != NULL){
                target = temp;
                if(node->data < temp->data) temp = temp->left;
                else temp = temp->right;
            }
            node->parent = target;
            if(node->data < target->data)target->left = node;
            else target->right = node;
        }

        print_inorder();
        if(error) cout << "(Reservation failed)";
        cout << endl;
    }
}

int main(){
    int k;
    while(cin >> k && k != -1){
        insert(k);
    }
    return 0;
}
