/* 
 * File:   BinarySearchTree.h
 * Author: sbarripi7.alumnes
 *
 * Created on 17 / d’abril / 2018, 08:10
 */


#include <iostream>
#include "NodeTree.h"

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


using namespace std;

template <class Type>
class BinarySearchTree{
    public:
        /*Constructors i Destructors*/
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree& orig);
        virtual ~BinarySearchTree();
        
        /*Consultors*/
        int size() const;
        bool isEmpty() const;
        NodeTree<Type>* root();
        bool search(const int key);
        void printInorder() const;
        void printPreorder() const;
        void printPostorder() const;
        int getHeight();
        
        /*Modificadors*/
        void insert(const Type& value, const int key);
        void mirror();        
    private:
        void postDelete(NodeTree<Type>* p);
        void preCopy(NodeTree<Type>* p, NodeTree<Type>* o);
        void insert(NodeTree<Type>* p, const Type& value, const int key);
        int size(NodeTree<Type>* p) const;
        void printPreorder(NodeTree<Type>* p) const;
        void printPostorder(NodeTree<Type>* p) const;
        void printInorder(NodeTree<Type>* p) const;
        int getHeight(NodeTree<Type>* p);
        void mirror(NodeTree<Type>* p);
        
        /*Atributs*/
        NodeTree<Type>* pRoot;
};

template <class Type>
BinarySearchTree<Type>::BinarySearchTree(){
    pRoot = nullptr;
}

template <class Type>
BinarySearchTree<Type>::BinarySearchTree(const BinarySearchTree& orig){   
    if(orig.isEmpty())
        pRoot = nullptr;
    else{
        pRoot = new NodeTree<Type>(orig.root());
        preCopy(pRoot, orig.pRoot);

    }
}

template <class Type>
BinarySearchTree<Type>::~BinarySearchTree(){
    postDelete(pRoot);
}


// CONSULTORES
template <class Type>
int BinarySearchTree<Type>::size() const{
    if(isEmpty())
        return 0;
    return size(pRoot);    
}

template <class Type>
bool BinarySearchTree<Type>::isEmpty() const{
    return pRoot == nullptr;
}

template <class Type>
NodeTree<Type>* BinarySearchTree<Type>::root(){
    return this->pRoot;
}

template <class Type>
bool BinarySearchTree<Type>::search(const int key){    
    if(isEmpty())
        return false;    
    
    NodeTree<Type>* node = pRoot;
    bool found = false;
    
    
    while(!found){        
        if(key > node->getKey()){
            if(node->hasRight())
                node = node->getright();                
            else return false;
        }
        
        else if(key < node->getKey()){
            if(node->hasLeft())
                node = node->getleft();
            else return false;
        }
        else found = true;        
    }
    
    return found;        
}

template<class Type>
void BinarySearchTree<Type>::printInorder() const{
    printInorder(pRoot);
}


template<class Type>
void BinarySearchTree<Type>::printPreorder() const{
    printPreorder(pRoot);    
}


template<class Type>
void BinarySearchTree<Type>::printPostorder() const{
    printPostorder(pRoot);
}


template<class Type>
int BinarySearchTree<Type>::getHeight(){
    if(isEmpty())
        return 0;
    else return pRoot->getHeight();
}

// SETTER

template<class Type>
void BinarySearchTree<Type>::insert(NodeTree<Type>* p, const Type& value, const int key){
    if(p->getKey() < key){
        if(p->hasRight())
            insert(p->getright(), value, key);
        else{
            NodeTree<Type> *node = new NodeTree<Type>(value, key);
            p->setRight(node);
            node->setParent(p);                    
        }
    }
    else{
        if(p->hasLeft())
            insert(p->getleft(), value, key);
        else{
            NodeTree<Type> *node = new NodeTree<Type>(value, key);
            p->setLeft(node);
            node->setParent(p);
        }
    }
    
    p->setHeight(getHeight(p));
    
        
    
}

template<class Type>
void BinarySearchTree<Type>::insert(const Type& value, const int key){
    if(search(key))
        throw invalid_argument("Ya hay ese elemento");
    
    if(isEmpty())
        pRoot = new NodeTree<Type>(value, key);
    else
        insert(pRoot, value, key);    
}


