
#include "BSTMovieFinder.h"

//================ CONSTRUCTORES ===============================================
BSTMovieFinder::BSTMovieFinder() {
    //Constructor por defecto
    bst = new BinarySearchTree<Movie>();
}

//================ DESTRUCTOR ==================================================
BSTMovieFinder::~BSTMovieFinder() {
    //Destructor
    delete bst;
}

// =============== MODIFICADORES ===============================================
void BSTMovieFinder::appendMovies(string filename) {
    //Extrae y añadfe peliculas de un documento .txt
    ifstream fin;
    fin.open(filename); //Abre el fichero
    if(!fin.is_open())
        throw ("No se ha podido abrir el archivo");
    string pelicula;
    int id;
    string title;
    float rating;
    size_t idTitle;
    size_t titleRating;
    while(getline(fin, pelicula)){
        idTitle = pelicula.find("::"); 
        titleRating = pelicula.rfind("::");
        id = stoi(pelicula.substr(0, idTitle));
        title = pelicula.substr(idTitle + 2, titleRating - idTitle - 2);
        rating = stof(pelicula.substr(titleRating + 2, pelicula.npos));
        insertMovie(id, title, rating);
    }
    fin.close();        
}

void BSTMovieFinder::insertMovie(int movieID, string title, float rating) {
    //Inserta una nueva película
    Movie* movie = new Movie(movieID, title, rating);    
    bst->insert(*movie, movieID);
}

//================ CONSULTORES =================================================
const string BSTMovieFinder::showMovie(int movieID) const {
    //Muestra una película dado su ID
    Movie pelicula = findMovie(movieID);
    return pelicula.toString();    
}

const Movie& BSTMovieFinder::findMovie(int movieID) const {
    //Busca una película dado su ID
    if(bst->isEmpty())
        throw out_of_range("Está vacío!");
    NodeTree<Movie>* node = bst->root(); //Empieza a buscar desde el nodo raíz
    bool found = false;
    while(!found){       // Mientras no la haya encontrado  
        if(movieID > node->getKey()){
            if(node->hasRight())
                node = node->getRight();                
            else throw invalid_argument("ID no encontrada");
        }
        else if(movieID < node->getKey()){
            if(node->hasLeft())
                node = node->getLeft();
            else throw invalid_argument("ID no encontrada");
        }
        else found = true; //Si el key es igual, búsqueda satisfactoria                    
    }

    return node->getValue();    //Retorna el valor del nodo
}

const float BSTMovieFinder::findRatingMovie(int movieID) const {
    //Busca la nota de una película dado su ID
    return findMovie(movieID).getRating();
}

void BSTMovieFinder::showMovies() const {
    //Muestra las películas
    NodeTree<Movie>* root = bst->root();
    showMovies(root);    
}

void BSTMovieFinder::showMovies(NodeTree<Movie>* p) const {
    //Muestra las peliculas
   static int counter = 0;
    if(p->hasLeft()){   //Primero va a por las de la izquierda
        showMovies(p->getLeft());
    }
    if(counter < 40){
        cout << p->getValue().toString(); //Muestra las primeras 40 películas
        cout << endl;
        counter++;
    }
    while(counter == 40){        
        cout << "Continuar? (Y/N)" << endl;
        char opt;
        cin >> opt;
        switch(toupper(opt)){
            case 'Y':
                counter = 0; //Continua con las películas a la izqda. de raíz
                break;
            case 'N':
                counter++;
                break;
            default:
                cout <<"Error. ";
        }
    }    
    if(p->hasRight()){        
        showMovies(p->getRight());
    }
    if(p->isRoot())
       counter = 0;
}

bool BSTMovieFinder::search(const int movieID) const {
    //Comprueba si hay una película dado su ID
    return bst->search(movieID);
}

const int BSTMovieFinder::depth() const{
    //Retorna la profundidad del BST
    return bst->root()->getHeight();
}

