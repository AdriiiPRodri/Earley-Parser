/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Produccion.cpp
 * Author: juane
 * 
 * Created on 12 December 2017, 10:40
 */

#include "Produccion.h"

Produccion::Produccion(const std::string& otra) {
    _produccion= otra;
}

char Produccion::parteIzq() {
    /*Suponiendo que la produccion es del tipo: S>alfa  */
    int pos_angle = _produccion.find_first_of('>', 0);

    return _produccion.substr(0, pos_angle)[0];
}

string Produccion::parteDer() {
    int pos_angle = _produccion.find_first_of('>', 0);

    return _produccion.substr(pos_angle+1, _produccion.size()-1);
}

void Produccion::imprimir() const{
        cout << _produccion << endl;
    }
