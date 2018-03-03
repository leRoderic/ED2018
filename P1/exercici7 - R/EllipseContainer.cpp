/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EllipseContainer.cpp
 * Author: Rodrigo Cabezas Quirós
 * 
 * Created on 2 de marzo de 2018, 18:19
 */

#include "EllipseContainer.h"
#include "Ellipse.h"
#include "Circle.h"
#include <iostream>
#include <vector>

using namespace std;

EllipseContainer::EllipseContainer() {
    vector <Ellipse*> v = vector <Ellipse*> (10);
}

EllipseContainer::EllipseContainer(const EllipseContainer& orig) {
}

EllipseContainer::~EllipseContainer() {
}

void EllipseContainer::addEllipse(Ellipse* a){
    if(v.size() < 10){
        this->v.push_back(a);
    }
    else{
        throw 10;
    }
    
}

float EllipseContainer::getAreas(void){
    vector <Ellipse*> :: iterator it;
    float suma = 0;
    int i = 0;
    for(it = v.begin(); it != v.end(); it++){
        suma += (*it)->getArea();    
    }
    return suma;
}

vector<Ellipse *> EllipseContainer::getVector(){
    return v;
}
