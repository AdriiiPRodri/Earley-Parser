
/* 
 * File:   Registro.cpp
 * Author: juane
 * 
 * Created on 12 December 2017, 10:56
 */

#include <string>
#include <iostream>

#include "Registro.h"

Registro::Registro() {
}

Registro::Registro(unsigned i_p, unsigned j_p, const string& A_p, const string& alfa_p, const string& beta_p, Gramatica* grammar_p) {
    i = i_p;
    j = j_p;
    A = A_p;
    alfa = alfa_p;
    beta = beta_p;
    grammar = grammar_p;
}

char Registro::splitVar() const{
    char car;
    unsigned pos;
    for (auto it = grammar->getVariables()->begin(); it != grammar->getVariables()->end(); ++it) {
        if (beta[0] == *it)
            return *it;
    }
    
    return 'e';
}

char Registro::splitTer() const{
    char car;
    unsigned pos;
    for (auto it = grammar->getTerminales()->begin(); it != grammar->getTerminales()->end(); ++it) {
        if (beta[0] == *it)
            return *it;
    }
    
    return 'e';
}

bool Registro::operator==(const Registro& other) const{
    return A==other.A && i == other.i && j == other.j && alfa == other.alfa && beta==other.beta;
}


void Registro::imprimir() const{
    cout << "(" << i << ", " << j << ", " << A << ", " << alfa << ", " << beta << ")" << endl;
}


