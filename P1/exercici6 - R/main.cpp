/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Rodrigo Cabezas Quirós
 *
 * Created on 27 de febrero 2018, 20:11
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
void newCircle(int dato1){
    try{
        Circle* circle = new Circle(dato1, dato1);
        }
    catch(int e){
        cout << "No se aceptan radios negativos." << endl;
    }
    
}

void newEllipse(int dato1, int dato2){
    try{
        Ellipse* elipse = new Ellipse(dato1, dato2);
        }
    catch(int e){
        cout << "No se aceptan radios negativos." << endl;
    }
}

int main() {
    int numCircles = 0, numEllipses = 0;
    char tipo;
    float dato1, dato2;
    string nombre;
    vector <string> options;
    options.push_back("1. Salir");
    options.push_back("2. Añadir figura");
    options.push_back("3. Glosario de figuras");
    options.push_back("4. Procesar archivo");
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
                        newCircle(dato1);
                        numCircles++;
                        break;
                    }
                    case 'E':{
                        newEllipse(dato1, dato2);
                        numEllipses++;
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
                break;
            case 4:
                cout << "Introduce nombre del fichero:" << endl;
                cin >> nombre;

                ifstream fichero(nombre);
                while(!fichero.eof()){
                    fichero >> tipo;
                    fichero >> dato1;
                    if(tipo == 'C'){
                        newCircle(dato1);
                        numCircles++;
                    }
                    else{
                        fichero >> dato2;
                        newEllipse(dato1, dato2);
                        numEllipses++;
                    }
                }
                fichero.close();
                cout << "Fin de fichero." << endl << endl;
                break;
        }
    }   
    while(option != 1);
    cout << "¡Hasta luego!" << endl;
    return 0;
}

