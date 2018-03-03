/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.h
 * Author: sbarripi7.alumnes
 *
 * Created on 20 / de febrer / 2018, 14:08
 */

#include <iostream>
using namespace std;

#ifndef ELLIPSE_H
#define ELLIPSE_H

class Ellipse {
    
    private:
        float r1;
        float r2;
        
    public:
        Ellipse();
        Ellipse(float, float);
        Ellipse(const Ellipse&);
        void setRadis(float, float);
        
        float getR1();
        virtual float getArea();
        virtual ~Ellipse();
};
#endif