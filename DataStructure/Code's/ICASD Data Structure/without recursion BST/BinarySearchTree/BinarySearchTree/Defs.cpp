#include "Defs.h"

Node::Node( int data ) {
    this->data = data;
    left = right = NULL;
}

void Node::setData( int data ) {
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

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

bool BinarySearchTree::insert(int data) {
    
    Node * newNode = new Node( data );
    if( newNode == NULL ) {
        return false;
    }
    
    if( root == NULL ) {
        root = newNode;
        return true;
    }
    
    Node * temp = root;
    
    while( true ) {
        
        if( data == temp->getData() ) {
            delete newNode;
            return false;
        }
        
        if( data < temp->getData() ) {
            //insert to left
            //check if temp has left child
            if( temp->getLeft() == NULL ) {
                temp->setLeft( newNode );
                return true;
            }
            temp = temp->getLeft();
        }
        else {
            //insert to right
            if( temp->getRight() == NULL ) {
                temp->setRight( newNode );
                return true;
            }
            temp = temp->getRight();
        }
    }
    
}


void BinarySearchTree::preOrder(Node * root) {
    
    if( root == NULL )
        return;
    
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

bool BinarySearchTree::deleteData( int data ) {
    
    if( root == NULL ) {
        return false;
    }
    
    //locate del and its parent
    Node * parent = root, * del = root;
    while( del->getData() != data ) {
        
        if( data < del->getData() ) {
            parent = del;
            del = del->getLeft();
        }
        else {
            parent = del;
            del = del->getRight();
        }
        
        if( del == NULL ) {
            return false;
        }
    }
    
    while( true ) {
        
    //check if del is terminal
    if( del->getLeft() == NULL && del->getRight() == NULL ) {
        
        if( del == root ) {
            delete root;
            root = NULL;
            return true;
        }
        
        if(parent->getLeft() == del ) {
            parent->setLeft( NULL );
        }
        else {
            parent->setRight( NULL );
        }
        
        delete del;
        return true;
        
    }
    
    //shift the del node down the tree
    
    if( del->getLeft() ) {
        //find max from left
        Node * max = del->getLeft();
        parent = del;
        
        while( max->getRight() ) {
            parent = max;
            max = max->getRight();
        }
        
        //swap
        int data = del->getData();
        del->setData( max->getData() );
        max->setData( data );
        
        del = max;
    }
    else {
        //find min from right
        Node * min = del->getRight();
        parent = del;
        
        while( min->getLeft() ) {
            parent = min;
            min = min->getLeft();
        }
        
        int data = del->getData();
        del->setData( min->getData() );
        min->setData( data );
        
        del = min;
    }
        
    }
}

void BinarySearchTree::clear(Node * root) {
    
    if( root == NULL ) {
        return;
    }
    
    clear( root->getLeft() );
    clear( root->getRight() );
    cout<<root->getData()<<" ";
    delete root;
    
}

BinarySearchTree::~BinarySearchTree() {
    clear( root );
    cout<<endl;
}

void BinarySearchTree::preOrder() {
    
    Node * stack[100];
    int top = -1;
    Node * temp = root;
    
    
    while( top != -1 || temp != NULL ) {
        
        while( temp ) {
            cout<<temp->getData()<<" ";
            stack[++top] = temp;
            temp = temp->getLeft();
        }
        
        temp = stack[top--];
        temp = temp->getRight();
        
    }
    cout<<endl;
    
}

void BinarySearchTree::inOrder() {
    
    Node * stack[100];
    int top = -1;
    Node * temp = root;
    
    while( top != -1 || temp != NULL ) {
        
        while( temp ) {
            stack[++top] = temp;
            temp = temp->getLeft();
        }
        
        temp = stack[top--];
        cout<<temp->getData()<<" ";
        temp = temp->getRight();
        
    }
    cout<<endl;
    
}

void BinarySearchTree::postOrder() {
    
    typedef struct {
        Node * addr;
        char flag;
    } pair;
    
    pair stack[100];
    int top = -1;
    Node * temp = root;
    
    while( temp != NULL || top != -1 ) {
        
        while( temp ) {
            pair p;
            p.addr = temp; p.flag = 'L';
            stack[++top] = p;
            temp = temp->getLeft();
        }
        
        pair p = stack[top--];
        
        if( p.flag == 'L') {
            temp = p.addr;
            temp = temp->getRight();
            p.flag = 'R';
            stack[++top] = p;
        }
        else {
            temp = p.addr;
            cout<<temp->getData()<<" ";
            temp = NULL;
        }
    }
    cout<<endl;
}












































