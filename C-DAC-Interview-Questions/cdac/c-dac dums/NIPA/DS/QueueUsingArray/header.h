#include <iostream.h>
#include <stdlib.h>
#include <conio.h>


// This class represents a simple queue using an array
class Queue
{
	int *arr;
	int front, rear;
	int size;
public:
	Queue( int size );
	void insert( int data );
	int deleteData();
	int queueEmpty();
	int queueFull();
	void display();
};


Queue::Queue( int size )
{
	this->size =size;
	arr = new int[size];
	front = -1;
	rear = -1;
}


void Queue::insert( int data )
{
	if( !queueFull() )
	{
		rear++;
		arr[rear] = data;
		if( front == -1 ) 
			front = 0;
	}
	else
	{
		cout<<" Queue overflow!";
		
	}
}


int Queue::deleteData()
{
	if( !queueEmpty())
	{
		return arr[front++];
	}
	
	
	cout<<"Queue underflow!";

	return NULL;
	

}


int Queue::queueEmpty()
{
	if( front > rear || ( front == -1 && rear == -1 ))
		return 1;
                                                                                                                    
		return 0;
}


int Queue::queueFull()
{
	if( rear == size -1 )
		return 1;

	return 0;
}


void Queue::display()
{
	int i;
	cout<<endl;
	for( i = front; i > -1 && i <= rear; i++ )
		cout<<" "<<arr[i];

	cout<<endl;
}




