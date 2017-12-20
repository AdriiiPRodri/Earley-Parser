
/* 
 * File:   Earley.cpp
 * Author: juane
 * 
 * Created on 12 December 2017, 11:32
 */

#include "Earley.h"

Earley::Earley(const Gramatica& g, const string& cad) {
    grammar = g;
    cadena = cad;


    for (auto ite = grammar.getVariables()->begin(); ite != grammar.getVariables()->end(); ++ite) {
        check_var.insert(std::make_pair(*ite, false));
    }

}

bool Earley::parse() {
    unsigned i = 0;
    
//     for (int i = 0; i < grammar.getProducciones().size(); i++) {
//            grammar.getProducciones()[i].imprimir();
//
//        }
//        
//        cout << cadena;
    
    initialization();

    do {
        clausure();

        //        cout << "clausura: \n";
        //        comprobar();
        for (auto it = check_var.begin(); it != check_var.end(); it++) {
            it->second = false;
        }

        if (advance()) {
            j++;
            //            cout << "advance: \n";
            //            comprobar();

            termination();
            //            cout << "terminacion: \n";

        } else {
            cout << "\nPASO " << (i++) + 1 << ": " << endl;
            comprobar();
            cout << "\n No se agregan registros en avance.." << endl;
            return 0;
        }

        cout << "\nPASO " << (i++) + 1 << ": " << endl;
        comprobar();
    } while (j < cadena.size());

    bool included = false;

    for (unsigned m = 0; m < registros[j].size() && !registros[j].empty() && !included; m++)
        included = (registros[j][m].getI() == 0 && registros[j][m].getJ() == cadena.size() && registros[j][m].getA() == "S" && registros[j][m].getBeta() == "");

    return included;
}

void Earley::initialization() {
    registros.resize(cadena.size() + 1);

    for (unsigned i = 0; i < grammar.getProducciones().size(); i++) {
        if (grammar.getProducciones()[i].parteIzq() == 'S')
            registros[0].push_back(Registro(0, 0, "S", "", grammar.getProducciones()[i].parteDer(), &grammar));
    }

    check_var.find('S')->second = true;
}

void Earley::clausure() {
    bool added = true;

    while (added) {
        added = false;
        char split_var;
        unsigned tamanio = registros[j].size();
        string aux;
        for (unsigned k = 0; k < tamanio; k++) {
            split_var = registros[j][k].splitVar();
            if (split_var != 'e' && check_var.find(split_var)->second == false) {
                aux = split_var;

                for (Produccion& prod : grammar.getProducciones())
                    if (prod.parteIzq() == split_var) {
                        added = true;
                        Registro reg(j, j, aux, "", prod.parteDer(), &grammar);

                        bool included = false;

                        //comprobamos si existe ya dicho registro en registros[j]
                        for (unsigned m = 0; m < registros[j].size() && !registros[j].empty() && !included; m++)
                            if (registros[j][m] == reg)
                                included = true;

                        if (!included) {
                            //cout << "clausurado: "; reg.imprimir(); cout << endl;
                            registros[j].push_back(reg);
                            check_var.find(split_var)->second = true;
                        }
                    }
            }
        }

        if (!added)
            return;

        auto it = check_var.begin();
        for (; it != check_var.end() && it->second == true; ++it)
            ;
        if (it == check_var.end())
            return;
    }
}

bool Earley::advance() {
    char split_ter;
    string aux;
    bool added = false;

    for (unsigned k = 0; k < registros[j].size(); k++) {
        split_ter = registros[j][k].splitTer();
        if (split_ter != 'e' && split_ter == cadena[j]) {
            aux = split_ter;
            string beta_aux = registros[j][k].getBeta();
            beta_aux.erase(beta_aux.begin());
            Registro reg(registros[j][k].getI(), j + 1, registros[j][k].getA(), registros[j][k].getAlfa() + aux, beta_aux, &grammar);

            registros[j + 1].push_back(reg);
            added = true;
        }
    }
    return added;
}

void Earley::termination() {
    unsigned cont, h, i;
    cont = h = i = 0;
    while (cont <= j + 1) {
        for (unsigned k = 0; k < registros[i].size(); k++) { //registros i
            if (registros[i][k].getI() == h && registros[i][k].getJ() == i) {
                // registros[i][k].imprimir();

                unsigned tope = registros[j].size();
                for (unsigned l = 0; l < tope; l++) { //registros j
                    if (registros[j][l].getI() == i) {
                        //registros[j][l].imprimir(); cout << endl;
                        char char_split_var;
                        string aux_split_var;

                        char_split_var = registros[i][k].splitVar();
                        aux_split_var = char_split_var;

                        if (aux_split_var == registros[j][l].getA() && registros[j][l].getBeta().empty()) {
                            string beta_aux = registros[i][k].getBeta();
                            beta_aux.erase(beta_aux.begin());
                            Registro reg(h, j, registros[i][k].getA(), registros[i][k].getAlfa() + registros[j][l].getA(), beta_aux, &grammar);

                            //reg.imprimir();
                            bool included = false;

                            for (unsigned m = 0; m < registros[j].size() && !registros[j].empty() && !included; m++)
                                if (registros[j][m] == reg)
                                    included = true;
                            if (!included) {
                                registros[j].push_back(reg);
                            }
                        }
                    }
                }
            }
        }
        if (h < i)
            h++;
        else if (i + 1 == j) {
            i = h = 0;
            cont++;
        } else if (h == i) {
            h = 0;
            i++;
        }
    }
}

void Earley::comprobar() const {
    for (unsigned i = 0; i < registros.size(); i++) {
        cout << "j: " << i << "\n";
        for (unsigned j = 0; j < registros[i].size(); j++)
            registros[i][j].imprimir();
    }
}

