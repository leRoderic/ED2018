
/* 
 * File:   BinarySearchTree.h
 * Author: Rodrigo Cabezas Quirós
 *
 * Created on 16 de abril de 2018, 16:41
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "NodeTree.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template<class E>
class BinarySearchTree {
public:
    // Metódos constructores
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<E>& orig);
    // Metódo destructor
    virtual ~BinarySearchTree();
    // Metódos consultores
    int size() const;
    int getHeight();
    bool isEmpty() const;
    NodeTree<E>* root();
    bool search(const E& e, NodeTree<E>* p);
    void printPreorder();
    void printPostorder();
    void printInorder();
    // Metódos modificadores
    void insert(const E& e);
    void mirror();
private:
    // Metódos internos de la clase
    void postDelete(NodeTree<E>* p);
    int size(NodeTree<E>* p) const;
    void printPreorder(NodeTree<E>* p);
    void printPostorder(NodeTree<E>* p);
    void printInorder(NodeTree<E>* p);
    int getHeight(NodeTree<E>* p);
	void mirror(NodeTree<E>* p);
    // Atributos de la clase
    NodeTree<E>* pRoot;
};

/*======================= CONSTRUCTORES ======================================*/

template<class E>
BinarySearchTree<E>::BinarySearchTree(){
    // Constructor por defecto
    cout << "Árbol binario creado" << endl;
}

template<class E>
BinarySearchTree<E>::BinarySearchTree(const BinarySearchTree<E>& orig){
    // Constructor copia
    this->pRoot = orig.root();
    cout << "Árbol binario creado" << endl;
}

/*======================= DESTRUCTOR =========================================*/

template<class E>
BinarySearchTree<E>::~BinarySearchTree(){
    // Destructor de la clase
    postDelete(this->root());    
    cout << "Árbol binario destruido"  << endl;
}

/*======================= CONSULTORES ========================================*/

template<class E>
int BinarySearchTree<E>::size() const{
    // Devuelve el tamaño del árbol
    if(this->isEmpty()){
        return 0;
    }
    else{
        // Llama a la función interna de la clase
        return (size(this->root()));
    }   
}

template<class E>
int BinarySearchTree<E>::getHeight(){
    // Devuelve la altura del árbol
    // Si el aárbol està vacío
    if(this->root() = nullptr){
        return 0;
    }
    else if(this->root()->isExternal()){
        return 1;
    }
    else{
        // Llama a la función interna de la clase
        this->getHeight(this->root());
    }
}

template<class E>
bool BinarySearchTree<E>::isEmpty() const{
    // Comprueba si el árbol está vacío
    return (this->pRoot == nullptr);
}

template<class E>
NodeTree<E>* BinarySearchTree<E>::root(){
    // Devuelve la raíz del árbol
    return (this->pRoot);    
}

template<class E>
bool BinarySearchTree<E>::search(const E& e, NodeTree<E>* p){
    // Comprueba si un elemento está en el árbol
    // RECURSIVA, HAY QUE LLAMARLA CON ROOT LA PRIMERA VEZ
    if(e == p->getData()){
        return true;        
    }
    else if(e > p->getData()){
        // Va a izquierda
        search(e,p->getLeft());
    }
    else if(e < p->getData()){
        // Va a derecha
        search(e,p->getRight());
    }
    else{
        return false;
    }
}

template<class E>
void BinarySearchTree<E>::printPreorder(){
    // Muestra el árbol por pantalla en Pre-Order
    if(this->isEmpty()){
        throw out_of_range("Nada que imprimir, árbol vacío.");
    }
    else{
        cout << "PreOrder = {";
        printPreorder(this->root());
        cout << "}" << endl;
    } 
}

template<class E>
void BinarySearchTree<E>::printPostorder(){
    // Muestra el árbol por pantalla en Post-Order
    if(this->isEmpty()){
        throw out_of_range("Nada que imprimir, árbol vacío.");
    }
    else{
        cout << "PreOrder = {";
        printPostorder(this->root());
        cout << "}" << endl;
    }
}

template<class E>
void BinarySearchTree<E>::printInorder(){
    // Muestra el árbol por pantalla en In-Order
    if(this->isEmpty()){
        throw out_of_range("Nada que imprimir, árbol vacío.");
    }
    else{
        cout << "PreOrder = {";
        printInorder(this->root());
        cout << "}" << endl;
    }
}

/*======================= MODIFICADORES ======================================*/

