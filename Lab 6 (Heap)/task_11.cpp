#include<iostream>
using namespace std;
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void exchange(int arr[],int size){
    for(int i=1;i<size;i++){
        arr[i-1]=arr[i];
    }
}
void heapify(int arr[],int index,int size){
    int i=index,l=index*2+1,r=index*2+2;
    if(l<size && arr[l]>arr[index]){
        index=l;
    }if(r<size && arr[r]>arr[index]){
        index=r;
    }if(index!=i){
        swap(&arr[i],&arr[index]);
        heapify(arr,index,size);
    }
}
void build_max_heap(int arr[],int size){
    for(int i=(size/2)-1;i>=0;i--){
        heapify(arr,i,size);
    }
}
int main(){
    int arr[1000],x,size=0;
    while(1){
        cin>>x;
        if(x==-1){
            break;
        }arr[size]=x;
        size++;
    }int a,b;
    while(size>1){
        build_max_heap(arr,size);
        a=arr[0];
        exchange(arr,size);
        size--;
        build_max_heap(arr,size);
        b=arr[0];
        if(a-b==0 && size>1){
            exchange(arr,size);
            size--;
        }else{
            arr[0]=a-b;
        }
    }cout<<arr[0];
    return 0;
}