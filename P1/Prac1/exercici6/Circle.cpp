/* 
 * File:   Circle.cpp
 * Author: Sergio Barril Pizarro i Rodrigo Cabezas Quirós
 * 
 * Created on 20 / de febrer / 2018, 10:06
 */

#include "Circle.h"


Circle::Circle():Ellipse(){
    cout << "Soc el constructor del Cercle" << endl;
}

Circle::Circle(float r):Ellipse() {
    cout << "Soc el constructor del Cercle" << endl;
    
    if(r > 0){
        r1 = r;
        r2 = r;
    } else{
        cout << "Atencio, aquest valor no es acceptat" << endl;
        throw invalid_argument("Negatiu o zero");
    }
}

float Circle::getArea(){
    return 3.14*r1*r1;
}

Circle::~Circle(){
    cout<<"Soc el destructor del cercle" << endl;
}









