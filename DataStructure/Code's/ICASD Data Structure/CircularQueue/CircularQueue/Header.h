#include <iostream>
using namespace std;

class CircularQueue {
    int * arr;
    int size, front, rear;
public:
    CircularQueue( int size = 5 ) {
        this->size = size;
        front = rear = -1;
        arr = new int[ size ];
    }
    ~CircularQueue() {
        delete [] arr;
    }
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        if(  ( front == -1 && rear == (size-1) ) ||
           ( (rear+1) % size ==  front )  )
            return true;
        
        return false;
    }
    
    bool insert( int data ) {
        if( isFull() ) {
            return false;
        }
        
        rear = ( rear + 1 ) % size;
        arr[rear] = data;
        
        return true;
    }
    
    int deleteData() {
        if( isEmpty() ) {
            return -999;
        }
        
        front = ( front + 1 ) % size;
        return arr[front];
    }
    
};





















