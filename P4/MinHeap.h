/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MinHeap.h
 * Author: Tropped
 *
 * Created on May 19, 2018, 11:12 AM
 */

#ifndef MINHEAP_H
#define MINHEAP_H

#include "Entry.h"
#include <vector>
#include <stdexcept>
using namespace std;

template <class Type>
class MinHeap {
public:
    MinHeap();
    MinHeap(const MinHeap& orig);
    virtual ~MinHeap();
    const int size() const;
    bool empty() const;
    void insert(int key, const Type& value);
    int min() const;
    const vector<Type> minValues() const;
    void removeMin();
    void printHeap();    
    const Type& search(int key) const;
private:
    int left(const int parent) const;
    int right(const int right) const;
    int parent(const int child) const;
    
    bool hasLeft(const int parent) const;
    bool hasRight(const int parent) const;
    bool hasParent(const int child) const;
    
    //void minValues(const int i, vector<Type>& values) const;
    void upHeap(const int i);
    void downHeap(const int i);
    void swap(const int i, const int j);
    
    const Type& search(const int key, const int parent) const;
    
    vector<Entry<Type>> heap;        
};

// =============================================
//               CONSTRUCTORS
// ============================================

/**
 * Constructor
 */
template <class Type>
MinHeap<Type>::MinHeap(){
}

/**
 * Constructor copia 
 */
template <class Type>
MinHeap<Type>::MinHeap(const MinHeap& orig){
    this->heap = orig.heap;
}

/**
 * Destructor
 */
template <class Type>
MinHeap<Type>::~MinHeap(){
}

// ===============================
//          CONSULTORES
// ==============================

/**
 * Retorna el número de nodos del minHeap
 * @return 
 */
template <class Type>
const int MinHeap<Type>::size() const{
    return heap.size();
}

/**
 * Retorna true si está vacío, de lo contrario false
 * @return 
 */
template <class Type>
bool MinHeap<Type>::empty() const{
    return heap.size() == 0;
}

/**
 * Retorna la key más pequeña
 * @return 
 */
template <class Type>
int MinHeap<Type>::min() const{
    if(empty())
        throw out_of_range("El heap está vacío");
    return heap[0].key();
}

// ==================================
//          MIN VALUES
// ==================================

/**
 * Retorna un vector con los valores con key más pequeña
 * @return 
 */
template <class Type>
const vector<Type> MinHeap<Type>::minValues() const{
    if(empty())
        throw out_of_range("El heap está vacío");
    
    vector<Type> values;            
    search(min(), 0, values);    
    return values;
}


//
//template <class Type>
//void MinHeap<Type>::minValues(int i, vector<Type>& values) const{
//    values.push_back(heap[i].value());
//    if(heap[left(i)].key() == min())
//        minValues(left(i), values);
//    if(heap[right(i)].key() == min())
//        minValues(right(i), values);    
//}
//

// ===============================
//      LEFT RIGHT PARENT
// ===============================

/**
 * Retorna el índice del hijo izquierdo 
 */
template <class Type>
int MinHeap<Type>::left(const int parent) const{
    return parent * 2 + 1;    
}

/**
 * Retorna el indice del hijo derecho
 */
template <class Type>
int MinHeap<Type>::right(const int parent) const{
    return 2 * (parent + 1);    
}

/**
*  Retorna el indice del padre
*/
template <class Type>
int MinHeap<Type>::parent(const int child) const{
    if(child % 2 == 0)
        return (child - 2)/2;
    else return (child - 1)/2;
}

/**
 * Retorna true si tiene hijo izquierdo
 */
template <class Type>
bool MinHeap<Type>::hasLeft(const int parent) const{
    return left(parent) < size();    
}

/**
 * Retorna true si tiene hijo derecho
 */
template <class Type>
bool MinHeap<Type>::hasRight(const int parent) const{
    return right(parent) < size();
}

/**
 * Retorna true si tiene padre
 */
template <class Type>
bool MinHeap<Type>::hasParent(const int child) const{
    return parent(child) >= 0;    
}


// ==================================
//          INSERT AND REMOVE
// ==================================

/**
 * Inserta una entrada en el heap
 */
template <class Type>
void MinHeap<Type>::insert(int key, const Type& value){
    heap.push_back(Entry<Type>(key, value));
    upHeap(size() - 1);
}

/**
 * Reordena el heap para mantener la propiedad de orden
 */
template <class Type>
void MinHeap<Type>::upHeap(const int i){    
    if(hasParent(i))
        if(heap[parent(i)].key() > heap[i].key()){
            swap(i, parent(i));                   
            upHeap(parent(i));            
        }    
}

/**
 * Elimina el nodo con la clave mas pequeña
 */
template <class Type>
void MinHeap<Type>::removeMin(){
    if(empty())
        throw out_of_range("El heap está vacío");
    
    int n = size();    
    heap[0] = heap[n - 1];
    heap.pop_back();
    downHeap(0);
}

/**
 * Reordena el heap para mantener la propiedad de orden
 * @param parent
 */
template <class Type>
void MinHeap<Type>::downHeap(const int parent){
    
    int child = -1;    
    if(hasLeft(parent))
        child = left(parent);                
    if(hasRight(parent)){
        if(heap[right(parent)].key() < heap[left(parent)].key())
        child = right(parent);
    }
    
    if(child != -1 && heap[child].key() < heap[parent].key()){
        swap(parent, child);    
        downHeap(child);        
    }
}

/**
 * Intercambia la llave y el valor de los nodos i y j
 */
template <class Type>
void MinHeap<Type>::swap(const int i, const int j){
    Entry<Type> aux = heap[i];
    heap[i] = heap[j];
    heap[j] = aux;    
}

// ==========================
//          PRINT
// ===========================

/**
 * Imprime el heap
 */
template <class Type>
void MinHeap<Type>::printHeap(){
    if(empty())
        throw out_of_range("El heap está vacío");
    
    cout << "Heap: " << endl;
    for(auto it=heap.begin(); it!=heap.end(); it++){
        cout << (*it).value() << ", ";
    }   
    cout << endl;
}

// =========================
//          SEARCH
// ===========================

/**
 * Retorna un vector con los valores con una clave determinada
 */
template <class Type>
const Type& MinHeap<Type>::search(int key) const{
    if(empty())
        throw out_of_range("El heap está vacío");
    
    return search(key, 0);
}

/**
 * Retorna un vector con los valores con una clave determinada
 */
template <class Type>
const Type& MinHeap<Type>::search(const int key, const int parent) const{ 
    Type& asd;
    if(heap[parent].key() == key)
         asd =  heap[parent].value();        
    if(hasLeft(parent) && heap[left(parent)].key() <= key)
        search(key, left(parent));
    
    if(hasRight(parent) && heap[right(parent)].key() <= key)
        search(key, right(parent)); 
    return asd;
}

#endif /* MINHEAP_H */

