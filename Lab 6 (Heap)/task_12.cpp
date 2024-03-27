#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;
    while(cin >> n && n != 0){
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            pq.push(x);
        }

        int cost = 0;
        while(!pq.empty()){
            int m1 = pq.top();
            pq.pop();
            int m2 = pq.top();
            pq.pop();
            cost += (m1 + m2);
            if(!pq.empty()){
                pq.push(m1 + m2);
            }
        }

        cout << cost << endl;
    }
    return 0;
}