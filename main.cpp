#include <iostream>
#include <algorithm>

#include "automate.h"
#include "lexer.h"

using namespace std;

int main() {
    string chaine = "(1+34)*123";
    Lexer l(chaine);


    Automate *automate = new Automate(chaine);
    automate->analyse();

    return 0;
}
