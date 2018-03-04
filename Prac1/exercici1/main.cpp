/* 
 * File:   main.cpp
 * Author: Sergio Barril Pizarro i Rodrigo Cabezas Quirós
 *
 * Created on 20 / de febrer / 2018, 08:11
 */


/* 
 * Respuesta a la pregunta: En la carpeta del proyecto hay 
 * el archivo main.cpp, con el código fuente del programa
 * la carpeta build, que contiene los archivos objeto
 * la carpeta dist, que contiene el ejecutable
 * la carpeta nbproject, que contiene los metadatos del proyecto para NetBeans
 * el archivo .dep, con las dependencias entre archivos
 * el archivo Makefile, con las instrucciones al compilador para construir la
 * aplicación.
 * 
 */

#include <iostream>

using namespace std;

int main() {    
    string nom;
    int option;
    
    string arr_options = {"Sortir", "Benvinguda"};
    
    cout << "*** INICI ***" << endl;
    cout << "Hola, com et dius?" << endl;
    cin >> nom;
    
    do{
        cout << "Hola " << nom <<", que vols fer?" << endl;
        
        for(int i = 0; i < 2; i++){
            cout << i + 1 << ".\t" << arr_options[i] << endl;
        }
        
        cin >> option;        
        switch(option){
            case 1:
                cout << "*** FI ***" << endl;
                break;
            case 2:
                cout << "Benvigut/da a l'assignatura d'Estructura de Dades, " << nom << endl;
                break;               
            default:
                cout << "No has escollit una opcio valida!" << endl;                        
        }  
    }while(option != 1);
    
    return 0;
}

