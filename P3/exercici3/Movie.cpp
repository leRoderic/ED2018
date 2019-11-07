/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Movie.cpp
 * Author: Tropped
 * 
 * Created on 27 de abril de 2018, 17:27
 */

#include "Movie.h"

// Constructor con parametros
Movie::Movie(int movieID, string title, float rating) :
    movieID(movieID),
    title(title),
    rating(rating)      
{
}

// Retorna el ID de la pelicula
const int Movie::getID() const {
    return movieID;
}

// Retorna el titulo de la pelicula
const string Movie::getTitle() const {
    return title;
}

// Retorna la nota de la pelicula
const float Movie::getRating() const {
    return rating;
}

// Actualiza el ID de la pelicula
void Movie::setID(int movieID) {
    this->movieID = movieID;
}

// Actualiza el rating de la pelicula
void Movie::setRating(float rating) {
    this->rating = rating;
}

// Actualiza el titulo de la pelicula
void Movie::setTitle(string title) {
    this->title = title;
}

// Retorna una string con los atributos de la pelicula
const string Movie::toString() const {
    string content = "";
    content += "Movie ID: " + to_string(movieID);
    content += "   Title: " + title;
    content += "   Rating: " + to_string(rating) + "/5 \n";
    
    return content;
}