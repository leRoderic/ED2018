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
#include "BalancedBST.h"

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
void initBST(BSTMovieFinder *&bst){
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
    if(bst != nullptr)
        delete bst;
    
    // Timer
    auto start = chrono::high_resolution_clock::now();
        bst = new BSTMovieFinder();    
        try{
            bst->appendMovies(filename);
        } catch(invalid_argument exc){
            cout << exc.what() << endl;
        }
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> diff = end - start;
    cout << "Tiempo construcción BST: " << diff.count() << endl;  
}



// Busca las peliculas en el BST
void cercaPeliculesBST(BSTMovieFinder *&bst){
    ifstream fin;
    fin.open("cercaPelicules.txt");
    if(!fin)
        cout << "No se ha podido abrir el archivo" << endl;
    else{
        int movieID, count = 0;

        auto start = chrono::high_resolution_clock::now();
            while(fin >> movieID){
                if(bst->search(movieID))
                    count++;        
            }
            fin.close();
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> diff = end - start;
        cout << "Tiempo utilizado: " << diff.count() << endl;
        cout << "Peliculas encontradas: " << count << endl;        
    }
}

void test(){
    cout << "********* TEST CASE ************ " << endl;
    
    BalancedBST<int> *bst = new BalancedBST<int>();
    cout << "Árbol creado" << endl << endl;
    
    int testArray [] = {2, 0, 8, 45, 76, 5, 3, 40};

    for(int i = 0; i < 8; i++) {
        try{            
            bst->insert(testArray[i], testArray[i]);
            cout << "Inserta en el arbol el elemento " << testArray[i] << endl;
        } catch(invalid_argument exc){
            cout << exc.what() << endl;
        }
    }
    
    cout << endl << "Preorden: [";
    bst->printPreorder();
    cout << "]" << endl << "Inorden: [";        
    bst->printInorder();
    cout << "]" << endl << "Postorden: [";
    bst->printPostorder();     
    cout << "]" << endl;    
    
    bst->mirror();   
    cout << "Arbol espejo creado" << endl;
    cout << "Preorden: [";
    bst->printPreorder();
    cout << endl;
       
    delete bst;
    cout << "Árbol destruido" << endl << endl;
    
}


int main() {
    
    vector <string> options;    
    options.push_back("Inicializar BST desde fichero");    
    options.push_back("Mostrar peliculas del BST");       
    options.push_back("cercaPelicules BST");            
    options.push_back("Profundidad BST");            
    options.push_back("Título más largo BST");        
    options.push_back("Puntuaciones BST");        
    options.push_back("Test AVL");
    
    options.push_back("Salir");
       
    BSTMovieFinder *bst = nullptr;
    
    
    
    int option;
     cout << "*** Inicio ***" << endl << endl;        
    do{
        option = mainMenu(options);        
        switch(option){
            case 1:{ // Leer de fichero  BST
                initBST(bst);
                break;
            }          
            case 2:{ // Mostrar peliculas BST
                if(bst == nullptr)
                    cout << "Arbol no inicializado" << endl;
                
                else try{bst->showMovies();}
                    catch(out_of_range exc){
                        cout << exc.what() << endl;
                    }
                break;            
            }            
            case 3: // Buscar peliculas BST
                if(bst == nullptr)
                    cout << "Arbol no inicializado" << endl;
                else{
                    cercaPeliculesBST(bst);                                        
                }
                break;            
            case 4:{ // Profundidad del BST
                cout << "Profundidad: ";
                if(bst == nullptr)
                    cout << "Arbol no inicializado" << endl;
                else cout << "La profundidad es de " << bst->depth() << endl;
                break;
            }                                    
            case 5:{ // Titulo mas largo del BST
                if(bst == nullptr)
                    cout << "Arbol no inicializado" << endl;
                else{
                    cout << "Título más largo: " << endl;
                    try{
                        string titol = bst->longTitle();
                        cout << titol << endl;
                        cout << "Longitud: " << titol.length() << endl;
                    } catch(out_of_range exc){
                        cout << exc.what() << endl;
                    }                        
                }
                break;
            }            
            case 6:{ // Puntuaciones BST
                if(bst == nullptr)
                    cout << "Árbol no inicializado" << endl;
                else{                    
                    try{
                        array<float,2> puntuaciones = bst->ratings();                
                        cout << "Películas con más rating (" << puntuaciones[1] << "):" << endl;
                        bst->printRatings(puntuaciones[1]);
                        cout << endl;
                        cout << "Películas con menos rating (" << puntuaciones[0] <<"):" << endl;
                        bst->printRatings(puntuaciones[0]);
                        cout << endl;
                    }catch(out_of_range exc){
                        cout << exc.what() << endl;
                    }
                }
                break;
            }
            case 7:{ // Test AVL
                test();
            }                        
            case 8:
                break;
            default:
                cout << "Opcion no valida" << endl;
        }            
    }while(option != 8);
    
    if(bst != nullptr)
        delete bst;
    return 0;
}