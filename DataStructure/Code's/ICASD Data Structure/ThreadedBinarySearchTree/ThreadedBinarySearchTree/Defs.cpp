#include "Defs.h"

Node::Node( int data ) {
    this->data = data;
    left = right = NULL;
    lflag = rflag = 'T';
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

void Node::setLFlag(char lflag) {
    this->lflag = lflag;
}

char Node::getLFlag() {
    return lflag;
}

void Node::setRFlag(char rflag) {
    this->rflag = rflag;
}

char Node::getRFlag() {
    return rflag;
}


TBST::TBST() {
    root = NULL;
}

//insert to left
//1. parent will become inorder successor of new node
//2. parent's inorder predecessor will become inorder predecessor of newnode
//3. new node will become left child of parent

//insert to right
//1. parent will become inorder predecessor of newnode
//2. parent's inorder successor will become inorder successor of newnode
//3. newnode will become right child of parent

bool TBST::insert(int data) {
    
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
            return true;
        }
        
        if( data < temp->getData() ) {
            //insert to left
            if( temp->getLFlag() == 'T' ) {
                newNode->setRight( temp );
                newNode->setLeft( temp->getLeft() );
                temp->setLeft( newNode );
                temp->setLFlag('L');
                return true;
            }
            temp = temp->getLeft();
        }
        else {
            //insert to right
            if( temp->getRFlag() == 'T') {
                newNode->setLeft( temp );
                newNode->setRight( temp->getRight() );
                temp->setRight( newNode );
                temp->setRFlag('L');
                return true;
            }
            temp = temp->getRight();
        }
    }
    
}

void TBST::inOrder() {
    
    Node * temp = root;
    char flag = 'L';
    
    cout<<"Inorder : ";
    
    while( temp ) {
        
        while( temp->getLFlag() == 'L' && flag == 'L') {
            temp = temp->getLeft();
        }
        
        cout<<temp->getData()<<" ";
        flag = temp->getRFlag();
        temp = temp->getRight();
    }
    
    cout<<endl;
    
    
}

void TBST::preOrder() {
    
    Node * temp = root;
    char flag = 'L';
    
    cout<<"preorder : ";
    
    while (temp) {
        
        while( temp->getLFlag() == 'L' && flag == 'L' ) {
            cout<<temp->getData()<<" ";
            temp = temp->getLeft();
        }
        
        if( flag == 'L') {
            cout<<temp->getData()<<" ";
        }
        flag = temp->getRFlag();
        temp = temp->getRight();
    }
    cout<<endl;
    
}

bool TBST::isRightChild( Node * node ) {
    
    if( node == root ) {
        return false;
    }
    
    Node * temp = root;
    char flag = 'L';
    
    while( temp ) {
    
        while( temp->getLFlag() == 'L' && flag == 'L') {
            temp = temp->getLeft();
        
            if( temp == node ) {
                return false;
            }
        }
    
        flag = temp->getRFlag();
        temp = temp->getRight();
    
        if( temp == node && flag == 'L') {
            return true;
        }
    }
    
    return false;
}

void TBST::postOrder() {
    
    Node * temp = root;
    char flag = 'L';
    
    cout<<"Postorder : ";
    
    while( temp ) {
        
        while( temp->getLFlag() == 'L' && flag == 'L') {
            temp = temp->getLeft();
        }
        
        flag = temp->getRFlag();
        
        if( flag == 'L') {
            //temp has right child
            temp = temp->getRight();
        }
        else {
            while( true ) {
                
                //temp does not have right child, so visit temp
                cout<<temp->getData()<<" ";
                bool isRight = isRightChild( temp );
            
                if( isRight ) {
                    //temp is right child, so go to it's parent and visit parent
                    while( temp->getLFlag() == 'L') {
                        temp = temp->getLeft();
                    }
                
                    temp = temp->getLeft();
                }
                else {
                    //temp is left child, so go to it's parent and then to right of parent**
                    while( temp->getRFlag() == 'L') {
                        temp = temp->getRight();
                    }
                    temp = temp->getRight();
                    flag = 'T';
                    break;
                }
            }
        }
        
    }
    
    cout<<endl;
    
}

//deleting left child
//del's inorder predecessor will become inorder predecessor of parent

//deleting right child
//del's inorder successor will become inorder successor of parent

bool TBST::deleteData(int data) {
    
    if( root == NULL ) {
        return false;
    }
    
    Node * parent = root, * del = root;
    
    while( del->getData() != data ) {
        
        if( data < del->getData() ) {
            
            if( del->getLFlag() == 'T' ) {
                return false;
            }
            
            parent = del;
            del = del->getLeft();
        }
        else {
            
            if( del->getRFlag() == 'T') {
                return false;
            }
            
            parent = del;
            del = del->getRight();
        }
        
    }
    
    while( true ) {
        
        if( del->getLFlag() == 'T' && del->getRFlag() == 'T') {
            
            if( del == root ) {
                root = NULL;
                delete del;
            }
            
            if( del == parent->getLeft() ) {
                parent->setLeft( del->getLeft() );
                parent->setLFlag('T');
            }
            else {
                parent->setRight( del->getRight() );
                parent->setRFlag('T');
                
            }
            delete del;
            return true;
            
        }
        
        if( del->getLFlag() == 'L' ) {
            
            Node * max = del->getLeft();
            parent = del;
            
            while (max->getRFlag() == 'L') {
                parent = max;
                max = max->getRight();
            }
            
            int data = del->getData();
            del->setData( max->getData() );
            max->setData( data );
            
            del = max;
        }
        else {
            
            Node * min = del->getRight();
            parent = del;
            
            while( min->getLFlag() == 'L') {
                parent = min;
                min = min->getLeft();
            }
            
            int data = min->getData();
            min->setData( del->getData() );
            del->setData( data );
            
            del = min;
            
        }
        
    }
    
}


























































