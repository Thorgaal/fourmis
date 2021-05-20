#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"
#include <iostream>
#include "Coordonate.hpp"
#include <vector>
#include "EnsCoord.hpp"
#include "../Ants/Ant.hpp"
#include "Case.hpp"
#include "Grid.hpp"

TEST_CASE("Coordonate Test"){
    //Test of the assignement of the coordonates
    Coordonate c = Coordonate{1,1};
    CHECK(c.getLig() == 1);
    CHECK(c.getCol() == 1);
    CHECK(c.getSize() == 20);
    //CHECK_THROWS_AS(Coordonate{1,0},std::string);
    
    //Test of ==, != and <<
    CHECK(Coordonate{1,1} == Coordonate{1,1});
    CHECK_FALSE(Coordonate{1,1} != Coordonate{1,1});
    CHECK_FALSE(Coordonate{1,1} == Coordonate{1,2});
    CHECK(Coordonate{1,1} != Coordonate{1,2});
    CHECK_FALSE(Coordonate{1,1} == Coordonate{2,1});
    CHECK(Coordonate{1,1} != Coordonate{1,2});
    std::ostringstream ch;
    ch<<Coordonate{1,1};
    CHECK(ch.str() == "(1,1)"); 
    
    //Test of the reassignement of the coordonates
    Coordonate c1;
    c1 = c;
    CHECK(c1==c1);
    CHECK_FALSE(c!=c1); 
    
    //Test with big values
    Coordonate c2 = Coordonate{5,5,100};
    CHECK(c2.getSize() == 100);
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


TEST_CASE("Case Test"){
    Case Case1 = Case{Coordonate{1,2},false,NULL, false};
    
    //Test getters
    CHECK(Case1.hasSugar() == false);
    CHECK(Case1.getCoord() == Coordonate{1,2});
    CHECK(Case1.getPheroS() == 0);
    CHECK(Case1.getPheroN() == 0);
    CHECK(Case1.getAntId() == -1);
    CHECK(Case1.hasNest() == false);
    CHECK(Case1.isOnTheWayS() == false);
    Ant *antestp;
    antestp = NULL;
    CHECK(Case1.getAnt() == antestp);
    CHECK(Case1.getMaxPheroN() == 1);
    CHECK(Case1.isEmpty() == true);
    
    //Test setters and getters
    Case1.pSugar();
    CHECK(Case1.hasSugar() == true);
    CHECK(Case1.isEmpty() == false);
    Case1.pOSugar();
    CHECK(Case1.hasSugar() == false);
    
    Ant antest = Ant{Coordonate{1,2},4};
    antestp = &antest;
    Case1.addAnt(antestp);
    CHECK(Case1.isEmpty() == false);
    CHECK(Case1.getAntId() == 4);
    CHECK(Case1.getAnt() == antestp);
    Case1.pOAnt();
    CHECK(Case1.isEmpty() == true);
    CHECK(Case1.getAntId() == -1);
    antestp = NULL;
    CHECK(Case1.getAnt() == antestp);
    
    Case1.addNest();
    CHECK(Case1.hasNest() == true);
    CHECK(Case1.isEmpty() == false);
    
    Case1.pPheroN(0.75);
    CHECK(Case1.getPheroN() == 0.75);
    Case1.pPheroN(0);
    CHECK(Case1.getPheroN() == 0);
    
    Case1.addPheroS();
    CHECK(Case1.getPheroS() == 255);
    CHECK(Case1.isOnTheWayS() == true);
    Case1.evaporate();
    CHECK(Case1.getPheroS() < 255);
    
    Case1 = Case{Coordonate{1,2},false,NULL, false};
    antestp = &antest;
    Case Case2 = Case{Coordonate{2,2},false,antestp, false};
    Ant antest2 = Ant{Coordonate{2,2},3};
    CHECK_THROWS_AS(moveA(&antest2,&Case2,&Case1),std::string);
    moveA(&antest,&Case2,&Case1);
    CHECK(Case2.getAntId() == -1);
    CHECK(Case1.getAntId() == 4);
    
    Case Case3 = Case{Coordonate{1,4},false,antestp, false};
    CHECK_THROWS_AS(closerN(&Case1,&Case2,&Case3),std::string);
    Case3.addNest();
    CHECK(closerN(&Case1,&Case2,&Case3));
    CHECK_FALSE(closerN(&Case2,&Case1,&Case3));   
}


TEST_CASE("Grid Test"){
    //Test min
    CHECK(min(-1,1) == -1);
    CHECK(min(15,0) == 0);
    CHECK(min(1,1) == 1);
    
    //Test neighbor
    Coordonate *c;
    Coordonate cval = Coordonate{1,1};
    c = &cval;
    EnsCoord ensc = neighbor(c);
    CHECK(ensc.size() == 3);
    CHECK(ensc.in(Coordonate{1,2}));   
    CHECK(ensc.in(Coordonate{2,1}));
    CHECK(ensc.in(Coordonate{2,2}));
    
    cval = Coordonate{4,4,16};
    ensc = neighbor(c);
    CHECK(ensc.size() == 3);
    CHECK(ensc.in(Coordonate{3,3,16}));   
    CHECK(ensc.in(Coordonate{3,4,16}));
    CHECK(ensc.in(Coordonate{4,3,16}));
    //CHECK_FALSE(ensc.in(Coordonate{4,3}));
    
    cval = Coordonate{3,3};
    ensc = neighbor(c);
    CHECK(ensc.size() == 8);
    CHECK(ensc.in(Coordonate{2,2}));   
    CHECK(ensc.in(Coordonate{2,3}));
    CHECK(ensc.in(Coordonate{2,4}));
    CHECK(ensc.in(Coordonate{3,2}));   
    CHECK(ensc.in(Coordonate{3,4}));
    CHECK(ensc.in(Coordonate{4,2}));
    CHECK(ensc.in(Coordonate{4,3}));   
    CHECK(ensc.in(Coordonate{4,4}));
    
    //Test randC
    CHECK(ensc.in(randC(ensc)));   
    CHECK(ensc.in(randC(ensc))); 
    CHECK(ensc.in(randC(ensc)));
    
    //Test class Grid
    Grid gri = Grid(10);
    
    //Test placeNest and getCase
    placeNest(gri,EnsCoord{std::vector<Coordonate>{Coordonate{3,3,100},Coordonate{5,5,100}}});
    CHECK(gri.getCase(3,3).hasNest());
    CHECK(gri.getCase(5,5).hasNest());
    for(int x = 1; x<=5;x++){
        for(int y = 1; y<=5;y++){
            if(not((x == 3 && y == 3) || (x == 5 && y == 5))) CHECK_FALSE(gri.getCase(x,y).hasNest());
        }
    }
    
    //Test placeSugar and getCase
    placeSugar(gri,EnsCoord{std::vector<Coordonate>{Coordonate{2,3,100},Coordonate{4,5,100}}});
    CHECK(gri.getCase(2,3).hasSugar());
    CHECK(gri.getCase(4,5).hasSugar());
    for(int x = 1; x<=5;x++){
        for(int y = 1; y<=5;y++){
            if(not((x == 2 && y == 3) || (x == 4 && y == 5))) CHECK_FALSE(gri.getCase(x,y).hasSugar());
        }
    }
    
    //Test placeAnt and getCase
    Ant *pa1;
    Ant *pa2;
    Ant a1 = Ant{Coordonate{7,4,100},0};
    Ant a2 = Ant{Coordonate{3,6,100},1};
    pa1 = &a1;
    pa2 = &a2;
    placeAnts(gri,std::vector<Ant*>{pa1,pa2});
    CHECK(gri.getCase(7,4).getAntId() == 0);
    CHECK(gri.getCase(3,6).getAntId() == 1);
    for(int x = 1; x<=5;x++){
        for(int y = 1; y<=5;y++){
            if(not((x == 7 && y == 4) || (x == 3 && y == 6))) CHECK(gri.getCase(x,y).getAntId() == -1);
        }
    }
    
    //Test evaporation and putCase
    Case modifie1 = gri.getCase(6,7);
    Case modifie2 = gri.getCase(8,9);
    modifie1.addPheroS();
    modifie2.addPheroS();
    gri.putCase(modifie1);
    gri.putCase(modifie2);
    CHECK(gri.getCase(6,7).getPheroS() == 255);
    CHECK(gri.getCase(8,9).getPheroS() == 255);
    gri.evaporation();
    CHECK(gri.getCase(6,7).getPheroS() == 250);
    CHECK(gri.getCase(8,9).getPheroS() == 250);
    
    //Test constructeur
    gri = Grid(10); 
    for(int x = 1; x<=5;x++){
        for(int y = 1; y<=5;y++){
            CHECK_FALSE(gri.getCase(x,y).hasNest());
            CHECK_FALSE(gri.getCase(x,y).hasSugar());
            CHECK(gri.getCase(x,y).getAntId() == -1);
        }
    }
    
    //Test linearisePheroN
    placeNest(gri,EnsCoord{std::vector<Coordonate>{Coordonate{5,5,100}}});
    gri.linearisePheroN();
    for(int i = 0; i<4;i++) CHECK(gri.getCase(5-i,5).getPheroN() > gri.getCase(5-i-1,5).getPheroN());
    for(int i = 0; i<5;i++) CHECK(gri.getCase(5+i,5).getPheroN() > gri.getCase(5+i+1,5).getPheroN());
    for(int i = 0; i<4;i++) CHECK(gri.getCase(5,5-i).getPheroN() > gri.getCase(5,5-i-1).getPheroN());
    for(int i = 0; i<4;i++) CHECK(gri.getCase(5,5+i).getPheroN() > gri.getCase(5,5+i+1).getPheroN());
    
    //Test iniGrid
    gri = Grid(10);
    iniGrid(gri, EnsCoord{std::vector<Coordonate>{Coordonate{3,3,100},Coordonate{5,5,100}}},EnsCoord{std::vector<Coordonate>{Coordonate{2,3,100},Coordonate{4,5,100}}}, std::vector<Ant*>{pa1,pa2});
    CHECK(gri.getCase(3,3).hasNest());
    CHECK(gri.getCase(5,5).hasNest());
    for(int x = 1; x<=5;x++){
        for(int y = 1; y<=5;y++){
            if(not((x == 3 && y == 3) || (x == 5 && y == 5))) CHECK_FALSE(gri.getCase(x,y).hasNest());
        }
    }
    CHECK(gri.getCase(2,3).hasSugar());
    CHECK(gri.getCase(4,5).hasSugar());
    for(int x = 1; x<=5;x++){
        for(int y = 1; y<=5;y++){
            if(not((x == 2 && y == 3) || (x == 4 && y == 5))) CHECK_FALSE(gri.getCase(x,y).hasSugar());
        }
    }
    CHECK(gri.getCase(7,4).getAntId() == 0);
    CHECK(gri.getCase(3,6).getAntId() == 1);
    for(int x = 1; x<=5;x++){
        for(int y = 1; y<=5;y++){
            if(not((x == 7 && y == 4) || (x == 3 && y == 6))) CHECK(gri.getCase(x,y).getAntId() == -1);
        }
    }
}