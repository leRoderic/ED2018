/**
 * File:   BSTMovieFinder.cpp
 * Author: Tropped
 * 
 * Created on 28 de abril de 2018, 1:11
 */

#include "BSTMovieFinder.h"

// Constructor por defecto de BSTMovieFinder
BSTMovieFinder::BSTMovieFinder() {
    bst = new BinarySearchTree<Movie>();
}


// Destructor de BSTMovie Finder
BSTMovieFinder::~BSTMovieFinder() {
    delete bst;
}

// Toma como parámetro un nombre de archivo, lo lee
// y añade todas las peliculas que contiene al BST
void BSTMovieFinder::appendMovies(string filename) {
    ifstream fin;
    fin.open(filename);
    if(!fin.is_open())
        cout << "No se ha podido abrir el archivo" << endl;
    else{
        string pelicula;
        int id;
        string title;
        float rating;

        size_t idTitle;
        size_t titleRating;

        while(getline(fin, pelicula)){
            idTitle = pelicula.find("::"); // Posicion del primer delimitador
            titleRating = pelicula.rfind("::"); // Posicion del ultimo delimitador 

            // Substring + cambio de tipo        
            id = stoi(pelicula.substr(0, idTitle));
            title = pelicula.substr(idTitle + 2, titleRating - idTitle - 2);
            rating = stof(pelicula.substr(titleRating + 2, pelicula.npos));

            insertMovie(id, title, rating);  
        }

        fin.close();
    }
}

// Añade una pelicula al BST con los atributos pasados por parámetro
void BSTMovieFinder::insertMovie(int movieID, string title, float rating) {

    Movie* movie = new Movie(movieID, title, rating);
    try{    
        bst->insert(*movie, movieID);
    } catch( invalid_argument exc){
        cout << exc.what() << endl;
    }
}

// Retorna la información de la película cuyo ID se pasa por parámetro
const string BSTMovieFinder::showMovie(int movieID) const {    
    Movie pelicula = findMovie(movieID);        
    return pelicula.toString();    
}

// Retorna la pelicula cuyo ID se pasa por parámetro
const Movie& BSTMovieFinder::findMovie(int movieID) const {
    if(bst->isEmpty())
        throw out_of_range("Está vacío!");
    
    NodeTree<Movie>* node = bst->root();
    bool found = false;
    
    
    while(!found){        
        if(movieID > node->getKey()){
            if(node->hasRight())
                node = node->getRight();                
            else throw invalid_argument("ID no encontrada");
        }
        
        else if(movieID < node->getKey()){
            if(node->hasLeft())
                node = node->getLeft();
            else throw invalid_argument("ID no encontrada");
        }
        else found = true;                    
    }

    return node->getValue();
}

// Retorna la valoracion de la pelicula cuyo ID se pasa por parametro
const float BSTMovieFinder::findRatingMovie(int movieID) const {
    return findMovie(movieID).getRating();
}

// Iniciador de la recursion para mostrar las peliculas por orden de ID
void BSTMovieFinder::showMovies() const {
    NodeTree<Movie>* root = bst->root();
    showMovies(root);    
}

// Muestra las peliculas por orden de ID
void BSTMovieFinder::showMovies(NodeTree<Movie>* p) const {
   static int counter = 0;
    
    if(p->hasLeft()){
        showMovies(p->getLeft());
    }
        
    if(counter < 40){
        cout << p->getValue().toString();
        counter++;
    }
    
    while(counter == 40){        
        cout << "Continuar? (Y/N)" << endl;
        char opt;
        cin >> opt;
        switch(toupper(opt)){
            case 'Y':
                counter = 0;
                break;
            case 'N':
                counter++;
                break;
            default:
                cout <<"Error. ";
        }
    }    
    
    if(p->hasRight()){        
        showMovies(p->getRight());
    }
   
    if(p->isRoot())
       counter = 0;
}

// Dado un ID, retorna true si está en el BST, de lo contrario false
bool BSTMovieFinder::search(const int movieID) const {
    return bst->search(movieID);
}

// Retorna la profundidad del árbol
const int BSTMovieFinder::depth() const{
    return bst->root()->getHeight();
}

// Retorna el titulo mas largo del arbol
const string BSTMovieFinder::longTitle() const{
    if(bst->isEmpty())
        throw out_of_range("El árbol está vacío");
    return longTitle(bst->root());
}

// Funcion recursiva que retorna el titulo mas largo del subarbol que tiene p como raiz
const string BSTMovieFinder::longTitle(NodeTree<Movie>* p) const {
        
    int lengthp = 0, lengthl = 0, lengthr = 0;
    string leftTitle, rightTitle;
    
    lengthp = p->getValue().getTitle().length();
        
    if(p->hasLeft()){
        leftTitle = longTitle(p->getLeft());
        lengthl = leftTitle.length();
    }
    
    if(p->hasRight()){
        rightTitle = longTitle(p->getRight());
        lengthr = rightTitle.length();
    }    
      
    if(lengthp >= lengthl){
        if(lengthp >= lengthr)
            return p->getValue().getTitle();
    }
    if(lengthl >= lengthp){
        if(lengthl >= lengthr)
            return leftTitle;
    }
    
    if(lengthr >= lengthl){
        if(lengthr >= lengthp)
            return rightTitle;
    }    
}

// Retorna un array con la nota mas baja y la mas alta
const array<float, 2> BSTMovieFinder::ratings() const {
    if(bst->isEmpty())
        throw out_of_range("Árbol vacío");
    
    ratings(bst->root());    
}

// Retorna un array con la nota mas baja y la mas alta del subarbol con raiz p
const array<float,2> BSTMovieFinder::ratings(NodeTree<Movie>* p) const {
    array<float,2> l_rating;
    array<float,2> p_rating;
    array<float,2> r_rating;
    
    p_rating[0] = p->getValue().getRating();
    p_rating[1] = p->getValue().getRating();   
    
    if(p->hasLeft()){
        l_rating = ratings(p->getLeft());
        p_rating[0] = min(l_rating[0], p_rating[0]);
        p_rating[1] = max(l_rating[1], p_rating[1]);
    }
    
    if(p->hasRight()){
        r_rating = ratings(p->getRight());
        p_rating[0] = min(r_rating[0], p_rating[0]);
        p_rating[1] = max(r_rating[1], p_rating[1]);        
    }                       
    
    return p_rating;
}

// Imprime todas las peliculas con un cierto rating
void BSTMovieFinder::printRatings(const float rating) const{
    if(bst->isEmpty())
        throw out_of_range("Árbol vacío");
    printRatings(bst->root(), rating);
}


// Imprime las peliculas con un cierto rating, del subarbol con rating p
void BSTMovieFinder::printRatings(NodeTree<Movie>* p, const float rating) const{    
    if(p->hasLeft()){
        printRatings(p->getLeft(), rating);
    }

    if(p->getValue().getRating() == rating){
    cout << p->getValue().toString();    
    }
        
    if(p->hasRight()){        
        printRatings(p->getRight(), rating);
    }
}
