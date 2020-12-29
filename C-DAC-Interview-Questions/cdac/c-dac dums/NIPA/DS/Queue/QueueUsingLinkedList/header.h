#include <iostream.h>
#include <stdlib.h>
#include <conio.h>



class Node
{
	int data;
	Node * next;
public:
	Node( int data );
	int getData();
	Node * getNext();
	void setNext( Node * );

};

Node::Node( int data )
{
	this->data = data;
	next = NULL;
}

int Node::getData()
{
	return data;
}

Node * Node::getNext()
{
	return next;
}

void Node::setNext( Node * next )
{
	this->next = next;
}



class QueueLL
{
	Node * front;
	Node * rear ;

public:
	QueueLL();
	int queueEmpty();
	void insert( int );
	int deleteData();
	void display();
};


QueueLL::QueueLL()
{
	front = NULL;
	rear = NULL;
}


int QueueLL::deleteData()
{
	int data = -333;
	Node *temp;

   	if( !queueEmpty() )
	{
		data = front->getData();
		temp = front;
		front = front->getNext();
		delete temp;
		if( front == NULL )
			rear = NULL;
	}

	return data;
}

void QueueLL::insert( int data )
{
	Node * newNode = new Node( data );

	if( queueEmpty() )
	{
		front = rear = newNode;
	}
	else
	{
		rear->setNext( newNode );
int QueueLL::queueEmpty()
{
	if( front == NULL && rear == NULL )
		return 1;

	return 0;
}

void QueueLL::display()
{
	Node * temp;

	temp = front;

	while( temp )
	{
		cout<<" "<<temp->getData();
		temp = temp->getNext();
	}
}