/* 
 * File:   Circle.h
 * Author: Sergio Barril Pizarro i Rodrigo Cabezas Quirós
 *
 * Created on 20 / de febrer / 2018, 10:06
 */

#include <iostream>
#include <stdexcept>


using namespace std;

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
    
    private:
        float radi;
        
    public:
        Circle();
        Circle(float);   
        virtual ~Circle();
        
        float getArea();
};

#endif