template<class E>
void BinarySearchTree<E>::insert(const E& e){
    // Añade un elemento al árbol
    if(this->isEmpty()){
        // Si el está vacío, se asigna el valor a la raíz directamente
        NodeTree<E>* asd = new NodeTree<E>(e);
        this->pRoot = asd;
    }
    else if(this->search(e,this->root())){
        // BST no permite elementos duplicados
        throw invalid_argument("El elemento ya existe en el árbol.");
    }
    else{
        NodeTree<E>* tmp = this->root();
        bool found = false;
        while(!found){
            // Va a izquierda
            if(tmp->getData() > e){
                // Si tiene hijos, sigue buscando
                if(tmp->hasLeft()){
                    tmp = tmp->getLeft();
                }
                // Caso contrario, crea y añade nuevo nodo.
                else{
                    NodeTree<E> *p = new NodeTree<E>(e);
                    tmp->setLeft(p);
					p->setParent(tmp);
                    found = true;
                }
            }
            else{
                // Si tiene hijos, sigue buscando
                if(tmp->hasRight()){
                    tmp = tmp->getRight();
                }
                // Casco contrario, crea y añade nuevo nodo.
                else{
                    NodeTree<E>* p = new NodeTree<E>(e);
                    tmp->setRight(p);
					p->setParent(tmp);
                    found = true;
                }
            }            
        }
    }
    cout << "Inserta al árbol el elemento " << e << endl;
}

template<class E> // NO ESTÁ ACABADO
void BinarySearchTree<E>::mirror(){
    // Intercambia los hijos de los nodos internos
	mirror(this->root());
	NodeTree<E>* tmp = this->root()->getLeft;
	this->root()->setLeft(this->root()->getRight);
	this->root()->setRight(tmp);
    cout << "Espejo del árbol creado" << endl;*/
}

/*======================= FUNCIONES INTERNAS =================================*/

template<class E>
void BinarySearchTree<E>::postDelete(NodeTree<E>* p){
    // ¿Destructor recursivo?
    if(p->hasChildren()){
        if(p->hasLeft()){
            // Elimina los hijos izquierdos recursivamente
            postDelete(p->getLeft());
        }
        if(p->hasRight()){
            // Elimina los hijos derechos recursivamente
            postDelete(p->getRight());
        }
    }
    // Elimina el nodo
    delete p;
}

template<class E>
int BinarySearchTree<E>::size(NodeTree<E>* p) const{
    // Devuelve el tamaño desde el nodo p
    if(p == nullptr){
        // El nodo ráiz tiene nivel 0
        return 0;
    }
    if(p->isExternal()){
        // Los nodos externos tiene nivel 1
        return 1;
    }
    else{
        return (size(p->getLeft()) + size(p->getRight()) + 1);
    }
}

template<class E>
void BinarySearchTree<E>::printPreorder(NodeTree<E>* p){
    // Imprime en Pre-Order desde el nodo p
    // Pre-Order: VLR
    cout << p->getData() << ", ";
    if(p->hasLeft()){
        printPreorder(p->getLeft());
    }
    if(p->hasRight()){
        printPreorder(p->getRight());
    }    
}

template<class E>
void BinarySearchTree<E>::printPostorder(NodeTree<E>* p){
    // Imprime en Post-Order desde el nodo p
    // Post-Order: LRV
    if(p->hasLeft()){
        printPostorder(p->getLeft());
    }
    if(p->hasRight()){
        printPreorder(p->getRight());
    }
    cout << p->getData() << ", ";    
}

template<class E>
void BinarySearchTree<E>::printInorder(NodeTree<E>* p){
    // Imprime en In-Order desde el nodo p
    // In-Order: LVR
    if(p->hasLeft()){
        printPostorder(p->getLeft());
    }
    cout << p->getData() << ", ";
    if(p->hasRight()){
        printPreorder(p->getRight());
    }   
}

template<class E>
int BinarySearchTree<E>::getHeight(NodeTree<E>* p){
    // Devuelve la altura del nodo p
    if(!p->hasChildren()){
        return 0;
    } 
    else if(p->isExternal()){
        return 1;
    }
    else{
        return max(getHeight(p->getLeft()+1), getHeight(p->getRight()+1));
    }
}

template<class E>
void BinarySearchTree<E>::mirror(NodeTree<E>* p) {
	if (!(p->hasChildren())) {
		return;
	}
	else {
		NodeTree<E>* tmp;
		mirror(p->getLeft());
		mirror(p->getRight());
		tmp = p->getLeft;
		p->setLeft(p->getRight());
		p->setRight(tmp);
	}
}

#endif /* BINARYSEARCHTREE_H */

