#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    stack<string>html;
    int n,i,j,y=0;
    cin>>n;
    cin.ignore();
    for(i=0; i<n; i++){
        string a;
        getline(cin,a);
        for(j=0; j<a.size();){
            if(a[j]=='<'){
                string b="";
                j++;
                while(a[j]!='>'){
                    b+=a[j];
                    j++;
                }
                if(b[0]!='/'){  // If it's an opening tag
                    html.push(b);
                    b="";
                }
                else{ // If it's a closing tag
                    string c="";
                    int k;
                    for(k=1; k<b.size(); k++)
                    {
                        c+=b[k];
                    }
                    b="";
                    if(html.top()==c && html.size()!=0)
                    {
                        html.pop();
                        c="";
                    }
                    else
                    {
                        if(y==0)
                        {
                            y=i+1;
                        }
                        c="";
                    }
                }
            }
            j++;
        }
    }
    int o;
    cin>>o;
    if(o==-1){
        if(y!=0){
            cout<<"Error at line "<<y<<endl;
        }
        else if(y==0){
            cout<<"No error"<<endl;
        }
    }
}