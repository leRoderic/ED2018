
#include <iostream>
#include "NodeTree.h"

#ifndef BALANCEDBST_H
#define BALANCEDBST_H


using namespace std;

template <class Type>
class BalancedBST{
    public:
        /*Constructores y Destructores*/
        BalancedBST();
        BalancedBST(const BalancedBST& orig);
        virtual ~BalancedBST();  
        /*Consultores*/
        int size() const;
        bool isEmpty() const;
        NodeTree<Type>* root();
        bool search(const Type& element);
        void printInorder() const;
        void printPreorder() const;
        void printPostorder() const;
        int getHeight();
        /*Modificadores*/
        void insert(const Type& value);
        void mirror();
    private:
        void postDelete(NodeTree<Type>* p);
        void preCopy(NodeTree<Type>* p, NodeTree<Type>* o);
        void insert(NodeTree<Type>* p, const Type& element);
        int size(NodeTree<Type>* p) const;
        void printPreorder(NodeTree<Type>* p) const;
        void printPostorder(NodeTree<Type>* p) const;
        void printInorder(NodeTree<Type>* p) const;
        int getHeight(NodeTree<Type>* p);
        int getBalance(NodeTree<Type>* p);
        void mirror(NodeTree<Type>* p);
        void rotateExternLeft(NodeTree<Type>* p);
        void rotateExternRight(NodeTree<Type>* p);
        void rotateInternLeft(NodeTree<Type>* p);
        void rotateInternRight(NodeTree<Type>* p);
        NodeTree<Type>* pRoot;
};

//================ CONSTRUCTORES ===============================================
template <class Type>
BalancedBST<Type>::BalancedBST(){
    //Constructor por defecto
    pRoot = nullptr;    //Nodo ráiz vacío
}

template <class Type>
BalancedBST<Type>::BalancedBST(const BalancedBST& orig){  
    //Constructor copia
    if(orig.isEmpty())
        pRoot = nullptr;
    else{
        pRoot = new NodeTree<Type>(orig.root());
        preCopy(pRoot, orig.pRoot); //Copia nodo a nodo
    }
}

//================ DESTRUCTOR ==================================================
template <class Type>
BalancedBST<Type>::~BalancedBST(){           
    if(!isEmpty())  //Mientras no esté vacío
        postDelete(pRoot);
}

//================ CONSULTORES =================================================
template <class Type>
int BalancedBST<Type>::size() const{
    // Retorna la cantidad de elementos en el arbol
    if(isEmpty())
        return 0;
    return size(pRoot);    
}

template <class Type>
bool BalancedBST<Type>::isEmpty() const{
    //Comrpueba si el árbol está vacío.
    return pRoot == nullptr;
}

template <class Type>
NodeTree<Type>* BalancedBST<Type>::root(){
    //Getter para nodo ráiz.
    return this->pRoot;
}

template <class Type>
bool BalancedBST<Type>::search(const Type& element){    
    //Busca un nodo
    if(isEmpty())
        return false;    
    NodeTree<Type>* node = pRoot; //Empieza desde el nodo ráiz
    bool found = false;
    while(!found){     //Mientras no lo haya encontrado   
        if(element > node->getValue()){ //Más grande, va a derechas
            if(node->hasRight())
                node = node->getRight();                
            else return false;
        }
        else if(element < node->getValue()){ //Más pequeño, va a izquierdas
            if(node->hasLeft())
                node = node->getLeft();
            else return false;
        }
        else found = true;   //Si es igual, búsqueda satisfactoria     
    }
    return found;        
}

template<class Type>
void BalancedBST<Type>::printInorder() const{
    cout << "Inorder = {";
    // Imprime el contenido en inorden
    printInorder(pRoot);
    cout << "}";
}

template<class Type>
void BalancedBST<Type>::printPreorder() const{
    // Imprime el contenido en preorden
    cout << "Preorder = {";
    printPreorder(pRoot);
    cout << "}";
}

template<class Type>
void BalancedBST<Type>::printPostorder() const{
    // Imprime el contenido en postorden
    cout << "Postorder = {";
    printPostorder(pRoot);
    cout << "}";
}

template<class Type>
int BalancedBST<Type>::getHeight(){
    // Retorna la altura del arbol, que equivale a la altura de la raiz
    if(isEmpty())
        return 0;
    else return pRoot->getHeight();
}

