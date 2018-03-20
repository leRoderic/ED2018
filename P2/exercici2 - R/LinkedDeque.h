/* 
 * File:   LinkedDeque.h
 * Author: Rodrigo Cabezas Quirós
 * 
 * Created on 20 de marzo de 2018, 8:04
 */

#ifndef LINKEDDEQUE_H
#define LINKEDDEQUE_H
#include "Node.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template <class Element>
class LinkedDeque {
public:
    LinkedDeque<Element>();
    LinkedDeque(const LinkedDeque<Element>& deque);
    virtual ~LinkedDeque();
    bool isEmpty() const;
    void insertFront(const Element & element);
    void insertRear(const Element & element);
    void deleteFront();
    void deleteRear();
    void print();
    int size();
    const Element& getFront() const;
    const Element& getRear()const;
private:
    Node<Element> *_front;
    Node<Element> *_rear;
    int num_elements;
};

template <class Element>
Element LinkedDeque<Element>::LinkedDeque(){
    this->_front = nullptr;
    this->_rear = nullptr;
    this->num_elements = 0;
}

template <class Element>
Element LinkedDeque<Element>::LinkedDeque(const LinkedDeque<Element>& deque){
    this->_front = nullptr;
    this->_rear = nullptr;
    this->num_elements = 0;
}

template <class Element>
Element LinkedDeque<Element>::deleteFront(){
    if(this->_front = nullptr){
        throw underflow_error("No hay ningún frente asignado.");
    }
    Node tmp = this->getFront();     // antiguo frente
    delete _front;                  // fuera antiguo frente  
    this->_front = tmp.getNext();  // asigno el nuevo frente
    this->num_elements--;
}

template <class Element>
Element LinkedDeque<Element>::deleteRear(){
    if(this->_rear = nullptr){
        throw underflow_error("No hay ningún rear asignado.");
    }
    Node tmp = this->getRear();        // antiguo rear
    delete _rear;                     // fuera antiguo rear
    this->_rear = tmp.getPrevious(); // asigno nuevo rear
    this->num_elements--;
}

template <class Element>
Element LinkedDeque<Element>::getFront() const{
    return this->_front;
}

template <class Element>
Element LinkedDeque<Element>::getRear() const{
    return this->_rear;
}

template <class Element>
Element LinkedDeque<Element>::insertFront(const Element& element){
    Node* a = new Node(element);        // nuevo nodo
    a.setNext(this->getFront());       // frente a derecha
    this->_front.setPrevious(a);      // anterior a frente ahora es el nuevo nodo
    this->_front = a;                // el frente es el nuevo nodo
    this->num_elements++;
}

template <class Element>
Element LinkedDeque<Element>::insertRear(const Element& element){
    Node* a = new Node(element);        // nuevo nodo
    a.setPrevious(this->getRear());    // rear a izquierda
    this->_rear->setNext(a);          // siguiente de cola es nuevo nodo
    this->_rear = a;                 // rear es el nuevo nodo
    this->num_elements++;
}

template <class Element>
Element LinkedDeque<Element>::isEmpty() const{
    return (this->num_elements == 0);
}

template <class Element>
Element LinkedDeque<Element>::print(){
    if(isEmpty()){
        throw underflow_error;
    }
    Node tmp = this->_front;
    while(tmp){
        cout << tmp.getElement() << " ";
        tmp = tmp.getNext();
    }   
}

template <class Element>
Element LinkedDeque<Element>::size(){
    return this->num_elements;
}

#endif /* LINKEDDEQUE_H */

