/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Tropped
 *
 * Created on May 19, 2018, 11:08 AM
 */

#include <iostream>
#include <cstdlib>
#include "MinHeap.h"

using namespace std;


/*
 * 
 */
int main() {
    MinHeap<int> heap;
    
    vector<int> llista {41, 67, 34, 1, 69, 24, 78, 58, 62, 64, 5, 45, 81, 27, 61};
    
//    for(int i = 0; i < llista.size(); i++){
//        heap.insert(llista[i], llista[i]);
//    }
//    
    try{
    heap.printHeap();
    }catch(out_of_range empty){
        cout << empty.what() << endl;
    }
    try{          
        heap.removeMin();
    }catch(out_of_range exc){
        cout << exc.what() << endl;
    }
        
    heap.insert(2,2);
    heap.insert(5,3);
    heap.insert(9,2);
    heap.insert(10, 48);    
    heap.insert(2,5);
    heap.insert(2,7);
       
    heap.printHeap();
    heap.printHeap();
    
    
    vector<int> valors = heap.minValues();

    cout << "Valors:" << endl;
    for(int i = 0; i < valors.size(); i++)
        cout << valors[i] << ", ";
    
        
    
    return 0;
}

