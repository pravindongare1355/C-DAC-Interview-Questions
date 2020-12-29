#include "header.h"

int main()
{
	Queue q(4);

	int choice, data, del;

	while( 1 )
	{
		system("cls");
		q.display();

		cout<<" 1. Insert "<<endl;
		cout<<" 2. Delete "<<endl;
		cout<<" 3. Quit "<<endl;
		cout<<"\n\t\tChoice: ";
		cin>>choice;

		switch( choice )
		{

		case 1:
			cout<<"\n\tEnter data: ";
			cin>>data;
			q.insert(data);
			break;

		case 2:
			del = q.deleteData();
			if( del != NULL )
			{
				cout<<"\n\t Deleted data is: "<<del;
				//getch();
			}
			break;

		case 3:
			exit(0);
		}
	}

	return 0;
}