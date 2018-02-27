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

class Ellipse {
    
    private:
        double r1;
        double r2;
        
    public:
        Ellipse();
        void setRadis(double, double);
        double calculaArea();
};