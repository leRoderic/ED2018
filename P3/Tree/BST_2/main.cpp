/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sbarripi7.alumnes
 *
 * Created on 17 / d’abril / 2018, 08:09
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <stdexcept>
#include "BSTMovieFinder.h"

using namespace std;

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

void init(BSTMovieFinder *&bst){
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
    
    if(bst != nullptr)
        delete bst;
    
    auto start = chrono::high_resolution_clock::now();
        bst = new BSTMovieFinder();    
        bst->appendMovies(filename);
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> diff = end - start;
    cout << "Tiempo utilizado: " << diff.count() << endl;    
}

void cercaPelicules(BSTMovieFinder *&bst){
    ifstream fin;
    fin.open("cercaPelicules.txt");
    if(!fin)
        throw invalid_argument("No se ha podido abrir el archivo");
    
    int movieID, count = 0;
    
    auto start = chrono::high_resolution_clock::now();
        while(fin >> movieID){
            if(bst->search(movieID))
                count++;        
        }
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> diff = end - start;
    cout << "Tiempo utilizado: " << diff.count() << endl;
    cout << "Peliculas encontradas: " << count << endl;
}
int main() {
    
    vector <string> options;    
    options.push_back("Inicializar peliculas desde fichero");
    options.push_back("Mostrar peliculas");
    options.push_back("cercaPelicules.txt");
    options.push_back("Profundidad");
    options.push_back("Salir");
    BSTMovieFinder *bst = nullptr;
    
    
    int option;
     cout << "*** Inicio ***" << endl << endl;        
    do{
        option = mainMenu(options);
        switch(option){
            case 1:{           
                init(bst);               
               break;
            }
            case 2:
                if(bst == nullptr)
                    cout << "Arbol no inicializado" << endl;
                else bst->showMovies();
                break;            
            case 3:
                cercaPelicules(bst);
                break;            
            case 4:{
                cout << "Profundidad: " << bst->depth() << endl;
                break;
            }
            case 5:{
                break;
            }
            default:
                cout << "Opcion no valida" << endl;
        }
    }while(option != 5);
                     
    delete bst;        
    return 0;
}

