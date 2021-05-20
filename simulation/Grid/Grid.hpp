
#ifndef GRID_HPP
#define GRID_HPP
#include "EnsCoord.hpp"
#include "Coordonate.hpp"
#include "Case.hpp"
#include <vector>


int min(int a, int b);

bool isInG(int c,int l, int s);
EnsCoord neighbor(Coordonate *c);
Coordonate randC(EnsCoord ens);
float getMaxPhero(std::vector<Case> c); 
class Grid{
    private:
        std::vector<Case> cases;
        //side is for simplfy calculs
        int side;
        Case nest;
        int getId(Case c);
        
    public:
        //the side is the width and height
        Grid(int side);
        Case getCase(int col, int lig) const;
        void putCase(Case c);
        void linearisePheroN();    
        void evaporation(); 
        void setNest(Case nest);
        Case getNest() const;
        std::vector<Case> getCases() const;

};

void placeNest(Grid &g, EnsCoord c);
void placeSugar(Grid &g, EnsCoord c);
void placeAnts(Grid &g,std::vector<Ant *> a);
void iniGrid(Grid &g, EnsCoord coordN, EnsCoord coordS, std::vector<Ant *> a);




#endif


