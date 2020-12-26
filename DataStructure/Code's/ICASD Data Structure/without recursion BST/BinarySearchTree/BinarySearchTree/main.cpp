#include "Defs.h"

int main(int argc, const char * argv[]) {

    
    BinarySearchTree bst;
    
    bst.insert( 52);
    bst.insert( 10 );
    bst.insert( 5 );
    bst.insert( 8 );
    bst.insert( 40 );
    bst.insert( 30 );
    bst.insert( 48 );
    bst.insert( 20 );
    bst.insert( 25 );
    bst.insert( 62 );
    bst.insert( 55 );
    bst.insert( 90 );
    bst.insert( 60 );
    bst.insert( 80 );
    bst.insert( 58 );
    
    bst.preOrder( bst.getRoot() );
    cout<<endl;
    bst.preOrder();
    
    bst.inOrder( bst.getRoot() );
    cout<<endl;
    bst.inOrder();
    
    
    bst.postOrder( bst.getRoot() );
    cout<<endl;
    bst.postOrder();

    
    
    
    return 0;
}










