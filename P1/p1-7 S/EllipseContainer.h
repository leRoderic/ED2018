/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EllipseContainer.h
 * Author: Tropped
 *
 * Created on 3 de marzo de 2018, 13:55
 */

#include <vector>
#include <iostream>
#include "Ellipse.h"

using namespace std;


#ifndef ELLIPSECONTAINER_H
#define ELLIPSECONTAINER_H

class EllipseContainer {
public:
    EllipseContainer();
    EllipseContainer(const EllipseContainer& orig);
    virtual ~EllipseContainer();
    
    void addEllipse(Ellipse *);
    float getAreas();
    vector<Ellipse *> getVector();
    
private:
    vector<Ellipse *> v;
    

};

#endif /* ELLIPSECONTAINER_H */

