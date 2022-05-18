#include <iostream>
using std::cout;
class Node {
public:
    int _info;
    Node *_rear = nullptr;
    Node *_front = nullptr;
};

class Queue {
    Node *_head = nullptr;
    Node *_back = nullptr;
public:
    void insert(int x){
        
        if(_head == nullptr && _back == nullptr){
            Node *p = new Node();
            
            p->_info = x;
            
            _head = p;
            _back = p;
            
            return;
        }
        
        Node *newNode = new Node();
        
        newNode->_info = x;
        
        _back->_rear = newNode;
        newNode->_front = _back;
        
        _back = newNode;
        
    }
    void remove(){
        if(_head == nullptr){
            cout << "void remove\n";
            return;
        }
        Node *temp = _head->_rear;
        delete _head;
        _head = temp;
    }
    void print(){
        if(_head == nullptr){
            cout << "queue is empty\n";
            return;
        }
        Node *temp = _back;
        while(temp != _head){
            cout << temp->_info << "-";
            temp = temp->_front;
        }
        cout << _head->_info << "\n";
    }
    friend bool is_empty(Queue q);
};
bool is_empty(Queue q){
    if(q._head != nullptr){
        return false;
    }
    return true;
}

int main(){
    Queue queue;
    queue.insert(10);
    queue.insert(20);
    queue.insert(30);
    queue.insert(40);
    queue.print();
    queue.remove();
    queue.print();
    queue.insert(50);
    queue.print();
    
    while(!is_empty(queue)){
        queue.remove();
    }
    //control
    queue.remove();
    queue.print();
    
}