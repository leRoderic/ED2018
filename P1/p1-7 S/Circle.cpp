/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.cpp
 * Author: sbarripi7.alumnes
 * 
 * Created on 20 / de febrer / 2018, 10:06
 */

#include "Circle.h"


Circle::Circle():Ellipse(){
    cout << "Soc el constructor del Cercle" << endl;
}

Circle::Circle(float r):Ellipse() {
    cout << "Soc el constructor del Cercle" << endl;
    setRadi(r);
}

Circle::Circle(const Circle &orig):Ellipse(orig) {
    cout << "Soc el constructor copia del Circle" << endl;
}

void Circle::setRadi(float r){
    
    if(r > 0){
        Circle::setRadis(r,r);
    }
    else
        throw invalid_argument("Atencio, aquest valor no es acceptat");
}

float Circle::getArea(){
    float r1 = getR1();
    return 3.14*r1*r1;
}

Circle::~Circle(){
    cout<<"Soc el destructor del cercle" << endl;
}









