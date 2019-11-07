/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapMovieFinder.h
 * Author: Tropped
 *
 * Created on May 21, 2018, 12:16 PM
 */

#ifndef HEAPMOVIEFINDER_H
#define HEAPMOVIEFINDER_H

using namespace std;
#include <iostream>
#include <fstream>

#include "MinHeap.h"
#include "Movie.h"
#include <math.h>


class HeapMovieFinder {
public:
    HeapMovieFinder();
    HeapMovieFinder(const HeapMovieFinder& orig);
    virtual ~HeapMovieFinder();
    void appendMovies(string filename);
    void insertMovie(int movieID, string title, float rating);
    string showMovie(const int movieID) const;
    void findMovie(const int movieID) const;
    void removeMin();
    int min() const;
    bool empty() const;
    int depth() const;
    
private:
    MinHeap<Movie> heap;

};

#endif /* HEAPMOVIEFINDER_H */

