#include<stdio.h>
#include<string.h>
void main()
{
	char st[20][20] , temp[20];
	int n,i,j;
	printf("Enter the no of strings\n");
	scanf("%d",&n);
	printf("Enter the strings\n");
	for(i=0;i<n;i++)
		scanf("%s",st[i]);
	for(i=0;i<n;i++)
		for(j=0;j<n-1;j++)
			if(strlen(st[j])>strlen(st[j+1]))
			{
				strcpy(temp,st[j]);
				strcpy(st[j],st[j+1]);
				strcpy(st[j+1],temp);
			}
	printf("The shorted string array is\n");
	//for(i=0;i<n;i++)
		printf("%s\n",st[0]);

}

