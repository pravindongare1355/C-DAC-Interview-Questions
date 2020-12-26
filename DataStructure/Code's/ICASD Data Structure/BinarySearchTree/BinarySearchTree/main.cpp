#include "Header.h"

int main(int argc, const char * argv[]) {
    
    BinarySearchTree bst;
    
    bst.insert( 50 );
//    bst.insert( 10 );
//    bst.insert( 5);
//    bst.insert( 20 );
//    bst.insert( 30 );
//    bst.insert( 15);
//    bst.insert( 18 );
//    bst.insert( 8 );
//    bst.insert( 100 );
//    bst.insert( 80 );
//    bst.insert( 120  );
//    bst.insert( 60 );
//    bst.insert( 90 );
//    bst.insert( 85 );
//    bst.insert( 95 );
    
    //cout<<bst.insert( 10 )<<endl;
    
    bst.preOrder( bst.getRoot() );
    cout<<endl;
    bst.inOrder( bst.getRoot() );
    cout<<endl;
    bst.postOrder( bst.getRoot() );
    cout<<endl;
    
    cout<<"del 50 : "<<bst.deleteData( 50 )<<endl;
    bst.preOrder( bst.getRoot() );
    cout<<endl;
    bst.inOrder( bst.getRoot() );
    cout<<endl;
    bst.postOrder( bst.getRoot() );
    cout<<endl;
    
    
    return 0;
}












