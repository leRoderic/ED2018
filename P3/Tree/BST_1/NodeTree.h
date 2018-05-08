/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
        NodeTree(const Type& data);
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
        const Type& getElement() const;
        int getHeight() const;
        
        /*Modificadors*/
        void setHeight(int h);
        void setData(const Type& data);
        void setRight(NodeTree<Type>* newRight);
        void setLeft(NodeTree<Type>* newLeft);
        void setParent(NodeTree<Type>* newParent);
        
        private:
        NodeTree<Type>* pParent;
        NodeTree<Type>* pLeft;
        NodeTree<Type>* pRight;
        Type data;
        int height;
};

#endif /* NODETREE_H */



// Constructores y destructores 
template <class Type>
NodeTree<Type>::NodeTree(const Type& data){
    pParent = nullptr;
    pLeft = nullptr;
    pRight = nullptr;
    this->data = data;
    this->height = 0;    
}

template <class Type>
NodeTree<Type>::~NodeTree(){
    
}


// Consultores
template <class Type>
NodeTree<Type>* NodeTree<Type>::getright() const{
    return this->pRight;    
}

template <class Type>
NodeTree<Type>* NodeTree<Type>::getleft() const{
    return this->pLeft;
}

template <class Type>
NodeTree<Type>* NodeTree<Type>::getparent() const{
    return this->pParent;
}

template <class Type>
bool NodeTree<Type>::hasRight() const{    
    return !(pRight == nullptr);
}

template <class Type>
bool NodeTree<Type>::hasLeft() const{
    return !(pLeft == nullptr);
}

template <class Type>
bool NodeTree<Type>::isRoot() const{
    return pParent == nullptr;
}

template <class Type>
bool NodeTree<Type>::isExternal() const{
    return !hasRight() && !hasLeft();
}

template <class Type>
const Type& NodeTree<Type>::getElement() const{
    return this->data;
}

// Modificadores

template <class Type>
void NodeTree<Type>::setHeight(int h){
    this->height = h;
}

template <class Type>
void NodeTree<Type>::setData(const Type& data){
    this->data = data;
}

template <class Type>
void NodeTree<Type>::setRight(NodeTree<Type>* newRight){
    pRight = newRight;
}

template <class Type>
void NodeTree<Type>::setLeft(NodeTree<Type>* newLeft){
    pLeft = newLeft;
}

template <class Type>
void NodeTree<Type>::setParent(NodeTree<Type>* newParent){
    pParent = newParent;
}

template <class Type>
int NodeTree<Type>::getHeight() const{
    return this->height;
}


