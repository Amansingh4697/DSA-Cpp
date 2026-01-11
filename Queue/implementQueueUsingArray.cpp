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
