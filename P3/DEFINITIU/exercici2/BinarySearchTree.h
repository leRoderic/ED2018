
#include <iostream>
#include "NodeTree.h"

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


using namespace std;

template <class Type>
class BinarySearchTree{
    public:
        /*Constructores y Destructores*/
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree& orig);
        virtual ~BinarySearchTree();
        /*Consultores*/
        int size() const;
        bool isEmpty() const;
        NodeTree<Type>* root();
        bool search(const int key);
        void printInorder() const;
        void printPreorder() const;
        void printPostorder() const;
        int getHeight();
        
        /*Modificadores*/
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
        NodeTree<Type>* pRoot;
};

//================ CONSTRUCTORES ===============================================
template <class Type>
BinarySearchTree<Type>::BinarySearchTree(){
    //Constructor por defecto
    pRoot = nullptr;    //Crea el árbol vacío
}

template <class Type>
BinarySearchTree<Type>::BinarySearchTree(const BinarySearchTree& orig){
    //Constructor copia
    if(orig.isEmpty())
        pRoot = nullptr;    
    else{
        pRoot = new NodeTree<Type>(orig.root());
        preCopy(pRoot, orig.pRoot);

    }
}

//================ DESTRUCTOR ==================================================
template <class Type>
BinarySearchTree<Type>::~BinarySearchTree(){
    //Destructor
    postDelete(pRoot);
}

//================ CONSULTORES =================================================
template <class Type>
int BinarySearchTree<Type>::size() const{
    if(isEmpty())
        return 0;
    return size(pRoot);    
}

template <class Type>
bool BinarySearchTree<Type>::isEmpty() const{
    //Comprueba si el árbol está vacío
    return pRoot == nullptr;
}

template <class Type>
NodeTree<Type>* BinarySearchTree<Type>::root(){
    //Getter para raíz
    return this->pRoot;
}

template <class Type>
bool BinarySearchTree<Type>::search(const int key){
    //Busca un elemento en el árbol
    if(isEmpty()) //Si está vacio, no hay nada que buscar.  
        return false;    
    NodeTree<Type>* node = pRoot;
    bool found = false; 
    while(!found){    //Mientras no se haya encontrado    
        if(key > node->getKey()){ //Si es más pequeño, va a derechas
            if(node->hasRight())
                node = node->getRight();                
            else return false;
        }
        else if(key < node->getKey()){ //Si es más grande, va a izquierdas
            if(node->hasLeft())
                node = node->getLeft();
            else return false;
        }
        else found = true;    //Si el elemento coincide, se ha encontrado    
    }
    return found;        
}

template<class Type>
void BinarySearchTree<Type>::printInorder() const{
    //Imprime en inorden
    cout << "Inorder = {";
    printInorder(pRoot);
    cout << "}";
}

template<class Type>
void BinarySearchTree<Type>::printPreorder() const{
    //Imprime en preorden
    cout << "Preorder = {";
    printPreorder(pRoot);
    cout << "}";
}

template<class Type>
void BinarySearchTree<Type>::printPostorder() const{
    //Imprime en postorden
    cout << "Postorder = {";
    printPostorder(pRoot);
    cout << "}";
}

template<class Type>
int BinarySearchTree<Type>::getHeight(){
    //Calcula altura
    if(isEmpty())
        return 0;   //Árbol vacío == altura 0
    else return pRoot->getHeight();
}

// =============== MODIFICADORES ===============================================
template<class Type>
void BinarySearchTree<Type>::insert(NodeTree<Type>* p, const Type& value, const int key){
    //Inserta un nuevo nodo en el árbol
    if(p->getKey() < key){  //Si es más pequeño, va a derechas
        if(p->hasRight())
            insert(p->getRight(), value, key);
        else{
            NodeTree<Type> *node = new NodeTree<Type>(value, key);
            p->setRight(node); //Asigna el nuevo nodo
            node->setParent(p); //Le asigna padre                    
        }
    }
    else{
        if(p->hasLeft())    //Si es más grande, va a izquierdas
            insert(p->getLeft(), value, key);
        else{
            NodeTree<Type> *node = new NodeTree<Type>(value, key);
            p->setLeft(node); //Asigna el nuevo nodo
            node->setParent(p); //Le asigna padre
        }
    }
    p->setHeight(getHeight(p)); //Actualiza la altura del nodo 
}

