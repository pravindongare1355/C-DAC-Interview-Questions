#include "Header.h"


int main(int argc, const char * argv[]) {

    CircularQueue cq( 4 );
    
    cout<<"ins : "<<cq.insert( 10 )<<endl;
    cout<<"ins : "<<cq.insert( 20 )<<endl;
    cout<<"ins : "<<cq.insert( 30 )<<endl;
    cout<<"ins : "<<cq.insert( 40 )<<endl;
    cout<<"ins : "<<cq.insert( 50 )<<endl;
    
    cout<<"del : "<<cq.deleteData()<<endl;
    cout<<"del : "<<cq.deleteData()<<endl;
    cout<<"del : "<<cq.deleteData()<<endl;
    cout<<"del : "<<cq.deleteData()<<endl;
    cout<<"del : "<<cq.deleteData()<<endl;
    
    cout<<"ins : "<<cq.insert( 10 )<<endl;
    cout<<"ins : "<<cq.insert( 20 )<<endl;
    cout<<"ins : "<<cq.insert( 30 )<<endl;
    cout<<"ins : "<<cq.insert( 40 )<<endl;
    
    
    return 0;
}
















