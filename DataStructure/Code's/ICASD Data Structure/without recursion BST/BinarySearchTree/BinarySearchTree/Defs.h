#include <iostream>
using namespace std;

class Node {
    int data;
    Node * left, * right;
public:
    Node( int data );
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
    ~BinarySearchTree();
    
    bool insert( int data );
    void preOrder( Node *  );
    void inOrder( Node * );
    void postOrder( Node * );
    bool deleteData( int data );
    Node * getRoot();
    
    void clear( Node * );
    
    void inOrder();
    void preOrder();
    void postOrder();
    
    
};

























