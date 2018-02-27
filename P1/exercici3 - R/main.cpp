/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Rodrigo Cabezas Quirós
 *
 * Created on 20 de febrero 2018, 09:19
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <math.h>

#include "Circle.h"

using namespace std;

/*
 * 
 */
int main() {
    int circleNumber = 0;
    float tempRadius;
    vector <string> options;
    options.push_back("1. Salir");
    options.push_back("2. Introducir círculo");
    int option;
    cout << "Hola, ¿que quieres hacer?" << endl << endl;
    do
    {
        for(int i=0; i < options.size(); i++)
            cout << options[i] << endl;
        cin >> option;
        if(!(option > 0 && option < (options.size() + 1)))
            cout << "Opción errónea. Vuelve a probar." << endl;
        switch(option)
        {
            case 2:
                circleNumber++;
                cout << "Círculo número " << circleNumber << "." << endl;
                cout << "Introduce radio del círculo " << circleNumber << ":" << endl;
                cin >> tempRadius;
                try{
                    Circle* circle = new Circle(tempRadius);
                }catch(int e){
                    cout << "Se ha producido una excepción." << endl;
                }
                break;
                
        }
    }   
    while(option != 1);
    cout << "¡Hasta luego!" << endl;
    return 0;
}

