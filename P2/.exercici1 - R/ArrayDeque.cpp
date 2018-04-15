/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayDeque.cpp
 * Author: Rodrigo Cabezas Quirós
 * 
 * Created on 6 de marzo de 2018, 8:45
 */

#include "ArrayDeque.h"
#include <iostream>
#include <stdexcept>

using namespace std;

ArrayDeque::ArrayDeque(int maxSize) {
    size = maxSize;
    vector <int> data1 = vector <int> (maxSize);
    this->data = data1;
    cout << "Estructura creada." << endl;
}

ArrayDeque::~ArrayDeque() {
}

bool ArrayDeque::isEmpty() const{
    if(this->data.size() == 0){
        return true;
    }
    return false;    
}

bool ArrayDeque::isFull() const{
    if(this->data.size() == this->getMaxSize()){
        return true;
    }
    return false;
}

void ArrayDeque::insertFront(int element){
    if(isFull()){
        throw length_error("EXCEPTION: El vector ya está lleno.");
    }
    if(!isFull()){
        this->data.push_back(element);
    }
    else{
        for(int i = this->data.size(); 0 < i; i--){
            this->data[i] = this->data[i-1];
        }
        this->data[0] = element;
        this->front = element;
    }
}

void ArrayDeque::insertRear(int element){
    if(isFull()){
        throw length_error("EXCEPTION: El vector ya está lleno.");
    }
    else{
        this->data.push_back(element);
        this->rear = element;
    }
}

void ArrayDeque::deleteFront(){
    if(!isEmpty()){
        if(this->data.size() == 1){
            this->data.clear();
        }
        else{
            for(int i = 0; i < this->data.size(); i++){
                this->data[i] = this->data[i+1];
            }
            this->front = this->data[0];
        }
    }
    else{
        throw out_of_range("EXCEPTION: La estructura está vacía.");
    }
}

void ArrayDeque::deleteRear(){
    if(isEmpty()){
        throw out_of_range("EXCEPTION: La estructura está vacía.");
    }
    else{
        int tmp = this->data.size();
        this->rear = this->data[tmp - 1];
        this->data.pop_back();
    }
}

void ArrayDeque::print(){
    if(isEmpty()){
        throw out_of_range("ArrayDeque está vacío.");
    }
    else{
        // Imprime de la siguiente forma: [20, 80, 45]
        cout << "Contenido de ArrayDeque:" << endl;
        cout <<"[";
        for(int i = 0; i < this->data.size(); i++){
        cout << " " << this->data[i] << ",";
        }
        cout << "]" << endl;
    }
}

int ArrayDeque::getFront() const{
    if(isEmpty()){
        throw out_of_range("ArrayDeque está vacío.");
        return -1;
    }
    else{
        // Utilizando metódos de la clase Vector,
        //return this->data.front();
        return this->front;
    }  
}

int ArrayDeque::getRear() const{
    if(isEmpty()){
        throw out_of_range("ArrayDeque está vacío.");
        return -1;
    }
    else{
        // Utilizando metódos de la clase Vector,
        //return this->data.back();
        return this->rear;
    }
}

int ArrayDeque::getMaxSize() const{
    return this->size;
}