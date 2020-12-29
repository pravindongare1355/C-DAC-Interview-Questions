#include "header.h"

int main()
{
	CQueue q(6);
	
	int data, choice;

	while( 1 )
	{
		system("cls");
		q.display();

		cout<<"\n\n\t1. insert";
		cout<<"\n\t2. delete";
		cout<<"\n\t3. exit";
		cout<<"\n\t\tChoice: ";
		cin>>choice;

		switch( choice )
		{
		case 1:
			cout<<"\n\tEnter data: ";
			cin>>data;
			q.insert( data );
			break;
		case 2:
			cout<<"\ndeleted data is: "<<q.deleteData()<<endl;
			getch();
			break;
		case 3:
			q.freeMem();
			exit(0);
		}

	}

	return 0;
}