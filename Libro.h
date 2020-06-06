//
//  Libro.h
//  Proyecto3
//
//  Created by Miguel Tánori on 18/05/20.
//  Copyright © 2020 Miguel Tánori. All rights reserved.
//
#include <string>
#include <iostream>
using namespace std;
#ifndef Libro_h
#define Libro_h

class Libro : public Material
{
public:
    void setNumPag(int i) { numPag = i;};
    int getNumPag() { return numPag; };
    void setAutor(string a) { autor = a;};
    string getAutor() { return autor; };
    Libro();
    Libro(int, string);
    void muestraDatos();
    int cantidadDiasPrestamo();
private:
    int numPag;
    string autor;
};

Libro :: Libro(int n, string a){
    this -> numPag = n;
    this -> autor = a;
}

Libro :: Libro(){
    this -> numPag = 0;
    this -> autor = "No disponible";
}

int Libro :: cantidadDiasPrestamo(){
    return 7;
}

void Libro :: muestraDatos(){
    cout << "\nTipo de Material: Libro\nID: " << idMaterial << "\nTítulo: " << titulo << "\nNúmero de Páginas: " << numPag << "\nAutor: " << autor << "\n";
}
#endif /* Libro_h */
