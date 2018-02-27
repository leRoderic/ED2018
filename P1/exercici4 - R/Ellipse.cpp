/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.cpp
 * Author: Rodrigo Cabezas Quirós
 * 
 * Created on 26 de febrero de 2018, 20:24
 */

#include "Ellipse.h"
#include <iostream>

using namespace std;

Ellipse::Ellipse() {
    float radius1 = 1.0;
    float radius2 = 1.0;
    area = 3.14;
}

Ellipse::Ellipse(float r1, float r2) {
    if(r1 <=0 || r2 <=0){
        throw 10;
    }
    else{
        float radius1 = r1;
        float radius2 = r2;
        if(radius1 == radius2){
            area = 3.14 * radius1 * radius1;
        }
        else{
            area = 3.14 * radius1 * radius2;
        }
        cout << "El área de esta elipse es: " << area << endl;
    }   
}

Ellipse::~Ellipse() {
}

float Ellipse::getArea(void){
    return area;
}

