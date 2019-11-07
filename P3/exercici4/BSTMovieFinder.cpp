
#include "BSTMovieFinder.h"

BSTMovieFinder::BSTMovieFinder() {
    // Constructor por defecto de BSTMovieFinder
    bst = new BinarySearchTree<Movie>();
}

BSTMovieFinder::~BSTMovieFinder() {
    // Destructor de BSTMovie Finder
    delete bst;
}

void BSTMovieFinder::appendMovies(string filename) {
    // Toma como parámetro un nombre de archivo, lo lee
    // y añade todas las peliculas que contiene al BST
    ifstream fin;
    fin.open(filename);
    if(!fin.is_open())
        cout << "No se ha podido abrir el archivo" << endl;
    else{
        string pelicula;
        int id;
        string title;
        float rating;

        size_t idTitle;
        size_t titleRating;

        while(getline(fin, pelicula)){
            idTitle = pelicula.find("::"); // Posicion del primer delimitador
            titleRating = pelicula.rfind("::"); // Posicion del ultimo delimitador 

            // Substring + cambio de tipo        
            id = stoi(pelicula.substr(0, idTitle));
            title = pelicula.substr(idTitle + 2, titleRating - idTitle - 2);
            rating = stof(pelicula.substr(titleRating + 2, pelicula.npos));

            insertMovie(id, title, rating);  
        }

        fin.close();
    }
}

void BSTMovieFinder::insertMovie(int movieID, string title, float rating) {
    // Añade una pelicula al BST con los atributos pasados por parámetro
    Movie* movie = new Movie(movieID, title, rating);
    try{    
        bst->insert(*movie, movieID);
    } catch( invalid_argument exc){
        cout << exc.what() << endl;
    }
}

const string BSTMovieFinder::showMovie(int movieID) const { 
    // Retorna la información de la película cuyo ID se pasa por parámetro
    Movie pelicula = findMovie(movieID);        
    return pelicula.toString();    
}

const Movie& BSTMovieFinder::findMovie(int movieID) const {
    // Retorna la pelicula cuyo ID se pasa por parámetro
    if(bst->isEmpty())
        throw out_of_range("Está vacío!");
    NodeTree<Movie>* node = bst->root();
    bool found = false;
    while(!found){        
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
        else found = true;                    
    }
    return node->getValue();
}

const float BSTMovieFinder::findRatingMovie(int movieID) const {
    // Retorna la valoracion de la pelicula cuyo ID se pasa por parametro
    return findMovie(movieID).getRating();
}

void BSTMovieFinder::showMovies() const {
    // Iniciador de la recursion para mostrar las peliculas por orden de ID
    NodeTree<Movie>* root = bst->root();
    showMovies(root);    
}

void BSTMovieFinder::showMovies(NodeTree<Movie>* p) const {
    // Muestra las peliculas por orden de ID
   static int counter = 0;
    if(p->hasLeft()){
        showMovies(p->getLeft());
    }
    if(counter < 40){
        cout << p->getValue().toString();
        cout << endl;
        counter++;
    }
    while(counter == 40){        
        cout << "Continuar? (Y/N)" << endl;
        char opt;
        cin >> opt;
        switch(toupper(opt)){
            case 'Y':
                counter = 0;
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
    // Dado un ID, retorna true si está en el BST, de lo contrario false
    return bst->search(movieID);
}

const int BSTMovieFinder::depth() const{
    // Retorna la profundidad del árbol
    return bst->root()->getHeight();
}

const string BSTMovieFinder::longTitle() const{
    //Busca la película con el título más largo
    if(bst->isEmpty())
        throw out_of_range("El árbol está vacío");
    return longTitle(bst->root());
}

const string BSTMovieFinder::longTitle(NodeTree<Movie>* p) const {
    //Busca la película con el título más largo
    int lengthp = 0, lengthl = 0, lengthr = 0;
    string leftTitle, rightTitle;
    lengthp = p->getValue().getTitle().length();  
    if(p->hasLeft()){
        leftTitle = longTitle(p->getLeft());
        lengthl = leftTitle.length();
    }
    if(p->hasRight()){
        rightTitle = longTitle(p->getRight());
        lengthr = rightTitle.length();
    }    
    if(lengthp >= lengthl){
        if(lengthp >= lengthr)
            return p->getValue().getTitle();
    }
    if(lengthl >= lengthp){
        if(lengthl >= lengthr)
            return leftTitle;
    }
    if(lengthr >= lengthl){
        if(lengthr >= lengthp)
            return rightTitle;
    }    
}

const array<float, 2> BSTMovieFinder::ratings() const {
    if(bst->isEmpty())
        throw out_of_range("Árbol vacío");
    
    ratings(bst->root());    
}

const array<float,2> BSTMovieFinder::ratings(NodeTree<Movie>* p) const {
    //Retorna mayor y menor puntuación de pelicula
    array<float,2> l_rating = {-1,-1};
    array<float,2> p_rating = {-1,-1};
    array<float,2> r_rating = {-1,-1};
    p_rating[0] = p->getValue().getRating();
    p_rating[1] = p->getValue().getRating();   
    if(p->hasLeft()){
        l_rating = ratings(p->getLeft());
        p_rating[0] = min(l_rating[0], p_rating[0]);
        p_rating[1] = max(l_rating[1], p_rating[1]);
    }
    if(p->hasRight()){
        r_rating = ratings(p->getRight());
        p_rating[0] = min(r_rating[0], p_rating[0]);
        p_rating[1] = max(r_rating[1], p_rating[1]);        
    }                       
    return p_rating;
}

void BSTMovieFinder::printRatings(const float rating) const{
    //Imprime puntuaciones peliculas
    if(bst->isEmpty())
        throw out_of_range("Árbol vacío");
    printRatings(bst->root(), rating);
}


void BSTMovieFinder::printRatings(NodeTree<Movie>* p, const float rating) const{
    //Imprime puntuaciones peliculas
    if(p->hasLeft()){
        printRatings(p->getLeft(), rating);
    }
    if(p->getValue().getRating() == rating){
    cout << p->getValue().toString();
    cout << endl;
    }   
    if(p->hasRight()){        
        printRatings(p->getRight(), rating);
    }
}
