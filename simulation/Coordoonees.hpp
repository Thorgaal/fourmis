#pragma once
#include <iostream>

class Coordoonnees{
    private:
        const int gridSize = 20;
        unsigned int x, y;

    public:
        int tailleGrille(); 
        Coordoonnees(int lig,int col);
        int getX();
        int getY();

        

};
std::ostream& operator<<(std::ostream& out, Coordoonnees c);
bool operator==(Coordoonnees c1,Coordoonnees c2);
bool operator!=(Coordoonnees c1,Coordoonnees c2);