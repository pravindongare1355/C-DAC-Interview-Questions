#include "header.h"

int main()
{
	BSearchTree bst;
	int data, choice;

	while( 1 )
	{
		system("cls");
		cout<<"\nIn   Order: ";
		bst.displayInOrder( bst.getRoot() );
		cout<<"\nNR InOrder: ";
		//bst.NonRecInorder();
		cout<<endl;
		
		cout<<"\nPost Order  : ";
		bst.displayPostOrder( bst.getRoot() );
		cout<<"\nNR PostOrder: ";
		bst.NonRecPostOrder();
		cout<<endl;
		
		cout<<"\nPre  Order : ";
		bst.displayPreOrder( bst.getRoot() );
		cout<<"\nNR PreOrder: ";
		bst.NonRecPreOrder();
		cout<<endl;
		
		cout<<"\n #### MENU ####"<<endl;
		cout<<"\n\n 1. Insert"<<endl;
		cout<<" 2. Delete Node"<<endl;
		cout<<" 3. Exit"<<endl;

		cout<<"\n\t\tChoice: ";
		cin>>choice;

		switch( choice )
		{
		case 1:
			cout<<" Enter the data: ";
			cin>>data;
			bst.insert(data );
			break;
		case 2:
			cout<<"\n\tEnter the value of node to be deleted: ";
			cin>>data;
			bst.deleteNode( data );
			break;

		case 3:
			exit(0);
		}
	}

	return 0;
}
