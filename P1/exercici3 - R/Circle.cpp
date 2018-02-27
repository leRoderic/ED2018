/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.cpp
 * Author: Rodrigo Cabezas Quirós
 * 
 * Created on 20 de febrer 2018, 09:27
 */

#include "Circle.h"
#include <iostream>


using namespace std;

Circle::Circle() {
    float radius = 1.0;
    float area = 3.14;
    
}

Circle::Circle(float tempRadius) {
    if(tempRadius <=0){
        cout << "No se aceptan radios negativos." << endl;
        throw 10;
    }
    else{
        const float PI = 3.1416;
        radius = tempRadius;
        area = (radius*radius)*PI;
        cout << "El área de este círculo es: " << area << endl;
    }
    
}

Circle::~Circle() {
}

float Circle::getArea(void){
    return area;
    
}

float Circle::getRadius(void){
    return radius;
}

