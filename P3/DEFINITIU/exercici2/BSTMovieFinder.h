
#ifndef BSTMOVIEFINDER_H
#define BSTMOVIEFINDER_H

#include <string>
#include <fstream>

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
    // Extra!
    void showMovies() const;
    bool search(int movieID) const;
    const int depth() const;
private:
    BinarySearchTree<Movie>* bst;
    void showMovies(NodeTree<Movie>* p) const;

};

#endif /* BSTMOVIEFINDER_H */
