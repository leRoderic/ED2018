/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Rodrigo Cabezas Quirós
 *
 * Created on 27 de febrero 2018, 20:11
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

#include "Circle.h"
#include "Ellipse.h"
#include "EllipseContainer.h"

using namespace std;

/*
 * 
 */
void newCircle(EllipseContainer &container, int dato1){
    try{
        Circle* circle = new Circle(dato1, dato1);
        container.addEllipse(circle);
        }
    catch(int e){
        cout << "No se aceptan radios negativos." << endl;
    }
    
}

void newEllipse(EllipseContainer &container, int dato1, int dato2){
    try{
        Ellipse* elipse = new Ellipse(dato1, dato2);
        container.addEllipse(elipse);
        }
    catch(int e){
        cout << "No se aceptan radios negativos." << endl;
    }
}

int main() {
    int numCircles = 0, numEllipses = 0;
    char tipo;
    float dato1, dato2;
    string nombre;
    vector <string> options;
    EllipseContainer container;
    vector<Ellipse *> v = container.getVector();
    options.push_back("1. Salir");
    options.push_back("2. Añadir figura");
    options.push_back("3. Glosario de figuras");
    options.push_back("4. Procesar archivo");
    options.push_back("5. Suma de todas las áreas");
    int option;
    cout << "*** Inicio ***" << endl << endl;
    do
    {
        for(int i=0; i < options.size(); i++)
            cout << options[i] << endl;
        cin >> option;
        if(!(option > 0 && option < (options.size() + 1)))
            cout << "Opción errónea. Vuelve a probar." << endl;
        switch(option)
        {
            case 2:
                cout << "Introduce los datos de la figura: tipo[C ó E] dato1 dato2 [0 en tipo C]" << endl;
                cin >> tipo >> dato1 >> dato2;
                switch(tipo){
                    case 'C':{
                        newCircle(container,dato1);
                        numCircles++;
                        break;
                    }
                    case 'E':{
                        newEllipse(container,dato1, dato2);
                        numEllipses++;
                        break;
                    }
                    default:{
                        cout << "No se ha seleccionado ninguna figura posible." << endl;
                        break;
                    } 
                }
                break;
            case 3:
                cout << "Tienes " << numCircles << " círculos y " << numEllipses << " elipses." << endl;
                break;
            case 4:{
                cout << "Introduce nombre del fichero:" << endl;
                cin >> nombre;

                ifstream fichero(nombre);
                while(!fichero.eof()){
                    fichero >> tipo;
                    fichero >> dato1;
                    if(tipo == 'C'){
                        newCircle(container,dato1);
                        numCircles++;
                    }
                    else{
                        fichero >> dato2;
                        newEllipse(container,dato1, dato2);
                        numEllipses++;
                    }
                }
                fichero.close();
                cout << "Fin de fichero." << endl << endl;
                break;
            }
            case 5:
                cout << "La suma de las áreas de las figuras almacenadas es de: " << container.getAreas() << endl;
                break;
        }
    }   
    while(option != 1);    
    vector<Ellipse *>::iterator it;
    for(it = v.begin(); it != v.end(); it++){
        if(dynamic_cast<Circle *>((*it))){        
            delete (Circle *)((*it));
        }
        else{
            delete (Ellipse *)((*it));
        }        
    } 
    cout << "¡Hasta luego!" << endl;
    return 0;
}
/**
 Preguntes:

 a) Què ens permet fer l'herència que no podríem fer altrament ?
 -> L'herència ens permet reutilitzar codi, conservant les clases base i afegint
    nous atributs estalviem codi.

 b) Que passa si getArea() de la classe Ellipse no és virtual? Perquè?
 -> Si el métode no fos virtual no es podría sobreescriure en les classes
    derivades. En aquest cas implicaria que el métode getArea de la classe
    Circle no funcionés.
  
 c) Perquè els constructors i destructors els hem de cridar a laes classes 
    derivades i no a la classe base?
 -> Perquè tant els contructors com els destructors són propis de cada classe,
    i per tant, per crear o destruir una instància d'una classe cal utilitzar
    els seus propis constructors/ destructors tot i que sigui classe derivada.
 
 d) Es podria fer que getArea() fos un mètode de la classe pare "Ellipse"?
 -> Si, pero caldria modificar les crides per les classes derivades. En el cas
    del Cercle, fer que els dos radis de l'Elipse siguin iguals al radi 
   del cercle.
 
 e) Anomema els membres de dades definits en els teus programes i digues a quina
    classe pertanyen. Explica les decisions de visibilitat.
-> =============================================================================================
   Dades           | Classe             | Visibilitat atributs  |   Explicació
   =============================================================================================
   const float PI; | Ellipse            | protected             | Accés classe derivada (Cercle).
   float radius1;  | Ellipse            | protecetd             | Accés classe derivada (Cercle).
   float radius2;  | Ellipse            | protected             | Accés classe derivada (Cercle).
   float area;     | Ellipse            | protected             | Accés classe derivada (Cercle).
   =============================================================================================
   vector v;       | EllipseContainer   | private               | No interessa accés usuari.
   =============================================================================================

 f) L'iterador que recorre les figures, quant s'incrementa cada cop? Perquè?
 -> L'iterador s'incrementa cada cop una unitat, per tal de avançar per les
    posicions del vector de la classe EllipseContainer.

 */
