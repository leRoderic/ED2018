/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sbarripi7.alumnes
 *
 * Created on 17 / d’abril / 2018, 08:09
 */

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;


int main() {
    
    BinarySearchTree<int> *bst = new BinarySearchTree<int>();
    
    int testArray [] = {2, 0, 8, 45, 76, 5, 3, 40};

    for(int i = 0; i < 8; i++) {
        bst->insert(testArray[i]);
    }
    
    bst->printPreorder();

    cout << endl;
        
    bst->printInorder();
    
    cout << endl;
    
    bst->printPostorder();    
        
    cout << endl;
    
    bst->mirror();
    
    bst->printPreorder();
       
    delete bst;

    
    
    return 0;
}

