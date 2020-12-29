#include<stdio.h>
#include<conio.h>

void main()
{
	int i,j,k,h,l=0,m=4;

	for(i=0;i<=5;i++)
	{
		for(j=4;j>=i;j--)
		{
			printf(" ");
		} 
		for(k=l;k>=0;k--)
		{
			printf("%d",k);
		}
		l++;
		for(h=1;h<=i;h++)
		{
			printf("%d",h);
		}
		printf("\n");
	}

	for(i=0;i<5;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf(" ");
		}
		
		for(k=m;k>=0;k--)
		{
			printf("%d",k);
		}
		m--;
		for(h=1;h<=m+1;h++)
		{
			printf("%d",h);
		}
		printf("\n");

	}
}