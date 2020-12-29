#include<stdio.h>
#include<conio.h>

void main()
{
	int a,b,rem1,quo1,rem2,quo2,sum=0;

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
			sum=(rem1*rem2)+sum;
		}
	}
	printf("\n %d",sum);
}