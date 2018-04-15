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
#include "LinkedDeque.h"

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


void delFront(LinkedDeque<int> *deque){
    if(deque != nullptr){
        try{
            deque->deleteFront();
        }catch(out_of_range buit){
            cout << "EXCEPTION: " << buit.what() << endl;
        }
    }
}

void delRear(LinkedDeque<int> *deque){
    if(deque != nullptr){
        try{
            deque->deleteRear();
        }catch(out_of_range buit){
            cout << "EXCEPTION: " << buit.what() << endl;
        }
    }
}


void testCase1(){   
    LinkedDeque<int> *deque = new LinkedDeque<int>();
    delFront(deque);
    delRear(deque);
    deque->insertFront(20);   
    deque->insertFront(30);
    deque->insertRear(80);
    deque->insertRear(45);   
    delFront(deque);
    deque->print();
    delete deque;
}

void testCase2(){
    LinkedDeque<int> *deque = new LinkedDeque<int>();
    delFront(deque);
    delRear(deque);
    deque->insertFront(2);
    deque->insertFront(3);
    deque->insertRear(8);
    deque->insertRear(4);    
    delFront(deque);
    deque->print();
    delete deque;   
}

void menuDeque(vector<string> options){          
    int option, element;          
    LinkedDeque<int> *deque = new LinkedDeque<int>();
    
    
    do{
        option = mainMenu(options);
        switch(option){         
            case 1:{ // insertFront();                
                cout << "Introduce el elemento:" << endl;
                cin >> element;
                deque->insertFront(element);
                break;
            }
            case 2: //insBack(arr);                
                cout << "Introduce el elemento:" << endl;
                cin >> element;
                deque->insertRear(element);
                break;
            case 3: //removeFront(arr);
                delFront(deque);              
                break;
            case 4: //removeRear(arr);
                delRear(deque);
                break;
            case 5:
            {
                deque->print();
                break;
            }
        }
    }while(option != 6);   
}

int main() {
    int option = 0;
       
    vector <string> modos;
    modos.push_back("Nuevo Deque");
    modos.push_back("Test Case #1");
    modos.push_back("Test Case #2");
    modos.push_back("Salir");

    vector <string> options;    
    options.push_back("Insertar al frente");
    options.push_back("Insertar al final");
    options.push_back("Eliminar por el frente");
    options.push_back("Eliminar por el final");
    options.push_back("Imprimir contenido de LinkedDeque");    
    options.push_back("Salir");
    
    cout << "*** Inicio ***" << endl << endl;        
    do{
        option = mainMenu(modos);
        switch(option){
            case 1:{ // inicializar deque                
                menuDeque(options);
                break;
            }
            case 2:{
                testCase1();
                break;
            }
            case 3:{
                testCase2();
                break;
            }
            case 4:{
                cout << "¡Hasta luego!" << endl;
                break;
            }
            default:
                cout << "Opción no válida" << endl;
        }
    }while(option != 4);                
    return 0;
}

