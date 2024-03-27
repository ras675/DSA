#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    stack<int>st;
    string s;
    cin>>s;
    int x,y;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/'){
            st.push(s[i]-48);
        }else{
            x=st.top();
            st.pop();
            y=st.top();
            st.pop();
            if(s[i]=='+'){
                st.push(y+x);
            }else if(s[i]=='-'){
                st.push(y-x);
            }else if(s[i]=='*'){
                st.push(y*x);
            }else{
                st.push(y/x);
            }
        }
    }cout<<st.top();
    return 0;
}
