
/* 
 * File:   Gramatica.cpp
 * Author: juane
 * 
 * Created on 12 December 2017, 11:07
 */

#include "Gramatica.h"
#include <fstream>

Gramatica::Gramatica(const vector<Produccion>& producciones_p) {
    producciones = producciones_p;

    obtain_ter_var();
}

Gramatica::Gramatica(const string& name_file) {
    string prod;
    ifstream file;
    file.open(name_file);

    if (file.is_open()) {
        while (getline(file, prod)) {
            Produccion prod_aux(prod);
            producciones.push_back(prod_aux);
        }

        file.close();
        cout << "Gramatica leida correctamente..\n";
        obtain_ter_var();
    } else
        cout << "Error al leer el archivo..\n";
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

void Gramatica::add(string prod) {
    producciones.push_back(prod);
}

void Gramatica::remove(string prod) {
    auto it = producciones.begin();
    Produccion prod_aux(prod);
    for (unsigned i = 0; i < producciones.size(); i++)
        if (producciones[i] == prod_aux)
            it += i;
    producciones.erase(it);
}

