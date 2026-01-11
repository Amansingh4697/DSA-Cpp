#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack{
public:
    int st[10];
    int Top = -1;
    Stack(){    
    }
    void push(int x){
      Top = Top + 1;
      if(Top>=10) cout<<"stack Overflow";
      st[Top] = x;
    }
    void pop(){
        if(Top<0){
          cout<<"stack underflow";
        }
        Top = Top - 1;
    }
    int top(){
        return st[Top];
    }
    int size(){
        return Top + 1;
    }
};
int main(){
    Stack* st = new Stack();
    st->push(10);
    st->push(20);
    st->push(30);
    cout<<st->top()<<" ";
    st->pop();
    cout<<st->top()<<" ";
    cout<<st->size()<<" ";
    st->pop();
    st->pop();
    cout<<st->size();
}
