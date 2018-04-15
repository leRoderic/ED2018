/* 
 * File:   Impressio.h
 * Author: Tropped
 *
 * Created on 12 de abril de 2018, 11:19
 */

#include <iostream>

using namespace std;

#ifndef IMPRESSIO_H
#define IMPRESSIO_H

class Impressio {
public:
    Impressio();
    Impressio(string name, int priority, string fname);
    virtual ~Impressio();
    int getPriority();
    string getName();
    string getFname();
    
    friend ostream& operator<<(ostream&os, const Impressio& impr);
private:
    string name, fname;
    int priority;
};


#endif /* IMPRESSIO_H */

