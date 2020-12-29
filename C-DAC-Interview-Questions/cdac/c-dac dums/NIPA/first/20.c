#include<stdio.h>
#include<conio.h>
int main()
{
	char ch='G';
	int i,j;
	for(i=0;i<7;i++)
	{
		for(j=i;j<7;j++)
		{
			printf("%c",ch);
			ch--;
		}
		printf("\n");
	}
	return 0;
}