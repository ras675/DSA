#include<iostream>
#include<string>

#define ALPH_SIZE 26
using namespace std;

struct trienode
{
    trienode *next[ALPH_SIZE];
    bool terminal;
};

trienode *createnode(){
    trienode *newnode=new trienode;

    for(int i=0; i<ALPH_SIZE;i++){
        newnode->next[i]=NULL;
    }
    newnode->terminal=false;
    return newnode;
}

bool trieInsert(trienode *root, string str, int len){
    trienode *curr=root;
    for(int i=0; i<len; i++){
        int idx=str[i]-'a';
        if(curr->next[idx]==NULL){
            curr->next[idx]= new trienode();
        }
        curr=curr->next[idx];
    }
        curr->terminal=true;
        return true;
}
bool search(trienode *root, string key)
{
    trienode *pCrawl = root;

    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (!pCrawl->next[index])
            return false;

        pCrawl = pCrawl->next[index];
    }

    return (pCrawl->terminal);
}
void display(trienode *curr, string str, int level){
    if(curr->terminal==true){
        str[level]='\0';
        cout<<str<<endl;
    }
    for(int i=0; i<ALPH_SIZE;i++){
        if(curr->next[i]!=NULL){
            str[level]='a'+i;
            display(curr->next[i],str,level+1);
        }
    }
}

int main(){
trienode *root = createnode();
    string words[] = {"toy", "algo", "algorithm", "to", "tom", "also", "algea", "tommy", "toyota"};
    int len = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < len; i++)
    {
        trieInsert(root, words[i], words[i].length());
    }

    string displayStr(50,'\0');
    display(root, displayStr, 0);

    int s;
    s=search(root, "toy");
    if(s==1) cout<<"T";
    else cout<<"F";
    s=search(root, "toyo");
    if(s==1) cout<<"T";
    else cout<<"F";
    s=search(root, "al");
    if(s==1) cout<<"T";
    else cout<<"F";
    s=search(root, "also");
    if(s==1) cout<<"T";
    else cout<<"F";
    s=search(root, "algorithm");
    if(s==1) cout<<"T";
    else cout<<"F";
    s=search(root, "algorithmic");
    if(s==1) cout<<"T";
    else cout<<"F";

    return 0;
}
