#include<iostream>
#include<stack>
using namespace std;
struct node{
    int d;
    node* l,*r,*p;
};
node* create(int n){
    node* t=new node;
    t->d=n;
    t->l=t->r=t->p=NULL;
    return t;
}
node* build(node* root,int arr[],int n){
    stack<int>large,small;
    for(int i=0;i<n;i++){
        if(arr[i]<root->d){
            small.push(arr[i]);
        }else{
            large.push(arr[i]);
        }
    }if(large.size()){
        node* t=create(large.top());
        large.pop();
        root->r=t;
        t->p=root;
        int x=large.size();
        int a[x];
        for(int i=x-1;i>=0;i--){
            a[i]=large.top();
            large.pop();
        }t=build(t,a,x);
    }if(small.size()){
        node* t=create(small.top());
        small.pop();
        root->l=t;
        t->p=root;
        int x=small.size();
        int a[x];
        for(int i=x-1;i>=0;i--){
            a[i]=small.top();
            small.pop();
        }t=build(t,a,x);
    }return root;
}
void print(node* root){
    if(root){
        print(root->r);
        print(root->l);
        cout<<root->d<<" ";
    }
}
int main(){
    int i,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }node* root=create(arr[n-1]);
    root=build(root,arr,n-1);
    print(root);
    return 0;
}