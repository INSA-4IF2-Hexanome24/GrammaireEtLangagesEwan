#pragma once

#include <deque>
#include <string>

using namespace std;
#include "symbole.h"

typedef deque<Symbole*> Pile;


struct Etat {
    Pile pile;
    Pile alire;
};

class Automate {
   public:
      Automate() { }
      virtual ~Automate() { }



   protected:
      
};

