/* 
 * File:   NodeTree.h
 * Author: sbarripi7.alumnes
 *
 * Created on 17 / d’abril / 2018, 08:18
 */


#ifndef NODETREE_H
#define NODETREE_H

using namespace std;

template <class E>
class NodeTree {
    public:
        NodeTree(const E& value, const int key);
        NodeTree(const NodeTree& orig);
        virtual ~NodeTree(); // destructor

        /*Consultors*/
        NodeTree<E>* getRight() const;
        NodeTree<E>* getLeft() const;
        NodeTree<E>* getParent() const;
        bool hasRight() const;
        bool hasLeft() const;
        bool isRoot() const;
        bool isExternal() const;
        const E& getValue() const;
        const int getKey() const;
        int getHeight() const;
		
        
        /*Modificadors*/
        void setHeight(int h);
        void setValue(const E& newValue);
        void setKey(int newKey);
        void setRight(NodeTree<E>* newRight);
        void setLeft(NodeTree<E>* newLeft);
        void setParent(NodeTree<E>* newParent);
        
        private:
        NodeTree<E>* pParent;
        NodeTree<E>* pLeft;
        NodeTree<E>* pRight;
        E value;
        int key;
        int height;
		int fBal;
};

#endif /* NODETREE_H */


/********************************
    Constructores y destructores 
*********************************/

// Constructor
template <class E>
NodeTree<E>::NodeTree(const E& value, const int key){
	this->pParent = nullptr;
	this->pLeft = nullptr;
	this->pRight = nullptr;
	this->value = value;
	this->key = key;
	this->height = 1;
	this->fBal = 0;
}

template <class E>
NodeTree<E>::NodeTree(const NodeTree& orig):
    pParent(nullptr),
    pLeft(nullptr),
    pRight(nullptr),
    value(orig.value),
    height(orig.height)
	fBal(orig.fBal)
{          
}


// Destructor
template <class E>
NodeTree<E>::~NodeTree(){    
}

/***************************
        Consultores
****************************/

// Retorna el hijo derecho
template <class E>
NodeTree<E>* NodeTree<E>::getRight() const{
    return this->pRight;    
}

// Retorna el hijo izquierdo
template <class E>
NodeTree<E>* NodeTree<E>::getLeft() const{
    return this->pLeft;
}

// Retorna el padre
template <class E>
NodeTree<E>* NodeTree<E>::getParent() const{
    return this->pParent;
}

// True si tiene hijo derecho, false si no
template <class E>
bool NodeTree<E>::hasRight() const{    
    return !(pRight == nullptr);
}

// True si tiene hijo izquierdo, false si no
template <class E>
bool NodeTree<E>::hasLeft() const{
    return !(pLeft == nullptr);
}

// True si es root, false si no
template <class E>
bool NodeTree<E>::isRoot() const{
    return pParent == nullptr;
}

// True si es un nodo externo, false si es interno
template <class E>
bool NodeTree<E>::isExternal() const{
    return !hasRight() && !hasLeft();
}


// Retorna el valor contenido en el nodo
template <class E>
const E& NodeTree<E>::getValue() const{
    return this->value;
}

// Retorna la clave del nodo
template <class E>
const int NodeTree<E>::getKey() const{
    return this->key;
}


/********************
    Modificadores
********************/
template <class E>
void NodeTree<E>::setHeight(int h){
    this->height = h;
}
    
// Modifica el valor del nodo
template <class E>
void NodeTree<E>::setValue(const E& value){
    this->value = value;
}

// Cambia de nodo que tiene como hijo derecho
template <class E>
void NodeTree<E>::setRight(NodeTree<E>* newRight){
    pRight = newRight;
}

// Cambia de nodo que tiene como hijo izquierdo
template <class E>
void NodeTree<E>::setLeft(NodeTree<E>* newLeft){
    pLeft = newLeft;
}

// Cambia de nodo que tiene como padre
template <class E>
void NodeTree<E>::setParent(NodeTree<E>* newParent){
    pParent = newParent;
}

// Retorna la altura del nodo
template <class E>
int NodeTree<E>::getHeight() const{
    return this->height;
}