#include<stdio.h>

void bubbleSort( int * arr, int size )
{
	int i, j, temp;
	int passes = size-1, comps = size -1;

	for( i = 0; i < passes; i++ )
	{
		int count = 0;
		for( j = 0; j < comps-i; j++ )
		{
			if( arr[j] > arr[j+1] )
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				count++;
			}
		}
		if( count == 0 )
			return;
	}
}

int main()
{
	int i, size, arr[100];

	printf("how many elements: ");
	scanf("%d",&size);

	for( i = 0; i < size; i++ )
		scanf("%d",&arr[i]);

	bubbleSort( arr, size );

	printf("The sorted array is : ");
	for( i = 0; i < size; i ++ )
		printf("\n%d",arr[i]);

	return 0;
}