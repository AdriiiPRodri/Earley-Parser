
/* 
 * File:   Registro.h
 * Author: juane
 *
 * Created on 12 December 2017, 10:56
 */

#ifndef REGISTRO_H
#define REGISTRO_H

#include "Gramatica.h"

/*A > Alfa.Beta*/

using namespace std;

class Registro {
public:
    Registro();
    Registro(unsigned i_p, unsigned j_p, const string& A_p, const string& alfa_p, const string& beta_p, Gramatica* grammar_p);

    unsigned getI() const {
        return i;
    }

    unsigned getJ() const {
        return j;
    }

    string getA() const {
        return A;
    }

    string getAlfa() const {
        return alfa;
    }

    string getBeta() const {
        return beta;
    }

    char splitVar() const;

    char splitTer() const;

    void imprimir() const;

    bool operator==(const Registro& other) const;
private:
    Gramatica* grammar;
    unsigned i, j; //posicion 1 y 2
    string A; //posicion 3
    string alfa; //posicion 4    
    string beta; //posicion 5
};

#endif /* REGISTRO_H */

