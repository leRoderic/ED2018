/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapMovieFinder.cpp
 * Author: Tropped
 * 
 * Created on May 21, 2018, 12:16 PM
 */

#include "HeapMovieFinder.h"

HeapMovieFinder::HeapMovieFinder() {
}

HeapMovieFinder::HeapMovieFinder(const HeapMovieFinder& orig) {
    this->heap = orig.heap;
}

HeapMovieFinder::~HeapMovieFinder() {
}

void HeapMovieFinder::appendMovies(string filename) {
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
void HeapMovieFinder::insertMovie(int movieID, string title, float rating) {

    Movie movie(movieID, title, rating);    
    try{    
        heap.insert(movieID, movie);
    } catch( invalid_argument exc){
        cout << exc.what() << endl;
    }
}

void HeapMovieFinder::findMovie( const int movieID) const {        
    cout << showMovie(movieID) << endl;
}

string HeapMovieFinder::showMovie(const int movieID) const{
    vector<Movie> pelicules = heap.search(movieID);
    if(pelicules.empty())
        return "";
    
    return heap.search(movieID)[0].toString();
}

void HeapMovieFinder::removeMin(){    
    heap.removeMin();    
}

int HeapMovieFinder::min() const{
    try{
        heap.min();
    }catch(out_of_range exc){
        throw exc;
    }
}

bool HeapMovieFinder::empty() const{
    return heap.empty();
}

int HeapMovieFinder::depth() const{
    int n = heap.size();
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    return floor(log2(n)) + 1;            
}