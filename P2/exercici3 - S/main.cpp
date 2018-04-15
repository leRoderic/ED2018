/* 
 * File:   main.cpp
 * Author: Rodrigo Cabezas Quirós
 *
 * Created on 6 de marzo de 2018, 8:45
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "LinkedDeque.h"
#include "Impressio.h"

using namespace std;

ostream& operator<<(ostream& out, const Impressio &impr){
    
    out << endl << impr.name << "\t\t" << impr.priority << "\t" << impr.fname;

    return out;
}


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


void delFront(LinkedDeque<Impressio> *deque){
    if(deque != nullptr){
        try{
            deque->deleteFront();
        }catch(out_of_range buit){
            cout << "EXCEPTION: " << buit.what() << endl;
        }
    }
}

void delRear(LinkedDeque<Impressio> *deque){
    if(deque != nullptr){
        try{
            deque->deleteRear();
        }catch(out_of_range buit){
            cout << "EXCEPTION: " << buit.what() << endl;
        }
    }
}

void prioridad(LinkedDeque<Impressio>* deque, Impressio *impr){
    switch(impr->getPriority()){
        case 1:
            deque->insertFront(*impr);
            break;
        case 2:
            deque->insertRear(*impr);
            break;
        default:
            cout << "Prioridad inválida. Impresión no añadida" << endl;                                    
    }
        
}

void readFile(LinkedDeque<Impressio> * deque){
    Impressio *impr;
    string fentradas;
    cout << "Introduce el nombre del fichero" << endl;
    cin >> fentradas;
    
    string name, fname;
    int priority;
    
    ifstream fichero(fentradas);
    if(fichero.is_open()){
        while(!fichero.eof()){
            fichero >> name;
            fichero >> priority;
            fichero >> fname;
            
            impr = new Impressio(name, priority, fname);
            prioridad(deque, impr);               
        }
        fichero.close();
    }
}

void teclado(LinkedDeque<Impressio> *deque){
    Impressio *impr;
    int n;
    cout << "Introduce el número de entradas:" << endl;
    cin >> n;
    
    string name, fname;
    int priority;
    for(int i = 0; i < n; i++){
        cin >> name;
        cin >> priority;
        cin >> fname;
        impr = new Impressio(name, priority, fname);
        prioridad(deque, impr);                
    }
}

int main() {
    int option = 0;
    LinkedDeque<Impressio> *deque = new LinkedDeque<Impressio>();
    
    vector <string> options;    
    options.push_back("Leer un fichero con las entradas de la cola de impresión");
    options.push_back("Eliminar una impresión por delante");
    options.push_back("Eliminar una impresión por el final");
    options.push_back("Insertar n entradas de impresión des de teclado (0 para finalizar)");
    options.push_back("Imprimir la cola de impresión");
    options.push_back("Salir");
    
    cout << "*** Inicio ***" << endl << endl;        
    do{
        option = mainMenu(options);
        switch(option){
            case 1:{ // inicializar deque                
                readFile(deque);
                break;
            }
            case 2:{
                delFront(deque);
                break;
            }
            case 3:{
                delRear(deque);
                break;
            }
            case 4:{
                teclado(deque);
                break;
            }
            case 5:{
                deque->print();
                break;
            }
            case 6:{
                cout << "Hasta luego!" << endl;
                break;
            }
            default:
                cout << "Opción no válida" << endl;
        }
    }while(option != 6);                
    return 0;
}

