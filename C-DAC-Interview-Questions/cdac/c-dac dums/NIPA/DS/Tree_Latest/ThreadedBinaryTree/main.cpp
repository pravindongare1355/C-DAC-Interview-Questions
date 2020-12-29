#include "header.h"


int main()
{
	TBinaryTree tbt;
	int data, choice;

	while(1)
	{
		system("cls");
		cout<<"\nIn   Order: ";
		tbt.displayInOrder();
		cout<<"\nPre   Order: ";
		tbt.displayPreOrder();
		
		
		cout<<"\n\n 1. Insert"<<endl;
		cout<<"\n 2. Delete"<<endl;
		cout<<" 3. Quit"<<endl;

		cout<<"\n\t\tChoice: ";
		cin>>choice;

		switch( choice )
		{
		case 1:
			cout<<" Enter the data: ";
			cin>>data;
			tbt.insert(data );
			break;
		case 2:
			cout<<"Enter the Data: ";
			cin>>data;
			tbt.deleteNode( data );
			break;
		case 3:
			exit(0);
		}
	}

	return 0;
}
