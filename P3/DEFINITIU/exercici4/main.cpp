
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <stdexcept>
#include "AVLMovieFinder.h"
#include "BSTMovieFinder.h"

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

void initAVL(AVLMovieFinder *&avl){
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
    if(avl != nullptr)
        delete avl;
    
    // Timer
    auto start = chrono::high_resolution_clock::now();
        avl = new AVLMovieFinder();    
        try{
            avl->appendMovies(filename);
        } catch(invalid_argument exc){
            cout << exc.what() << endl;
        }
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> diff = end - start;
    cout << "Tiempo construcción AVL: " << diff.count() << endl;
}

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

void cercaPeliculesAVL(AVLMovieFinder *&avl){
    ifstream fin;
    fin.open("cercaPelicules.txt");
    if(!fin)
        cout << "No se ha podido abrir el archivo" << endl;
    else{
        int movieID, count = 0;

        auto start = chrono::high_resolution_clock::now();
            while(fin >> movieID){
                if(avl->search(movieID))
                    count++;        
            }
            fin.close();
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> diff = end - start;
        cout << "Tiempo utilizado: " << diff.count() << endl;
        cout << "Peliculas encontradas: " << count << endl;        
    }
}


int main() {
    
    vector <string> options;    
    options.push_back("Inicializar BST desde fichero");
    options.push_back("Inicializar AVL desde fichero");    
    
    options.push_back("Mostrar peliculas del BST");
    options.push_back("Mostrar peliculas del AVL");
    
    options.push_back("cercaPelicules BST");
    options.push_back("cercaPelicules AVL");
    
    options.push_back("Profundidad BST");
    options.push_back("Profundidad AVL");
    
    options.push_back("Título más largo BST");
    options.push_back("Título más largo AVL");
    
    options.push_back("Puntuaciones BST");
    options.push_back("Puntuaciones AVL");
    
    options.push_back("Salir");
       
    AVLMovieFinder *avl = nullptr;
    BSTMovieFinder *bst = nullptr;
    
    
    int option;
     cout << "*** Inicio ***" << endl << endl;        
    do{
        option = mainMenu(options);        
        switch(option){
            case 1:{           
                initBST(bst);
                break;
            }
            case 2:{
                initAVL(avl);
                break;
            }            
            case 3:{
                if(bst == nullptr)
                    cout << "Arbol no inicializado" << endl;
                else bst->showMovies();
                break;            
            }
            case 4:{
                if(avl == nullptr)
                    cout << "Arbol no inicializado" << endl;
                else avl->showMovies();
                break;
            }
            case 5:
                if(bst == nullptr)
                    cout << "Arbol no inicializado" << endl;
                else{
                    cercaPeliculesBST(bst);                                        
                }
                break;            
            case 6:
                if(avl == nullptr)
                    cout << "Arbol no inicializado" << endl;
                else{
                    cercaPeliculesAVL(avl);                                        
                }
                break; 
            case 7:{
                cout << "Profundidad: ";
                if(bst == nullptr)
                    cout << "Arbol no inicializado" << endl;
                else cout << "La profundidad es de " << bst->depth() << endl;
                break;
            }            
            case 8:{
                cout << "Profundidad: ";
                if(avl == nullptr)
                    cout << "Arbol no inicializado" << endl;
                else cout << "La profundidad es de " << avl->depth() << endl;
                break;
            }
            
            case 9:{
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
            
            case 10:{
                if(avl == nullptr)
                    cout << "Arbol no inicializado" << endl;
                else{
                    cout << "Título más largo: " << endl;
                    try{
                        string titol = avl->longTitle();
                        cout << titol << endl;
                        cout << "Longitud: " << titol.length() << endl;
                    } catch(out_of_range exc){
                        cout << exc.what() << endl;
                    }   
                }
                break;
            }
            
            case 11:{
                if(bst == nullptr)
                    cout << "Árbol no inicializado" << endl;
                else{                    
                    try{
                        array<float,2> puntuaciones = bst->ratings();                
                        cout << "Películas con más rating (" << puntuaciones[1] << "):" << endl;
                        bst->printRatings(puntuaciones[1]);
                        cout << "Películas con menos rating (" << puntuaciones[0] <<"):" << endl;
                        bst->printRatings(puntuaciones[0]);
                    }catch(out_of_range exc){
                        cout << exc.what() << endl;
                    }
                }
                break;
            }
            
            case 12:{
                if(avl == nullptr)
                    cout << "Árbol no inicializado" << endl;
                else{                    
                    try{
                        array<float,2> puntuaciones = avl->ratings();                
                        cout << "Películas con más rating (" << puntuaciones[1] << "):" << endl;
                        bst->printRatings(puntuaciones[1]);
                        cout << "Películas con menos rating (" << puntuaciones[0] <<"):" << endl;
                        bst->printRatings(puntuaciones[0]);
                    }catch(out_of_range exc){
                        cout << exc.what() << endl;
                    }
                }
                break;
            }
            case 13:
                break;
            default:
                cout << "Opcion no valida" << endl;
        }            
    }while(option != 13);
    
    if(bst != nullptr)
        delete bst;
    return 0;
}