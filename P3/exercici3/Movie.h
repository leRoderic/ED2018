/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Movie.h
 * Author: Tropped
 *
 * Created on 27 de abril de 2018, 17:27
 */

#include <iostream>
#include <string>

using namespace std;

#ifndef MOVIE_H
#define MOVIE_H

class Movie {
public:
    // Constructor
    Movie(int movieID, string title, float rating);
    
    // Getters
    const int getID() const;
    const string getTitle() const;
    const float getRating() const;
    
    // Setters
    void setID(int movieID);
    void setTitle(string title);
    void setRating(float rating);
    
    const string toString() const;  
    
private:
    int movieID;
    string title;
    float rating;
};

#endif /* MOVIE_H */

