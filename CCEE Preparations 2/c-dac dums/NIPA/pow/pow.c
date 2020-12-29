#include<stdio.h>
#include<conio.h>

void main()
{
	int a,b,rem1,quo1,rem2,quo2,sum=0,i,j=1;

	printf("\n Enter the Two Nos:-");
	scanf("%d %d",&a,&b);

	while(a!=0)
	{
		rem1=a % 10;
		a=a / 10;
		quo2=b;
		
		while(quo2!=0)
		{
			rem2=quo2 % 10;
			quo2=quo2 / 10;
			j=1;
			for(i=0;i<rem2;i++)
			{
				j=j*rem1;	
				
			}
			sum=sum+j;
		}
	}
	printf("\n %d",sum);
}