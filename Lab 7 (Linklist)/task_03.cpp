#include<iostream>
using namespace std;
struct node{
    int data;
    node *p,*l,*r;
};
node* create(int d){
    node* temp=new node;
    temp->data=d;
    temp->l=temp->p=temp->r=NULL;
    return temp;
}
int height(node* root){
    if(!root){
        return -1;
    }int l=height(root->l);
    int r=height(root->r);
    return max(l,r)+1;
}
node* search(node* root,int d){
    if(root==NULL || root->data==d){
        return root;
    }node* lsearch=search(root->l,d);
    if(lsearch){
        return lsearch;
    }return search(root->r,d);
}
node* place(node* root,int d,int c,int pa){
    if(!root){
        root=create(d);
        return root;
    }node* temp=create(d);
    node* s=search(root,pa);
    if(s){
        if(c==1){
            s->l=temp;
        }else if(c==2){
            s->r=temp;
        }temp->p=s;
    }return root;
}
node* remove(node* root,int d){
    if(!root){
        return root;
    }node* s=search(root,d);
    if(s){
        if(!s->p){
            root=NULL;
            delete s;
            return root;
        }if(s==s->p->l){
            s->p->l=NULL;
        }else{
            s->p->r=NULL;
        }s->p=NULL;
        delete s;
        return root;
    }return root;
}
void print(node* root){
    if(root){
        cout<<root->data<<"(";
        if(root->p){
            cout<<root->p->data<<") ";
        }else{
            cout<<"N) ";
        }print(root->l);
        print(root->r);
    }
}
int main(){
    node* root=NULL;
    int n,i,d,c,pa;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>d>>pa>>c;
        root=place(root,d,c,pa);
    }print(root);
    cout<<endl;
    while(true){
        cin>>n;
        if(n==2){
            cin>>i;
            root=remove(root,i);
            print(root);
        }else if(n==3){
            cin>>i;
            node *s=search(root,i);
            if(s){
                cout<<"Present, left(";
                if(s->l){
                    cout<<s->l->data<<"), right(";
                }else{
                    cout<<"null), right(";
                }if(s->r){
                    cout<<s->r->data<<")";
                }else{
                    cout<<"null)";
                }
            }else{
                cout<<"Not present";
            }
        }else if(n==4){
            cout<<height(root);
        }else{
            break;
        }cout<<endl;
    }return 0;
}