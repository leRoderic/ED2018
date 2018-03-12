/* 
 * File:   main.cpp
 * Author: Sergio Barril Pizarro i Rodrigo Cabezas Quirós
 *
 * Created on 20 / de febrer / 2018, 09:11
 */

#include <iostream>
#include <fstream>
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

void afegirFigura(int &ccount, int &ecount, char tipus, float r1, float r2){
    
    switch(tipus){
        case 'C':
        {
            try {
                Circle *nouCercle = new Circle(r1);               
                cout << "L'area d'aquest cercle es de " << nouCercle->getArea() << endl;
                ccount++;
                delete nouCercle;
            } catch(invalid_argument neg){
                cout << "S'ha produit una excepcio. Rao: " << neg.what() << endl;    
            }            
            break; 
        }
        case 'E':
        {
            try{
                Ellipse *novaElipse = new Ellipse(r1, r2);          
                cout << "L'area d'aquesta el·lipse es de " << novaElipse->getArea() << endl;
                ecount++;
                delete novaElipse;
            } catch(invalid_argument neg){
                cout << "S'ha produit una excepcio. Rao: " << neg.what() << endl;
            }                     
            break;
        }
        default:
            cout << "Tipus invàlid" << endl;
    }
}

void consolaFigura(int &ccount, int &ecount){
    
    char tipus;
    float r1, r2 = 0;
    
    cout << "Entra les dades de la teva figura" << endl;
    cin >> tipus >> r1;
    
    if(tipus == 'E')
        cin >> r2;
        
    afegirFigura(ccount, ecount, tipus, r1, r2);    
}

void fitxerFigures(int &ccount, int &ecount){
    string nom_fitxer;
    cout << "Digueu el nom del fitxer" << endl;
    cin >> nom_fitxer;
    ifstream fitxer(nom_fitxer);
    
    char tipus;
    float r1, r2 = 0;
    
    while(!fitxer.eof()) {
        fitxer >> tipus;
        fitxer >> r1;
        if(tipus == 'E')
            fitxer >> r2;
        afegirFigura(ccount, ecount, tipus, r1, r2);
    }    
    fitxer.close();
}

int main() {
    
    int option;
    int circCount = 0, ellipCount = 0;
    
    cout << " *** INICI ***" <<endl;
    
    vector<string> vec_options;
    vec_options.push_back("Sortir");
    vec_options.push_back("Introduir figura");
    vec_options.push_back("Llegir de fitxer");
    vec_options.push_back("Glossari de Figures");   
    
    do{
        option = menu(vec_options);
        
        switch(option){
            case 1:
                cout << "*** FI ***" << endl;
                break;
            case 2:
                consolaFigura(circCount, ellipCount);
                break;
                
            case 3:
                fitxerFigures(circCount, ellipCount);
                break;
                
            case 4:
                cout << "Tens " << circCount << " cercles ";
                cout << "i " << ellipCount << " el·lipses" << endl;
                break;
                
            default:
                cout << "No has escollit una opcio valida!" << endl;                        
        }        
    }while(option != 1);
    
    return 0;
}


