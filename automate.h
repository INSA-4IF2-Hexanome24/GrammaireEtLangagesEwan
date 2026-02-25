#pragma once

#include <iostream>
#include <deque>
#include <map>
#include "symbole.h"

using namespace std;

struct ElementPile {
    Symbole* symbole;
    int etat;
    int valeur;
};

typedef std::deque<ElementPile> Pile;


typedef std::map<int, std::map<Symbole*, std::pair<char, int>>> Action;
typedef std::map<int, std::map<Symbole*, int>> Goto;



class Automate {
public:
    Automate() = default;
    virtual ~Automate() = default;

    bool AnalyseLALR(const Pile& mot,
                           const Action& action,
                           const Goto& go_to,
                           int etat_initial,
                           int& resultat);

protected:
};
