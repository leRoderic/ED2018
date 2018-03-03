/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.h
 * Author: Rodrigo Cabezas Quirós
 *
 * Created on 26 de febrero de 2018, 20:24
 */

#ifndef ELLIPSE_H
#define ELLIPSE_H

class Ellipse {
public:
    virtual float getArea();
    Ellipse();
    Ellipse(float r1, float r2);
    virtual ~Ellipse();
protected:
    const float PI = 3.14;
    float radius1;
    float radius2;
    float area;

};

#endif /* ELLIPSE_H */

