#include<iostream>
using namespace std;

de
class Node{
	public :
		int data;
		Node* next;
};

//traversing

void printlist(Node* n)
{

    while(n!=NULL)
    {
    	cout<<n->data<<endl;
        n=n->next;	
	}
};


int main()
{
	
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;
	
	//memory allocate
	
	head = new Node();
	second = new Node();
	third = new Node();
	
	//connectivity of node
	
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next=third;
	
	third->data = 3;
	third->next = NULL;
	
    printlist(head);
	
};
