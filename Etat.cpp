#include "Etat.h"
#include "automate.h"

void Etat::Afficher(Symbole *symbole)
{
    cout << name << " | Symbole: ";
    symbole->Affiche();
    cout << endl;
}

bool Etat_0::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case EXPR:
    {
        // automate.printStateStack();
        automate.transitionSimple(symbole, new Etat_1("etat_1"));
        // automate.printStateStack();
        break;
    }
    case OPENPAR:
    {
        automate.decalage(symbole, new Etat_2("etat_2"));
        break;
    }
    case INT:
    {
        automate.decalage(symbole, new Etat_3("etat_3"));
        break;
    }
    default:
    {
        AfficherErreur();
        return false;
    }
    }
    return true;
}

bool Etat_1::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case PLUS:
    {
        automate.decalage(symbole, new Etat_4("etat_4"));
        break;
    }
    case MULT:
    {
        automate.decalage(symbole, new Etat_5("etat_5"));
        break;
    }
    case FIN:
    {
        return false;
    }
    default:
    {
        AfficherErreur();
        return false;
    }
    }

    return true;
}

bool Etat_2::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case OPENPAR:
    {
        automate.decalage(symbole, new Etat_2("etat_2"));
        break;
    }
    case INT:
    {
        automate.decalage(symbole, new Etat_3("etat_3"));
        break;
    }
    case EXPR:
    {
        automate.transitionSimple(symbole, new Etat_6("etat_6"));
        break;
    }
    default:
    {
        AfficherErreur();
        return false;
    }
    }

    return true;
}

bool Etat_3::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case PLUS:
    {
        Expr *s1 = automate.popSymbole();
        automate.reduction(1, new Expr(s1->getValue()));
        break;
    }
    case MULT:
    {
        Expr *s1 = automate.popSymbole();
        automate.reduction(1, new Expr(s1->getValue()));
        break;
    }
    case CLOSEPAR:
    {
        Expr *s1 = automate.popSymbole();
        automate.reduction(1, new Expr(s1->getValue()));
        break;
    }
    case FIN:
    {
        Expr *s1 = automate.popSymbole();
        automate.reduction(1, new Expr(s1->getValue()));
        break;
    }
    default:
    {
        AfficherErreur();
        return false;
    }
    }

    return true;
}

bool Etat_4::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case CLOSEPAR:
    {
        automate.decalage(symbole, new Etat_2("etat_2"));
        break;
    }
    case INT:
    {
        automate.decalage(symbole, new Etat_3("etat_3"));
        break;
    }
    case EXPR:
    {
        automate.transitionSimple(symbole, new Etat_7("etat_7"));
        break;
    }
    default:
    {
        AfficherErreur();
        return false;
    }
    }

    return true;
}

bool Etat_5::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case OPENPAR:
    {
        automate.decalage(symbole, new Etat_2("etat_2"));
        break;
    }
    case INT:
    {
        automate.decalage(symbole, new Etat_3("etat_3"));
        break;
    }
    case EXPR:
    {
        automate.transitionSimple(symbole, new Etat_8("etat_8"));
        break;
    }
    default:
    {
        AfficherErreur();
        return false;
    }
    }

    return true;
}

bool Etat_6::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case PLUS:
    {
        automate.decalage(symbole, new Etat_4("etat_4"));
        break;
    }
    case MULT:
    {
        automate.decalage(symbole, new Etat_5("etat_5"));
        break;
    }
    case CLOSEPAR:
    {
        automate.decalage(symbole, new Etat_9("etat_9"));
        break;
    }
    default:
    {
        AfficherErreur();
        return false;
    }
    }

    return true;
}

bool Etat_7::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case PLUS:
    {
        Expr *s1 = automate.popSymbole();
        automate.popAndDestroySymbole();
        Expr *s2 = automate.popSymbole();
        automate.reduction(3, new Expr(s2->getValue() + s1->getValue()));
        break;
    }
    case MULT:
    {
        automate.decalage(symbole, new Etat_5("etat_5"));
        break;
    }
    case CLOSEPAR:
    {
        Expr *s1 = automate.popSymbole();
        automate.popAndDestroySymbole();
        Expr *s2 = automate.popSymbole();
        automate.reduction(3, new Expr(s2->getValue() + s1->getValue()));
        break;
    }
    case FIN:
    {
        Expr *s1 = automate.popSymbole();
        automate.popAndDestroySymbole();
        Expr *s2 = automate.popSymbole();
        automate.reduction(3, new Expr(s2->getValue() + s1->getValue()));
        break;
    }
    default:
    {
        AfficherErreur();
        return false;
    }
    }

    return true;
}

bool Etat_8::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case PLUS:
    {
        Expr *s1 = automate.popSymbole();
        automate.popAndDestroySymbole();
        Expr *s2 = automate.popSymbole();
        automate.reduction(3, new Expr(s2->getValue() * s1->getValue()));
        break;
    }
    case MULT:
    {
        Expr *s1 = automate.popSymbole();
        automate.popAndDestroySymbole();
        Expr *s2 = automate.popSymbole();
        automate.reduction(3, new Expr(s2->getValue() * s1->getValue()));
        break;
    }
    case CLOSEPAR:
    {
        Expr *s1 = automate.popSymbole();
        automate.popAndDestroySymbole();
        Expr *s2 = automate.popSymbole();
        automate.reduction(3, new Expr(s2->getValue() * s1->getValue()));
        break;
    }
    case FIN:
    {
        Expr *s1 = automate.popSymbole();
        automate.popAndDestroySymbole();
        Expr *s2 = automate.popSymbole();
        automate.reduction(3, new Expr(s2->getValue() * s1->getValue()));
        break;
    }
    default:
    {
        AfficherErreur();
        return false;
    }
    }

    return true;
}

bool Etat_9::Transition(Automate &automate, Symbole *symbole)
{
    switch (*symbole)
    {
    case PLUS:
    {
        automate.popAndDestroySymbole();
        Expr *s1 = automate.popSymbole();
        automate.popAndDestroySymbole();
        automate.reduction(3, new Expr(s1->getValue()));
        break;
    }
    case MULT:
    {
        automate.popAndDestroySymbole();
        Expr *s1 = automate.popSymbole();
        automate.popAndDestroySymbole();
        automate.reduction(3, new Expr(s1->getValue()));
        break;
    }
    case CLOSEPAR:
    {
        automate.popAndDestroySymbole();
        Expr *s1 = automate.popSymbole();
        automate.popAndDestroySymbole();
        automate.reduction(3, new Expr(s1->getValue()));
        break;
    }
    case FIN:
    {
        automate.popAndDestroySymbole();
        Expr *s1 = automate.popSymbole();
        automate.popAndDestroySymbole();
        automate.reduction(3, new Expr(s1->getValue()));
        break;
    }
    default:
    {
        AfficherErreur();
        return false;
    }
    }
    return true;
}