/*
template<class Type>
void BinarySearchTree<Type>::insert(const Type& value, const int key){
    if(search(key))
        throw invalid_argument("Ya hay ese elemento");  
    
    NodeTree<Type>* node = new NodeTree<Type>(value, key);
    if(isEmpty()){
        pRoot = node;
    } else {
        bool found = false;
        NodeTree<Type>* aux = pRoot;
        while(!found){            
            if(aux->getKey() < key){
                if(aux->hasRight())
                    aux = aux->getright();                
                else{
                    aux->setRight(node);
                    node->setParent(aux);
                    found = true;                    
                }                    
            }
            else{
                if(aux->hasLeft())
                    aux = aux->getleft();                
                else{
                    aux->setLeft(node);
                    node->setParent(aux);
                    found = true;
                }
            }                
        }
    }    
}
*/
template<class Type>
void BinarySearchTree<Type>::mirror(){
    mirror(pRoot);
}


// METODOS AUXILIARES

template <class Type>
void BinarySearchTree<Type>::preCopy(NodeTree<Type>* p, NodeTree<Type>* orig){    
    if(orig->hasLeft()){        
        NodeTree<Type>* left = new NodeTree<Type>(orig->getleft());
        left->setParent(p);
        p->setLeft(left);
        preCopy(left, orig->getleft());        
    }
    
    if(orig->hasRight()){
        NodeTree<Type>* right = new NodeTree<Type>(orig->getright());
        right->setParent(p);
        p->setRight(right);
        preCopy(right, orig->getright());
    }            
}

template<class Type>
void BinarySearchTree<Type>::postDelete(NodeTree<Type>* p){
    // Si tiene hijo izquierdo
    if(p->hasLeft())
        postDelete(p->getleft());
    // Si tiene hijo derecho
    if(p->hasRight())
        postDelete(p->getright());
    
    delete p;    
}


template<class Type>
int BinarySearchTree<Type>::size(NodeTree<Type>* p) const{   
    int size = 1;
    if(p->hasLeft())
        size += size(p->getleft());
    if(p->hasRight())
        size += size(p->getright());   
    return size;
}


template<class Type>
void BinarySearchTree<Type>::printPreorder(NodeTree<Type>* p) const{   
    cout << p->getValue();

    if(p->hasLeft()){
        cout << endl;
        printPreorder(p->getleft());
    }
    
    if(p->hasRight()){
        cout << endl;
        printPreorder(p->getright());
    }
}


template<class Type>
void BinarySearchTree<Type>::printPostorder(NodeTree<Type>* p) const{    
    if(p->hasLeft()){
        printPostorder(p->getleft());
        cout << endl;
    }
    
    if(p->hasRight()){        
        printPostorder(p->getright());
        cout << endl;
    }
    cout << p->getValue();    
}


template<class Type>
void BinarySearchTree<Type>::printInorder(NodeTree<Type>* p) const{    
    if(p->hasLeft()){
        printInorder(p->getleft());
    }
        
    cout << p->getValue();
    cout << endl;    
        
    if(p->hasRight()){        
        printInorder(p->getright());
    }
}

template<class Type>
void BinarySearchTree<Type>::mirror(NodeTree<Type>* p){
    NodeTree<Type>* aux = p->getleft();
    p->setLeft(p->getright());
    p->setRight(aux);
    
    if(p->hasLeft())
        mirror(p->getleft());
    if(p->hasRight())
        mirror(p->getright());    
}

template<class Type>
int BinarySearchTree<Type>::getHeight(NodeTree<Type>* p){
    int lHeight = 0, rHeight = 0;
    
    if(p->hasLeft())
        lHeight = p->getleft()->getHeight();
    if(p->hasRight())
        rHeight = p->getright()->getHeight();
    
    int maxHeight = lHeight;
    if(maxHeight < rHeight)
        maxHeight = rHeight;
    
    return maxHeight + 1;        
}

#endif /* BINARYSEARCHTREE_H */
