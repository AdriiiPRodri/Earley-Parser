
/* 
 * File:   Produccion.h
 * Author: juane
 *
 * Created on 12 December 2017, 10:40
 */

#ifndef PRODUCCION_H
#define PRODUCCION_H

#include <string>
#include <iostream>

using namespace std;

class Produccion {
public:
    Produccion(const string& otra);
    
    char parteIzq() const;
    string parteDer() const;
    
    void imprimir() const;
    
    bool operator==(const Produccion& other) const;
private:
    string _produccion;  //de la forma S>alfa
};

#endif /* PRODUCCION_H */

