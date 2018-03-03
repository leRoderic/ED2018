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

#include "Ellipse.h"
#include "Circle.h"
#include <iostream>


using namespace std;

Circle::Circle(){
    float radius = 1.0;
    float area = 3.14;
    cout << "Soy el constructor del círculo por defecto." << endl;
    
}

Circle::Circle(float r1, float r2){
    cout << "Soy el constructor del círculo con parámetros." << endl;
    if(r1 <=0 || r2 <= 0){
        throw 10;
    }
    else{
        const float PI = 3.1416;
        radius1 = r1;
        area = r1 * r2 * PI;
        cout << "El área de este círculo es: " << area << endl;
    }
    
}

Circle::~Circle() {
}

float Circle::getRadius(void){
    return radius1;
}

