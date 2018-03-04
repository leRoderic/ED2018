/* 
 * File:   main.cpp
 * Author: Sergio Barril Pizarro i Rodrigo Cabezas Quirós
 *
 * Created on 20 / de febrer / 2018, 09:11
 */


/*
 * a) La herencia nos permite tener un vector con objetos de dos clases
 * diferentes: circulos y elipses, ya que ambos son elipses.
 * 
 * b) Si getArea() no fuera virtual, entonces cuando calculamos .getAreas()
 * siempre se llamaría al método Ellipse::getArea(), aunque el elemento sea
 * un Circle, ya que los elementos del vector de EllipseContainer son Ellipse *.
 * Para hacer polimorfismo, necesitamos que sea virtual.
 * En este caso concreto, el resultado sería el mismo, pues considerando el
 * circulo como una elipse con ambos radios iguales, el area de un circulo se
 * calcula igual que la de una elipse.
 * 
 * 
 * c) Porque los constructores de las clases derivadas, a su vez, 
 * llaman a los constructores y destructores de la clase base.
 * Así, antes de que se construya el objeto de la clase derivada, se resuelve la llamada
 * al constructor base, ya que la clase derivada podria necesitar los atributos de la
 * superclase.
 * 
 * d) Sí, es como lo hemos hecho.
 * 
 * e) -> =============================================================================================
   Datos           | Clase              | Visibilidad atributos  |   Explicación
   =============================================================================================
   float r1;       | Ellipse            | protecetd              | Acceso classe derivada (Cercle)
   float r2;       | Ellipse            | protected              | Acceso classe derivada (Cercle)
   =============================================================================================
   vector v;       | EllipseContainer   | private                | No interesa acceso usuario.
   =============================================================================================
 * 
 * No interesa acceso sin límites al vector v, ya que tenemos que controlar que
 * no permita más de 10 figuras, por ejemplo. (Y así, mantenemos la encapsulación)
 * 
 * f) El iterador va avanzando de figura en figura, así que de uno en uno, porque
 * queremos visitar todas las figuras.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "Circle.h"
#include "EllipseContainer.h"
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

void afegirFigura(EllipseContainer &ellipContenidor, int &ccount, int &ecount, char tipus, float r1, float r2){
    
    switch(tipus){
        case 'C':
        {
            Circle *nouCercle = nullptr;
            
            try{
                nouCercle = new Circle(r1);
                cout << "L'area d'aquest cercle es de " << nouCercle->getArea() << endl;
                ellipContenidor.addEllipse(nouCercle);
                ccount++;
            }
            catch(invalid_argument neg){
                cout << neg.what() << endl;
                cout << "S'ha produit una excepcio" << endl;
            }            
            catch(length_error ple){
                cout << ple.what() << endl;
                cout << "S'ha produit una excepcio" << endl;              
                if(nouCercle != nullptr)
                    delete nouCercle;   
            }            
            break; 
        }
        case 'E':
        {
            Ellipse *novaElipse = nullptr;           
            try{
                novaElipse = new Ellipse(r1,r2);
                cout << "L'area d'aquesta el·lipse es de " << novaElipse->getArea() << endl;
                ellipContenidor.addEllipse(novaElipse);
                ecount++;            
            }
            catch(invalid_argument neg){
                cout << neg.what() << endl;
                cout << "S'ha produit una excepcio" << endl;
            }            
            catch(length_error ple){
                cout << ple.what() << endl;
                cout << "S'ha produit una excepció" << endl;
                if(novaElipse != nullptr)
                    delete novaElipse;
            }                                         
            break;
        }
        default:
            cout << "Tipus invàlid" << endl;
    }
}

void consolaFigura(int &ccount, int &ecount, EllipseContainer &ellipContenidor){
    
    char tipus;
    float r1, r2 = 0;
    
    cout << "Entra les dades de la teva figura" << endl;
    cin >> tipus >> r1;
    
    if(tipus == 'E')
        cin >> r2;
    afegirFigura(ellipContenidor, ccount, ecount, tipus, r1, r2);    
}

void fitxerFigures(int &ccount, int &ecount, EllipseContainer &ellipContenidor){
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
        afegirFigura(ellipContenidor, ccount, ecount, tipus, r1, r2);

    }
    
    fitxer.close();
}

int main() {
    
    int option;
    int circCount = 0, ellipCount = 0;
    
    EllipseContainer ellipContenidor;
    
    cout << "***INICI***" << endl;
    
    vector<string> vec_options;
    vec_options.push_back("Sortir");
    vec_options.push_back("Introduir figura");
    vec_options.push_back("Llegir de fitxer");
    vec_options.push_back("Glossari de Figures");
    vec_options.push_back("Sumatori arees");
        
    do{
        option = menu(vec_options);
        
        switch(option){
            case 1:
                cout << "*** FI ***" << endl;
                break;
            case 2:
                consolaFigura(circCount, ellipCount, ellipContenidor);
                break;
                
            case 3:
                fitxerFigures(circCount, ellipCount, ellipContenidor);
                break;
                
            case 4:
                cout << "Tens " << circCount << " cercles ";
                cout << "i " << ellipCount << " el·lipses" << endl;
                break;
                
            case 5:
                cout<<"La suma de les arees es " << ellipContenidor.getAreas() << endl;
                break;                
                
            default:
                cout << "No has escollit una opcio valida!" << endl;                        
        }        
    }while(option != 1);
    
    vector<Ellipse *> v = ellipContenidor.getVector();    
    vector<Ellipse *>::iterator it;
    
    for(it = v.begin(); it != v.end(); it++){
        if(dynamic_cast<Circle *>((*it))){
            cout << "Cercle eliminat" << endl;            
            delete (Circle *)((*it));
        }
        else{
            cout << "Elipse eliminada" << endl;
            delete (Ellipse *)((*it));
        }        
    }              
    return 0;
}


