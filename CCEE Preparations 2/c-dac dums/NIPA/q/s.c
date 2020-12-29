#include<stdio.h>
#include<conio.h>
int main()
{
	//char ch='G';
	int i='G',j,k,l=71;
	for(i=65;i<=71;i++)
	{
		for(k=65;k<=i;k++)
		{
			printf(" ");
		}
		for(j=l;j>=65;j--)
		{
			
			printf("%c",j);
			
		}
		l--;

		printf("\n");
		}
	return 0;
}