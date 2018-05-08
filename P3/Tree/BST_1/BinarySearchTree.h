/* 
 * File:   BinarySearchTree.h
 * Author: sbarripi7.alumnes
 *
 * Created on 17 / d’abril / 2018, 08:10
 */

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
        bool search(const Type& element);
        void printInorder() const;
        void printPreorder() const;
        void printPostorder() const;
        int getHeight();
        
        /*Modificadors*/
        void insert(const Type& element);
        void mirror();        
    private:
        void postDelete(NodeTree<Type>* p);
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
    insert(orig.pRoot->getElement());          
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
bool BinarySearchTree<Type>::search(const Type& element){    
    if(isEmpty())
        return false;    
    
    NodeTree<Type>* node = pRoot;
    bool found = false;
    
    
    while(!found){        
        if(element > node->getElement()){
            if(node->hasRight())
                node = node->getright();                
            else return false;
        }
        
        else if(element < node->getElement()){
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
    cout << "Inordre = {";
    printInorder(pRoot);
    cout << "}" << endl;
}


template<class Type>
void BinarySearchTree<Type>::printPreorder() const{
    cout << "Preordre = {";    
    printPreorder(pRoot);
    cout << "}" << endl;
    
}


template<class Type>
void BinarySearchTree<Type>::printPostorder() const{
    cout << "Postordre = {";
    printPostorder(pRoot);
    cout << "}" << endl;
}


template<class Type>
int BinarySearchTree<Type>::getHeight(){
    if(isEmpty())
        return 0;
    else return pRoot->getHeight();
}

// SETTER
template<class Type>
void BinarySearchTree<Type>::insert(const Type& element){
    NodeTree<Type>* node = new NodeTree<Type>(element);
    if(isEmpty()){
        pRoot = node;
    } else {
        bool found = false;
        NodeTree<Type>* aux = pRoot;
        while(!found){
            if(aux->getElement() == element){
                delete node;
                throw out_of_range("Ya hay ese elemento");
            }
            
            else if(aux->getElement() < element){
                if(aux->hasRight())
                    aux = aux->getright();                
                else{
                    aux->setRight(node);
                    node->setParent(aux);
                    found = true;                    
                }                    
            }
            
            else if(aux->getElement() > element){
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


template<class Type>
void BinarySearchTree<Type>::mirror(){
    mirror(pRoot);
}


// METODOS AUXILIARES

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
    cout << p->getElement();

    if(p->hasLeft()){
        cout << ", ";
        printPreorder(p->getleft());
    }
    
    if(p->hasRight()){
        cout << ", ";
        printPreorder(p->getright());
    }
}


template<class Type>
void BinarySearchTree<Type>::printPostorder(NodeTree<Type>* p) const{    
    if(p->hasLeft()){
        printPostorder(p->getleft());
        cout << ", ";
    }
    
    if(p->hasRight()){        
        printPostorder(p->getright());
        cout << ", ";
    }
    cout << p->getElement();    
}


template<class Type>
void BinarySearchTree<Type>::printInorder(NodeTree<Type>* p) const{
    if(p->hasLeft()){
        printInorder(p->getleft());
    }
    
    cout << p->getElement();
    cout << ", ";
    
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

#endif /* BINARYSEARCHTREE_H */