// =============== MODIFICADORES ===============================================
template<class Type>
void BalancedBST<Type>::insert(NodeTree<Type>* p, const Type& value){
    if(p->getValue() < value){ // Si la nueva peli tiene clave mas grande
        if(p->hasRight())
            insert(p->getRight(), value);
        else{
            NodeTree<Type> *node = new NodeTree<Type>(value);
            p->setRight(node);
            node->setParent(p);                    
        }
    }
    else{ // Si la nueva peli tiene clave mas pequeña
        if(p->hasLeft())
            insert(p->getLeft(), value);
        else{
            NodeTree<Type> *node = new NodeTree<Type>(value);
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
        case -2:    //Hace falta rotar a la derecha
            signe = balance * p->getLeft()->getBalance();
            if(signe > 0)
                rotateExternRight(p);
            else rotateInternRight(p);
            break;
        case 2: //Hace falta rotar a la izquierda
            signe = balance * p->getRight()->getBalance();
            if(signe > 0)
                rotateExternLeft(p);
            else rotateInternLeft(p);
            break;            
    }        
}

template<class Type>
void BalancedBST<Type>::insert(const Type& value){
    //Inserta un elemento en el árbol
    if(search(value))
        //No se permiten elementos duplicados
        throw invalid_argument("Ya hay ese elemento");
    if(isEmpty())
        //En caso de estar vacío, será el nodo ráiz
        pRoot = new NodeTree<Type>(value);
    else
        //Caso contrario, buscarà sitio dónde insertar
        insert(pRoot, value);    
}

template<class Type>
void BalancedBST<Type>::mirror(){
    // Invierte los hijos derechos e izquierdos
    mirror(pRoot);
}

template<class Type>
void BalancedBST<Type>::rotateExternLeft(NodeTree<Type>* node){
    //Rotación externa izquierda
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
        if(node->getValue() < node->getParent()->getValue()){ // Si node era hijo izquierdo
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
    // Rotación externa derecha
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
        if(node->getValue() < node->getParent()->getValue()) // Si node era hijo izquierdo
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
    //Rotación interna izquierda
    NodeTree<Type>* tmp = node->getRight();
    rotateExternRight(tmp);
    rotateExternLeft(node);
}

template<class Type>
void BalancedBST<Type>::rotateInternRight(NodeTree<Type>* node){
    //Rotación interna derecha
    NodeTree<Type>* tmp = node->getLeft();
    rotateExternLeft(tmp);
    rotateExternRight(node);
}

//================ AUXILIARES ==================================================
template <class Type>
void BalancedBST<Type>::preCopy(NodeTree<Type>* p, NodeTree<Type>* orig){  
    // Metodo recursivo para constructor copia
    if(orig->hasLeft()){    //Copia primero nodos de la izquierda    
        NodeTree<Type>* left = new NodeTree<Type>(orig->getLeft());
        left->setParent(p);
        p->setLeft(left);
        preCopy(left, orig->getLeft());        
    }
    //Copia los de la izquierda si procede
    if(orig->hasRight()){
        NodeTree<Type>* right = new NodeTree<Type>(orig->getRight());
        right->setParent(p);
        p->setRight(right);
        preCopy(right, orig->getRight());
    }            
}

template<class Type>
void BalancedBST<Type>::postDelete(NodeTree<Type>* p){
    // Metodo recursivo para destructor
    // Si tiene hijo izquierdo
    if(p->hasLeft())
        postDelete(p->getLeft());
    // Si tiene hijo derecho
    if(p->hasRight())
        postDelete(p->getRight());
    delete p; //Se carga el nodo
}

template<class Type>
int BalancedBST<Type>::size(NodeTree<Type>* p) const{ 
    // Metodo recursivo para obtener el numero de elementos del arbol
    int size = 1;
    if(p->hasLeft())
        size += size(p->getLeft());
    if(p->hasRight())
        size += size(p->getRight());   
    return size;
}

template<class Type>
void BalancedBST<Type>::printPreorder(NodeTree<Type>* p) const{
    //En Preorden: VLR
    cout << p->getValue();
    if(p->hasLeft()){
        cout << ",";
        printPreorder(p->getLeft());
    }
    if(p->hasRight()){
        cout << ",";
        printPreorder(p->getRight());
    }
}

template<class Type>
void BalancedBST<Type>::printPostorder(NodeTree<Type>* p) const{   
    //En Postorden: LRV
    if(p->hasLeft()){
        printPostorder(p->getLeft());
        cout << ",";
    }
    if(p->hasRight()){        
        printPostorder(p->getRight());
        cout << ",";
    }
    cout << p->getValue();    
}

template<class Type>
void BalancedBST<Type>::printInorder(NodeTree<Type>* p) const{ 
    //En Inorden: LVR
    if(p->hasLeft()){
        printInorder(p->getLeft());
    }
    cout << p->getValue();
    cout << ",";
    if(p->hasRight()){        
        printInorder(p->getRight());
    }
}

template<class Type>
void BalancedBST<Type>::mirror(NodeTree<Type>* p){
    // Metodo recursivo que invierte hijos izq. y derecho
    NodeTree<Type>* aux = p->getLeft();
    p->setLeft(p->getRight());
    p->setRight(aux);
    if(p->hasLeft())
        mirror(p->getLeft());
    if(p->hasRight())
        mirror(p->getRight());    
}

template<class Type>
int BalancedBST<Type>::getHeight(NodeTree<Type>* p){
    // Metodo que calcula la altura de un nodo, y la retorna.
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
    //Calcula el balance de un nodo
    int balance = 0;
    if(p->hasRight())
        balance += p->getRight()->getHeight();
    if(p->hasLeft())
        balance -= p->getLeft()->getHeight();    
    return balance;
}

#endif /* BALANCEDBST */