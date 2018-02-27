/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Circle.cpp
 * Author: sbarripi7.alumnes
 * 
 * Created on 20 / de febrer / 2018, 10:06
 */

#include "Circle.h"

Circle::Circle() {
}

double Circle::getRadi(){
    return this->radi;
}

void Circle::setRadi(double r){
    
    if(r > 0)
        radi = r;
    else{
        cout << "Atencio, aquest valor no es acceptat" << endl;
        throw -1;
    }
    
}

double Circle::calculaArea(){
    return 3.14*radi*radi;
}







