/**
 * File:   BSTMovieFinder.cpp
 * Author: Tropped
 * 
 * Created on 28 de abril de 2018, 1:11
 */

#include "BSTMovieFinder.h"

BSTMovieFinder::BSTMovieFinder() {
    bst = new BinarySearchTree<Movie>();
}


BSTMovieFinder::~BSTMovieFinder() {
    delete bst;
}

void BSTMovieFinder::appendMovies(string filename) {
    ifstream fin;
    fin.open(filename);
    if(!fin.is_open())
        throw ("No se ha podido abrir el archivo");
    
    string pelicula;
    int id;
    string title;
    float rating;
    
    size_t idTitle;
    size_t titleRating;
    
    while(getline(fin, pelicula)){
        idTitle = pelicula.find("::");
        titleRating = pelicula.rfind("::");
        
        id = stoi(pelicula.substr(0, idTitle));
        title = pelicula.substr(idTitle + 2, titleRating - idTitle - 2);
        rating = stof(pelicula.substr(titleRating + 2, pelicula.npos));
        
        insertMovie(id, title, rating);
    }
    
    fin.close();        
}

void BSTMovieFinder::insertMovie(int movieID, string title, float rating) {

    Movie* movie = new Movie(movieID, title, rating);    
    bst->insert(*movie, movieID);
}

const string BSTMovieFinder::showMovie(int movieID) const {
    Movie pelicula = findMovie(movieID);
    return pelicula.toString();    
}

const Movie& BSTMovieFinder::findMovie(int movieID) const {
    if(bst->isEmpty())
        throw out_of_range("Está vacío!");
    
    NodeTree<Movie>* node = bst->root();
    bool found = false;
    
    
    while(!found){        
        if(movieID > node->getKey()){
            if(node->hasRight())
                node = node->getright();                
            else throw invalid_argument("ID no encontrada");
        }
        
        else if(movieID < node->getKey()){
            if(node->hasLeft())
                node = node->getleft();
            else throw invalid_argument("ID no encontrada");
        }
        else found = true;                    
    }

    return node->getValue();
}

const float BSTMovieFinder::findRatingMovie(int movieID) const {
    return findMovie(movieID).getRating();
}

void BSTMovieFinder::showMovies() const {
    NodeTree<Movie>* root = bst->root();
    showMovies(root);    
}

void BSTMovieFinder::showMovies(NodeTree<Movie>* p) const {
   static int counter = 0;
    
    if(p->hasLeft()){
        showMovies(p->getleft());
    }
        
    if(counter < 40){
        cout << p->getValue().toString();
        cout << endl;
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
        showMovies(p->getright());
    }
   
    if(p->isRoot())
       counter = 0;
}

bool BSTMovieFinder::search(const int movieID) const {
    return bst->search(movieID);
}

const int BSTMovieFinder::depth() const{
    return bst->root()->getHeight();
}

