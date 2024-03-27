#include<iostream>
#include<algorithm>
using namespace std;

void min_Heapify(int Heap[], int n, int idx){
    int smallest = idx;
    int left = 2 * idx;
    int right = left + 1;

    if(left <= n && Heap[left] < Heap[smallest]){
        smallest = left;
    }
    if(right <= n && Heap[right] < Heap[smallest]){
        smallest = right;
    }

    if(smallest != idx){
        swap(Heap[smallest], Heap[idx]);
        min_Heapify(Heap, n, smallest);
    }
}

void build_min_Heap(int Heap[], int n){ 
    for(int i = n/2; i>0; i--){
        min_Heapify(Heap, n, i);
    }
}

int Heap_Minimum(int Heap[]){
    return Heap[1];
}

int Heap_extract_min(int Heap[], int &n){
    int mini = Heap[1];
    swap(Heap[1], Heap[n]);
    n--;
    min_Heapify(Heap, n, 1);
    return mini;
}

void Min_heap_insert(int value, int Heap[], int &n){
    n++;
    Heap[n] = value;
    int i = n;
    while(i>1 && Heap[i] < Heap[i/2]){
        swap(Heap[i], Heap[i/2]);
        i = i/2;
    }
}

void Heap_decrease_key(int p, int k, int Heap[], int n){
    Heap[p] = Heap[p] - k;
    int i = p;
    while(i>1 && Heap[i] < Heap[i/2]){
        swap(Heap[i], Heap[i/2]);
        i = i/2;
    }
}

void Heap_increase_key(int key, int amount, int Heap[], int n){
    Heap[key] = Heap[key] + amount;
    min_Heapify(Heap, n, key);
}

void print_Heap(int Heap[], int n){
    for(int i=1; i<=n; i++){
        cout << Heap[i] << " ";
    } 
    cout << endl;
}

int main(){
    int n = 0, x = 0;
    int Heap[1000];    // Heap[0] stores the heapsize = n
    while(cin >> x && x != -1){
        Heap[++n] = x;
    }   Heap[0] = n;
    cout << "Min Heap: ";
    build_min_Heap(Heap, n);
    print_Heap(Heap, n);

    int cmd;
    while(cin >> cmd){
        if(cmd == 1){
            cout << Heap_Minimum(Heap) << endl;
            print_Heap(Heap, n);
        }else if(cmd == 2){
            cout << Heap_extract_min(Heap, n) << endl;
            print_Heap(Heap, n);
        }else if(cmd == 3){
            int value;  
            cin >> value;
            Min_heap_insert(value, Heap, n);
            print_Heap(Heap, n);
        }else if(cmd == 4){
            int p, k;
            cin >> p >> k;
            Heap_decrease_key(p, k, Heap, n);
            print_Heap(Heap, n);
        }else if(cmd == 5){
            int key, amount;
            cin >> key >> amount;
            Heap_increase_key(key, amount, Heap, n);
            print_Heap(Heap, n);
        }
    }
    return 0;
}