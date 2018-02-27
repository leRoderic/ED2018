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
#include <fstream>

#include "Circle.h"
#include "Ellipse.h"

using namespace std;

/*
 * 
 */
int main() {
    int numCircles = 0, numEllipses = 0;
    char tipo;
    float dato1, dato2;
    vector <string> options;
    options.push_back("1. Salir");
    options.push_back("2. Añadir figura");
    options.push_back("3. Glosario de figuras");
    int option;
    cout << "*** Inicio ***" << endl << endl;
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
                cout << "Introduce los datos de la figura: tipo[C ó E] dato1 dato2 [0 en tipo C]" << endl;
                cin >> tipo >> dato1 >> dato2;
                switch(tipo){
                    case 'C':{
                        try{
                        Circle* circle = new Circle(dato1);
                        numCircles++;
                        }
                        catch(int e){
                            cout << "No se aceptan radios negativos." << endl;
                        }
                        break;
                    }
                    case 'E':{
                        try{
                            Ellipse* elipse = new Ellipse(dato1, dato2);
                            numEllipses++;
                        }
                        catch(int e){
                            cout << "No se aceptan radios negativos." << endl;
                        }
                        break;
                    }
                    default:{
                        cout << "No se ha seleccionado ninguna figura posible." << endl;
                        break;
                    } 
                }
                break;
            case 3:
                cout << "Tienes " << numCircles << " círculos y " << numEllipses << " elipses." << endl;
        }
    }   
    while(option != 1);
    cout << "¡Hasta luego!" << endl;
    return 0;
}

