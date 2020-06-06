//
//  Material.h
//  Proyecto3
//
//  Created by Miguel Tánori on 18/05/20.
//  Copyright © 2020 Miguel Tánori. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;
#ifndef Material_h
#define Material_h

class Material
{
public:
    void setIdMaterial(int i) { idMaterial = i;};
    int getIdMaterial() { return idMaterial; };
    void setTitulo(string t) { titulo = t;};
    string getTitulo() { return titulo;};
    Material();
    Material(int, string);
    virtual void muestraDatos() = 0;
    virtual int cantidadDiasPrestamo() = 0;
protected:
    int idMaterial;
    string titulo;
};

Material :: Material(int iD, string t){
    this -> idMaterial = iD;
    this -> titulo = t;
}

Material :: Material(){
    this -> idMaterial = 0;
    this -> titulo = "No Disponible";
}

#endif /* Material_h */
