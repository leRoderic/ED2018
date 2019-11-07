
#ifndef BSTMOVIEFINDER_H
#define BSTMOVIEFINDER_H

#include <string>
#include <fstream>
#include <array>

#include "BinarySearchTree.h"
#include "Movie.h"

using namespace std;

class BSTMovieFinder{
public:
    BSTMovieFinder();
    virtual ~BSTMovieFinder();
    void appendMovies(string filename);
    void insertMovie(int movieID, string title, float rating);
    const string showMovie(int movieID) const;
    const Movie& findMovie(int movieID) const;
    const float findRatingMovie(int movieID) const;
    const string longTitle() const;
    const array<float,2> ratings() const;
    void printRatings(const float rating) const;
    
    // Extra functions
    void showMovies() const;
    bool search(int movieID) const;
    const int depth() const;
private:
    BinarySearchTree<Movie>* bst;
    
    void showMovies(NodeTree<Movie>* p) const;
    const string longTitle(NodeTree<Movie>* p) const;
    const array<float,2> ratings(NodeTree<Movie>* p) const;
    void printRatings(NodeTree<Movie>* p, const float rating) const;

};

#endif /* BSTMOVIEFINDER_H */
