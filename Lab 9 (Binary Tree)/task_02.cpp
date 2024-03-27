#include<iostream>
#include<queue>

using namespace std;

struct node
{
    int data;
    node *left,*right,*parent;

};

node* createNode(int d)
{
    node* temp=new node;
    temp->data=d;
    temp->left=NULL;
    temp->parent=NULL;
    temp->right=NULL;
    return temp;
}

void Insert(node *root,int d)
{
    node *n=createNode(d);
    node* temp=root;
    while(1)
    {
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
}

void preOrder(node* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<"(";
        if(root->parent==NULL)
        {
            cout<<"null) ";
        }
        else
        {
            cout<<root->parent->data<<") ";
        }
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node* root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        cout<<root->data<<"(";
        if(root->parent==NULL)
        {
            cout<<"null) ";
        }
        else
        {
            cout<<root->parent->data<<") ";
        }
        inOrder(root->right);
    }
}

void postOrder(node* root)

{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<"(";
        if(root->parent==NULL)
        {
            cout<<"null) ";
        }
        else
        {
            cout<<root->parent->data<<") ";
        }
    }
}

void levelOrder(node* root)

{
    queue<node *>q;
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        cout<<temp->data<<"(";
        if(temp->parent==NULL)
        {
            cout<<"null) ";
        }
        else
        {
            cout<<temp->parent->data<<") ";
        }
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
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
        if(n==1)
        {
            cout<<"In Order\n";
            inOrder(root);
        }
        else if(n==2)
        {
            cout<<"Pre Order\n";
            preOrder(root);
        }
        else if(n==3)
        {
            cout<<"Post Order\n";
            postOrder(root);
        }
        else if(n==4)
        {
            cout<<"Level Order\n";
            levelOrder(root);
        }
        else
        {
            break;
        }
        cout<<endl;
    }
    return 0;
}

