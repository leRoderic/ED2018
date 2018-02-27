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
#include "Ellipse.h"

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


void addFigura(int &ccount, int &ecount){
    
    char tipus;
    double r1, r2;
    
    cout << "Entra les dades de la teva figura" << endl;
    cin >> tipus >> r1;
    
    if(tipus == 'E')
        cin >> r2;
    
    switch(tipus){
        case 'C':
        {
            Circle nouCercle;
    
            try{
                nouCercle.setRadi(r1);
                cout << " L'area d'aquest cercle es de " << nouCercle.calculaArea() << endl;
                ccount++;
            }
            catch(int e){
                cout << "S'ha produit una excepcio" << endl;    
            }
            break; 
        }
        case 'E':
        {
            Ellipse novaElipse;
            
            try{
                novaElipse.setRadis(r1,r2);
                cout << "L'area d'aquesta el·lipse es de " << novaElipse.calculaArea() << endl;
                ecount++;
            }
            catch(int e){
                cout << "S'ha produit una excepcio" << endl;
            }
            
            break;
        }
        default:
            cout << "Tipus invàlid" << endl;
    }
}

int main() {
    
    string nom;
    int option;
    int circCount = 0, ellipCount = 0;
    
    vector<string> vec_options = {"Sortir", "Introduir figura", "Glossari de Figures"};
    
    do{
        option = menu(vec_options);
        
        switch(option){
            case 1:
                cout << "*** FI ***" << endl;
                break;
            case 2:
                addFigura(circCount, ellipCount);
                break;
                
            case 3:
                cout << "Tens " << circCount << " cercles ";
                cout << "i " << ellipCount << " el·lipses" << endl;
                
            default:
                cout << "No has escollit una opcio valida!" << endl;                        
        }        
    }while(option != 1);
    
    return 0;
}


