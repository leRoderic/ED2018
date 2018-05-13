
#ifndef NODETREE_H
#define NODETREE_H

using namespace std;

template <class Type>
class NodeTree {
    public:
        /*Constructores*/
        NodeTree(const Type& value);
        NodeTree(const NodeTree& orig);
        /*Destructores*/
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
        int getHeight() const;
        int getBalance() const;        
        /*Modificadores*/
        void setHeight(int h);
        void setBalance(int b);
        void setValue(const Type& newValue);
        void setRight(NodeTree<Type>* newRight);
        void setLeft(NodeTree<Type>* newLeft);
        void setParent(NodeTree<Type>* newParent);
        private:
        NodeTree<Type>* pParent;
        NodeTree<Type>* pLeft;
        NodeTree<Type>* pRight;
        Type value;
        int height;
        int balance;
};

//================ CONSTRUCTORES ===============================================
template <class Type>
NodeTree<Type>::NodeTree(const Type& value) :
    //Constructor
    pParent(nullptr),
    pLeft(nullptr),
    pRight(nullptr),
    value(value),
    height(1),
    balance(0)
{      
}

template <class Type>
NodeTree<Type>::NodeTree(const NodeTree& orig):
    // Constructor copia
    pParent(nullptr),
    pLeft(nullptr),
    pRight(nullptr),
    value(orig.value),
    height(orig.height),
    balance(orig.balance)
{          
}

//================ DESTRUCTOR ==================================================
template <class Type>
NodeTree<Type>::~NodeTree(){    
}

//================ CONSULTORES =================================================
template <class Type>
NodeTree<Type>* NodeTree<Type>::getRight() const{
    //Getter para hijo derecho
    return this->pRight;    
}

template <class Type>
NodeTree<Type>* NodeTree<Type>::getLeft() const{
    //Getter para hijo izquierdo
    return this->pLeft;
}

template <class Type>
NodeTree<Type>* NodeTree<Type>::getParent() const{
    //Getter para padre
    return this->pParent;
}

template <class Type>
bool NodeTree<Type>::hasRight() const{    
    //Comprueba si existe hijo derecho
    return !(pRight == nullptr);
}

template <class Type>
bool NodeTree<Type>::hasLeft() const{
    //Comprueba si existe hijo izquierdo
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
    //Getter para valor
    return this->value;
}

template <class Type>
int NodeTree<Type>::getHeight() const{
    //Getter para altura del nodo
    return this->height;
}

template <class Type>
int NodeTree<Type>::getBalance() const{
    //Getter para balance
    return this->balance;
}

//================ MODIFICADORES ===============================================
template <class Type>
void NodeTree<Type>::setHeight(int h){
    //Setter para altura
    this->height = h;
}

template <class Type>
void NodeTree<Type>::setBalance(int b){
    //Setter para balance
    this->balance = b;
}
    
template <class Type>
void NodeTree<Type>::setValue(const Type& value){
    //Setter para valor del nodo
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

#endif /* NODETREE_H */