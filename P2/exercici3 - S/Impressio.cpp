/* 
 * File:   Impressio.cpp
 * Author: Tropped
 * 
 * Created on 12 de abril de 2018, 11:19
 */

#include "Impressio.h"

Impressio::Impressio(){
    
}

Impressio::Impressio(string name, int priority, string fname) {
    this->name = name;
    this->priority = priority;
    this->fname = fname;
}

Impressio::~Impressio() {
}

int Impressio::getPriority(){
    return this->priority;
}

string Impressio::getName(){
    return this->name;
}

string Impressio::getFname(){
    return this->fname;
}