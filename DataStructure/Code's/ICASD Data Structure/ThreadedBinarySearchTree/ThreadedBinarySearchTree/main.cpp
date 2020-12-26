#include "Defs.h"

int main(int argc, const char * argv[]) {

    TBST t1;
    
    t1.insert( 50 );
    t1.insert( 20 );
    t1.insert( 30 );
    t1.insert( 10 );
    t1.insert( 15 );
    t1.insert( 80 );
    t1.insert( 60 );
    t1.insert( 90 );
    t1.insert( 70 );
    t1.insert( 55 );
    
    t1.inOrder();
    t1.preOrder();
    t1.postOrder();
    
    t1.deleteData( 50 );
    t1.inOrder();
    t1.preOrder();
    t1.postOrder();
    
    cout<<t1.deleteData( 50 )<<endl;
    
    return 0;
}

















