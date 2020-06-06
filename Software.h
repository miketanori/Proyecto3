//
//  Software.h
//  Proyecto3
//
//  Created by Miguel Tánori on 18/05/20.
//  Copyright © 2020 Miguel Tánori. All rights reserved.
//
#include <string>
#include <iostream>
using namespace std;
#ifndef Software_h
#define Software_h
class Software : public Material
{
public:
    void setVersion(int v) { version = v;};
    int getDuracion() { return version; };
    void setSO(string s) { SO = s;};
    string getSO() { return SO; };
    Software();
    Software(int, string);
    void muestraDatos();
    int cantidadDiasPrestamo();
private:
    int version;
    string SO;
};

Software :: Software(int v, string s){
    this -> version = v;
    this -> SO = s;
}

Software :: Software(){
    this -> version = 0;
    this -> SO = "No disponible";
}

int Software :: cantidadDiasPrestamo(){
    return 1;
}

void Software :: muestraDatos(){
    cout << "\nTipo de Material: Software\nID: " << idMaterial << "\nTítulo: " << titulo << "\nVersión: " << version << "\nSO: " << SO << "\n";
}

#endif /* Software_h */
