#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
   Node(int value){
      val = value;
      next = nullptr;
   }
};
class Stack{
    public:
    int Size = 0;
    Node* Top = nullptr;
    void push(int val){
     Node* newNode = new Node(val);
     newNode->next = Top;
     Top = newNode;
     Size = Size+1;
    }
    void pop(){
        Node* temp = Top;
        Top = Top->next;
        delete Top;
        Size = Size-1;
    }
    int top(){
    return Top->val;
   }
   int size(){
    return Size;
   }
};
int main(){
Stack st = Stack();
st.push(5);
st.push(6);
st.push(7);
cout<<st.top()<<" ";
cout<<st.size()<<" ";
st.pop();
cout<<st.size();
}
