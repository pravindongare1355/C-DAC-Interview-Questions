#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

class Node
{
	int data;
	Node * right;
	Node * left;
	char lflag;
	char rflag;
public:
	Node( int data );

	int getData();
	void setData( int );
	
	void setRight( Node * );
	Node * getRight();

	void setLeft( Node * );
	Node * getLeft();

	void setlflag( char );
	char getlflag();
	void setrflag( char );
	char getrflag();
};

Node::Node( int data )
{
	this->data = data;
	right = NULL;
	left = NULL;
	lflag = 'T';
	rflag = 'T';
}

int Node::getData()
{
	return data;
}

void Node::setData( int data )
{
	this->data = data;
}

void  Node::setRight( Node * right )
{
	this->right = right;
}

Node * Node::getRight()
{
	return right;
}

void  Node::setLeft( Node * left )
{
	this->left = left;
}

Node * Node::getLeft()
{
	return left;
}

void Node::setlflag( char flag )
{
	lflag = flag;
}

char Node::getlflag()
{
	return lflag;
}

void Node::setrflag( char flag )
{
	rflag = flag;
}

char Node::getrflag()
{
	return rflag;
}



class TBinaryTree
{
	Node * root;
public:
	TBinaryTree();
	void insert( int );
	void displayInOrder();
	void displayPreOrder ();
	void displayPostOrder();
	int deleteNode( int data );
	int RightSon(Node *);
};

TBinaryTree::TBinaryTree()
{
	root = NULL;
}

void TBinaryTree::insert( int data )
{
	Node *temp1;
	Node * newNode = new Node( data );

	temp1 = root;
	if( root == NULL)
		root = newNode;
	else
	{
		
		
		while(1)
		{
			if( newNode->getData() < temp1->getData() )
			{
				if(temp1->getlflag() == 'T')
				{
					newNode->setLeft ( temp1->getLeft() );
					newNode->setRight( temp1 );
					temp1->setLeft( newNode );
					temp1->setlflag( 'L' );
					break;
				}
				temp1 = temp1->getLeft();
			}
			else
			{
				if(temp1->getrflag() == 'T')
				{
					
					newNode->setRight( temp1->getRight() );
					
					newNode->setLeft( temp1 );
					
					temp1->setRight( newNode );
					
					temp1->setrflag( 'L' );
					break;
				}
				temp1 = temp1->getRight();
			}
		}
			
	}
}


void TBinaryTree::displayInOrder()
{
	Node *temp ;
	char flag = 'L';
	temp = root;
	while(temp != NULL )
	{
		while(temp->getlflag() != 'T' && flag == 'L')
		{
			temp = temp->getLeft();
		}
		cout<<" ";
		cout<< temp->getData();
		flag = temp->getrflag();
		temp = temp->getRight();
	}

}

void TBinaryTree:: displayPreOrder ( )
{
	Node * Temp=  root;
	char flag='L';
	while(Temp)
	{
		while(Temp->getlflag() !='T' && flag == 'L')
		{
			cout<<" "<< Temp->getData();
			Temp=Temp->getLeft();
		}
		if(flag=='L')
			cout<<" "<< Temp->getData();
		flag=Temp->getrflag();
		Temp=Temp->getRight();
	}
}
int TBinaryTree::RightSon(Node *curr)
{
	char flag='L';
	Node * temp= root;
	do
	{
		while(temp->getlflag()=='L'&&flag=='L')
		{
			temp=temp->getLeft();
			if(curr==temp)
				return 0;
		}
		flag=temp->getrflag();
		temp=temp->getRight();
		if(flag=='L'&&temp==curr)
			return 1;
	}while(temp!=NULL);
	return 0;
}



void TBinaryTree::displayPostOrder()
{
	
	int a;
	char flag='L';
	Node * curr=root;

	while(curr)
	{
		while(curr->getlflag()=='L'&&flag=='L')
			curr=curr->getLeft();

		flag=curr->getrflag();
		if(flag=='L')
		{
			curr=curr->getRight();
		}
		else
		{
			while(1)
			{
				cout<<" "<<curr->getData();
				a=RightSon(curr);
				if(a==1)
				{
					while(curr->getlflag()=='L')
						curr=curr->getLeft();
					
					curr=curr->getLeft();
				}
				else
				{
					while(curr->getrflag()=='L')
						curr=curr->getRight();
					curr=curr->getRight();
					flag='T';
					break;
				}
			}
		}

	}
}

int TBinaryTree::deleteNode( int data )
{
	char flag;
	Node * parent = NULL, * deletable = NULL;
	parent = deletable = root;


	while( deletable->getData() != data )
	{
		if( deletable->getData() < data )
		{
			if( deletable->getrflag() == 'T')
				return 0;

			flag = 'R';
			parent = deletable;
			deletable = deletable->getRight();
		}
		else
		{
			if( deletable->getlflag() == 'T')
				return 0;

			flag = 'L';
			parent = deletable;
			deletable = deletable->getLeft();
		}
	}

	while(1) 
	{
		if( deletable->getlflag() == 'T' && deletable->getrflag() == 'T' )
		{
			if( deletable == root )
			{
				root = NULL;
			}
			else
			{
				if( flag == 'L')
				{
					parent->setLeft( deletable->getLeft() );
					parent->setlflag('T');
				}
				if( flag == 'R')
				{
					parent->setRight( deletable->getRight() );
					parent->setrflag( 'T' );
				}
			}

			delete deletable;
			return 1;

		}
		else
		{
			Node * max, * min;
			int temp;
			if(  deletable->getlflag() == 'L' )
			{
				//max = getMaxFromLeft( deletable );
				parent = deletable;
				max = deletable->getLeft();
				flag = 'L';

				while( max->getrflag() == 'L' )
				{
					parent = max;
					max = max->getRight();
					flag = 'R';
				}
				
				temp = max->getData();
				max->setData( deletable->getData() );
				deletable->setData( temp );
				
				deletable = max;
				
			}
			else
			{
				//min = getMinFromRight( deletabel );
				min = deletable->getRight();
				parent = deletable;
				flag = 'R';

				while( min->getlflag() == 'L')
				{
					parent = min;
					min = min->getLeft();
					flag = 'L';
				}
				

				temp = min->getData();
				min->setData( deletable->getData() );
				deletable->setData( temp );
				
				deletable = min;
				
			}
		}
	}
}






