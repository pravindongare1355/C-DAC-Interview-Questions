#include <iostream>
using namespace std;

class Queue {
    int * arr;
    int size;
    int front, rear;
public:
    Queue( int size = 4 ) {
        this->size = size;
        front = rear = -1;
        arr = new int[size];
    }
    ~Queue() {
        delete [] arr;
    }
    bool isFull() {
        return rear == (size - 1);
    }
    bool isEmpty() {
        if( ( front == -1 && rear == -1 ) || ( front > rear ) )
            return true;
        
        return false;
    }
    
    bool insert( int data ) {
        
        if( isFull() ) {
            return false;
        }
        
        arr[++rear] = data;
        if( front == -1 ) {
            front = 0;
        }
        
        return true;
    }
    
    int deleteData() {
        
        if( isEmpty() ) {
            return -999;
        }
        
        return arr[front++];
        
    }
};




















