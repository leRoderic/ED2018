/* 
 * File:   LinkedDeque.h
 * Author: sbarripi7.alumnes
 *
 * Created on 10 / d’abril / 2018, 14:45
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
LinkedDeque<Element>::LinkedDeque(){
    
    _front = new Node<Element>();
    _rear = new Node<Element>();
    
    _front->setNext(_rear);
    _rear->setPrevious(_front);
                    
    this->num_elements = 0;
}

template <class Element>
LinkedDeque<Element>::LinkedDeque(const LinkedDeque<Element>& deque){
    
    this->_front = new Node<Element>();
    this->_rear = new Node<Element>();

    this->_front->setNext(_rear);
    this->_rear->setPrevious(_front);
                    
    this->num_elements = 0;
    
    Node<Element>* tmp = deque._front->getNext();
    while(tmp->getNext() != nullptr){ // si tmp no es el rear
        insertFront(tmp->getElement());
        tmp = tmp.getNext();
    }                
}

template <class Element>
LinkedDeque<Element>::~LinkedDeque(){     
    while(!isEmpty())
        deleteFront();
    delete _front;
    delete _rear;
    
}

template <class Element>
void LinkedDeque<Element>::deleteFront(){
    if(isEmpty()){
        throw out_of_range("El deque está vacío.");
    }
    
    Node<Element> *tmp = _front->getNext();         
    _front->setNext(tmp->getNext());
    tmp->getNext()->setPrevious(_front);
    tmp->setPrevious(_front);
    
    delete tmp;    
    num_elements--;
}

template <class Element>
void LinkedDeque<Element>::deleteRear(){
    if(isEmpty()){
        throw out_of_range("El deque está vacío");
    }
    
    Node<Element> *tmp = _rear->getPrevious();
    _rear->setPrevious(tmp->getPrevious());
    tmp->getPrevious()->setNext(_rear);
    
    delete tmp;
    num_elements--;
}

template <class Element>
const Element& LinkedDeque<Element>::getFront() const{
    return _front->getNext()->getElement();
}

template <class Element>
const Element& LinkedDeque<Element>::getRear() const{
    return _rear->getPrevious()->getElement();
}

template <class Element>
void LinkedDeque<Element>::insertFront(const Element& element){
    Node<Element>* nuevo = new Node<Element>(element);        // nuevo nodo
  
    nuevo->setNext(_front->getNext());
    nuevo->setPrevious(_front);
    _front->setNext(nuevo); // frente a derecha
    nuevo->getNext()->setPrevious(nuevo);

    num_elements++;    
}

template <class Element>
void LinkedDeque<Element>::insertRear(const Element& element){
    Node<Element>* nuevo = new Node<Element>(element);        // nuevo nodo
    
    nuevo->setPrevious(_rear->getPrevious());
    nuevo->setNext(_rear);    // rear a izquierda    
    _rear->setPrevious(nuevo);
    nuevo->getPrevious()->setNext(nuevo);
    
    
    
    num_elements++;
}

template <class Element>
bool LinkedDeque<Element>::isEmpty() const{
    return (num_elements == 0);
}

template <class Element>
void LinkedDeque<Element>::print(){       
    Node<Element> *tmp = _front->getNext();
    cout << "[";    
    for(int i=0; i< num_elements - 1; i++){
        cout << tmp->getElement() << ", ";
        tmp = tmp->getNext();
    }  
    if(!isEmpty())
        cout << tmp->getElement();            
    cout << "]" << endl;                
}

template <class Element>
int LinkedDeque<Element>::size(){
    return num_elements;
}

#endif /* LINKEDDEQUE_H */