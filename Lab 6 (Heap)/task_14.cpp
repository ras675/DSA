#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;
    int a[1000];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    priority_queue<int> pq;
    int fst, snd, trd;
    for(int i=0; i<n; i++){
        pq.push(a[i]);
        if(pq.size() < 3){
            cout << "-1" << endl;
        }else{
            fst = pq.top();
            pq.pop();
            snd = pq.top();
            pq.pop();
            trd = pq.top();
            pq.pop();
            
            pq.push(fst);
            pq.push(snd);
            pq.push(trd);

            cout << fst * snd * trd << endl;
        }
    }
    return 0;
}