template<class Type>
void BinarySearchTree<Type>::insert(const Type& value, const int key){
    //Inserta un nuevo nodo en el árbol
    if(search(key))
        // BST no admite elementos duplicados
        throw invalid_argument("Ya hay ese elemento");
    if(isEmpty())
        // Si está vacío, nuevo nodo será raíz
        pRoot = new NodeTree<Type>(value, key);
    else
        // En caso contrario, le busca posición para inserción
        insert(pRoot, value, key);    
}


template<class Type>
void BinarySearchTree<Type>::mirror(){
    //Crea el espejo del árbol
    mirror(pRoot);
}

//================ AUXILIARES ==================================================
template <class Type>
void BinarySearchTree<Type>::preCopy(NodeTree<Type>* p, NodeTree<Type>* orig){
    //Copia los nodos de árbol a árbol (origen a copia)
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

template<class Type>
void BinarySearchTree<Type>::postDelete(NodeTree<Type>* p){
    //Destructor de nodos
    // Si tiene hijo izquierdo
    if(p->hasLeft())
        postDelete(p->getLeft());
    // Si tiene hijo derecho
    if(p->hasRight())
        postDelete(p->getRight());    
    delete p;    // Elimina el nodo
}

template<class Type>
int BinarySearchTree<Type>::size(NodeTree<Type>* p) const{
    //Calcula el tamaño del árbol
    int size = 1;
    if(p->hasLeft())
        size += size(p->getLeft()); //Añade altura nodo izquierdo
    if(p->hasRight())
        size += size(p->getRight());   //Añade altura nodo derecho
    return size;    //Devuelve altura
}

template<class Type>
void BinarySearchTree<Type>::printPreorder(NodeTree<Type>* p) const{
    //En Preorden: VLR
    cout << p->getValue();
    if(p->hasLeft()){
        cout << endl;
        printPreorder(p->getLeft());
    }
    if(p->hasRight()){
        cout << endl;
        printPreorder(p->getRight());
    }
}

template<class Type>
void BinarySearchTree<Type>::printPostorder(NodeTree<Type>* p) const{
    //En Postorden: LRV    
    if(p->hasLeft()){
        printPostorder(p->getLeft());
        cout << endl;
    }
    if(p->hasRight()){        
        printPostorder(p->getRight());
        cout << endl;
    }
    cout << p->getValue();    
}

template<class Type>
void BinarySearchTree<Type>::printInorder(NodeTree<Type>* p) const{
    //En Inorden: LVR    
    if(p->hasLeft()){
        printInorder(p->getLeft());
    }    
    cout << p->getValue();
    cout << endl;       
    if(p->hasRight()){        
        printInorder(p->getRight());
    }
}

template<class Type>
void BinarySearchTree<Type>::mirror(NodeTree<Type>* p){
    //Crea el espejo del árbol
    NodeTree<Type>* aux = p->getLeft();//Nodo temporal, para no perder el nodo
    p->setLeft(p->getRight()); //Nodo izqdo. = nodo derecho
    p->setRight(aux); //Nodo derecho = nodo izqdo.
    //Sigue recursivamente en función de si tienen hijos o no
    if(p->hasLeft())
        mirror(p->getLeft());
    if(p->hasRight())
        mirror(p->getRight());    
}

template<class Type>
int BinarySearchTree<Type>::getHeight(NodeTree<Type>* p){
    //Calcula altura de nodo
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

#endif /* BINARYSEARCHTREE_H */
