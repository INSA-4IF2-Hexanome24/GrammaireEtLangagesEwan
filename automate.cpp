#include "automate.h"



bool Automate::AnalyseLALR(const Pile& mot, const Action& action, const Goto& go_to, int etat_initial, int& resultat) {
    Pile pile;
    pile.push_back({new Symbole(FIN), etat_initial, 0});
    
    Pile entree = mot;
    entree.push_back({new Symbole(FIN), 0, 0});

    while (!entree.empty()) {
        ElementPile sommet = pile.back();
        cout << sommet.etat << " Symbole:" << *(sommet.symbole) << " | ";
        Symbole* a = entree.front().symbole;

        auto it = action.find(sommet.etat);
        if (it == action.end()) return false;

        auto jt = it->second.find(a);
        if (jt == it->second.end()) return false;

        char type = jt->second.first; // 's', 'r', 'a'
        int num = jt->second.second;

        if (type == 's') { // shift
            int val = 0;
            if (Entier* e = dynamic_cast<Entier*>(a)) val = e->getValeur();
            pile.push_back({a, num, val});
            entree.pop_front();
        } else if (type == 'r') { // reduce
            // dépiler selon la règle num
            int val = 0;
            switch(num) {
                case 2: // E -> E + E
                    {
                        ElementPile right = pile.back(); pile.pop_back();
                        pile.pop_back(); // enlever '+'
                        ElementPile left = pile.back(); pile.pop_back();
                        val = left.valeur + right.valeur;
                    }
                    break;
                case 3: // E -> E * E
                    {
                        ElementPile right = pile.back(); pile.pop_back();
                        pile.pop_back(); // enlever '*'
                        ElementPile left = pile.back(); pile.pop_back();
                        val = left.valeur * right.valeur;
                    }
                    break;
                case 4: // E -> ( E )
                    {
                        pile.pop_back(); // ')'
                        ElementPile middle = pile.back(); pile.pop_back();
                        pile.pop_back(); // '('
                        val = middle.valeur;
                    }
                    break;
                case 5: // E -> val
                    {
                        ElementPile e = pile.back(); pile.pop_back();
                        val = e.valeur;
                    }
                    break;
                default:
                    break;
            }

            
            Symbole* E_sym = new Symbole(INT); // clé pour goto
            auto it = go_to.find(pile.back().etat);
            if (it == go_to.end()) return false; // pas de transition
            auto jt = it->second.find(E_sym);
            if (jt == it->second.end()) return false;

            int etat_suivant = jt->second;
            pile.push_back({E_sym, etat_suivant, val});

            pile.push_back({new Symbole(INT), etat_suivant, val});
        } else if (type == 'a') {
            resultat = pile.back().valeur;
            return true;
        }
    }
    return false;
}
