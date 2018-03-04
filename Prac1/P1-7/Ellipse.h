/* 
 * File:   Ellipse.h
 * Author: Sergio Barril Pizarro i Rodrigo Cabezas Quirós
 *
 * Created on 20 / de febrer / 2018, 14:08
 */

#include <iostream>
using namespace std;

#ifndef ELLIPSE_H
#define ELLIPSE_H

class Ellipse {
    
    protected:
        float r1;
        float r2;
        
    public:
        Ellipse();
        Ellipse(float, float);
        
        virtual float getArea();
        virtual ~Ellipse();
};
#endif