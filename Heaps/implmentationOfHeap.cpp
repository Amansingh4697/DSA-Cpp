#include<bits/stdc++.h>
using namespace std;
class heap{
    public:
    int arr[10];
    int size;
    heap(){
        arr[0] = -1;
        size = 0;
    }
    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;
        while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }else{
                break;
            }
        }
    }
    void print(){
        for(int i = 1;i<10;i++){
            cout<<arr[i]<<endl;
        }
    }
    void deletefromHeap(){
        if(size==0){
            cout<<"nothing to delete";
            return;
        }
        // step1 : put last element into pirst index;
        arr[1] = arr[size];
        // step2 : remove last element
        size--;
        // step3 : propogate root node to its correct positon
        int index = 1 ;
        while(index<size){
           int leftIndex = 2*index;
           int rightIndex = 2*index+1;
          if(leftIndex<=size && arr[leftIndex]>arr[index] && arr[leftIndex]>arr[rightIndex]){
             swap(arr[leftIndex],arr[index]);
             index = leftIndex;
          }
          else if(rightIndex<=size && arr[rightIndex]>arr[index] && arr[rightIndex]>arr[leftIndex]){
            swap(arr[rightIndex],arr[index]);
            index = rightIndex;
          }else{
            return;
          }
        }
    }
};
int main(){
    heap h1 =  heap();
    h1.insert(50);
    h1.insert(40);
    h1.insert(60);
    h1.insert(20);
    h1.print();
    h1.deletefromHeap();
    h1.print();
}
