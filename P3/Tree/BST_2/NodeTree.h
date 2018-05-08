/* 
 * File:   NodeTree.h
 * Author: sbarripi7.alumnes
 *
 * Created on 17 / d’abril / 2018, 08:18
 */


#ifndef NODETREE_H
#define NODETREE_H

using namespace std;

template <class Type>
class NodeTree {
    public:
        NodeTree(const Type& value, const int key);
        NodeTree(const NodeTree& orig);
        virtual ~NodeTree(); // destructor

        /*Consultors*/
        NodeTree<Type>* getright() const;
        NodeTree<Type>* getleft() const;
        NodeTree<Type>* getparent() const;
        bool hasRight() const;
        bool hasLeft() const;
        bool isRoot() const;
        bool isExternal() const;
        const Type& getValue() const;
        const int getKey() const;
        int getHeight() const;
        
        /*Modificadors*/
        void setHeight(int h);
        void setValue(const Type& newValue);
        void setKey(int newKey);
        void setRight(NodeTree<Type>* newRight);
        void setLeft(NodeTree<Type>* newLeft);
        void setParent(NodeTree<Type>* newParent);
        
        private:
        NodeTree<Type>* pParent;
        NodeTree<Type>* pLeft;
        NodeTree<Type>* pRight;
        Type value;
        int key;
        int height;
};

#endif /* NODETREE_H */


/********************************
    Constructores y destructores 
*********************************/

// Constructor
template <class Type>
NodeTree<Type>::NodeTree(const Type& value, const int key) :
    pParent(nullptr),
    pLeft(nullptr),
    pRight(nullptr),
    value(value),
    key(key),
    height(1)
{      
}

template <class Type>
NodeTree<Type>::NodeTree(const NodeTree& orig):
    pParent(nullptr),
    pLeft(nullptr),
    pRight(nullptr),
    value(orig.value),
    height(orig.height)
{          
}


// Destructor
template <class Type>
NodeTree<Type>::~NodeTree(){    
}

/***************************
        Consultores
****************************/

// Retorna el hijo derecho
template <class Type>
NodeTree<Type>* NodeTree<Type>::getright() const{
    return this->pRight;    
}

// Retorna el hijo izquierdo
template <class Type>
NodeTree<Type>* NodeTree<Type>::getleft() const{
    return this->pLeft;
}

// Retorna el padre
template <class Type>
NodeTree<Type>* NodeTree<Type>::getparent() const{
    return this->pParent;
}

// True si tiene hijo derecho, false si no
template <class Type>
bool NodeTree<Type>::hasRight() const{    
    return !(pRight == nullptr);
}

// True si tiene hijo izquierdo, false si no
template <class Type>
bool NodeTree<Type>::hasLeft() const{
    return !(pLeft == nullptr);
}

// True si es root, false si no
template <class Type>
bool NodeTree<Type>::isRoot() const{
    return pParent == nullptr;
}

// True si es un nodo externo, false si es interno
template <class Type>
bool NodeTree<Type>::isExternal() const{
    return !hasRight() && !hasLeft();
}


// Retorna el valor contenido en el nodo
template <class Type>
const Type& NodeTree<Type>::getValue() const{
    return this->value;
}

// Retorna la clave del nodo
template <class Type>
const int NodeTree<Type>::getKey() const{
    return this->key;
}


/********************
    Modificadores
********************/
template <class Type>
void NodeTree<Type>::setHeight(int h){
    this->height = h;
}
    
// Modifica el valor del nodo
template <class Type>
void NodeTree<Type>::setValue(const Type& value){
    this->value = value;
}

// Cambia de nodo que tiene como hijo derecho
template <class Type>
void NodeTree<Type>::setRight(NodeTree<Type>* newRight){
    pRight = newRight;
}

// Cambia de nodo que tiene como hijo izquierdo
template <class Type>
void NodeTree<Type>::setLeft(NodeTree<Type>* newLeft){
    pLeft = newLeft;
}

// Cambia de nodo que tiene como padre
template <class Type>
void NodeTree<Type>::setParent(NodeTree<Type>* newParent){
    pParent = newParent;
}

// Retorna la altura del nodo
template <class Type>
int NodeTree<Type>::getHeight() const{
    return this->height;
}