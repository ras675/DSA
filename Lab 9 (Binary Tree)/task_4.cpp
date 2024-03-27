#include<iostream>
#include<vector>
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

void insert(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
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

            Node * temp = newNode;
            temp->height++;
            while(temp->parent != NULL){
                if(temp->height == temp->parent->height) temp->parent->height++;
                temp = temp->parent;
            }
        }
    }
}

Node * search(int val){
    Node * x = root;
    while(true){
        if(x == NULL || x->data == val) return x;
        if(val > x->data) x = x->right;
        else x = x->left;
    }
}

vector<int> ancestors(int val){
    vector<int> v;
    Node * x = search(val);
    while(x != NULL){
        v.push_back(x->data);
        x = x->parent;
    }
    return v;
}

int main(){
    insert();
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int val1, val2;
        cin >> val1 >> val2;
        vector<int> v1 = ancestors(val1);
        vector<int> v2 = ancestors(val2);
        int lca = -1;
        for(int i=0; i<v1.size(); i++){
            for(int j=0; j<v2.size(); j++){
                if(v1[i] == v2[j]){
                    lca = v1[i];
                    break;
                }
            }
            if(lca != -1) break;
        }
        cout << lca << " ";
    }
    return 0;
}