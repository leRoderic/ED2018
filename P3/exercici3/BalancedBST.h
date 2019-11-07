/* 
 * File:   BinarySearchTree.h
 * Author: sbarripi7.alumnes
 *
 * Created on 17 / d’abril / 2018, 08:10
 */


#include <iostream>
#include "NodeTree.h"

#ifndef BALANCEDBST_H
#define BALANCEDBST_H


using namespace std;

template <class Type>
class BalancedBST{
    public:
        /*Constructors i Destructors*/
        BalancedBST();
        BalancedBST(const BalancedBST& orig);
        virtual ~BalancedBST();
        
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
        int getBalance(NodeTree<Type>* p);
        void mirror(NodeTree<Type>* p);
        void rotEsqExt(NodeTree<Type>* p);
        
        void rotateExternLeft(NodeTree<Type>* p);
        void rotateExternRight(NodeTree<Type>* p);
        void rotateInternLeft(NodeTree<Type>* p);
        void rotateInternRight(NodeTree<Type>* p);
        
        
        /*Atributs*/
        NodeTree<Type>* pRoot;
};

// Constructor por defecto
template <class Type>
BalancedBST<Type>::BalancedBST(){
    pRoot = nullptr;
}


// Constructor copia
template <class Type>
BalancedBST<Type>::BalancedBST(const BalancedBST& orig){   
    if(orig.isEmpty())
        pRoot = nullptr;
    else{
        pRoot = new NodeTree<Type>(orig.root());
        preCopy(pRoot, orig.pRoot);
    }
}

// Destructor del arbol
template <class Type>
BalancedBST<Type>::~BalancedBST(){           
    if(!isEmpty())
        postDelete(pRoot);
}


// CONSULTORES

// Retorna la cantidad de elementos en el arbol
template <class Type>
int BalancedBST<Type>::size() const{
    if(isEmpty())
        return 0;
    return size(pRoot);    
}

// Retorna  true si el arbol esta vacio, de lo contrario false
template <class Type>
bool BalancedBST<Type>::isEmpty() const{
    return pRoot == nullptr;
}

// Retorna el nodo raíz
template <class Type>
NodeTree<Type>* BalancedBST<Type>::root(){
    return this->pRoot;
}

// Retorna true si hay un nodo con la clave pasada por parametro; de lo contrario false
template <class Type>
bool BalancedBST<Type>::search(const int key){    
    if(isEmpty())
        return false;    
    
    NodeTree<Type>* node = pRoot;
    bool found = false;
    
    
    while(!found){        
        if(key > node->getKey()){
            if(node->hasRight())
                node = node->getRight();                
            else return false;
        }
        
        else if(key < node->getKey()){
            if(node->hasLeft())
                node = node->getLeft();
            else return false;
        }
        else found = true;        
    }
    
    return found;        
}

// Imprime el contenido en inorden
template<class Type>
void BalancedBST<Type>::printInorder() const{
    printInorder(pRoot);
}

// Imprime el contenido en preorden
template<class Type>
void BalancedBST<Type>::printPreorder() const{
    printPreorder(pRoot);    
}

// Imprime el contenido en postorden
template<class Type>
void BalancedBST<Type>::printPostorder() const{
    printPostorder(pRoot);
}

// Retorna la altura del arbol, que equivale a la altura de la raiz
template<class Type>
int BalancedBST<Type>::getHeight(){
    if(isEmpty())
        return 0;
    else return pRoot->getHeight();
}

// SETTER

template<class Type>
void BalancedBST<Type>::insert(NodeTree<Type>* p, const Type& value, const int key){
    
    if(p->getKey() < key){ // Si la nueva peli tiene clave mas grande
        if(p->hasRight())
            insert(p->getRight(), value, key);
        else{
            NodeTree<Type> *node = new NodeTree<Type>(value, key);
            p->setRight(node);
            node->setParent(p);                    
        }
    }
    else{ // Si la nueva peli tiene clave mas pequeña
        if(p->hasLeft())
            insert(p->getLeft(), value, key);
        else{
            NodeTree<Type> *node = new NodeTree<Type>(value, key);
            p->setLeft(node);
            node->setParent(p);
        }
    }
    
    // Actualizar la altura en los nodos
    p->setHeight(getHeight(p));
    
    // Actualizar el factor de balance en los nodos
    int balance = getBalance(p);
    p->setBalance(balance);
    
    // Comprobar el factor y reestructurar
    int signe;
    
    switch(balance){
        case -2:
            signe = balance * p->getLeft()->getBalance();
            if(signe > 0)
                rotateExternRight(p);
            else rotateInternRight(p);
            break;
        case 2:
            signe = balance * p->getRight()->getBalance();
            if(signe > 0)
                rotateExternLeft(p);
            else rotateInternLeft(p);
            break;            
    }        
}

template<class Type>
void BalancedBST<Type>::insert(const Type& value, const int key){
    if(search(key))
        throw invalid_argument("Ya hay ese elemento");
    
    if(isEmpty())
        pRoot = new NodeTree<Type>(value, key);
    else
        insert(pRoot, value, key);    
}

// Invierte los hijos derechos e izquierdos
template<class Type>
void BalancedBST<Type>::mirror(){
    mirror(pRoot);
}

template<class Type>
void BalancedBST<Type>::rotateExternLeft(NodeTree<Type>* node){
    NodeTree<Type>* tmp = node->getRight();
    node->setRight(tmp->getLeft());
    if(tmp->hasLeft()){
        tmp->getLeft()->setParent(node);
    }
    tmp->setLeft(node);
    if(node == pRoot){
        node->setParent(tmp);
        tmp->setParent(nullptr);
        this->pRoot = tmp;
    }
    else{
        if(node->getKey() < node->getParent()->getKey()){ // Si node era hijo izquierdo
            node->getParent()->setLeft(tmp);
        }
        else{ // Si node era hijo derecho
            node->getParent()->setRight(tmp);
        }
        
        tmp->setParent(node->getParent());
        node->setParent(tmp);
    }

   // Actualizar alturas
    node->setHeight(getHeight(node));
    tmp->setHeight(getHeight(tmp));
    
    // Actualizar balances
    node->setBalance(getBalance(node));
    tmp->setBalance(getBalance(tmp));
}

