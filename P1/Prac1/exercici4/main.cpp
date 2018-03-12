/* 
 * File:   main.cpp
 * Author: Sergio Barril Pizarro i Rodrigo Cabezas Quirós
 *
 * Created on 20 / de febrer / 2018, 09:11
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Circle.h"
#include "Ellipse.h"

using namespace std;


int menu(vector<string> vec_options){
    cout << "Hola, que vols fer?" << endl;
    
    for(int i = 0; i < vec_options.size(); i++){
            cout << i + 1 << ".\t" << vec_options[i] << endl;
        }
    
    int option;
    cin >> option;  
    
    if(option > 0 && option <= vec_options.size())
        return option;
    else
        return -1;
}


void addFigura(int &ccount, int &ecount){
    
    char tipus;
    float r1, r2;
    
    cout << "Entra les dades de la teva figura" << endl;
    cin >> tipus >> r1;
    
    switch(tipus){
        case 'C':
        {            
            try{
            Circle nouCercle(r1);
                cout << "L'area d'aquest cercle es de " << nouCercle.getArea() << endl;
                ccount++;
            } catch(invalid_argument neg){
                cout << "S'ha produit una excepcio. Rao: " << neg.what() << endl;    
            }
            break; 
        }
        case 'E':
        {
            cin >> r2;
            try{
            Ellipse novaElipse(r1,r2);           
                cout << "L'area d'aquesta el·lipse es de " << novaElipse.getArea() << endl;
                ecount++;
            } catch(invalid_argument neg){
                cout << "S'ha produit una excepcio. Rao: " << neg.what() << endl;
            }            
            break;
        }
        default:
            cout << "Tipus invàlid" << endl;
    }
}

int main() {
    
    int option;
    int circCount = 0, ellipCount = 0;
    
    vector<string> vec_options;
    vec_options.push_back("Sortir");
    vec_options.push_back("Introduir figura");
    vec_options.push_back("Glossari de figures");
    
    do{
        option = menu(vec_options);
        
        switch(option){
            case 1:
                cout << "*** FI ***" << endl;
                break;
            case 2:
                addFigura(circCount, ellipCount);
                break;
                
            case 3:
                cout << "Tens " << circCount << " cercles ";
                cout << "i " << ellipCount << " el·lipses" << endl;
                break;
                
            default:
                cout << "No has escollit una opcio valida!" << endl;       
        }        
    }while(option != 1);
    
    return 0;
}