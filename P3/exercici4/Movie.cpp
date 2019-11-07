
#include "Movie.h"

Movie::Movie(int movieID, string title, float rating) :
    // Constructor con parametros
    movieID(movieID),
    title(title),
    rating(rating)      
{
}

const int Movie::getID() const {
    // Retorna el ID de la pelicula
    return movieID;
}

const string Movie::getTitle() const {
    // Retorna el titulo de la pelicula
    return title;
}

const float Movie::getRating() const {
    // Retorna la nota de la pelicula
    return rating;
}


void Movie::setID(int movieID) {
    // Actualiza el ID de la pelicula
    this->movieID = movieID;
}


void Movie::setRating(float rating) {
    // Actualiza el rating de la pelicula
    this->rating = rating;
}

void Movie::setTitle(string title) {
    // Actualiza el titulo de la pelicula
    this->title = title;
}

const string Movie::toString() const {
    // Retorna una string con los atributos de la pelicula
    string content = "";
    content += "Movie ID: " + to_string(movieID);
    content += "   Title: " + title;
    content += "   Rating: " + to_string(rating) + "/5";
    return content;
}