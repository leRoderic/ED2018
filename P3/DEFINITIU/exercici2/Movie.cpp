
#include "Movie.h"

Movie::Movie(int movieID, string title, float rating) :
    //Constructor
    movieID(movieID),
    title(title),
    rating(rating)      
{
}

const int Movie::getID() const {
    //Getter para id
    return movieID;
}

const string Movie::getTitle() const {
    //Getter para título
    return title;
}

const float Movie::getRating() const {
    //Getter para nota
    return rating;
}

void Movie::setID(int movieID) {
    //Getter para id de película
    this->movieID = movieID;
}

void Movie::setRating(float rating) {
    //Setter para nota
    this->rating = rating;
}

void Movie::setTitle(string title) {
    //Setter para título
    this->title = title;
}

const string Movie::toString() const {
    //ToString
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



