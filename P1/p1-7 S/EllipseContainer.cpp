/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EllipseContainer.cpp
 * Author: Tropped
 * 
 * Created on 3 de marzo de 2018, 13:55
 */

#include <stdexcept>
#include <vector>
#include "EllipseContainer.h"


EllipseContainer::EllipseContainer() {
}

EllipseContainer::EllipseContainer(const EllipseContainer& orig) {
}

EllipseContainer::~EllipseContainer() {
}

void EllipseContainer::addEllipse(Ellipse* ellipse) {
    if(v.size() < 10)    
        v.push_back(ellipse);
    else
        throw length_error("El vector esta ple: ja te 10 figures");
}

float EllipseContainer::getAreas(){
    vector<Ellipse *>::iterator it;
    float suma = 0;
    
    for(it = v.begin(); it != v.end(); it++)
        suma += (*it)->getArea();
    
    return suma;
}

vector<Ellipse *> EllipseContainer::getVector(){
    return v;
}