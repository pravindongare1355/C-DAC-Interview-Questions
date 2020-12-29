#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{

	char str[5][6],temp[6];
	int i,j;
	printf("Enter the 5 strings:-\n");
	for(i=0;i<5;i++)
	{
		
			scanf("%s",&str[i]);
		
	}
	

	for(i=0;i<5;i++)
	{
		for(j=i;j<5;j++)
		{
			if(strlen(str[i])>strlen(str[j+1]))
			{
			
				strcpy(temp,str[i]);
				strcpy(str[i],str[j+1]);
				strcpy(str[j+1],temp);
			}
		}
	}
	
	for(i=0;i<5;i++)
	{
		
			printf("%s\n",str[i]);
		
	}
}

































































































