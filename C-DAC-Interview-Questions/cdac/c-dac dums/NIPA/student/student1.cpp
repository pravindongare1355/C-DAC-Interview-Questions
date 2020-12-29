#include "student1.h"


	char * student1::GetName()
	{
		  return name;
	}
	////////////////////////////
	int student1::GetAge()
	{
		  return age;
	}
	///////////////////////////	
	int student1::GetRollno()
	{
		  return rollno;
	}
	////////////////////////////
	void student1::SetName(char * nm)
	{
		  strcpy(name,nm);
	}
	///////////////////////////	
	void student1::SetAge(int a)
	{
		age=a;
	}
	///////////////////////////	
	void student1::SetRoll(int r)
	{
		  rollno=r;
	}
	///////////////////////////	
	void student1::Display()
	{
		printf("\n Name=%s",name);
		printf("\n age=%d",age);
		printf("\n Roll No=%d",rollno);
	}
	///////////////////////////	

