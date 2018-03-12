/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
        cout << a[i] << endl;
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

void insFront(ArrayDeque arr){
    try{
        int element;
        cout << "Introduce elemento:" << endl;
        cin >> element;
        arr.insertFront(element);
        cout << "Elemento " << element << " agregado." << endl;
    } // Excepciones isFull() y ArrayDeque no existe
    catch(int e){
        
    }
}


void insBack(ArrayDeque arr){
    try{
        int element;
        cout << "Introduce elemento:" << endl;
        cin >> element;
        arr.insertRear(element);
        cout << "Elemento " << element << " agregado." << endl;
    }// Excecpciones ArrayDeque isFull() y ArrayDeque no existe
    catch (int e){
        
    }
}

void removeFront(ArrayDeque arr){
    try{
        int element = arr.getFront();
        arr.deleteFront();
        cout << "Elemento " << element << " eliminado." << endl;
    }
    catch(int e){
        // Excecpción ArrayDeque isEmpty()
    }
}

void removeRear(ArrayDeque arr){
    try{
        int element = arr.getRear();
        arr.deleteRear();
        cout << "Elemento " << element << " eliminado." << endl;
    }
    catch(int e){
        // Excecpción ArrayDeque isEmpty()
    }
}


int main() {
    int option, tmp;
    ArrayDeque* arr;
    vector <string> options;
    options.push_back("1. Nuevo ArrayDeque");
    options.push_back("2. Insertar al frente");
    options.push_back("3. Insertar al final");
    options.push_back("4. Eliminar por el frente");
    options.push_back("5. Eliminar por el final");
    options.push_back("6. Imprimir contenido de ArrayDeque");
    options.push_back("7. Salir");
    cout << "*** Inicio ***" << endl << endl;
    do{
        option = mainMenu(options);
        switch(option){
            case 1:{
                cout << "Introduce tamaño para ArrayDeque:" << endl;
                cin >> tmp;
                ArrayDeque* arr = new ArrayDeque(tmp);
                break;
            }
            case 2:{
                //insFront(arr);
                break;
            }
            case 3:
                //insBack(arr);
                break;
            case 4:
                //removeFront(arr);
                break;
            case 5:
                //removeRear(arr);
                break;
            case 6:
                //arr.print();
                break;
        }
        
    }while(option != 7);
    cout << "¡Hasta luego" << endl;
    //delete arr;
    return 0;
}

