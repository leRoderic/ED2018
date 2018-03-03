/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EllipseContainer.h
 * Author: Rodrigo Cabezas Quirós
 *
 * Created on 2 de marzo de 2018, 18:19
 */

#ifndef ELLIPSECONTAINER_H
#define ELLIPSECONTAINER_H
#include "Ellipse.h"
#include <vector>

using namespace std;

class EllipseContainer {
public:
    void addEllipse(Ellipse* a);
    float getAreas();
    EllipseContainer();
    EllipseContainer(const EllipseContainer& orig);
    virtual ~EllipseContainer();
    vector<Ellipse *> getVector();
private:
    vector <Ellipse *> v;
};

#endif /* ELLIPSECONTAINER_H */

