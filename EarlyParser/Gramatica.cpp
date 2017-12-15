/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Gramatica.cpp
 * Author: juane
 * 
 * Created on 12 December 2017, 11:07
 */

#include "Gramatica.h"

Gramatica::Gramatica(const vector<Produccion>& producciones_p) {
    producciones=producciones_p;
    
//    for(unsigned i=0; i<producciones_p.size(); i++)
//        producciones_p[i].imprimir();
//    
    obtain_ter_var();
}

void Gramatica::obtain_ter_var() {
    char caracter;
    string parte;
    for (unsigned i = 0; i < producciones.size(); i++) {
        //parte izquierda
        variables.insert(producciones[i].parteIzq());
        
        //parte derecha
        parte = producciones[i].parteDer();
        for (unsigned j = 0; j < parte.size(); j++) {
            if (!is_upper(caracter = parte[j]))
                terminales.insert(caracter);
        }
    }
}
