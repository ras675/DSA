#include<iostream>

using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    int height;
};

int Update_height(Node *n){
    if(n==NULL) return 0;
    return n->height;
}

Node *createNode(int key){
    Node* newnode= new Node;
    newnode->key=key;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->height=1;

    return newnode;
}

int getBalancedFactor(Node *n){
    if(n==NULL) return 0;
    return Update_height(n->left)-Update_height(n->right);
}



Node* insert(Node*& node, int key){
    if(node==NULL)
        return (createNode(key));

    if(key < node->key)
        node->left=insert(node->left,key);
    else if(key > node->key)
        node->right=insert(node->right,key);


    node->height= 1+ max(Update_height(node->left),Update_height(node->right));

    return node;
}
void inOrder(Node* root){
    if(root!=NULL){
        inOrder(root->left);
        int bf=getBalancedFactor(root);
        cout<<root->key<<"("<<bf<<")"<<" ";
        inOrder(root->right);
    }
}
int main(){
    Node* root=NULL;
    int n;
    while(1){
    cin>>n;
        if(n==-1) break;
        root= insert(root,n);
        inOrder(root);
        cout<<endl;
    }
    return 0;
}
