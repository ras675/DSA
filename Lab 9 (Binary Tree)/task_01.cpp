#include<iostream>
using namespace std;

struct node
{
    int data;
    int height;
    node *left;
    node *right;
    node *parent;
};

node* createNode(int d)
{
    node* temp=new node;
    temp->data=d;
    temp->height=0;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=NULL;
    return temp;
}

void Insert(node *root,int d)
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

void print(node* root)
{
    if(root!=NULL)
    {
        print(root->left);
        cout<<root->data<<" ";
        print(root->right);
    }
}

node* search(node* root,int d)
{
    if(root==NULL || root->data==d)
    {
        return root;
    }
    if(d<root->data)
    {
        return search(root->left,d);
    }
    return search(root->right,d);
}

int main()
{
    node *root=NULL;
    int n,d;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>d;
        if(i==0)
        {
            root=createNode(d);
        }
        else
        {
            Insert(root,d);
        }
    }
    while(1)
    {
        cin>>n;
        if(n==2)
        {
            print(root);
            cout<<endl;
        }
        else if(n==3)
        {
            cin>>d;
            node* temp=search(root,d);
            if(temp==NULL)
            {
                cout<<"Not Present";
            }
            else
            {
                cout<<"Present\nParent(";
                if(temp->parent==NULL)
                {
                    cout<<"null";
                }
                else
                {
                    cout<<temp->parent->data;
                }
                cout<<") Left(";
                if(temp->left==NULL)
                {
                    cout<<"null";
                }
                else
                {
                    cout<<temp->left->data;
                }
                cout<<") Right(";
                if(temp->right==NULL)
                {
                    cout<<"null)";
                }
                else
                {
                    cout<<temp->right->data<<")";
                }
            }
            cout<<endl;
        }
        else if(n==4)
        {
            cin>>d;
            node* temp=search(root,d);
            if(temp==NULL)
            {
                cout<<"Not Present";
            }
            else
            {
                cout<<temp->height;
            }
            cout<<endl;
        }
        else
        {
            break;
        }
    }
    return 0;
}


