
/* 
 * File:   Earley.h
 * Author: juane
 *
 * Created on 12 December 2017, 11:32
 */

#ifndef EARLEY_H
#define EARLEY_H

#include <string>
#include <vector>
#include <map>
#include "Gramatica.h"
#include "Registro.h"

using namespace std;

class Earley {
public:
    Earley(const Gramatica& g, const string& cad);
    
    bool parse();
private:
    Gramatica grammar;
    string cadena;
    vector<vector<Registro> > registros;
    map<char,bool> check_var;
    
    unsigned j=0;
    
    void initialization();
    void clausure();
    bool advance();
    void termination();
    
    void comprobar() const;
};

#endif /* EARLEY_H */

