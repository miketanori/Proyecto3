//
//  main.cpp
//  Proyecto3
//
//  Created by Miguel Tánori on 18/05/20.
//  Copyright © 2020 Miguel Tánori. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Material.h"
#include "Reserva.h"
#include "Libro.h"
#include "Disco.h"
#include "Software.h"
using namespace std;
//Arreglo de apuntadores a objetos de tipo Material (con un máximo de 30 elementos) y un arreglo de Reservaciones (con un máximo de 60 elementos).
Material* material[30];
Reserva reserva[60];
Reserva r;
static string linea;
int contM, contR, contL, contD, contS, dd, m, a, i, ic, id;
Fecha f,f2;
Libro l[30];
Disco d[30];
Software s[30];
bool b;

int main() {
    ifstream entMaterial, entReservas;
    ofstream salReservas;
    char clave;
    string titulo;
    contM = 0;
    contL = 0;
    contD = 0;
    contS = 0;
    
    //-----Carga los datos al arreglo material de Material.txt------------------------------------------------------
    entMaterial.open("/Users/migueltanori/Desktop/Material.txt");
    while(entMaterial >> linea){
        id = (stoi(linea)); //idMaterial
        entMaterial >> linea;
        titulo = linea; //titulo
        entMaterial >> linea;
        clave = linea[0];
        switch(clave){ //clave
            case 'L'://Libro
                entMaterial >> linea;
                l[contL].setNumPag(stoi(linea));
                entMaterial >> linea;
                l[contL].setAutor(linea);
                material[contM] = &l[contL];
                contL++;
                break;
            case 'D'://Disco
                entMaterial >> linea;
                d[contD].setDuracion(stoi(linea));
                entMaterial >> linea;
                d[contD].setGenero(linea);
                material[contM] = &d[contD];
                contD++;
                break;
            case 'S'://Software
                entMaterial >> linea;
                s[contS].setVersion(stoi(linea));
                entMaterial >> linea;
                s[contS].setSO(linea);
                material[contM] = &s[contS];
                contS++;
                break;
        }
        material[contM] -> setIdMaterial(id);
        material[contM] -> setTitulo(titulo);
        contM++;
    }
    entMaterial.close();
    //-----Carga los datos al arreglo reserva de reserva.txt-------------------------------------------------------
    entReservas.open("/Users/migueltanori/Desktop/Reserva.txt");
    contR = 0;
    while(entReservas >> dd >> m >> a){
        f.setFecha(dd, m, a);
        reserva[contR].setFechaReservacion(f);
        entReservas >> linea;
        reserva[contR].setIdMaterial(stoi(linea));
        entReservas >> linea;
        reserva[contR].setIdCliente(stoi(linea));
        contR++;
    }
    entReservas.close();
    
    //----------------------------------------------MENU-----------------------------------------------------------
    char o = ' ';
    while (o != 'f'){
        cout << "\nBienvenido\nTeclee A para Consultar la lista de Materiales\nTeclee B para Consultar la lista de Reservaciones\nTeclee C para Consultar las reservaciones de un material dado\nTeclee D para Consultar las reservaciones de una fecha dada\nTeclee E para Hacer una reservación\nTeclee F para Terminar\n";
        cin >> o;
        switch(tolower(o)){
            case 'a':
                for(int x = 0; x<contM; x++){
                    material[x] -> muestraDatos();
                }
                break;
            case 'b':
                for(int x = 0; x<contR; x++){
                    for(int y = 0; y<contM; y++){
                        if(reserva[x].getIdMaterial() == material[y] -> getIdMaterial()){
                            cout << "\nInicio de reservación: " << reserva[x].getFechaReservacion()
                            << "Fin de reservación: " << reserva[x].calculaFechaFinReserva(material[y] -> cantidadDiasPrestamo())
                            << "IdMaterial: " << reserva[x].getIdMaterial()
                            << "\nIdCliente: " << reserva[x].getIdCliente() << endl;
                            break;
                        }
                    }
                }
                break;
            case 'c':
                b = false;
                while (b == false){
                    cout << "\nIngrese el Id del Material a consultar\n";
                    cin >> id;
                    
                    for(int x = 0; x<contM; x++){
                        for(int y = 0; y<contR; y++){
                            if(material[x] -> getIdMaterial() == reserva[y].getIdMaterial()){
                                if(id == reserva[y].getIdMaterial()){
                                    b = true;
                                    cout << "\nID: "
                                         << material[x] ->getIdMaterial()
                                         << "\nTítulo: "
                                         << material[x] ->getTitulo()
                                         << "\nInicio de reservación: "
                                         << reserva[y].getFechaReservacion()
                                         << "Fin de reservación: "
                                         << reserva[y].calculaFechaFinReserva(material[x] -> cantidadDiasPrestamo());
                                }
                            }
                        }
                    }
                    if (b == false){
                        cout << "\nID inválido\n\n";
                    }
                }
                break;
            case 'd':
                cout << "\nIngrese la Fecha a consultar (Año debe ser mayor a 2015)";
                cin >> f;
                cout << "\nMateriales que ya se encuentren reservados en la fecha: " << f;
                b = false;
                for(int x = 0; x<contM; x++){
                    for(int y = 0; y<contR; y++){
                        if(material[x] -> getIdMaterial() == reserva[y].getIdMaterial()){
                            if(f >= reserva[y].getFechaReservacion() && f<= reserva[y].calculaFechaFinReserva(material[x] ->cantidadDiasPrestamo())){
                                b = true;
                            material[x]->muestraDatos();
                            cout << "Inicio de reservación: " << reserva[y].getFechaReservacion()
                                << "Fin de reservación: " << reserva[y].calculaFechaFinReserva(material[x] -> cantidadDiasPrestamo());
                            cout << endl;
                            }
                        }
                    }
                }
                if (b == false){
                    cout << "\nNo hay Materiales reservados en esa fecha\n\n";
                }
                break;
            
            case 'e':
                ic = 0;
                b = false;
                cout << "\nIngrese el Id del Cliente a reservar\n";
                cin >> ic;
                r.setIdCliente(ic);
                while(b==false){
                    cout << "\nIngrese el Id del Material a reservar\n";
                    cin >> id;
                    for(int y = 0; y<contM; y++){
                        if( id == material[y]->getIdMaterial()){
                            r.setIdMaterial(id);
                            cout << "\nMaterial " << r.getIdMaterial() << " existe\n";
                            i = y;
                            b = true;
                            break;
                        }
                    }
                    if(b==false){
                    cout << "\nId inválido\n";
                    }
                }
                
               cout << "\nIngrese la Fecha a reservar (Año debe ser mayor a 2015)";
                 cin >> f;
                
                 b = false;
                 for(int x = 0; x<contM; x++){
                     for(int y = 0; y<contR; y++){
                         if(material[x] -> getIdMaterial() == reserva[y].getIdMaterial()
                            && material[x] -> getIdMaterial() == r.getIdMaterial()){
                             if(f >= reserva[y].getFechaReservacion() && f<= reserva[y].calculaFechaFinReserva(material[x] ->cantidadDiasPrestamo())){
                                 b = true;
                              cout << "\nEl material ya está reservado\nIntente otra fecha\n";
                             material[x]->muestraDatos();
                             cout << "Inicio de reservación: " << reserva[y].getFechaReservacion()
                                 << "Fin de reservación: " << reserva[y].calculaFechaFinReserva(material[x] -> cantidadDiasPrestamo());
                             cout << endl;
                             }
                         }
                     }
                 }
                 if (b == false){
                     r.setFechaReservacion(f);
                     cout << "\nMaterial " << r.getIdMaterial() << " está disponible\n";
                     reserva[contR]= r;
                     cout << "\nSe reservó:\n";
                     cout << "Inicio de reservación: " << reserva[contR].getFechaReservacion()
                     << "Fin de reservación: " << reserva[contR].calculaFechaFinReserva(material[i] -> cantidadDiasPrestamo())
                     << "IdMaterial: " << reserva[contR].getIdMaterial()
                     << "\nIdCliente: " << reserva[contR].getIdCliente() << endl;
                     contR++;
                 }
                break;
                
            case 'f':
                salReservas.open("/Users/migueltanori/Desktop/Reserva.txt");
                for(int x = 0; x<contR; x++){
                    salReservas << reserva[x].getFechaReservacion().getDia() << " "
                    << reserva[x].getFechaReservacion().getMes() << " "
                    << reserva[x].getFechaReservacion().getAnio() << " "
                    << reserva[x].getIdMaterial() << " "
                    << reserva[x].getIdCliente()<< endl;
                    
                }
                
                salReservas.close();
                cout << "¡Hasta luego!\n\n";
                break;
            
            default:
                cout << "\nIntroduzca una opción válida\n";
                break;
        }
    }
    
    return 0;
}
/*
 
 while(b==false){
     
     
     for(int x = 0; x<contM; x++){
         for(int y = 0; y<contR; y++){
             if(material[x] -> getIdMaterial() == reserva[y].getIdMaterial()){
                 if(f < reserva[y].getFechaReservacion() && f> reserva[y].calculaFechaFinReserva(material[x] ->cantidadDiasPrestamo())){
                     b = true;
                 }
                 else{
                     b = false;
                     f2 = reserva[y].calculaFechaFinReserva(material[x] -> cantidadDiasPrestamo());
                 }
             }
         }
     }
     if(b==false){
     cout << "\nEste material no está disponible en: " << f
         << "Lo estará en: " << f2;
     }
 }
 
 */
