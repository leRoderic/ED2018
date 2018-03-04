/* 
 * File:   Ellipse.cpp
 * Author: Sergio Barril Pizarro i Rodrigo Cabezas Quirós
 * 
 * Created on 20 / de febrer / 2018, 14:08
 */

#include "Ellipse.h"

Ellipse::Ellipse() {
    r1 = 0;
    r2 = 0;
}

Ellipse::Ellipse(float r1, float r2) {
    if(r1 > 0 && r2 > 0){
        this->r1 = r1;
        this->r2 = r2;
    }
    else{
        cout << "Atencio, aquests valors no son acceptats" << endl;
        throw invalid_argument("Negatiu o zero");
    }
}

Ellipse::~Ellipse(){
    
}


float Ellipse::getArea(){
    return 3.14*r1*r2;
}