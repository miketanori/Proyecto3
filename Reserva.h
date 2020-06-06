//
//  Reserva.h
//  Proyecto3
//
//  Created by Miguel Tánori on 18/05/20.
//  Copyright © 2020 Miguel Tánori. All rights reserved.
//
#include "Fecha.h"
#include <string>
#include <iostream>
using namespace std;
#ifndef Reserva_h
#define Reserva_h

class Reserva
{
public:
    void setIdMaterial(int i) { idMaterial = i;};
    int getIdMaterial() { return idMaterial; };
    void setIdCliente(int i) { idCliente = i;};
    int getIdCliente() { return idCliente; };
    void setFechaReservacion(Fecha f) { fechaReservacion = f;};
    Fecha getFechaReservacion() { return fechaReservacion;};
    Reserva();
    Reserva(int, int, Fecha);
    Fecha calculaFechaFinReserva(int);
private:
    int idMaterial, idCliente;
    Fecha fechaReservacion;
};

Reserva :: Reserva(int iM, int iC, Fecha f){
    idMaterial = iM;
    idCliente = iC;
    fechaReservacion = f;
}

Reserva :: Reserva(){
    idMaterial = 0;
    idCliente = 0;
    Fecha f;
    fechaReservacion = f;
}

Fecha Reserva ::calculaFechaFinReserva(int d){
    Fecha nueva = fechaReservacion + d;
    return nueva;
}

#endif /* Reserva_h */
