#include<iostream>
#include<stack>
#include<deque>
#include<string>
using namespace std;
int main(){
    int num,i,j;
    cin>>num;
    cin.ignore();
    while(num--){
        string str;
        deque<char>d;
        stack<char>s;
        getline(cin,str);
        for(i=0;i<str.size();){
            if(str[i]=='['){
                i++;
                while(str[i]!='\0' && str[i]!=']' && str[i]!='['){
                    if(str[i]!='<'){
                        s.push(str[i]);
                    }else{
                        if(s.size()){
                            s.pop();
                        }
                    }i++;
                }while(s.size()){
                    d.push_front(s.top());
                    s.pop();
                }if(str[i]!='['){
                    i++;
                }
            }else if(str[i]=='<'){
                if(d.size()){
                    d.pop_back();
                }i++;
            }else if(str[i]==']'){
                i++;
            }else{
                d.push_back(str[i]);
                i++;
            }
        }while(d.size()){
            cout<<d.front();
            d.pop_front();
        }cout<<endl;
    }return 0;
}