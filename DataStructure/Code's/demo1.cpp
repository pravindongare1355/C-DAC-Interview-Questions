#include<iostream>
using namespace std;

int arr[5];
static int count;

void push(int i)
{
	if(count >= 5)
	{
		cout<<"Stack is Full !!";
	}
	else if(count < 5)
	{
	    arr[count ++] = i;	
	}
	

   	
}

void pop()
{
	if(count == -1)
	{
		cout<<"Stack is Empty !!"<<endl;
	    
		count--;
		

    }
    else if(count >)
}
void show()
{
	for(int i=0; i<count; i++)
	{
		cout<<arr[i]<<endl;
	}
}

int main()
{
	push(10);
	push(20);
	push(30);
    push(40);
	push(50);
    push(30);

	show();
cout<<"====================================="<<endl;	
	pop();
	return 0;
}
