/* 
 * File:   Circle.cpp
 * Author: Sergio Barril Pizarro i Rodrigo Cabezas Quirós
 * 
 * Created on 20 / de febrer / 2018, 10:06
 */

#include "Circle.h"

Circle::Circle() {
    radi = 0;
}

Circle::Circle(float r) {   
    if(r > 0)
        radi = r;
    else{
        cout << "Atencio, aquest valor no es acceptat" << endl;
        throw invalid_argument("Radi negatiu o zero");
    }
}

Circle::~Circle(){
    
}

float Circle::getArea(){
    return 3.14*radi*radi;
}







