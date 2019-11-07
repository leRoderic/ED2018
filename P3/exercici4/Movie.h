
#include <iostream>
#include <string>

using namespace std;

#ifndef MOVIE_H
#define MOVIE_H

class Movie {
public:
    /*Constructor*/
    Movie(int movieID, string title, float rating);
    /*Consultores*/
    const int getID() const;
    const string getTitle() const;
    const float getRating() const;
    /*Modificadores*/
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

