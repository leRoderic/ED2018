/* 
 * File:   main.cpp
 * Author: Rodrigo Cabezas Quirós
 * 
 * Created on 20 de marzo de 2018, 8:04
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "LinkedDeque.h"

using namespace std;

int main() {
    LinkedDeque<string> *deque = new LinkedDeque<string>();
    int opt;
    vector <string> options;
    options.push_back("1. Leer un fichero con las entradas de la cola de impresión");
    options.push_back("2. Eliminar impresión por delante");
    options.push_back("3. Eliminar impresión por el final");
    options.push_back("4. Añadir n entradas de impresión desde teclado");
    options.push_back("5. Emprimir cola de impresión");
    options.push_back("6. Salir");
    cout << "*** Inicio ***" << endl << endl;
    for(int i = 0; i < options.size(); i++){
        cout << options[i] << endl;
    }
    cin >> opt;
    do{
        switch(opt){
            case 1:
                string a, nombre, archivo;
                int prioridad;
                cout << "Introduce nombre del fichero: "<< endl;
                cin >> a;
                fstream fichero(a);
                while(!fichero.eof()){
                    fichero >> nombre;
                    fichero >> prioridad;
                    fichero >> archivo;
                    if(prioridad == 1){
                        //deque.insertFront(archivo);
                    }
                    else{
                        //deque.insertRear(archivo);
                    }
                }
                break;
            /*case 2:
                deque.deleteFront();
                break;
            case 3:
                deque.deleteRear();
                break;
            case 4:
                break;
            case 5:
                deque.print();
                break;  */ 
        }   
    }while(opt !=6);
    delete deque;
    return 0;
}

