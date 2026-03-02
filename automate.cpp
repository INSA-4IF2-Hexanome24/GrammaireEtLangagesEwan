#include <algorithm>
#include "automate.h"

Automate::Automate(string chaine)
{
    lexer = new Lexer(chaine);

    Etat *etat0 = new Etat_0("etat0");
    statestack.push_back(etat0);
}

void Automate::analyse()
{
    bool nouvelEtat = true;
    while (nouvelEtat && statestack.back() != NULL)
    {
        // printStateStack();
        Symbole *symbole = lexer->Consulter();
        // symbole->Affiche();
        nouvelEtat = statestack.back()->Transition(*this, symbole);
    }
    cout << "Fin de lecture" << endl;
    if (*symbolstack.back() != ERREUR)
    {
        int resultat = symbolstack.back()->getValue();
        symbolstack.pop_back();
        cout << "Expression syntaxiquement correcte" << endl
             << "Résultat de l'analyse : " << resultat << endl;
    }
    else
    {
        cout << "Expression non correcte syntaxiquement : caractère invalide" << endl;
    }
}

void Automate::decalage(Symbole *s, Etat *e)
{
    symbolstack.push_back(s);
    statestack.push_back(e);
    lexer->Avancer();
}

void Automate::transitionSimple(Symbole *s, Etat *e)
{
    symbolstack.push_back(s);
    statestack.push_back(e);
}

void Automate::reduction(int n, Symbole *s)
{
    for (int i = 0; i < n; i++)
    {
        delete (statestack.back());
        statestack.pop_back();
    }
    statestack.back()->Transition(*this, s);
}

Expr *Automate::popSymbole()
{
    Expr *e = (Expr *)symbolstack.back();
    symbolstack.pop_back();
    return e;
}

void Automate::popAndDestroySymbole()
{
    delete symbolstack.back();
    symbolstack.pop_back();
}

void Automate::printStateStack()
{
    cout << "Contenu de statestack : ";
    for (auto it = statestack.rbegin(); it != statestack.rend(); ++it)
    {
        cout << (*it)->name << " ";
    }
    cout << endl;
}