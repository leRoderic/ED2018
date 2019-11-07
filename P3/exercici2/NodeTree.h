
#ifndef NODETREE_H
#define NODETREE_H

using namespace std;

template <class Type>
class NodeTree {
    public:
        /*Constructores*/
        NodeTree(const Type& value, const int key);
        NodeTree(const NodeTree& orig);
        virtual ~NodeTree();
        /*Consultores*/
        NodeTree<Type>* getRight() const;
        NodeTree<Type>* getLeft() const;
        NodeTree<Type>* getParent() const;
        bool hasRight() const;
        bool hasLeft() const;
        bool isRoot() const;
        bool isExternal() const;
        const Type& getValue() const;
        const int getKey() const;
        int getHeight() const; 
        /*Modificadores*/
        void setHeight(int h);
        void setValue(const Type& newValue);
        void setKey(int newKey);
        void setRight(NodeTree<Type>* newRight);
        void setLeft(NodeTree<Type>* newLeft);
        void setParent(NodeTree<Type>* newParent);
        private:
        NodeTree<Type>* pParent;
        NodeTree<Type>* pLeft;
        NodeTree<Type>* pRight;
        Type value;
        int key;
        int height;
};

//================ CONSTRUCTORES ===============================================
template <class Type>
NodeTree<Type>::NodeTree(const Type& value, const int key) :
    //Construtor por defecto
    pParent(nullptr),
    pLeft(nullptr),
    pRight(nullptr),
    value(value),
    key(key),
    height(1)
{      
}

template <class Type>
NodeTree<Type>::NodeTree(const NodeTree& orig):
    //Constructor copia
    pParent(nullptr),
    pLeft(nullptr),
    pRight(nullptr),
    value(orig.value),
    height(orig.height)
{          
}

//================ DESTRUCTOR ==================================================
template <class Type>
NodeTree<Type>::~NodeTree(){    
}

//================ CONSULTORES =================================================
template <class Type>
NodeTree<Type>* NodeTree<Type>::getRight() const{
    //Getter nodo izquierdo
    return this->pRight;    
}

template <class Type>
NodeTree<Type>* NodeTree<Type>::getLeft() const{
    //Getter nodo derecho
    return this->pLeft;
}

template <class Type>
NodeTree<Type>* NodeTree<Type>::getParent() const{
    //Getter para padre
    return this->pParent;
}

template <class Type>
bool NodeTree<Type>::hasRight() const{
    //Consulta si tiene hijo izquierdo    
    return !(pRight == nullptr);
}

template <class Type>
bool NodeTree<Type>::hasLeft() const{
    //Consulta si tiene hijo derecho
    return !(pLeft == nullptr);
}

template <class Type>
bool NodeTree<Type>::isRoot() const{
    //Comprueba si el nodo es raíz
    return pParent == nullptr;
}

template <class Type>
bool NodeTree<Type>::isExternal() const{
    //Comprueba si el nodo es externo
    return !hasRight() && !hasLeft();
}

template <class Type>
const Type& NodeTree<Type>::getValue() const{
    //Getter para elemento
    return this->value;
}

template <class Type>
const int NodeTree<Type>::getKey() const{
    //Getter para key
    return this->key;
}

//================ MODIFICADORES ===============================================
template <class Type>
void NodeTree<Type>::setHeight(int h){
    //Setter para altura
    this->height = h;
}
    
template <class Type>
void NodeTree<Type>::setValue(const Type& value){
    //Setter para el valor
    this->value = value;
}

template <class Type>
void NodeTree<Type>::setRight(NodeTree<Type>* newRight){
    //Setter para hijo derecho
    pRight = newRight;
}

template <class Type>
void NodeTree<Type>::setLeft(NodeTree<Type>* newLeft){
    //Setter para hijo izquierdo
    pLeft = newLeft;
}

template <class Type>
void NodeTree<Type>::setParent(NodeTree<Type>* newParent){
    //Setter para padre
    pParent = newParent;
}

template <class Type>
int NodeTree<Type>::getHeight() const{
    //Getter para altura
    return this->height;
}

#endif /* NODETREE_H */