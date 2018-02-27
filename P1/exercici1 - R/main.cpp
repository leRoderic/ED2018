/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Rodrigo Cabezas Quirós
 *
 * Created on 20 de febrero 2018, 08:29
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
    string name;
    string arr_options[] = {"1. Salir", "2. Bienvenida"};
    int option;
    cout << "Hola, ¿Cómo te llamas?" << endl;
    cin >> name;
    cout << "Hola " << name << ", ¿que quieres hacer?" << endl << endl;
    do
    {
        for(int i=0; i < 2; i++)
            cout << arr_options[i] << endl;
        cin >> option;
        if(!(option > 0 && option < 3))
            cout << "Opción errónea. Vuelve a probar." << endl;
        switch(option)
        {
            case 2:
                cout << "¡Bienvenid@ a la asignatura de estructuras de datos " << name << "!" << endl;
                break;
        }
    }   
    while(option != 1);
    cout << "¡Hasta luego!" << endl;
    return 0;
}

