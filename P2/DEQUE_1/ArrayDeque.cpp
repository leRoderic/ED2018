/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayDeque.cpp
 * Author: sbarripi7.alumnes
 * 
 * Created on 6 / de març / 2018, 08:48
 */

#include "ArrayDeque.h"

ArrayDeque::ArrayDeque(int maxSize) {    
        
    vector<int> vtemp(maxSize);
    size = maxSize;   
    this->data = vtemp;
    front = 0;
    rear = 0;
    count = 0;
    
    cout << "Estructura creada" << endl;
}

ArrayDeque::~ArrayDeque() {
}

void ArrayDeque::insertFront(int element){
    if(isFull()){
        throw out_of_range("La estructura está llena");
    }
    
    if(!isEmpty())
        front = (front+ 1)%size;       
    data[front] = element;
    count++; 
    cout << "Elemento " << element << " agregado" << endl;
}

void ArrayDeque::insertRear(int element){
    if(isFull())
        throw out_of_range("La estructura está llena");
    
    if(!isEmpty())
        rear = (rear + size - 1)%size;
    
    data[rear] = element;
          
    count++;
    cout << "Elemento " << element << " agregado" << endl;
}

void ArrayDeque::deleteFront(){
    if(isEmpty())
        throw out_of_range("La estructura está vacía");
        
    int element = getFront();    
    
    if(count > 1)
        front = (front + size - 1)%size;        
    count--;
    
    cout << "Elemento " << element << " eliminado" << endl;
}

void ArrayDeque::deleteRear(){
    if(isEmpty())
        throw out_of_range("La estructura está vacía");
    
    int element = getRear();
    
    if(count > 1)
        rear = (rear + 1)%size;       
    count--;
    
    cout << "Elemento " << element << " eliminado" << endl;
}


bool ArrayDeque::isFull() const{    
    return (count == size);    
}

bool ArrayDeque::isEmpty() const{
    return (count == 0);
}

int ArrayDeque::getFront() const{
    if(isEmpty())
        throw out_of_range("La estructura está vacía");
    return data[front];    
}

int ArrayDeque::getRear() const{
    if(isEmpty())
        throw out_of_range("La estructura está vacía");
    return data[rear];    
}

void ArrayDeque::print() const{
    if(isEmpty())
        cout << "[]" << endl;
    else{  
        cout << "[";
        for(int i = front; i != rear; i = (i + size - 1)%size)
            cout << data[i] << ",";    
        cout << data[rear] << "]" << endl;
    }
}