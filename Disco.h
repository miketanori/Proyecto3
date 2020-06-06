//
//  Disco.h
//  Proyecto3
//
//  Created by Miguel Tánori on 18/05/20.
//  Copyright © 2020 Miguel Tánori. All rights reserved.
//
#include <string>
#include <iostream>
using namespace std;
#ifndef Disco_h
#define Disco_h
class Disco : public Material
{
public:
    void setDuracion(int d) { duracion = d;};
    int getDuracion() { return duracion; };
    void setGenero(string g) { genero = g;};
    string getGenero() { return genero; };
    Disco();
    Disco(int, string);
    void muestraDatos();
    int cantidadDiasPrestamo();
private:
    int duracion;
    string genero;
};

Disco :: Disco(int d, string g){
    this -> duracion = d;
    this -> genero = g;
}

Disco :: Disco(){
    this -> duracion = 0;
    this -> genero = "No disponible";
}

int Disco :: cantidadDiasPrestamo(){
    return 2;
}

void Disco :: muestraDatos(){
    cout << "\nTipo de Material: Disco\nID: " << idMaterial << "\nTítulo: " << titulo << "\nDuración: " << duracion << "\nGénero: " << genero << "\n";
}
#endif /* Disco_h */
