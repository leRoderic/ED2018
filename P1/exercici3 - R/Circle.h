/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.h
 * Author: Rodrigo Cabezas Quirós
 *
 * Created on 20 de febrero 2018, 09:27
 */

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
    float getRadius();
    float getArea();
    Circle();
    Circle(float radius);
    virtual ~Circle();
private:
    float radius;
    float area;
    

};

#endif /* CIRCLE_H */

