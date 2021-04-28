#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include <iostream>
#include "Coordonate.hpp"
#include <vector>
#include "EnsCoord.hpp"

TEST_CASE("Coordonate tests"){
    Coordonate c = Coordonate{0,0};
    CHECK(c.getX() == 0);
    CHECK(c.getY() == 0);
    Coordonate c1 = c, c2 = {2,1};
    CHECK(c==c1);
    CHECK(c!=c1);
    CHECK_FALSE(c == c2);
    CHECK_FALSE(c!=c1); 
}
TEST_CASE("EnsCoord Test"){
    std::vector<Coordonate> e = std::vector<Coordonate>(20*20);
    int step = 0;
    for(int i =0; i<e.size(); i++){
        e[i] = Coordonate{step,i};
        if(i%20==0) step++;
    }
    EnsCoord ens = EnsCoord{e};
    Coordonate c = Coordonate{0,0}, c1  = Coordonate{19,19}, c2 = Coordonate{14,12};
    CHECK((ens.in(c) && ens.in(c2) && ens.in(c2)));
    ens.remove(c);
    CHECK_FALSE(ens.in(c));
    CHECK(ens.add(c));
    CHECK(ens.in(c));   
    
}