/* 
 * File:   Ellipse.h
 * Author: Sergio Barril Pizarro i Rodrigo Cabezas Quirós
 *
 * Created on 20 / de febrer / 2018, 14:08
 */

#include <iostream>
#include <stdexcept>

using namespace std;

#ifndef ELLIPSE_H
#define ELLIPSE_H

class Ellipse {
    
    private:
        float r1;
        float r2;
        
    public:
        Ellipse();
        Ellipse(float,float);
        virtual ~Ellipse();
        
        float getArea();
};

#endif