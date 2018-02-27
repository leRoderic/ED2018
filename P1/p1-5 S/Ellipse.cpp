/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.cpp
 * Author: sbarripi7.alumnes
 * 
 * Created on 20 / de febrer / 2018, 14:08
 */

#include "Ellipse.h"

Ellipse::Ellipse() {
}

void Ellipse::setRadis(double r1, double r2){
    if(r1 > 0 && r2 > 0){
        this->r1 = r1;
        this->r2 = r2;
    }
    else{
        cout << "Atencio, aquests valors no son acceptats" << endl;
        throw -1;
    }
}

double Ellipse::calculaArea(){
    return 3.14*r1*r2;
}