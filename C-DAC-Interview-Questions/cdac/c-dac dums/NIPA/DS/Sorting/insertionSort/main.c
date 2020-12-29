#include<iostream.h>

void insertionSort( int * arr, int size )
{
	int i, j, temp;
	for( i = 0; i < size; i++ )
	{
		for( j = 0; j < i; j++ )
		{
			if( arr[i] < arr[j] )
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


int main()
{
	int i, size, arr[100];

	cout<<"how many elements: ";
	cin>>size;

	cout<<"\nEnter the elements: ";
	for( i = 0; i < size; i++ )
		cin>>arr[i];

	insertionSort( arr, size );

	printf("The sorted array is : ");
	for( i = 0; i < size; i ++ )
		cout<<"\n"<<arr[i];

	return 0;
}