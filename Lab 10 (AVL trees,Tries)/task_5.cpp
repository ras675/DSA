#include<iostream>
using namespace std;

int printCnt;

struct Node{
    Node * next[26];
    bool endmark;
};

Node * createNode(){
    Node * newNode = new Node();
    newNode->endmark = false;
    for(int i=0; i<26; i++){
        newNode->next[i] = NULL;
    }
    return newNode;
}

Node * root = createNode();

void insert(string s){
    Node * temp = root;
    for(int i=0; i<s.size(); i++){
        int c = s[i] - 'a';
        if(temp->next[c] == NULL){
            temp->next[c] = createNode();
        }
        temp = temp->next[c];
    }
    temp->endmark = true;
}

bool search(string s){
    Node * temp = root;
    for(int i=0; i<s.size(); i++){
        int c = s[i] - 'a';
        if(temp->next[c] == NULL) return false;
        temp = temp->next[c];
    }
    return temp->endmark;
}

void display(Node * x, string ans, const string s){
    if(x->endmark == true && printCnt < 3) {
        printCnt++;
        cout << s << ans << " ";
    }
    for(int i=0; i<26; i++) {
        if(x->next[i] != NULL){
            char c = i + 'a';
            display(x->next[i], ans + c, s);
        }
    }
}

int main(){
    string str;
    getline(cin, str);
    string s = "";
    for(int i=0; i<str.size(); i++){
        if(str[i] == ' '){
            insert(s);
            s = "";
        }
        else s = s + str[i];
        if(i == str.size()-1) insert(s);
    }
    string x;
    cin >> x;
    s = "";
    Node * temp = root;
    for(int i=0; i<x.size(); i++){
        printCnt = 0;
        int c = x[i] - 'a';
        s += x[i];
        if(temp->next[c] != NULL){
            display(temp->next[c], "", s);
            cout << endl;
            temp = temp->next[c];
        }
        else cout << "Null" << endl;
    }
    return 0;
}