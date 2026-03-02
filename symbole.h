#pragma once

#include <string>
using namespace std;

enum Identificateurs
{
   EXPR,
   OPENPAR,
   CLOSEPAR,
   PLUS,
   MULT,
   INT,
   FIN,
   ERREUR
};

const string Etiquettes[] = {"EXPR", "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR"};

class Symbole
{
public:
   Symbole(int i) : ident(i) {}
   virtual ~Symbole() {}

   operator int() const { return ident; }
   virtual void Affiche();
   virtual int getValue();

protected:
   int ident;
};

class Expr : public Symbole
{
public:
   Expr(int val) : Symbole(EXPR), valeur(val) {}
   ~Expr() {}

   virtual void Affiche();
   int getValue();
   int valeur;
};

class Openpar : public Symbole
{
public:
   Openpar() : Symbole(OPENPAR) {}
   ~Openpar() {}

   virtual void Affiche();
};

class Closepar : public Symbole
{
public:
   Closepar() : Symbole(CLOSEPAR) {}
   ~Closepar() {}

   virtual void Affiche();
};

class Plus : public Symbole
{
public:
   Plus() : Symbole(PLUS) {}
   ~Plus() {}

   virtual void Affiche();
};

class Mult : public Symbole
{
public:
   Mult() : Symbole(MULT) {}
   ~Mult() {}

   virtual void Affiche();
};

class Int : public Symbole
{
public:
   Int(int v) : Symbole(INT), valeur(v) {}
   ~Int() {}

   virtual void Affiche();
   int eval() { return valeur; }
   int getValue();

protected:
   int valeur;
};

class Fin : public Symbole
{
public:
   Fin() : Symbole(FIN) {}
   ~Fin() {}

   virtual void Affiche();
};

class Erreur : public Symbole
{
public:
   Erreur() : Symbole(ERREUR) {}
   ~Erreur() {}

   virtual void Affiche();
};