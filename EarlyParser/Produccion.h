/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
    
    char parteIzq();
    string parteDer();
    
    void imprimir() const;
private:
    string _produccion;  //de la forma S>alfa
};

#endif /* PRODUCCION_H */

