/* 
 * File:   Node.h
 * Author: Rodrigo Cabezas Quirós
 * 
 * Created on 20 de marzo de 2018, 8:04
 */

#ifndef NODE_H
#define NODE_H

template <class Element>
class Node {
public:
    Node();
    Node(Element element);
    virtual ~Node();
    Element getElement();
    Node getNext();
    void setNext(Node &a);
    Node getPrevious();
    void setPrevious(Node &a);
private:
    Node<Element> *next;
    Node<Element> *previous;
    Element element;
};

template <class Element>
Node<Element>::Node() {
    this->next = nullptr;
    this->previous = nullptr;
    this->element = nullptr;
}

template <class Element>
Node<Element>::Node(Element element) {
    this->next = nullptr;
    this->previous = nullptr;
    this->element = element;
}

template <class Element>
Element Node<Element>::getElement(){
    return this->element;
}

template <class Element>
Node<Element> Node<Element>::getNext(){
    return this->next;
}

template <class Element>
Node<Element> Node<Element>::getPrevious(){
    return this->previous;
}

template <class Element>
void Node<Element>::setNext(Node& a){
    this->next = a;
}

template <class Element>
void Node<Element>::setPrevious(Node& a){
    this->previous = a;
}

#endif /* NODE_H */

