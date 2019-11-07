
#ifndef NODETREE_H
#define NODETREE_H

using namespace std;

template <class Type>
class NodeTree {
    public:
        /*Constructores*/
        NodeTree(const Type& data);
        NodeTree(const NodeTree& orig);
        /*Destructor*/
        virtual ~NodeTree(); 
        /*Consultores*/
        NodeTree<Type>* getRight() const;
        NodeTree<Type>* getLeft() const;
        NodeTree<Type>* getParent() const;
        bool hasRight() const;
        bool hasLeft() const;
        bool isRoot() const;
        bool isExternal() const;
        const Type& getElement() const;
        int getHeight() const;  
        /*Modificadores*/
        void setHeight(int h);
        void setData(const Type& data);
        void setRight(NodeTree<Type>* newRight);
        void setLeft(NodeTree<Type>* newLeft);
        void setParent(NodeTree<Type>* newParent);
        private:
        NodeTree<Type>* pParent;
        NodeTree<Type>* pLeft;
        NodeTree<Type>* pRight;
        Type data;
        int height;
};

//================ CONSTRUCTORES ===============================================
template <class Type>
NodeTree<Type>::NodeTree(const Type& data){
    //Crea el nodo sin padres ni hijos
    pParent = nullptr;
    pLeft = nullptr;
    pRight = nullptr;
    this->data = data;
    this->height = 0;    
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
const Type& NodeTree<Type>::getElement() const{
    //Getter para elemento
    return this->data;
}

template <class Type>
int NodeTree<Type>::getHeight() const{
    return this->height;
}

//================ MODIFICADORES ===============================================
template <class Type>
void NodeTree<Type>::setHeight(int h){
    //Setter para altura
    this->height = h;
}

template <class Type>
void NodeTree<Type>::setData(const Type& data){
    //Setter para dato
    this->data = data;
}

template <class Type>
void NodeTree<Type>::setRight(NodeTree<Type>* newRight){
    //Setter para hijo izquierdo
    pRight = newRight;
}

template <class Type>
void NodeTree<Type>::setLeft(NodeTree<Type>* newLeft){
    //Setter para hijo derecho
    pLeft = newLeft;
}

template <class Type>
void NodeTree<Type>::setParent(NodeTree<Type>* newParent){
    //Setter para padre
    pParent = newParent;
}

#endif /* NODETREE_H */


