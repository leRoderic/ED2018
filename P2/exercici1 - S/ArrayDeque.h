/* 
 * File:   ArrayDeque.h
 * Author: sbarripi7.alumnes
 *
 * Created on 6 / de març / 2018, 08:48
 */

#include <vector>
#include <iostream>

using namespace std;


#ifndef ARRAYDEQUE_H
#define ARRAYDEQUE_H

class ArrayDeque {
public:
    ArrayDeque(int maxSize);   
    ~ArrayDeque();
    
    bool isEmpty() const;
    bool isFull() const;
    void insertFront(int element);
    void insertRear(int element);
    void deleteFront();
    void deleteRear();
    void print() const;
    int getFront() const;
    int getRear() const;
    
private:
    int size;
    vector<int> data;
    int front;
    int rear;
    int count;
};

#endif /* ARRAYDEQUE_H */

