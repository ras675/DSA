#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
};
class DoublyLinkedList{
    node* head;
    node* tail;
public:
    DoublyLinkedList(){
        head=NULL;
        tail=NULL;
    }
    node* createNode(int v){
        node* temp=new node;
        temp->data=v;
        temp->next=NULL;
        temp->prev=NULL;
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
            }cout<<"  **  ";
            temp=tail;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->prev;
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
            head->prev=newNode;
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
            newNode->prev=tail;
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
                temp1->prev=newNode;
                newNode->prev=temp;
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
            if(head!=NULL){
                head->prev=NULL;
            }
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
            node* temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            delete temp;
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
                temp1->prev=temp;
                temp->next=temp1;
            }print();
        }
    }
};

int main(){
    DoublyLinkedList dll;
    int n,v,k;
    while(1){
        cin>>n;
        if(n==1){
            cin>>v;
            dll.Insert_Front(v);
        }else if(n==2){
            cin>>v;
            dll.Insert_Back(v);
        }else if(n==3){
            cin>>v>>k;
            dll.Insert_After_Node(v,k);
        }else if(n==4){
            cin>>v>>k;
            dll.Update_Node(v,k);
        }else if(n==5){
            dll.Remove_Head();
        }else if(n==6){
            cin>>k;
            dll.Remove_Element(k);
        }else if(n==7){
            dll.Remove_End();
        }else if(n==8){
            cout<<"Exit";
            break;
        }
    }return 0;
}