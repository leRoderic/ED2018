/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.cpp
 * Author: sbarripi7.alumnes
 * 
 * Created on 20 / de febrer / 2018, 14:08
 */

#include "Ellipse.h"

Ellipse::Ellipse() {
    
    cout << "Soc el constructor de l'elipse" << endl;
    
    r1 = 0;
    r2 = 0;
}

Ellipse::Ellipse(float r1, float r2){
    
    cout << "Soc el constructor de l'elipse" << endl;    
    setRadis(r1,r2);
}

Ellipse::Ellipse(const Ellipse& orig){
    
    cout << "Soc el constructor copia de l'elipse" << endl;
    setRadis(orig.r1,orig.r2);
}

void Ellipse::setRadis(float r1, float r2){
    if(r1 > 0 && r2 > 0){
        this->r1 = r1;
        this->r2 = r2;
    }
    else
        throw invalid_argument("Atencio, aquests valors no son acceptats");
}

float Ellipse::getR1(){
    return r1;
}

float Ellipse::getArea(){
    return 3.14*r1*r2;
}

Ellipse::~Ellipse(){
    cout << "Soc el destructor de l'elipse" << endl;
}