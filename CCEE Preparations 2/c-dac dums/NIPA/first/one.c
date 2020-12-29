#include<stdio.h>
#include<conio.h>
int main()
{	
	int r,c1,c2,c3;
	for(r=1;r<=5;r++)
	{
		for(c1=r;c1<=5;c1++)
		{
			printf(" ");
		   
		}
			printf("%d",r);	
				
		for(c2=c1;c2<c1;c2++);
			{
				printf("%d%d",++r,r);
				
			}
		
	/*	for(c2=1;c2<=5;c2++)
		{	
			printf("%d ",c2);
			for(c3=c2;c3<=c2;c3++)
			{
				printf("%d ",c3);
			}
		}*/
		printf("\n");
	}
	return 0;
}