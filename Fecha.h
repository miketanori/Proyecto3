//
//  Fecha.h
//  Proyecto3
//
//  Created by Miguel Tánori on 18/05/20.
//  Copyright © 2020 Miguel Tánori. All rights reserved.
//
#include <string>
#include <iostream>
using namespace std;
#ifndef Fecha_h
#define Fecha_h

class Fecha
{
public:
    Fecha();
    Fecha(int, int, int);
    void setFecha(int d, int m, int a){dd = d; mm = m; aa = a;};
    int getDia() { return dd; };
    int getMes() { return mm; };
    int getAnio() { return aa;};
    bool operator>(Fecha);
    bool operator>=(Fecha);
    bool operator<(Fecha);
    bool operator<=(Fecha);
    bool operator==(Fecha);
    Fecha operator+(int);
    friend ostream &operator << (ostream &os, Fecha f);
    friend istream &operator >> (istream &os, Fecha &f);
    string nombreMes();
private:
    int dd, mm, aa;
};

Fecha :: Fecha(int dd, int mm, int aa){
    this -> dd = dd;
    this -> mm = mm;
    this -> aa = aa;
}

Fecha :: Fecha(){
    dd = 0;
    mm = 0;
    aa = 0;
}

bool Fecha::operator>(Fecha t1){
    if ((dd > t1.dd && mm == t1.mm && aa == t1.aa) || (mm > t1.mm && aa == t1.aa) || aa > t1.aa){
        return true;
    }
    else{
        return false;
    }
}

bool Fecha::operator>=(Fecha t1){
    if ((aa > t1.aa) ||
        (mm > t1.mm && aa == t1.aa) ||
        (dd >= t1.dd && mm == t1.mm && aa == t1.aa)){
        return true;
    }
    else{
        return false;
    }
}

bool Fecha::operator<(Fecha t1){
    if ((dd < t1.dd && mm == t1.mm && aa == t1.aa) ||
        (mm < t1.mm && aa == t1.aa) ||
        aa < t1.aa){
        return true;
    }
    else{
        return false;
    }
}

bool Fecha::operator<=(Fecha t1){
    if ((aa < t1.aa) ||
        (mm < t1.mm && aa == t1.aa) ||
        (dd <= t1.dd && mm == t1.mm && aa == t1.aa)){
        return true;
    }
    else{
        return false;
    }
}

bool Fecha::operator==(Fecha t1){
    if (dd == t1.dd && mm == t1.mm && aa == t1.aa){
        return true;
    }
    else{
        return false;
    }
}

Fecha Fecha::operator+(int d){
    int ddN = dd + d, mmN = mm, aaN= aa;

    if((mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) && ddN > 31){
        mmN = mm + ddN / 31;
        ddN = ddN % 31;
    }
    if(mm == 2 && ddN > 28){
           mmN = 2 + ddN / 28;;
           ddN = ddN % 28;
    }
    if((mm == 4 || mm == 6 || mm == 9 || mm == 11) && ddN > 30){
        mmN = mm + ddN / 30;
        ddN = ddN % 30;
    }
    if(mmN > 12){
        mmN = mmN/12;
        aaN++;
    }
    Fecha nuevo(ddN, mmN, aaN);
    return nuevo;
}

// funciones friend
ostream &operator << (ostream &os, Fecha f) {
    os << f.dd << "/" << f.nombreMes() << "/" << f.aa << endl;
    return os;
}

istream &operator >> (istream &os, Fecha &f) {
    bool o = false;
    while (o == false){
        cout << "\nDIA (dd): ";
        os >> f.dd;
        cout << "\nMES (mm): ";
        os >> f.mm;
        cout << "\nAÑO (aa): ";
        os >> f.aa;
        if((f.mm == 1 || f.mm == 3 || f.mm == 5 || f.mm == 7 || f.mm == 8 || f.mm == 10 || f.mm == 12) && f.dd < 32 && f.dd > 0 && f.aa >= 2015){
            break;
        }
        else if(f.mm == 2 && f.dd < 29 && f.dd > 0 && f.aa >= 2015){
            break;
        }
        else if((f.mm == 4 || f.mm == 6 || f.mm == 9 || f.mm == 11) && f.dd < 31 && f.dd > 0 && f.aa >= 2015){
             break;
        }
        else{
            cout << "\nFecha inválida\n";
        }
    }
    return os;
}

string Fecha :: nombreMes(){
    string mes;
    switch (mm){
        case 1:
            mes = "Ene";
            break;
        case 2:
            mes = "Feb";
            break;
        case 3:
            mes = "Mar";
            break;
        case 4:
            mes = "Abr";
            break;
        case 5:
            mes = "May";
            break;
        case 6:
            mes = "Jun";
            break;
        case 7:
            mes = "Jul";
            break;
        case 8:
            mes = "Ago";
            break;
        case 9:
            mes = "Sep";
            break;
        case 10:
            mes = "Oct";
            break;
        case 11:
            mes = "Nov";
            break;
        case 12:
            mes = "Dic";
            break;
        default:
            mes = "No disponible";
            break;
    }
    return mes;
}

#endif /* Fecha_h */
