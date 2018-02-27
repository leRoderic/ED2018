/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sbarripi7.alumnes
 *
 * Created on 20 / de febrer / 2018, 09:11
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Circle.h"

using namespace std;


int menu(vector<string> vec_options){
    cout << "Hola, que vols fer?" << endl;
    
    for(int i = 0; i < vec_options.size(); i++){
            cout << i + 1 << ".\t" << vec_options[i] << endl;
        }
    
    int option;
    cin >> option;  
    
    if(option > 0 && option <= vec_options.size())
        return option;
    else
        return -1;
}


void addCercle(int &count){
    
    double radi;
    
    cout << "Cercle número " << ++count << endl;
    cout << "Radi?" << endl;
    
    cin >> radi;
    Circle nouCercle;
    
    try{
        nouCercle.setRadi(radi);
        cout << "L'area d'aquest cercle es de " << nouCercle.calculaArea() << endl;
    }
    catch(int e){
        cout << "S'ha produit una excepcio" << endl;
                
    }
}

int main() {
    
    int option;
    int circCount = 0;
    
    vector<string> vec_options = {"Sortir", "Introduir cercle"};
    
    do{
        option = menu(vec_options);
        
        switch(option){
            case 1:
                cout << "*** FI ***" << endl;
                break;
            case 2:
                addCercle(circCount);
                break;
                
            default:
                cout << "No has escollit una opcio valida!" << endl;                        
        }        
    }while(option != 1);
    
    return 0;
}


