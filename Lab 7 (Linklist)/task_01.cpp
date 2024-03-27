#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
class LinkedList{
    node* head;
    node* tail;
public:
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
    node* createNode(int v){
        node* temp=new node;
        temp->data=v;
        temp->next=NULL;
        return temp;
    }
    void print(){
        if(head==NULL){
            cout<<"head: Null, tail: Null,  Empty\n";
        }else{
            cout<<"head: "<<head->data<<", tail: "<<tail->data<<",  ";
            node* temp=head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }cout<<endl;
        }
    }
    void Insert_Front(int v){
        node* newNode=createNode(v);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }print();
    }
    void Insert_Back(int v){
        node* newNode=createNode(v);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }print();
    }
    void Insert_After_Node(int v,int k){
        if(tail->data==k){
            Insert_Back(v);
        }else{
            node* newNode=createNode(v);
            node* temp=head;
            while(1){
                if(temp==NULL || temp->data==k){
                    break;
                }temp=temp->next;
            }if(temp==NULL){
                cout<<"Not Found"<<endl;
            }else{
                node* temp1=temp->next;
                newNode->next=temp1;
                temp->next=newNode;
            }print();
        }
    }
    void Update_Node(int v,int k){
        node* temp=head;
        while(1){
            if(temp==NULL || temp->data==k){
                break;
            }temp=temp->next;
        }if(temp==NULL){
            cout<<"Value Not Found"<<endl;
        }else{
            temp->data=v;
        }print();
    }
    void Remove_Head(){
        if(head==NULL){
            cout<<"Underflow"<<endl;
        }else{
            node* temp=head;
            head=head->next;
            delete temp;
        }print();
    }
    void Remove_End(){
        if(head==NULL){
            cout<<"Underflow"<<endl;
            print();
        }else if(head==tail){
            Remove_Head();
        }else{
            node* temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }node* temp1=temp->next;
            temp->next=NULL;
            tail=temp;
            delete temp1;
            print();
        }
    }
    void Remove_Element(int k){
        if(head==NULL){
            cout<<"Underflow"<<endl;
            print();
        }else if(head->data==k){
            Remove_Head();
        }else if(tail->data==k){
            Remove_End();
        }else{
            node* temp=head;
            while(1){
                if(temp->next==NULL || temp->next->data==k){
                    break;
                }temp=temp->next;
            }if(temp->next==NULL){
                cout<<"Value Not Found"<<endl;
            }else{
                node* temp1=temp->next->next;
                delete temp->next;
                temp->next=temp1;
            }print();
        }
    }
};

int main(){
    LinkedList ll;
    int n,v,k;
    while(1){
        cin>>n;
        if(n==1){
            cin>>v;
            ll.Insert_Front(v);
        }else if(n==2){
            cin>>v;
            ll.Insert_Back(v);
        }else if(n==3){
            cin>>v>>k;
            ll.Insert_After_Node(v,k);
        }else if(n==4){
            cin>>v>>k;
            ll.Update_Node(v,k);
        }else if(n==5){
            ll.Remove_Head();
        }else if(n==6){
            cin>>k;
            ll.Remove_Element(k);
        }else if(n==7){
            ll.Remove_End();
        }else if(n==8){
            cout<<"Exit";
            break;
        }
    }return 0;
}