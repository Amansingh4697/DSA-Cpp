#include <iostream>
using namespace std;
class Queue{
public:
int qe[10];
int currsize = 0;
int start = -1;
int end = -1;
void push(int x){
if(currsize == 10){
    cout<<"queue overflow";
    return;
}
else if(currsize == 0){
    start = 0;
    end = 0;
}
else{
    end = (end+1)%10; 
}
qe[end] = x;
currsize += 1;
}
void pop(){
    if(currsize == 0 ){
        cout<<"queue underflow";
    }
    else if(currsize == 1){
        start = -1;
        end = -1;
    }else{
        start = (start + 1)%10;
    }
    currsize -= 1;
}
int size(){
   return currsize;
}
int top(){
    return qe[start];
}
};
int main(){
Queue* qe = new Queue();
qe->push(10);
qe->push(20);
cout<<qe->top()<<" ";
qe->push(30);
qe->push(40);
qe->push(50);
qe->push(60);
qe->push(70);
qe->push(80);
qe->push(90);
qe->push(100);
cout<<qe->size()<<" ";
qe->pop();
cout<<qe->top()<<" ";
cout<<qe->size()<<" ";
qe->push(110);
cout<<qe->top()<<" ";
}

gfg

class myStack {
  public:
   
    int* arr;
    int capacity;
    int top;
    myStack(int n) {
        // Define Data Structures
        capacity = n;
        arr = new int[capacity];
        top = -1;
    }

    bool isEmpty() {
        // check if the stack is empty
        if(top == -1) return true;
        return false;
    }

    bool isFull() {
        // check if the stack is full
        if(top >= capacity-1) return true;
        return false;
    }

    void push(int x) {
        // inserts x at the top of the stack
        // if(top>=capacity-1){
        //     cout<<"stack overflow";
        //     return;
        // }
        if(isFull()){
            return;
        }
        top = top + 1;
        arr[top] = x;
    }

    void pop() {
        // removes an element from the top of the stack
        // if(top == -1){
        //     cout<<"stack Underflow";
        //     return;
        // }
        if(isEmpty()){
            return;
        }
        top = top-1;
    }

    int peek() {
        // Returns the top element of the stack
        if(top == -1) return -1;
        return arr[top];
    }
};
