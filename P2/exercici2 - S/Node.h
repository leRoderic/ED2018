/* 
 * File:   Node.h
 * Author: sbarripi7.alumnes
 *
 * Created on 10 / d’abril / 2018, 14:02
 */


#ifndef NODE_H
#define NODE_H

template <class Element>
class Node {
public:
    Node();
    Node(const Element & element);   
    virtual ~Node();
    const Element getElement();
    Node<Element>* getNext();
    void setNext(Node<Element> *nuevo);
    Node<Element>* getPrevious();        
    void setPrevious(Node<Element> *nuevo);
private:
    Node<Element> *next;
    Node<Element> *previous;
    Element element;
};

template <class Element>
Node<Element>::Node(){
    this->next = nullptr;
    this->previous = nullptr;
}

template <class Element>
Node<Element>::Node(const Element &element) {
    this->next = nullptr;
    this->previous = nullptr;
    this->element = element;
}

template <class Element>
Node<Element>::~Node(){
    
}


template <class Element>
const Element Node<Element>::getElement(){
    return this->element;
}

template <class Element>
Node<Element>* Node<Element>::getNext(){
    return this->next;
}

template <class Element>
Node<Element>* Node<Element>::getPrevious(){
    return this->previous;
}

template <class Element>
void Node<Element>::setNext(Node<Element> *nuevo){
    this->next = nuevo;
}

template <class Element>
void Node<Element>::setPrevious(Node<Element> *nuevo){
    this->previous = nuevo;
}

#endif /* NODE_H */

