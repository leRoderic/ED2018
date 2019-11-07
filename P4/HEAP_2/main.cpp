/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Tropped
 *
 * Created on May 19, 2018, 11:08 AM
 */

#include <iostream>
#include <chrono>

#include "MinHeap.h"
#include "HeapMovieFinder.h"

using namespace std;

// Muestra el menu y retorna la opcion elegida
int mainMenu(vector<string> a){       
    cout << "Que quieres hacer?" << endl << endl;
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

// Selecciona el fichero que hay que leer
// Añade las peliculas a un BSTMovieFinder
// Imprime por pantalla el tiempo que ha tardado    
void init(HeapMovieFinder *&heap){
    char opcion;    
    string filename = "";
    
    while(filename == ""){
        cout << "Qué fichero quieres (P/G)?" << endl;
        cin >> opcion;
    
        switch(toupper(opcion)){
            case 'P':
                filename = "movie_rating_small.txt";
                break;
            case 'G':
                filename = "movie_rating.txt";
                break;
            default:
                cout << "Archivo inválido" << endl;
        }
    }
    
    // Si ya habia un BST, lo eliminamos
    if(heap != nullptr)
        delete heap;
    
    // Timer
    auto start = chrono::high_resolution_clock::now();
        heap = new HeapMovieFinder();
        try{
            heap->appendMovies(filename);
        } catch(invalid_argument exc){
            cout << exc.what() << endl;
        }
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> diff = end - start;
    cout << "Tiempo construcción BST: " << diff.count() << endl;  
}

// Busca las peliculas en el BST
void cercaPelicules(HeapMovieFinder *&heap){
    ifstream fin;
    fin.open("cercaPelicules.txt");
    if(!fin)
        cout << "No se ha podido abrir el archivo" << endl;
    else{
        int movieID, count = 0;        
        auto start = chrono::high_resolution_clock::now();
            while(fin >> movieID){
                if(!heap->showMovie(movieID).empty())
                    count++;        
            }
            fin.close();
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> diff = end - start;
        cout << "Tiempo utilizado: " << diff.count() << endl;
        cout << "Peliculas encontradas: " << count << endl;        
    }
}

void printAmplada(HeapMovieFinder *heap){
    HeapMovieFinder aux = *heap;
    int count = 0;
    while(!aux.empty() && count < 40){
        int min = aux.min();
        aux.findMovie(min);
        aux.removeMin();
        count++;

        if(count == 40){
            cout << "Continuar? (Y/N)" << endl;
            char opt;
            cin >> opt;
            switch(toupper(opt)){
                case 'Y':
                    count = 0;
                    break;
                case 'N':
                    count++;
                    break;
                default:
                    cout <<"Error. ";
            }            
        }                
    }
}
          

/*
 * 
 */
int main() {
    HeapMovieFinder *heap = nullptr;
      
    vector <string> options;    
    options.push_back("Inicializar Heap desde fichero");        
    options.push_back("Mostrar peliculas del Heap");        
    options.push_back("cercaPelicules Heap");        
    options.push_back("Profundidad Heap");           
    options.push_back("Salir");           
    
    int option;
     cout << "*** Inicio ***" << endl << endl;        
    do{
        option = mainMenu(options);        
        switch(option){
            case 1:{ // Leer de fichero Heap
                init(heap);
                break;
            }                    
            case 2:{ // Mostrar peliculas Heap
                if(heap == nullptr)
                    cout << "Arbol no inicializado" << endl;
                else printAmplada(heap);                
                break;            
            }
            case 3: // Buscar peliculas Heap
                if(heap == nullptr)
                    cout << "Arbol no inicializado" << endl;
                else{
                    cercaPelicules(heap);
                }
                break;                                                        
            case 4:{ // Profundidad del Heap
                
                if(heap == nullptr)
                    cout << "Arbol no inicializado" << endl;
                else{
                    cout << "Profundidad: ";
                    cout << "La profundidad es de " << heap->depth() << endl;
                }
                
                break;
            }                
            case 5:
                break;
            default:
                cout << "Opcion no valida" << endl;
        }            
    }while(option != 5);
    
    if(heap != nullptr)
        delete heap;
    return 0;        
}

