#include "student.h"
#include "student1.h"
#include<iostream.h>

void main()
{
	cout<<"----------STRUCTURE-------------"<<endl;
	student s;
	s.SetName("ABC");
	s.SetAge(22);
	s.SetRoll(2);
	s.Display();
	test();
	cout<<"\n-------------------------------"<<endl;
	cout<<"\n------------CLASS--------------"<<endl;
	student1 s1;
	s1.SetName("ABC");
	s1.SetAge(22);
	s1.SetRoll(2);
	s1.Display();
	cout<<"\n-------------------------------"<<endl;
}