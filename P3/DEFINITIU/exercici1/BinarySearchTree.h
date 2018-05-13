
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
        bool search(const Type& element);
        void printInorder() const;
        void printPreorder() const;
        void printPostorder() const;
        int getHeight();
        /*Modificadores*/
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
        NodeTree<Type>* pRoot;
};

//================ CONSTRUCTORES ===============================================
template <class Type>
BinarySearchTree<Type>::BinarySearchTree(){
    //Constructor por defecto
    pRoot = nullptr;	//Crea el árbol vacío
}

template <class Type>
BinarySearchTree<Type>::BinarySearchTree(const BinarySearchTree& orig){ 
    //Constructor copia
    insert(orig.pRoot->getElement());	//Constructor copia       
}

//================ DESTRUCTOR ==================================================
template <class Type>
BinarySearchTree<Type>::~BinarySearchTree(){
    //Destructor
    postDelete(pRoot);	//Destructor.
}

//================ CONSULTORES =================================================
template <class Type>
int BinarySearchTree<Type>::size() const{
    //Devuelve el tamaño del árbol
    if(isEmpty())
        return 0;
    return size(pRoot);    
}

template <class Type>
bool BinarySearchTree<Type>::isEmpty() const{
    //Comprueba si el árbol está vacío
    return pRoot == nullptr;	//Si está vacío, no hay nodo raíz
}

template <class Type>
NodeTree<Type>* BinarySearchTree<Type>::root(){
    return this->pRoot;	//Getter para raíz del árbol
}

template <class Type>
bool BinarySearchTree<Type>::search(const Type& element){
    //Busca un elemento en el árbol
    if(isEmpty())
        return false;   //Si está vacio, no hay nada que buscar.     
    NodeTree<Type>* node = pRoot;
    bool found = false;
    while(!found){  //Mientras no se haya encontrado
        if(element > node->getElement()){   //Si es más pequeño, va a derechas
            if(node->hasRight())
                node = node->getRight();                
            else return false;
        }
        else if(element < node->getElement()){  //Si es más grande, va a izquierdas
            if(node->hasLeft())
                node = node->getLeft();
            else return false;
        }
        else found = true;  //Si el elemento coincide, se ha encontrado       
    }
    return found;        
}

template<class Type>
void BinarySearchTree<Type>::printInorder() const{
    //Imprime en inorden
    cout << "Inorder = {";
    printInorder(pRoot);    
    cout << "}" << endl;
}


template<class Type>
void BinarySearchTree<Type>::printPreorder() const{
    //Imprime en preorden
    cout << "Preorder = {";    
    printPreorder(pRoot);   
    cout << "}" << endl;
}

template<class Type>
void BinarySearchTree<Type>::printPostorder() const{
    //Imprime en postorden
    cout << "Postorder = {";
    printPostorder(pRoot);  
    cout << "}" << endl;
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
void BinarySearchTree<Type>::insert(const Type& element){
    //Inserta un nuevo nodo en el árbol
    NodeTree<Type>* node = new NodeTree<Type>(element); //Crea nuevo nodo
    if(isEmpty()){
        pRoot = node;   //Si está vacío, será la nueva raíz
    } else {
        bool found = false;
        NodeTree<Type>* aux = pRoot;
        while(!found){  //Busca posición para inserción
            if(aux->getElement() == element){   //BST no admite elementos repetidos
                delete node;    //Por o que borra el nodo creado 
                throw out_of_range("Ya hay ese elemento");
            }
            else if(aux->getElement() < element){ //Si es más grande, va a derechas
                if(aux->hasRight())
                    aux = aux->getRight();                
                else{
                    aux->setRight(node); //Coloca el nodo
                    node->setParent(aux);   //Le asigna el padre
                    found = true;   //Posición encontrada, acaba operación.                    
                }                    
            }
            
            else if(aux->getElement() > element){   //Si es más pequeño, va a izquierdas
                if(aux->hasLeft())
                    aux = aux->getLeft();                
                else{
                    aux->setLeft(node); //Coloca el nodo
                    node->setParent(aux);   //le asigna el padre.
                    found = true;   //Posición encontrada, acaba operación.
                }
            }                
        }
    }    
}


template<class Type>
void BinarySearchTree<Type>::mirror(){
    //Espejo del árbol
    mirror(pRoot);  
}

//================ AUXILIARES ==================================================
template<class Type>
void BinarySearchTree<Type>::postDelete(NodeTree<Type>* p){
    //Destructor de nodos
    // Si tiene hijo izquierdo
    if(p->hasLeft())
        postDelete(p->getLeft());
    // Si tiene hijo derecho
    if(p->hasRight())
        postDelete(p->getRight());
    delete p;   //Elimina el nodo.
}

template<class Type>
int BinarySearchTree<Type>::size(NodeTree<Type>* p) const{
    //Calcula el tamaño del árbol
    int size = 1;
    if(p->hasLeft())
        size += size(p->getLeft()); //Añade altura nodo izquierdo
    if(p->hasRight())
        size += size(p->getRight());    //Añade altura nodo derecho 
    return size;    //Devuelve altura a la función principal
}

template<class Type>
void BinarySearchTree<Type>::printPreorder(NodeTree<Type>* p) const{
    //En Preorden: VLR
    cout << p->getElement();
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
void BinarySearchTree<Type>::printPostorder(NodeTree<Type>* p) const{  
    //En Postorden: LRV
    if(p->hasLeft()){
        printPostorder(p->getLeft());
        cout << ",";
    }
    if(p->hasRight()){        
        printPostorder(p->getRight());
        cout << ",";
    }
    cout << p->getElement();    
}

template<class Type>
void BinarySearchTree<Type>::printInorder(NodeTree<Type>* p) const{
    //En Inorden: LVR
    if(p->hasLeft()){
        printInorder(p->getLeft());
    }
    cout << p->getElement();
    cout << ",";
    if(p->hasRight()){        
        printInorder(p->getRight());
    }
}

template<class Type>
void BinarySearchTree<Type>::mirror(NodeTree<Type>* p){
    //Crea el espejo del árbol
    NodeTree<Type>* aux = p->getLeft(); //Nodo temporal, para no perder el nodo
    p->setLeft(p->getRight());  //Nodo izqdo. = nodo derecho
    p->setRight(aux);   //Nodo derecho = nodo izqdo.
    //Sigue recursivamente en función de si tienen hijos o no
    if(p->hasLeft())
        mirror(p->getLeft());
    if(p->hasRight())
        mirror(p->getRight());    
}

#endif /* BINARYSEARCHTREE_H */

