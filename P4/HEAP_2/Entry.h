/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entry.h
 * Author: Tropped
 *
 * Created on May 19, 2018, 12:34 PM
 */

#ifndef ENTRY_H
#define ENTRY_H

using namespace std;

template <class Type>
class Entry {
public:
    Entry(int key, Type value);
    Entry(const Entry& orig);
    virtual ~Entry();
    int key() const;
    void setKey(const int key);
    const Type& value() const;
    void setValue(const Type& value);       
private:
    int mKey;
    Type mValue;    
};

/**
 * Constructor, que toma por parametro key y value
 */
template <class Type>
Entry<Type>::Entry(int key, Type value):
    mKey(key),
    mValue(value)
{}

/** 
 * Constructor copia
 */
template <class Type>
Entry<Type>::Entry(const Entry& orig):
    mKey(orig.mKey),
    mValue(orig.mValue)
{}

/**
 * Destructor
 */
template <class Type>
Entry<Type>::~Entry() {}

/**
 * Retorna la key 
 */
template <class Type>
int Entry<Type>::key() const{
    return mKey;
}

/**
 *  Actualiza la key
 * @param key
 */
template <class Type>
void Entry<Type>::setKey(const int key){
    this->mKey = key;
}

/**
 * Retorna el valor de la entrada
 * @return 
 */
template <class Type>
const Type& Entry<Type>::value() const{
    return mValue;
}

/**
 * Actualiza el vlor de la entrada 
 */
template <class Type>
void Entry<Type>::setValue(const Type& value){
    this->mValue = value;
}

#endif /* ENTRY_H */

