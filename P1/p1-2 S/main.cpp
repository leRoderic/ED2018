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

using namespace std;


int menu(string nom, vector<string> vec_options){
    cout << "Hola " << nom << ", que vols fer?" << endl;
    
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

int main() {
    
    string nom;
    int option;
    
    vector<string> vec_options = {"Sortir", "Benvinguda", "Redefinir el nom"};
    
    
    cout << "Hola, com et dius?" << endl;
    cin >> nom;
    

    
    do{
        
        option = menu(nom, vec_options);
        
        switch(option){
            case 1:
                break;

            case 2:
                cout << "Benvigut/da a l'assignatura d'Estructura de Dades, " << nom << endl;
                break;
                
            case 3:
                cout << "Quin es el teu nou nom?" << endl;
                cin >> nom;
                break;
                
            default:
                cout << "No has escollit una opcio valida!" << endl;                        
        }        
    }while(option != 1);
    
    return 0;
}


