#include <iostream.h>
#include <stdlib.h>

class Node
{
	int data;
	Node * leftLink;
	Node * rightLink;

public:

	Node( int data )
	{
		leftLink = NULL;
		rightLink = NULL;
		this->data = data;
	}

	Node * getLeftLink()
	{
		return leftLink;
	}

	Node *  getRightLink()
	{
		return rightLink;
	}

	void setLeftLink( Node * link )
	{
		leftLink = link;
	}

	void setRightLink( Node * link )
	{
		rightLink = link;
	}

	int getData()
	{
		return data;
	}
	
	void setData( int data )
	{
		this->data = data;
	}

};



class BSearchTree
{
	Node * root;

public:
	BSearchTree();
	void insert( int data );
	int displayInOrder( Node * );
	int displayPostOrder( Node * );
	int displayPreOrder( Node * );
	Node * getRoot();
//	Node & deleteNode( int );
	int deleteNode( int );
	void NonRecInorder();
	void NonRecPreOrder();
	void NonRecPostOrder();
	freeTree( Node * root )
	{
		if( root )
		{
			freeTree( root->getLeftLink() );
			freeTree( root->getRightLink() );
			delete root;
		}
	}
	~BSearchTree()
	{
		freeTree( root );
	}
};

BSearchTree::BSearchTree()
{
	root = NULL;
}

void BSearchTree::insert( int data )
{
	Node * newNode = new Node( data );

	if( root == NULL )
	{
		root = newNode;
	}
	else
	{
		Node * temp = root;
		
		while(1)
		{
			if( newNode->getData() < temp->getData() )
			{
				if( temp->getLeftLink() )
					temp = temp->getLeftLink();
				else
				{
					temp->setLeftLink( newNode );
					break;
				}
			}
			else
			{
				if( temp->getRightLink() )
					temp = temp->getRightLink();
				else
				{
					temp->setRightLink( newNode );
					break;
				}
			}
		}
	}
}


int BSearchTree::displayInOrder( Node * link )
{
	if( link == NULL )
		return 0;

	displayInOrder( link->getLeftLink() );
	cout<<" "<<link->getData();
	displayInOrder( link->getRightLink() );

		return 0;
}


int BSearchTree::displayPostOrder( Node * link )
{
	if( link == NULL )
		return 0;

	displayPostOrder( link->getLeftLink() );
	displayPostOrder( link->getRightLink() );
	cout<<" "<<link->getData();

		return 0;
}

int BSearchTree::displayPreOrder( Node * link )
{
	if( link == NULL )
		return 0;

	cout<<" "<<link->getData();
	displayPreOrder( link->getLeftLink() );
	displayPreOrder( link->getRightLink() );
	

		return 0;
}

Node * BSearchTree::getRoot()
{
	return root;
}






int BSearchTree::deleteNode( int data )
{
	char flag;
	Node * parent = NULL, * deletable = NULL;
	parent = deletable = root;

	if( root == NULL )
		return 0;

	while( deletable->getData() != data )
	{
		if( deletable->getData() < data )
		{
			flag = 'R';
			parent = deletable;
			deletable = deletable->getRightLink();
		}
		else
		{
			flag = 'L';
			parent = deletable;
			deletable = deletable->getLeftLink();
		}
		if( deletable == NULL )
			return 0;

		
	}

	while(1) 
	{
		if( deletable->getLeftLink() == deletable->getRightLink() )
		{
			if( deletable == root )
			{
				root = NULL;
			}
			else
			{
				if( flag == 'L')
					parent->setLeftLink( NULL );
				if( flag == 'R')
					parent->setRightLink( NULL );
			}

			delete deletable;
			return 1;



		}
		else
		{
			Node * max, * min;
			int temp;
			if( deletable->getLeftLink() )
			{
				//max = getMaxFromLeft( deletable );
				parent = deletable;
				max = deletable->getLeftLink();
				flag = 'L';

				while( max->getRightLink() )
				{
					parent = max;
					max = max->getRightLink();
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
				min = deletable->getRightLink();
				parent = deletable;
				flag = 'R';

				while( min->getLeftLink() )
				{
					parent = min;
					min = min->getLeftLink();
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

void BSearchTree::NonRecInorder()
{
	Node * stack[100];
	int top = -1;

	if( root == NULL )
		return;
	Node * temp = root;
	
	do
	{
		while( temp->getLeftLink() )
		{	
			++top;
			stack[top] = temp;
			temp = temp->getLeftLink();
		}
		cout<<" "<<temp->getData();
		temp = temp->getRightLink();			
		if( temp == NULL && top != -1 )
			temp = stack[top--];
	}while( top != -1 || temp != NULL );
}


void BSearchTree::NonRecPreOrder()
{
	Node * stack[100];
	int top = -1;

	if( root == NULL )
		return;

	Node * temp = root;
	do
	{
		while( temp )
		{
			cout<<" "<<temp->getData();
			stack[++top] = temp;
			temp = temp->getLeftLink();
		}
		temp = stack[top--];
		temp = temp->getRightLink();

	}while( temp || top != -1 );
}


void BSearchTree::NonRecPostOrder()
{
	typedef struct 
	{
		int flag; 
		Node * link;
	}Entry;
	Entry stack[100];
	
	int top = -1;

	Node * temp = root;

	while( temp )
	{
		++top;
		stack[top].flag = 0;
		stack[top].link = temp;

		temp = temp->getLeftLink();
	}
	
	while( top != -1 )
	{
		if( stack[top].flag == 0 )
		{
			stack[top].flag = 1;
			temp = stack[top].link;
			temp = temp->getRightLink();

			while( temp != NULL )
			{
				top++;
				stack[top].link = temp;
				stack[top].flag = 0;
				temp = temp->getLeftLink();
			}
		}
		else
		{
			temp = stack[top].link;
			cout<<" "<<temp->getData();
			top--;
		}
	}
}