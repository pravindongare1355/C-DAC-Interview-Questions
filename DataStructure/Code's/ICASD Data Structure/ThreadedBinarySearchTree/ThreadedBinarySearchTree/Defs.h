#include <iostream>
using namespace std;

class Node {
    int data;
    Node * left, * right;
    char lflag, rflag;
public:
    Node( int data );
    void setData( int );
    int getData();
    void setLeft( Node * );
    Node * getLeft();
    void setRight( Node * );
    Node * getRight();
    void setLFlag( char lflag );
    char getLFlag();
    void setRFlag( char rflag );
    char getRFlag();
};

class TBST  {
    Node * root;
public:
    TBST();
    bool insert( int data );
    bool deleteData( int data );
    bool isRightChild( Node * );
    void preOrder();
    void inOrder();
    void postOrder();
};

















