#include <iostream>
#include "lexer.h"
#include "automate.h"

using namespace std;

/// Fonction pour initialiser les tables Action et Goto
void InitialiserTables(Action& action, Goto& go_to) {
    // Création des symboles
    Symbole* PLUS_  = new Symbole(PLUS);
    Symbole* MULT_  = new Symbole(MULT);
    Symbole* OPEN_  = new Symbole(OPENPAR);
    Symbole* CLOSE_ = new Symbole(CLOSEPAR);
    Symbole* VAL_   = new Symbole(INT); // non-terminal E utilise INT comme clé
    Symbole* FIN_   = new Symbole(FIN);

    // Etat 0
      action[0][VAL_]   = {'s', 3}; 
      action[0][OPEN_]  = {'s', 2};

    // Etat 1
      action[1][PLUS_]  = {'s', 4}; 
      action[1][MULT_]  = {'s', 5}; 
      action[1][FIN_]   = {'a', 0};

    // Etat 2
      action[2][VAL_]  = {'s', 3}; 
      action[2][OPEN_]  = {'s', 2};

    // Etat 3
      action[3][PLUS_]  = {'r', 5};
      action[3][MULT_]  = {'r', 5};
      action[3][CLOSE_] = {'r', 5};
      action[3][FIN_]   = {'r', 5};

   // Etat 4
      action[4][VAL_]  = {'s', 3};
      action[4][OPEN_]  = {'s', 2};
   
   // Etat 5
      action[5][VAL_]  = {'s', 3};
      action[5][OPEN_]  = {'s', 2};
   
   // Etat 6
      action[6][PLUS_]  = {'s', 4};
      action[6][MULT_]  = {'s', 5};
      action[6][CLOSE_] = {'s', 9};
   
   // Etat 7
      action[7][PLUS_]  = {'r', 2};
      action[7][MULT_]  = {'s', 5};
      action[7][CLOSE_] = {'r', 2};
      action[7][FIN_]   = {'r', 2};
   
   // Etat 8
      action[8][PLUS_]  = {'r', 3};
      action[8][MULT_]  = {'r', 3};
      action[8][CLOSE_] = {'r', 3};
      action[8][FIN_]   = {'r', 3};
   
   // Etat 9
      action[9][PLUS_]  = {'r', 4};
      action[9][MULT_]  = {'r', 4};
      action[9][CLOSE_] = {'r', 4};
      action[9][FIN_]   = {'r', 4};

   // Exemple simplifié de table Goto
      go_to[0][VAL_]   = 1; 
      go_to[0][OPEN_]  = 1;
      go_to[2][VAL_]   = 6;
      go_to[2][OPEN_]  = 6;
      go_to[4][VAL_]   = 7;
      go_to[4][OPEN_]  = 7;
      go_to[5][VAL_]   = 8;
      go_to[5][OPEN_]  = 8;
}
int main(void) {
   string chaine("(1+34)*123");

   Lexer l(chaine);
   Pile mot;

   Symbole * s;
   while(*(s=l.Consulter())!=FIN) {
      s->Affiche();
      cout<<endl;
      l.Avancer();
   }
   return 0;
}




// int main() {
//     string chaine = "(1+34)*123";
//     Lexer l(chaine);

//     Pile mot;
//     Symbole* s;
//     while (*(s = l.Consulter()) != FIN) {;
      
//         mot.push_back({s, 0, 0});
//         l.Avancer();
//     }
//     mot.push_back({new Symbole(FIN), 0, 0});

//     Automate autoLALR;
//     Action action;
//     Goto go_to;

//     // Initialisation des tables
//     InitialiserTables(action, go_to);

//     int resultat;;
//     if (autoLALR.AnalyseLALR(mot, action, go_to, 0, resultat)) {
//         cout << "Résultat = " << resultat << endl;
//     } else {
//         cout << "Expression invalide !" << endl;
//     }

//     return 0;
// }
