/* 
 * File:   main.cpp
 * Author: Rodrigo Cabezas Quirós
 *
 * Created on 6 de marzo de 2018, 8:45
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "ArrayDeque.h"

using namespace std;
/*
 * 
 */

int mainMenu(vector<string> a){       
    cout << "¿Qué quieres hacer?" << endl << endl;
    for(int i = 0; i < a.size(); i++){
        cout << i + 1 <<".\t" << a[i] << endl;
    }
    int option;
    cin >> option;
    if(option > 0 && option <= a.size()){
        return option;
    }
    else{
        return -1;
    }   
}

int main() {
    int option, size, element;      
    
    cout << "Introduce tamaño para ArrayDeque:" << endl;
    cin >> size;
                
    ArrayDeque deque(size);
        
    vector <string> options;   
    options.push_back("Insertar al frente");
    options.push_back("Insertar al final");
    options.push_back("Eliminar por el frente");
    options.push_back("Eliminar por el final");
    options.push_back("Imprimir contenido de ArrayDeque");    
    options.push_back("Salir");
    cout << "*** Inicio ***" << endl << endl;
    
    do{
        option = mainMenu(options);
        switch(option){         
            case 1:{ // insertFront();
                try{
                    cout << "Introduce el elemento:" << endl;
                    cin >> element;
                    deque.insertFront(element);
                }
                catch(out_of_range full){
                    cout << full.what() << endl;
                }
                break;
            }
            case 2: //insBack(arr);
                try{
                    cout << "Introduce el elemento:" << endl;
                    cin >> element;
                    deque.insertRear(element);                    
                }
                catch(out_of_range full){
                    cout << full.what() << endl;
                }
                break;
            case 3: //removeFront(arr);
                try{
                    deque.deleteFront();
                }
                catch(out_of_range buit){
                    cout << buit.what() << endl;
                }                
                break;
            case 4: //removeRear(arr);
                try{
                    deque.deleteRear();
                }
                catch(out_of_range buit){
                    cout << buit.what() << endl;
                }   
                break;
            case 5:
            {
                deque.print();
                break;
            }
        }
    }while(option != 6);
    cout << "¡Hasta luego!" << endl;
    //delete arr;
    return 0;
}

