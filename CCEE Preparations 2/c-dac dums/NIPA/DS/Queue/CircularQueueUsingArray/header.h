#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class CQueue
{
	int * arr;
	int front;
	int rear;
	int size;
public:

	CQueue( int size );
	void insert( int data );
	int deleteData();
	int queueEmpty();
	int queueFull();
	void display();
	void freeMem();
};


CQueue::CQueue( int size )
{
	this->size = size;
	arr = new int[size];
	front = -1;
	rear = -1;
}

int CQueue::queueEmpty()
{
	if( front == rear )
		return 1;
	return 0;
}

int CQueue::queueFull()
{
	if( ((rear + 1)%size )== front || (front==-1 && rear == (size - 1) ))
		return 1;
	return 0;
}


void CQueue::insert( int data )
{
	if( !queueFull() )
	{
		rear = (rear + 1)%size;
		arr[rear] = data;
		
	}
	else
		cout<<" Queue Overflow!";
}



int CQueue::deleteData()
{
	if( !queueEmpty() )
	{
		front = ( front  + 1 )%size;
		return arr[front];
	}

	return -333;
}



void CQueue::display()
{
	if( !queueEmpty() )
	{
		for( int i = (front + 1) % size ; i != rear; i = (i+1)%size )
			cout<<" "<<arr[i];

		cout<<" "<<arr[i];
	}
}



void CQueue::freeMem()
{
	delete []arr;
}

