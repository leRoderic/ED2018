
/* 
 * File:   NodeTree.h
 * Author: Rodrigo Cabezas Quirós
 *
 * Created on 16 de abril de 2018, 16:41
 */

#ifndef NODETREE_H
#define NODETREE_H
#include <iostream>

using namespace std;

template<class E>
class NodeTree {
public:
    // Metódos constructores
    NodeTree(const E& data);
    NodeTree(const NodeTree<E>& orig);
    // Metódo destructor
    virtual ~NodeTree();
    // Metódos consultores
    NodeTree<E>* getRight() const;
    NodeTree<E>* getLeft() const;
    NodeTree<E>* getParent() const;
    const E& getData() const;
    int getHeight() const;
    bool isRoot() const;
    bool isExternal() const;
    bool hasRight() const;
    bool hasLeft() const;
    bool hasChildren() const;
    // Metódos modificadores
    void setData(const E& data);
    void setRight(NodeTree<E>* node);
    void setLeft(NodeTree<E>* node);
    void setParent(NodeTree<E>* node);
private:
    // Atributos de la clase
    NodeTree<E>* pParent;
    NodeTree<E>* pRight;
    NodeTree<E>* pLeft;
    E data;
    int height;
};

/*======================= CONSTRUCTORES ======================================*/

template<class E>
NodeTree<E>::NodeTree(const E& data){
    // Constructor por parámetro
    this->pParent = nullptr;
    this->pRight = nullptr;
    this->pLeft = nullptr;
    this->data = data;
    this->height = 0;
}

template<class E>
NodeTree<E>::NodeTree(const NodeTree<E>& orig){
    // Constructor copia
    this->pParent = orig.getParent();
    this->pRight = orig.getRight();
    this->pLeft = orig.getLeft();
    this->data = orig.getData();
    this->height = orig.getHeight();
}

/*======================= DESTRUCTOR =========================================*/

template<class E>
NodeTree<E>::~NodeTree(){
    // Destructor de la clase
    
}

/*======================= CONSULTORES ========================================*/

template<class E>
NodeTree<E>* NodeTree<E>::getRight() const{
    // Getter para hijo izquierdo
    return this->pRight;
}

template<class E>
NodeTree<E>* NodeTree<E>::getLeft() const{
    // Getter para hijo derecho
    return this->pLeft;
}

template<class E>
NodeTree<E>* NodeTree<E>::getParent() const{
    // Getter para padre
    return (this->pParent);
}

template<class E>
const E& NodeTree<E>::getData() const{
    // Getter para contenido
    return (this->data);
}

template<class E>
int NodeTree<E>::getHeight() const{
    // Getter para altura.
    return (this->height);
}

template<class E>
bool NodeTree<E>::isRoot() const{
    // Comprueba si es raíz
    return (this->getParent() == nullptr);
}

template<class E>
bool NodeTree<E>::isExternal() const{
    // Comprueba si es externo
    return (!this->hasRight() && !this->hasLeft());
}

template<class E>
bool NodeTree<E>::hasRight() const{
    // Comprueba si tiene hijo derecho
    return (this->getRight() != nullptr);
}

template<class E>
bool NodeTree<E>::hasLeft() const{
    // Comprueba si tiene hijo izquierdo
    return (this->getLeft() != nullptr);
}

template<class E>
bool NodeTree<E>::hasChildren() const{
    // Comprueba si tiene hijos
    return (this->hasLeft() || this->hasRight());
}

/*======================= MODIFICADORES ======================================*/

template<class E>
void NodeTree<E>::setData(const E& data){
    // Setter para contenido
    this->data = data;
}

template<class E>
void NodeTree<E>::setRight(NodeTree<E>* node){
    // Setter para hijo derecho
    this->pRight = node;
}

template<class E>
void NodeTree<E>::setLeft(NodeTree<E>* node){
    // Setter para hijo izquierdo
    this->pLeft = node;
}

template<class E>
void NodeTree<E>::setParent(NodeTree<E>* node){
    // Setter para padre
    this->pParent = node;
}

#endif /* NODETREE_H */

