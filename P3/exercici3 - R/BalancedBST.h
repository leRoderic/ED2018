
/* 
 * File:   BalancedBST.h
 * Author: Rodrigo Cabezas Quirós
 *
 * Created on 2 de mayo de 2018, 19:43
 */

#ifndef BALANCEDBST_H
#define BALANCEDBST_H
#include "NodeTree.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template<class E>
class BalancedBST {
public:
    BalancedBST();
    int size() const;
    bool isEmpty() const;
    NodeTree<E>* root();
    void insert(const E& element, const int key);
    bool search(const int key);
    void printPreorder() const;
    void printInorder() const;
    void printPostorder() const;
    int getHeight();
    void mirror();
    void rotateExternLeft(NodeTree<E>* node);
    void rotateExternRight(NodeTree<E>* node);
    void rotateInternLeft(NodeTree<E>* node);
    void rotateInternRight(NodeTree<E>* node);
    virtual ~BalancedBST();
private:
    NodeTree<E>* pRoot;
    int size(NodeTree<E>* p);
    void insert(NodeTree<E>* p,const E& element, const int key);
    void printPreorder(NodeTree<E>* node) const;
    void printInorder(NodeTree<E>* node) const;
    void printPostorder(NodeTree<E>* node) const;
    int getHeight(NodeTree<E>* node);
    void mirror(NodeTree<E>* node);
    void postDelete(NodeTree<E>* node);
};

template<class E>
BalancedBST<E>::BalancedBST():
    pRoot(nullptr)
{
}

template<class E>
int BalancedBST<E>::size() const{
    if(isEmpty()){
        return 0;
    }
    else{
        return size(pRoot);
    }
}

template<class E>
bool BalancedBST<E>::isEmpty() const{
    return (pRoot == nullptr);
}

template<class E>
NodeTree<E>* BalancedBST<E>::root(){
    return this->pRoot;
}

template<class E>
void BalancedBST<E>::insert(const E& element, const int key){
    if(search(key)){
        throw invalid_argument("El elemento ya está en el árbol.");
    }
    else if(isEmpty()){
        pRoot = new NodeTree<E>(element,key);
    }
    else{
        insert(pRoot, element, key);
    }
}

template<class E>
bool BalancedBST<E>::search(const int key){
    if(isEmpty()){
        return false;
    }
    NodeTree<E>* node = pRoot;
    bool found = false;    
    while(!found){        
        if(key > node->getKey()){
            if(node->hasRight()){
                node = node->getRight();
            }                
            else{
                return false;
            }
        }
        else if(key < node->getKey()){
            if(node->hasLeft()){
                node = node->getLeft();
            }
            else{
                return false;
            }
        }
        else{
            found = true;
        }
    }
    return found;        
}

template<class E>
void BalancedBST<E>::printPreorder() const{
    cout << "Preorder = {";
    printPreorder(pRoot);
    cout << "}";
}

template<class E>
void BalancedBST<E>::printInorder() const{
    cout << "Inorder = {";
    printInorder(pRoot);
    cout << "}";
}

template<class E>
void BalancedBST<E>::printPostorder() const{
    cout << "Postorder = {";
    printPostorder(pRoot);
    cout << "}";
}

template<class E>
int BalancedBST<E>::getHeight(){
    if(isEmpty()){
        return 0;
    }
    else{
        return pRoot->getHeight();
    }
}

template<class E>
void BalancedBST<E>::mirror(){
    mirror(pRoot);
}

template<class E>
void BalancedBST<E>::rotateExternLeft(NodeTree<E>* node){
        NodeTree<E>* tmp = node->getRight();
    node->setLeft(tmp->getRight());
    if(tmp->hasRight()){
        tmp->getRight()->setParent(node);
    }
    tmp->setRight(node);
    if(node == pRoot){
        node->setParent(tmp);
        tmp->setParent(nullptr);
        this->pRoot = tmp;
    }
    else{
        if(node->getValue() < node->getParent()->getValue()){
            node->getParent()->setLeft(tmp);
        }
        else{
            node->getParent()->setRight(tmp);
        }
        tmp->setParent(node->getParent());
        node->setParent(tmp);
    }    
}

