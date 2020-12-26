#include "Header.h"

int main(int argc, const char * argv[]) {

    Queue q1;
    
    cout<<"Ins : " << q1.insert( 10 )<<endl;
    cout<<"Ins : " << q1.insert( 20 )<<endl;
    
    cout<<"del : " << q1.deleteData()<<endl;
    cout<<"del : " << q1.deleteData()<<endl;
    cout<<"del : " << q1.deleteData()<<endl;

    cout<<"Ins : " << q1.insert( 10 )<<endl;
    cout<<"Ins : " << q1.insert( 20 )<<endl;
    cout<<"Ins : " << q1.insert( 30 )<<endl;
    cout<<"del : " << q1.deleteData()<<endl;
    cout<<"del : " << q1.deleteData()<<endl;
    cout<<"del : " << q1.deleteData()<<endl;
    
    cout<<"IsEmpty : "<<q1.isEmpty()<<endl;
    cout<<"IsFULL : "<<q1.isFull()<<endl;
    return 0;
}



















