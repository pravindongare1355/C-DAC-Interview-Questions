#include<iostream.h>

void selectionSort( int * arr, int size )
{
	int i, j, min, temp;

	for( i = 0; i < size-1; i++ )
	{
		min = i;
		for( j = i+1; j < size; j++ )
		{
			if( arr[j]  < arr[min] )
				min = j;
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}


int main()
{
	int arr[100], size, i;

	cout<<"\nEnter how many elemnts: ";
	cin>>size;

	cout<<"\nEnter elements: ";
	for( i = 0; i < size; i++ )
		cin>>arr[i];

	selectionSort( arr, size );
	
	cout<<"The sorted array is : ";
	for( i = 0; i < size; i++ )
		cout<<"\n"<<arr[i];

	return 0;
}