/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Gramatica.h
 * Author: juane
 *
 * Created on 12 December 2017, 11:07
 */

#ifndef GRAMATICA_H
#define GRAMATICA_H

#include <set>
#include <vector>
#include "Produccion.h"

using namespace std;

class Gramatica {
public:
    Gramatica(const vector<Produccion>& producciones_p);
    
    Gramatica(){}
    
    const set<char>* getTerminales() const {
        return &terminales;
    }

    const set<char>* getVariables() const {
        return &variables;
    }
    
    vector<Produccion> getProducciones() const {
        return producciones;
    }
    
    bool isVar(char carac){
        return variables.count(carac);
    }
    
    bool isTer(char carac){
        return terminales.count(carac);
    }
    
private:
    vector<Produccion> producciones;
    set<char> terminales;    //conjunto de terminales
    set<char> variables;     //conjunto de variables
    
    bool is_lower(char caracter){
        return caracter >= 97 && caracter<=122;
    }
    bool is_upper(char caracter){
        return caracter >= 65 && caracter<=90;
    }
    
    void obtain_ter_var();
};

#endif /* GRAMATICA_H */

