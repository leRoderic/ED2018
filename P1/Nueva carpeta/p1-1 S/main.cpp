/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sbarripi7.alumnes
 *
 * Created on 20 / de febrer / 2018, 08:11
 */


#include <array>
#include <iostream>

using namespace std;

int main() {
    
    string nom;
    int option;
       
    array<string, 2> arr_options = {"Sortir", "Benvinguda"};
    
    cout << "Hola, com et dius?" << endl;
    cin >> nom;
    
  
    do{
        cout << "Hola " << nom <<", que vols fer?" << endl;
        
        for(int i = 0; i < arr_options.size(); i++){
            cout << i + 1 << ".\t" << arr_options[i] << endl;
        }
        
        cin >> option;
        
        switch(option){
            case 1:
                break;

            case 2:
                cout << "Benvigut/da a l'assignatura d'Estructura de Dades, " << nom << endl;
                break;
                
            default:
                cout << "No has escollit una opcio valida!" << endl;                        
        }  
    }while(option != 1);
    
    return 0;
}

