
/*
 * File:   main.cpp
 * Author: juane
 *
 * Created on 12 December 2017, 10:32
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "Earley.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc == 2 || argc > 3) {
        cout << "Uso del programa: ./earley \"file_prods\" \"string_to_check\"" << endl;
        return 0;
    } else if (argc == 3) {
        string file_name= argv[1];
        string string_to_check= argv[2];

        Gramatica gram(file_name);
        Earley earley1(gram, string_to_check);

        if (earley1.parse())
            cout << "La palabra si pertenece al lenguaje\n";
        else
            cout << "La palabra no pertenece al lenguaje\n";

        return 0;
    } else if(argc==1){
        //GRAMATICA 1 DE PRUEBA

            Produccion p1("S>AB");
            Produccion p2("S>BC");
            Produccion p3("A>BA");
            Produccion p4("A>a");
            Produccion p5("B>CC");
            Produccion p6("B>b");
            Produccion p7("C>AB");
            Produccion p8("C>a");

            vector<Produccion> prods;

            prods.push_back(p1);
            prods.push_back(p2);
            prods.push_back(p3);
            prods.push_back(p4);
            prods.push_back(p5);
            prods.push_back(p6);
            prods.push_back(p7);
            prods.push_back(p8);

            Gramatica gram(prods);

            Earley earley1(gram, "baa");

        if (earley1.parse())
            cout << "La palabra si pertenece al lenguaje\n";
        else
            cout << "La palabra no pertenece al lenguaje\n";

        return 0;
    }
}
