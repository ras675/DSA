#include<iostream>

#include<queue>
using namespace std;

struct node

{

    int data,height;

    node *left,*right,*parent;

};

node* createNode(int d)

{

    node* temp=new node;

    temp->data=d;

    temp->height=0;

    temp->left=NULL;

    temp->parent=NULL;

    temp->right=NULL;

    return temp;

}

void place(node *root,int d)

{

    node *n=createNode(d);

    int x=0;

    node* temp=root;

    while(1)

    {

        x++;

        if(d>temp->data)

        {

            if(temp->right==NULL)

            {

                temp->right=n;

                n->parent=temp;

                break;

            }

            temp=temp->right;

        }

        else

        {

            if(temp->left==NULL)

            {

                temp->left=n;

                n->parent=temp;

                break;

            }

            temp=temp->left;

        }

    }

    temp=n;

    for(int i=0; i<=x; i++)

    {

        if((temp->height) < i)

        {

            temp->height=i;

        }

        temp=temp->parent;

    }

}
int diameter(node* root){
    queue<node *>q;

    q.push(root);

    int x=0;
    while(!q.empty())

    {

        node* temp=q.front();

        q.pop();

        if(temp->left->height+temp->right->height >x){
            x=temp->left->height+temp->right->height;
        if(temp->left!=NULL)

        {

            q.push(temp->left);

        }

        if(temp->right!=NULL)

        {

            q.push(temp->right);

        }

    }

}return x+3;
}

int main(){
    node* root=NULL;
    int i,d,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>d;
        if(i==0){
            root=createNode(d);
        }else{
            place(root,d);
        }
    }cout<<diameter(root);
    return 0;
}
