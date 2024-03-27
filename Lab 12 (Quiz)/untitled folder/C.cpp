#include<iostream>
using namespace std;
struct s{
    int b,e;
};
int search(s f[],int x,int n){
    int m,l=0,r=n-1;
    while(l<= r){
        m=(l+r)/2;
        if(f[m].b>x){
            r=m-1;
        }else if(f[m].e<x){
            l=m+1;
        }else if(f[m].b<=x && f[m].e>=x){
            return m+1;
        }
    }return -1;
}
int main(){
    int i,n,x,m=0;
    cin>>n;
    s f[n];
    f[0].b=1;
    for(i=0;i<n;i++){
        cin>>x;
        m+=x;
        if(i!=n-1){
            f[i+1].b=m+1;
        }f[i].e=m;
    }cin>>m;
    for(i=0;i<m;i++){
        cin>>x;
        cout<<search(f,x,n)<<endl;
    }return 0;
}
