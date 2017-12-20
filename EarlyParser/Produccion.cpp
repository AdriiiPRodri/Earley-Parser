
/* 
 * File:   Produccion.cpp
 * Author: juane
 * 
 * Created on 12 December 2017, 10:40
 */

#include "Produccion.h"

Produccion::Produccion(const std::string& otra) {
    _produccion = otra;
}

char Produccion::parteIzq() const {
    /*Suponiendo que la produccion es del tipo: S>alfa  */
    int pos_angle = _produccion.find_first_of('>', 0);

    return _produccion.substr(0, pos_angle)[0];
}

string Produccion::parteDer() const {
    int pos_angle = _produccion.find_first_of('>', 0);

    return _produccion.substr(pos_angle + 1, _produccion.size() - 1);
}

void Produccion::imprimir() const {
    cout << _produccion << endl;
}

bool Produccion::operator==(const Produccion& other) const {
    return _produccion== other._produccion;
}

