#include "header.h"

int main()
{
	int choice, data;
	QueueLL q1;

	while( 1 )
	{
		system("cls");
		q1.display();
		
		cout<<"\n\n\t1. Insert. ";
		cout<<"\n\t2. Delete data.";
		cout<<"\n\t3. Exit";
		cout<<"\n\t\tChoice: ";
		cin>>choice;

		switch( choice )
		{
		case 1:
			cout<<"\n\tEnter data: ";
			cin>>data;
			q1.insert( data );
			break;
		case 2:
			data = q1.deleteData();
			if( data != -333 )
			{
				cout<<"\nDeleted data: "<<data<<endl;
				getch();
			}
			else
				cout<<"\nQueue is Empty..";
			break;
		case 3:
			exit(0);
		}
	}
}