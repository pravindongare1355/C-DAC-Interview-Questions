#include <iostream>
using namespace std;

class Node {
    int data;
    Node * left, * right;
public:
    Node( int  );
    void setData( int );
    int getData();
    void setLeft( Node * );
    Node * getLeft();
    void setRight( Node * );
    Node * getRight();
};

class BinarySearchTree {
    Node * root;
public:
    BinarySearchTree();
    bool insert( int );
    
    void preOrder( Node * );
    void inOrder( Node * );
    void postOrder( Node * );
    bool deleteData( int data );
    Node * getRoot();
};



















