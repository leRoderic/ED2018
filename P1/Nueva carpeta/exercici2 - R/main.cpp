/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Rodrigo Cabezas Quirós
 *
 * Created on 20 de febrero 2018, 09:00
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */
int main() {
    vector <string> options;
    string name;
    options.push_back("1. Salir");
    options.push_back("2. Bienvenida");
    options.push_back("3. Cambiar nombre");
    int option;
    cout << "Hola, ¿Cómo te llamas?" << endl;
    cin >> name;
    cout << "Hola " << name << ", ¿que quieres hacer?" << endl << endl;
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
                cout << "¡Bienvenid@ a la asignatura de estructuras de datos " << name << "!" << endl;
                break;
            case 3:
                cout << "Dime tu nuevo nombre:" << endl;
                cin >> name;
                cout << "Nombre cambiado a " << name << "." << endl;
                break;
                
        }
    }   
    while(option != 1);
    cout << "¡Hasta luego!" << endl;
    return 0;
}

