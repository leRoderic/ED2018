/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayDeque.h
 * Author: Rodrigo Cabezas Quirós
 *
 * Created on 6 de marzo de 2018, 8:45
 */

#ifndef ARRAYDEQUE_H
#define ARRAYDEQUE_H
#include <vector>

using namespace std;

class ArrayDeque {
public:
    ArrayDeque(int maxSize);
    virtual ~ArrayDeque();
    bool isEmpty() const;
    bool isFull() const;
    void insertFront(int element);
    void insertRear(int element);
    void deleteFront();
    void deleteRear();
    void print();
    int getFront() const;
    int getRear() const;
    int getMaxSize() const;
private:
    int size;
    vector <int> data;
    int front;
    int rear;
    int  count;
    
};

#endif /* ARRAYDEQUE_H */

