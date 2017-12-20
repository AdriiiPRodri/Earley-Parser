
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
    /*if (argc == 2 || argc > 3) {
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
    } else if(argc==1){*/
        //GRAMATICA 1 DE PRUEBA

        //    Produccion p1("S>AB");
        //    Produccion p2("S>BC");
        //    Produccion p3("A>BA");
        //    Produccion p4("A>a");
        //    Produccion p5("B>CC");
        //    Produccion p6("B>b");
        //    Produccion p7("C>AB");
        //    Produccion p8("C>a");
        //
        //    vector<Produccion> prods;
        //
        //    prods.push_back(p1);
        //    prods.push_back(p2);
        //    prods.push_back(p3);
        //    prods.push_back(p4);
        //    prods.push_back(p5);
        //    prods.push_back(p6);
        //    prods.push_back(p7);
        //    prods.push_back(p8);
        //
        //    Gramatica gram(prods);
        //
        //    Earley earley1(gram, "baa");


        //GRAMATICA 2 DE PRUEBA

        //    Produccion p1("S>T");
        //    Produccion p2("S>S+T");
        //    Produccion p3("T>F");
        //    Produccion p4("T>T*F");
        //    Produccion p5("F>a");
        //    Produccion p6("F>b");
        //    Produccion p7("F>(S)");
        //
        //    vector<Produccion> prods;
        //
        //    prods.push_back(p1);
        //    prods.push_back(p2);
        //    prods.push_back(p3);
        //    prods.push_back(p4);
        //    prods.push_back(p5);
        //    prods.push_back(p6);
        //    prods.push_back(p7);
        //
        //
        //    Gramatica gram(prods);
        //        
        //    Earley earley1(gram, "(a+b)*a+a*b");

        //

        //    Produccion p1("S>U");
        //    Produccion p3("S>V");
        //    Produccion p4("U>TaU");
        //    Produccion p5("U>TaT");
        //    Produccion p6("U>UaT");
        //    Produccion p7("V>TbV");
        //    Produccion p8("V>TbT");
        //    Produccion p9("V>VbT");
        //    Produccion p10("T>aTbT");
        //    Produccion p11("T>bTaT");
        //    Produccion p12("T>z");
        //
        //    vector<Produccion> prods;
        //
        //    prods.push_back(p1);
        //    prods.push_back(p3);
        //    prods.push_back(p4);
        //    prods.push_back(p5);
        //    prods.push_back(p6);
        //    prods.push_back(p7);
        //    prods.push_back(p8);
        //    prods.push_back(p9);
        //    prods.push_back(p10);
        //    prods.push_back(p11);
        //    prods.push_back(p12);
        //
        //    Gramatica gram(prods);
        //        
        //    Earley earley1(gram, "azbzbzbz");




        //        Produccion p1("S>AA");
        //    Produccion p2("A>AAA");
        //    Produccion p3("A>a");
        //    Produccion p4("A>b");
        //
        //    vector<Produccion> prods;
        //
        //    prods.push_back(p1);
        //    prods.push_back(p2);
        //    prods.push_back(p3);
        //    prods.push_back(p4);
        //
        //    Gramatica gram(prods);
        //        
        //    Earley earley1(gram, "aaaab");




        //    Produccion p1("S>S+M");
        //    Produccion p2("S>M");
        //    Produccion p3("S>P");
        //    Produccion p4("M>M*T");
        //    Produccion p5("P>Q");
        //    Produccion p6("Q>M/P");
        //    Produccion p7("M>T");
        //    Produccion p8("T>2");
        //    Produccion p9("Q>3");
        //
        //    vector<Produccion> prods;
        //
        //    prods.push_back(p1);
        //    prods.push_back(p2);
        //    prods.push_back(p3);
        //    prods.push_back(p4);
        //    prods.push_back(p5);
        //    prods.push_back(p6);
        //    prods.push_back(p7);
        //    prods.push_back(p8);
        //    prods.push_back(p9);
        //
        //    Gramatica gram(prods);
        //        
        //    Earley earley1(gram, "2/3+2");




        //    Produccion p1("S>A");
        //    Produccion p3("S>B");
        //    Produccion p4("A>LaL");
        //    Produccion p5("A>LaA");
        //    Produccion p6("B>LbL");
        //    Produccion p7("B>LbB");
        //    Produccion p8("L>aLbL");
        //    Produccion p9("L>bLaL");
        //    Produccion p10("L>c");
        //
        //    vector<Produccion> prods;
        //
        //    prods.push_back(p1);
        //    prods.push_back(p3);
        //    prods.push_back(p4);
        //    prods.push_back(p5);
        //    prods.push_back(p6);
        //    prods.push_back(p7);
        //    prods.push_back(p8);
        //    prods.push_back(p9);
        //    prods.push_back(p10);
        //
        //    Gramatica gram(prods);
        //        
        //    Earley earley1(gram, "acbcaacbc");

        //    Produccion p1("S>bDD");
        //    Produccion p3("S>Ca");
        //    Produccion p4("S>bc");
        //    Produccion p5("A>B");
        //    Produccion p6("A>aCC");
        //    Produccion p7("A>baD");
        //    Produccion p8("B>cBD");
        //    Produccion p9("B>h");
        //    Produccion p10("B>AC");
        //    Produccion p11("C>bD");
        //    Produccion p12("C>aBA");
        //    Produccion p13("D>CD");
        //    Produccion p14("D>a");
        //
        //    vector<Produccion> prods;
        //
        //    prods.push_back(p1);
        //    prods.push_back(p3);
        //    prods.push_back(p4);
        //    prods.push_back(p5);
        //    prods.push_back(p6);
        //    prods.push_back(p7);
        //    prods.push_back(p8);
        //    prods.push_back(p9);
        //    prods.push_back(p10);
        //    prods.push_back(p11);
        //    prods.push_back(p12);
        //    prods.push_back(p13);
        //    prods.push_back(p14);
        //
        //    Gramatica gram(prods);
        //        
        //    Earley earley1(gram, "baa");

        Produccion p1("S>AaB");
        Produccion p3("S>AaC");
        Produccion p5("A>Ab");
        Produccion p6("A>Ac");
        Produccion p7("A>b");
        Produccion p8("A>c");
        Produccion p9("B>BdC");
        Produccion p10("B>0");
        Produccion p11("C>CeB");
        Produccion p12("C>1");

        vector<Produccion> prods;

        prods.push_back(p1);
        prods.push_back(p3);
        prods.push_back(p5);
        prods.push_back(p6);
        prods.push_back(p7);
        prods.push_back(p8);
        prods.push_back(p9);
        prods.push_back(p10);
        prods.push_back(p11);
        prods.push_back(p12);

        Gramatica gram(prods);

        Earley earley1(gram, "bba0d1");
        
        if (earley1.parse())
            cout << "La palabra si pertenece al lenguaje\n";
        else
            cout << "La palabra no pertenece al lenguaje\n";
        
        return 0;
    //}
}

