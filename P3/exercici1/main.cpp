
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;


int main() {
    BinarySearchTree<int> *bst = new BinarySearchTree<int>();   //Crea nuevo BST
    int testArray [] = {2, 0, 8, 45, 76, 5, 3, 40}; //Array para test
    for(int i = 0; i < 8; i++) {
        bst->insert(testArray[i]);  //Inserta en el árbol los elementos del array
    }
    bst->printPreorder();   //Imprime en preorden
    cout << endl; 
    bst->printInorder();    //Imprime en inorden
    cout << endl;
    bst->printPostorder();  //Imprime en postorden
    cout << endl;
    bst->mirror();  //Crea espejo del árbol
    bst->printPreorder();  //Imprime en preorden
    delete bst; //Elimina el árbol
    return 0;
}

