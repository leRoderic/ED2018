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

Movie::Movie(int movieID, string title, float rating) :
    movieID(movieID),
    title(title),
    rating(rating)      
{
}


const int Movie::getID() const {
    return movieID;
}

const string Movie::getTitle() const {
    return title;
}

const float Movie::getRating() const {
    return rating;
}



void Movie::setID(int movieID) {
    this->movieID = movieID;
}

void Movie::setRating(float rating) {
    this->rating = rating;
}

void Movie::setTitle(string title) {
    this->title = title;
}

const string Movie::toString() const {
    string content = "";
    content += "Movie ID: " + to_string(movieID);
    content += "   Title: " + title;
    content += "   Rating: " + to_string(rating) + "/5";
    
    return content;
}

ostream& operator<<(ostream& os, const Movie& mv){
    Movie movie = mv;
    os << movie.toString();
}



