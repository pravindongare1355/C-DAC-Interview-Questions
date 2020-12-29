#include<stdio.h>
#include<string.h>
void test();

class student1
{
  
	int rollno;
	int age;
	char name[20];
  public:
	  char * GetName();
	  
	  int GetAge();
	  
	  int GetRollno();
	  
	  void SetName(char * nm);
	  
	  void SetAge(int a);
	  
	  void SetRoll(int r);	  

		void Display();
	
};