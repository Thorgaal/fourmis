
#ifndef GRID_HPP
#define GRID_HPP
#include "EnsCoord.hpp"
#include "Coordonate.hpp"
#include "Case.hpp"
#include <vector>


int min(int a, int b);

class Grid{
    private:
        std::vector<Case> cases;
    public:
        Grid(int size);
        Case getCase(int col, int lig) const;

};

EnsCoord neighbor(Coordonate *c);
Coordonate randC(EnsCoord ens);




#endif


