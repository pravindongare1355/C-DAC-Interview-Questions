#include "student.h"


char * student::GetName()
	{
		  return name;
	}
	////////////////////////////
	int student::GetAge()
	{
		  return age;
	}
	///////////////////////////	
	int student::GetRollno()
	{
		  return rollno;
	}
	////////////////////////////
	void student::SetName(char * nm)
	{
		  strcpy(name,nm);
	}
	///////////////////////////	
	void student::SetAge(int a)
	{
		age=a;
	}
	///////////////////////////	
	void student::SetRoll(int r)
	{
		  rollno=r;
	}
	///////////////////////////	
	void student::Display()
	{
		printf("\n Name=%s",name);
		printf("\n age=%d",age);
		printf("\n Roll No=%d",rollno);
	}
	///////////////////////////	
	void test()
	{
		student s1;
		s1.SetAge(25);
		s1.SetName("PARESH");
		s1.SetRoll(1066);
		s1.Display();
	}
