#include <iostream>
using namespace std;
class Node{
    public:
    Node* next;
    int val;
    Node(int value){
        val = value;
        next = nullptr;
    }
};
class Queue{
    public:
    Node* start = nullptr;
    Node* end = nullptr;
    int size = 0;
    void push(int val){
        Node* newNode = new Node(val);
        if(start == nullptr && end == nullptr){
            newNode->next = end;
            end = newNode;
            start = newNode;
            size = size + 1;
        }
        else{
            end->next = newNode;
            end = newNode;
            size = size + 1;
        }
    }
    void pop(){
        Node* temp = start;
        start = start->next;
        delete temp;
        size = size -1;
    }
    int top(){
        return start->val;
    }
    int Size(){
        return size;
    }
};
int main(){
    Queue q = Queue();
    q.push(6);
    q.push(7);
    q.push(8);
    cout<<q.top()<<" ";
    q.pop();
    cout<<q.top()<<" ";
    q.pop();
    q.pop();
    cout<< q.Size();
}
