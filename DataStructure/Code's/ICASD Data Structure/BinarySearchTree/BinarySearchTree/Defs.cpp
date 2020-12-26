#include "Header.h"

Node::Node( int data ){
    this->data = data;
    left = right = NULL;
}

void Node::setData(int data) {
    this->data = data;
}

int Node::getData() {
    return data;
}

void Node::setLeft(Node * left) {
    this->left = left;
}

Node * Node::getLeft() {
    return left;
}

void Node::setRight(Node * right) {
    this->right = right;
}

Node * Node::getRight() {
    return right;
}


//

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

bool BinarySearchTree::insert( int data ) {
    
    Node * newNode = new Node( data );
    if( newNode == NULL ){
        return false;
    }
    
    if( root == NULL ) {
        root = newNode;
        return true;
    }
    
    Node * temp = root;
    
    while( true ){
        
        if( data == temp->getData() ){
            delete newNode;
            return false;
        }
        
        if( data < temp->getData() ) {
            //to left
            if( temp->getLeft() == NULL ) {
                temp->setLeft( newNode );
                return true;
            }
            temp = temp->getLeft();
        }
        else {
            //to right
            if( temp->getRight() == NULL ) {
                temp->setRight( newNode );
                return true;
            }
            temp = temp->getRight();
        }
    }
    
    return true;
}

void BinarySearchTree::preOrder(Node * root) {
    if( root == NULL ) {
        return;
    }
    
    cout<<root->getData()<<" ";
    preOrder( root->getLeft() );
    preOrder( root->getRight() );
}

void BinarySearchTree::inOrder(Node * root) {
    if( root == NULL ) {
        return;
    }
    
    inOrder( root->getLeft() );
    cout<<root->getData()<<" ";
    inOrder( root->getRight() );
}

void BinarySearchTree::postOrder(Node * root) {
    if( root == NULL ) {
        return;
    }
    
    postOrder( root->getLeft() );
    postOrder( root->getRight() );
    cout<<root->getData()<<" ";
}

Node * BinarySearchTree::getRoot() {
    return root;
}

bool BinarySearchTree::deleteData(int data) {
    
    if( root == NULL ) {
        return false;
    }
    
    Node * parent = root, * del = root;
    
    
    //locate node to be deleted along with its parent
    while( data != del->getData() ) {
        
        parent = del;
        
        if( data < del->getData() ) {
            del = del->getLeft();
        }
        else {
            del = del->getRight();
        }
        
        if( del == NULL ){
            return false;
        }
    }
    
    if( del->getLeft() == NULL && del->getRight() == NULL ) {
        
        if( root == del ) {
            delete root;
            root = NULL;
            return true;
        }
        
        if( parent->getLeft() == del ) {
            parent->setLeft( NULL );
        }
        else {
            parent->setRight( NULL );
        }
        
        delete del;
        return true;
        
    }
    
    return false;
}

















