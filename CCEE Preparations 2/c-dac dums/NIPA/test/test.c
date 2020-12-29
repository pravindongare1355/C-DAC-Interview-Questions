#include<stdio.h>
#include<conio.h>
void seclar(int a[5],int n);
void smallar(int a[5],int n);
void main()
{
	int a[5],i,j,temp;

	printf("Enter the 5 element in the array:-");
	for(i=0;i<5;i++)
	{
		scanf("\n%d",&a[i]);
	}
	
/*	for(i=0;i<5;i++)
	{
		printf("%d\t",a[i]);
	}*/
	seclar(a,5);
	
	smallar(a,5);
	/*	for(i=0;i<5;i++)
	{
		for(j=i;j<5;j++)
		{
			if(a[i]>a[j+1])
			{
				temp=a[i];
				a[i]=a[j+1];
				a[j+1]=temp;
			}
		}
	}1

	for(i=0;i<5;i++)
	{
		printf("%d\t",a[i]);
	}*/
}

void seclar(int a[5],int n)
{
int i,j,temp;


	for(i=0;i<5;i++)
	{
		for(j=i;j<5;j++)
		{
			if(a[i]>a[j+1])
			{
				temp=a[i];
				a[i]=a[j+1];
				a[j+1]=temp;
			}
		}
	}

	for(i=0;i<5;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\nSecond largest no. is:-%d",a[0]);
}

void smallar(int a[5],int n)
{
int i,j,temp;


	for(i=0;i<5;i++)
	{
		for(j=i;j<5;j++)
		{
			if(a[i]>a[j+1])
			{
				temp=a[i];
				a[i]=a[j+1];
				a[j+1]=temp;
			}
		}
	}

	for(i=0;i<5;i++)
	{
		printf("\n%d\t",a[i]);
	}
	printf("\nsmallest no. is:-%d",a[0]);
}