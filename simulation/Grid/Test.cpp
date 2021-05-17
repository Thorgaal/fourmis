#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"
#include <iostream>
#include "Coordonate.hpp"
#include <vector>
#include "EnsCoord.hpp"

TEST_CASE("Coordonate tests"){
    //test de l'asignation des valeurs
    Coordonate c = Coordonate{1,1};
    CHECK(c.getLig() == 1);
    CHECK(c.getCol() == 1);
    CHECK(c.getSize() == 20);
    //CHECK_THROWS_AS(Coordonate{1,0},std::exception);
    
    //test de ==, != et de <<
    CHECK(Coordonate{1,1} == Coordonate{1,1});
    CHECK_FALSE(Coordonate{1,1} != Coordonate{1,1});
    CHECK_FALSE(Coordonate{1,1} == Coordonate{1,2});
    CHECK(Coordonate{1,1} != Coordonate{1,2});
    CHECK_FALSE(Coordonate{1,1} == Coordonate{2,1});
    CHECK(Coordonate{1,1} != Coordonate{1,2});
    std::ostringstream ch;
    ch<<Coordonate{1,1};
    CHECK(ch.str() == "(1,1)");
    
    //test de la reasignation des valeurs
    Coordonate c1;
    c1 = c;
    CHECK(c1==c1);
    CHECK_FALSE(c!=c1); 
        
}
TEST_CASE("EnsCoord Test"){
    //test des fonctions
    EnsCoord ens1 = EnsCoord{std::vector<Coordonate>{Coordonate{1,2},Coordonate{2,2}}};
    CHECK(ens1.getElementById(0) == Coordonate{1,2});
    CHECK(ens1.getElementById(1) == Coordonate{2,2});
    
    
}