template<class E>
void BalancedBST<E>::rotateExternRight(NodeTree<E>* node){
    NodeTree<E>* tmp = node->getRight();
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
        if(node->getValue() < node->getParent()->getValue()){
            node->getParent()->setLeft(tmp);
        }
        else{
            node->getParent()->setRight(tmp);
        }
        tmp->setParent(node->getParent());
        node->setParent(tmp);
    }
}

template<class E>
void BalancedBST<E>::rotateInternLeft(NodeTree<E>* node){
    NodeTree<E>* tmp = node->getRight();
    rotateExternRight(tmp);
    rotateExternLeft(node);
}

template<class E>
void BalancedBST<E>::rotateInternRight(NodeTree<E>* node){
    NodeTree<E>* tmp = node->getLeft();
    rotateExternLeft(tmp);
    rotateExternRight(node);
}

template<class E>
BalancedBST<E>::~BalancedBST(){
    postDelete(pRoot);
}

template<class E>
int BalancedBST<E>::size(NodeTree<E>* node){
    int size = 1;
    if(node->hasLeft()){
        size += size(node->getLeft());
    }
    if(node->hasRight()){
        size += size(node->getRight());
    }
    return size;
}

template<class E>
void BalancedBST<E>::insert(NodeTree<E>* node, const E& element, const int key){
    if(node->getKey() > key){
        if(node->hasLeft()){
            insert(node->getLeft(),element,key);
        }
        else{
            NodeTree<E>* tmp = new NodeTree<E>(element, key);
            node->setLeft(tmp);
        }
    }
    else{
        if(node->hasRight()){
            insert(node->getRight(),element,key);
        }
        else{
            NodeTree<E>* tmp = new NodeTree<E>(element,key);
            node->setRight(tmp);
        }
    }
    int h1 = node->getLeft()->getHeight();
    int h2 = node->getRight()->getHeight();
    int h4, h3;
    if(h1 - h2 > 1){
        h3 = node->getLeft()->getLeft()->getHeight();
        h4 = node->getLeft()->getRight()->getHeight();
        if(h3 > h4){
            rotateExternLeft(node);
        }
        else{
            rotateInternLeft(node);
        }
    }
    else if(h1 - h2 < -1){
        h3 = node->getRight()->getLeft()->getHeight();
        h4 = node->getRight()->getRight()->getHeight();
        if(h3 > h4){
            rotateInternRight(node);
        }
        else{
            rotateExternRight(node);
        }
    }
}

template<class E>
void BalancedBST<E>::printPreorder(NodeTree<E>* node) const{
    cout << node->getValue();
    if(node->hasLeft()){
        cout << ",";
        printPreorder(node->getLeft());
    }
    if(node->hasRight()){
        cout << ",";
        printPreorder(node->getRight());
    }
}

template<class E>
void BalancedBST<E>::printInorder(NodeTree<E>* node) const{
    if(node->hasLeft()){
        cout << ",";
        printInorder(node->getLeft());
    }
    cout << node->getValue();
    if(node->hasRight()){
        cout << ",";
        printInorder(node->getRight());
    }
}

template<class E>
void BalancedBST<E>::printPostorder(NodeTree<E>* node)const{
    if(node->hasLeft()){
        cout << ",";
        printPostorder(node->getLeft());
    }
    if(node->hasRight()){
        cout << ",";
        printPostorder(node->getRight());
    }
    cout << node->getValue();
}

template<class E>
int BalancedBST<E>::getHeight(NodeTree<E>* node){
    int lHeight = 0, rHeight = 0;
    if(node->hasLeft()){
        lHeight = node->getLeft()->getHeight();
    }
    if(node->hasRight()){
        rHeight = node->getRight()->getHeight();
    }
    int maxHeight = max(rHeight,lHeight) + 1;
    return maxHeight;
}

template<class E>
void BalancedBST<E>::mirror(NodeTree<E>* node){
    NodeTree<E>* aux = node->getLeft();
    node->setLeft(node->getRight());
    node->setRight(aux);
    if(node->hasLeft()){
        mirror(node->getLeft());
    }
    if(node->hasRight()){
        mirror(node->getRight());
    }
}

template<class E>
void BalancedBST<E>::postDelete(NodeTree<E>* node){
    if(node->hasLeft()){
        postDelete(node->getLeft());
    }
    if(node->hasRight()){
        postDelete(node->getRight());
    }
    delete node;
}

#endif /* BALANCEDBST_H */

