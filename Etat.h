#pragma once

#include <string>
#include <iostream>
#include "symbole.h"
using namespace std;

class Automate;

class Etat
{
public:
    Etat(const string &nom) : name(nom) {}
    virtual ~Etat() {}

    void Afficher(Symbole *symbole);
    void AfficherErreur() { cout << "Caractère non reconnu" << endl; }
    virtual bool Transition(Automate &automate, Symbole *symbole) = 0;
    string name;

protected:
};

class Etat_0 : public Etat
{
public:
    Etat_0(const string &nom) : Etat(nom) {}
    ~Etat_0() {}

    bool Transition(Automate &automate, Symbole *symbole);
};

class Etat_1 : public Etat
{
public:
    Etat_1(const string &nom) : Etat(nom) {}
    ~Etat_1() {}

    bool Transition(Automate &automate, Symbole *symbole);
};

class Etat_2 : public Etat
{
public:
    Etat_2(const string &nom) : Etat(nom) {}
    ~Etat_2() {}

    bool Transition(Automate &automate, Symbole *symbole);
};

class Etat_3 : public Etat
{
public:
    Etat_3(const string &nom) : Etat(nom) {}
    ~Etat_3() {}

    bool Transition(Automate &automate, Symbole *symbole);
};

class Etat_4 : public Etat
{
public:
    Etat_4(const string &nom) : Etat(nom) {}
    ~Etat_4() {}

    bool Transition(Automate &automate, Symbole *symbole);
};

class Etat_5 : public Etat
{
public:
    Etat_5(const string &nom) : Etat(nom) {}
    ~Etat_5() {}

    bool Transition(Automate &automate, Symbole *symbole);
};

class Etat_6 : public Etat
{
public:
    Etat_6(const string &nom) : Etat(nom) {}
    ~Etat_6() {}

    bool Transition(Automate &automate, Symbole *symbole);
};

class Etat_7 : public Etat
{
public:
    Etat_7(const string &nom) : Etat(nom) {}
    ~Etat_7() {}

    bool Transition(Automate &automate, Symbole *symbole);
};

class Etat_8 : public Etat
{
public:
    Etat_8(const string &nom) : Etat(nom) {}
    ~Etat_8() {}

    bool Transition(Automate &automate, Symbole *symbole);
};

class Etat_9 : public Etat
{
public:
    Etat_9(const string &nom) : Etat(nom) {}
    ~Etat_9() {}

    bool Transition(Automate &automate, Symbole *symbole);
};