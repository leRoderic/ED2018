/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.h
 * Author: sbarripi7.alumnes
 *
 * Created on 20 / de febrer / 2018, 10:06
 */

#include <iostream>
#include "Ellipse.h"

using namespace std;

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle: public Ellipse{
            
    public:
        Circle();
        Circle(float);
        Circle(const Circle&);
        void setRadi(float);
        virtual ~Circle();
        float getArea();
};

#endif

