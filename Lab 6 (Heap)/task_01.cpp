#include<iostream>
#include<algorithm>
using namespace std;

void max_Heapify(int Heap[], int idx){
    int n = Heap[0];
    int largest = idx;
    int left = 2 * idx;
    int right = left + 1;

    if(left <= n && Heap[left] > Heap[largest]){
        largest = left;
    }
    if(right <= n && Heap[right] > Heap[largest]){
        largest = right;
    }

    if(largest != idx){
        swap(Heap[largest], Heap[idx]);
        max_Heapify(Heap, largest);
    }
}

void build_max_Heap(int Heap[]){ 
    int n = Heap[0];
    for(int i = n/2; i>0; i--){
        max_Heapify(Heap, i);
    }
}

void HeapSort(int Heap[]){      // SONRTING IN INCREASING ORDER
    int n = Heap[0], temp_sz = Heap[0];
    build_max_Heap(Heap);
    for(int i = n; i>1; i--){
        swap(Heap[i], Heap[1]);
        n--;
        Heap[0] = n;
        max_Heapify(Heap, 1);
    }
    Heap[0] = temp_sz;
}

int main(){
    int Heap[1000];
    int n = 0, x = 0;     // n = heapsize
    while(cin >> x && x != -1){
        Heap[++n] = x;
    }   Heap[0] = n;

    build_max_Heap(Heap);
    cout << "Max Heap: ";
    for(int i=1; i<=n; i++){
        cout << Heap[i] << " ";
    } 
    cout << endl;

    HeapSort(Heap);
    cout << "Sorted: ";
    for(int i=n; i>=1; i--){
        cout << Heap[i] << " ";
    } 
    cout << endl;

    return 0;
}