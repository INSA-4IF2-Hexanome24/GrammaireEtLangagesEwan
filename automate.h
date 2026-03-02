using namespace std;

#ifndef GL_TP_H
#define GL_TP_H

#include <vector>
#include <string>

#include "symbole.h"
#include "lexer.h"
#include "Etat.h"

class Automate
{
public:
    Automate(string chaine);
    void analyse();
    void decalage(Symbole *s, Etat *e);
    void reduction(int n, Symbole *s);
    void transitionSimple(Symbole *s, Etat *e);
    void printStateStack();
    Expr *popSymbole();
    void popAndDestroySymbole();
    ~Automate();

protected:
    vector<Symbole *> symbolstack;
    vector<Etat *> statestack;

    Lexer *lexer;
};

#endif