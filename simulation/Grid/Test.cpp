#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"
#include <iostream>
#include "Coordonate.hpp"
#include <vector>
#include "EnsCoord.hpp"
#include "../Ants/Ant.hpp"

TEST_CASE("Coordonate Test"){
    //test of the assignement of the coordonates
    Coordonate c = Coordonate{1,1};
    CHECK(c.getLig() == 1);
    CHECK(c.getCol() == 1);
    CHECK(c.getSize() == 20);
    //CHECK_THROWS_AS(Coordonate{1,0},std::exception);
    
    //test of ==, != and <<
    CHECK(Coordonate{1,1} == Coordonate{1,1});
    CHECK_FALSE(Coordonate{1,1} != Coordonate{1,1});
    CHECK_FALSE(Coordonate{1,1} == Coordonate{1,2});
    CHECK(Coordonate{1,1} != Coordonate{1,2});
    CHECK_FALSE(Coordonate{1,1} == Coordonate{2,1});
    CHECK(Coordonate{1,1} != Coordonate{1,2});
    std::ostringstream ch;
    ch<<Coordonate{1,1};
    CHECK(ch.str() == "(1,1)"); 
    
    //test of the reassignement of the coordonates
    Coordonate c1;
    c1 = c;
    CHECK(c1==c1);
    CHECK_FALSE(c!=c1); 
        
}


TEST_CASE("EnsCoord Test"){
    EnsCoord ens1 = EnsCoord{std::vector<Coordonate>{Coordonate{1,2},Coordonate{2,2}}};
    
    //test of getElementById and EnsCoord(std::vector<Coordonate>)
    CHECK(ens1.getElementById(0) == Coordonate{1,2}); 
    CHECK(ens1.getElementById(1) == Coordonate{2,2});
    
    //test getEns
    CHECK(ens1.getEns()[0] == Coordonate{1,2});
    CHECK(ens1.getEns()[1] == Coordonate{2,2});
    
    //test in
    CHECK(ens1.in(Coordonate{1,2}));  
    CHECK(ens1.in(Coordonate{2,2}));
    CHECK_FALSE(ens1.in(Coordonate{1,1}));
    CHECK_FALSE(ens1.in(Coordonate{4,4}));
    
    //test isEmpty
    CHECK_FALSE(ens1.isEmpty());
    
    //test size
    CHECK(ens1.size() == 2);
    
    //test add
    CHECK(ens1.add(Coordonate{1,3}));
    CHECK(ens1.getElementById(2) == Coordonate{1,3});
    CHECK(ens1.size() == 3);
    
    //test remove
    ens1.remove(Coordonate{1,2});
    CHECK(ens1.size() == 2);
    CHECK(ens1.getElementById(0) == Coordonate{2,2}); 
    CHECK(ens1.getElementById(1) == Coordonate{1,3});
}


TEST_CASE("Ant Test"){
    //test constructor, getCoord and getId
    Ant Ant1 = Ant{Coordonate{1,2},4};
    CHECK(Ant1.getCoord() == Coordonate{1,2});
    CHECK(Ant1.getId() == 4);
    
    //test wearSug, takeSugar and laySugar
    Ant1.takeSugar();
    CHECK(Ant1.wearSug() == true);
    Ant1.laySugar();
    CHECK(Ant1.wearSug() == false);
}