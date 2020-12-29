#include<iostream.h>


void q_sort(int numbers[], int left, int right)
{
	int pivot, l_hold, r_hold;

	l_hold = left;
	r_hold = right;
	pivot = numbers[left];

	while (left < right)
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--;

		if (left != right)
		{
			numbers[left] = numbers[right];
			left++;
		}

		while ((numbers[left] <= pivot) && (left < right))
			left++;

		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}

	numbers[left] = pivot;

	if (l_hold < left)
		q_sort(numbers, l_hold, left-1);

	if (r_hold > left)
		q_sort(numbers, right+1, r_hold);
}

void quickSort(int numbers[], int array_size)
{
	q_sort(numbers, 0, array_size - 1);
}

void main()
{
	int a[]={10,-9,33,5,48,0,1};
	int i;


	quickSort(a,7);
	for(i=0;i<7;i++)
		cout<<" "<<a[i];



}