template<class Type>
void BalancedBST<Type>::rotateExternRight(NodeTree<Type>* node){
    NodeTree<Type>* tmp = node->getLeft();
    node->setLeft(tmp->getRight());
        
    if(tmp->hasRight())
        tmp->getRight()->setParent(node);
    
    tmp->setRight(node);        
    if(node == pRoot){        
        node->setParent(tmp);
        tmp->setParent(nullptr);
        this->pRoot = tmp;
    }    
    else {
        if(node->getKey() < node->getParent()->getKey()) // Si node era hijo izquierdo
            node->getParent()->setLeft(tmp);
        else // Si node era hijo derecho
            node->getParent()->setRight(tmp);
        tmp->setParent(node->getParent());
        node->setParent(tmp);        
    }
    
    // Actualizar alturas
    node->setHeight(getHeight(node));
    tmp->setHeight(getHeight(tmp));
    
    // Actualizar balances
    node->setBalance(getBalance(node));
    tmp->setBalance(getBalance(tmp));
}

template<class Type>
void BalancedBST<Type>::rotateInternLeft(NodeTree<Type>* node){
    NodeTree<Type>* tmp = node->getRight();
    rotateExternRight(tmp);
    rotateExternLeft(node);
}

template<class Type>
void BalancedBST<Type>::rotateInternRight(NodeTree<Type>* node){
    NodeTree<Type>* tmp = node->getLeft();
    rotateExternLeft(tmp);
    rotateExternRight(node);
}


// METODOS AUXILIARES

// Metodo recursivo para constructor copia
template <class Type>
void BalancedBST<Type>::preCopy(NodeTree<Type>* p, NodeTree<Type>* orig){    
    if(orig->hasLeft()){        
        NodeTree<Type>* left = new NodeTree<Type>(orig->getLeft());
        left->setParent(p);
        p->setLeft(left);
        preCopy(left, orig->getLeft());        
    }
    
    if(orig->hasRight()){
        NodeTree<Type>* right = new NodeTree<Type>(orig->getRight());
        right->setParent(p);
        p->setRight(right);
        preCopy(right, orig->getRight());
    }            
}

// Metodo recursivo para destructor
template<class Type>
void BalancedBST<Type>::postDelete(NodeTree<Type>* p){
    // Si tiene hijo izquierdo
    if(p->hasLeft())
        postDelete(p->getLeft());
    // Si tiene hijo derecho
    if(p->hasRight())
        postDelete(p->getRight());
    
    delete p;    
}

// Metodo recursivo para obtener el numero de elementos del arbol
template<class Type>
int BalancedBST<Type>::size(NodeTree<Type>* p) const{   
    int size = 1;
    if(p->hasLeft())
        size += size(p->getLeft());
    if(p->hasRight())
        size += size(p->getRight());   
    return size;
}

// Metodo recursivo que recorre el arbol en preorden, imprimiendo
// el elemento
template<class Type>
void BalancedBST<Type>::printPreorder(NodeTree<Type>* p) const{   
    cout << p->getValue();

    if(p->hasLeft()){
        cout << ", ";
        printPreorder(p->getLeft());
    }
    
    if(p->hasRight()){
        cout << ", ";
        printPreorder(p->getRight());
    }
}

// Metodo recursivo que recorre el arbol en postorden, imprimiendo el 
// elemento
template<class Type>
void BalancedBST<Type>::printPostorder(NodeTree<Type>* p) const{    
    if(p->hasLeft()){
        printPostorder(p->getLeft());
        cout << ", ";
    }
    
    if(p->hasRight()){        
        printPostorder(p->getRight());
        cout << ", ";
    }
    cout << p->getValue();    
}

// Metodo recursivo que recorre el arbol en inorden, imprimiendo el elemento
template<class Type>
void BalancedBST<Type>::printInorder(NodeTree<Type>* p) const{    
    if(p->hasLeft()){
        printInorder(p->getLeft());
    }
        
    cout << p->getValue();
    cout << ", ";
        
    if(p->hasRight()){        
        printInorder(p->getRight());
    }
}

// Metodo recursivo que invierte hijos izq. y derecho
template<class Type>
void BalancedBST<Type>::mirror(NodeTree<Type>* p){
    NodeTree<Type>* aux = p->getLeft();
    p->setLeft(p->getRight());
    p->setRight(aux);
    
    if(p->hasLeft())
        mirror(p->getLeft());
    if(p->hasRight())
        mirror(p->getRight());    
}

// Metodo que calcula la altura de un nodo, y la retorna.
template<class Type>
int BalancedBST<Type>::getHeight(NodeTree<Type>* p){
    int lHeight = 0, rHeight = 0;
    
    if(p->hasLeft())
        lHeight = p->getLeft()->getHeight();
    if(p->hasRight())
        rHeight = p->getRight()->getHeight();
    
    int maxHeight = lHeight;
    if(maxHeight < rHeight)
        maxHeight = rHeight;
    
    return maxHeight + 1;        
}

template<class Type>
int BalancedBST<Type>::getBalance(NodeTree<Type>* p){
    int balance = 0;
    if(p->hasRight())
        balance += p->getRight()->getHeight();
    if(p->hasLeft())
        balance -= p->getLeft()->getHeight();    
    return balance;
}


#endif /* BALANCEDBST */