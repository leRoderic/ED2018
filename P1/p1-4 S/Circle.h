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
using namespace std;

class Circle {
    
    private:
        double radi;
        
    public:
        Circle();
        void setRadi(double);
        double calculaArea();
};

