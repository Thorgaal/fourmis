#ifndef COORDONATE_HPP
#define COORDONATE_HPP
#include <iostream>

class Coordonate{
    private:
        static constexpr int gridSize = 20;
        unsigned int x, y;

    public:
        Coordonate()= default;
        Coordonate(int lig,int col);
        int tailleGrille(); 
        int getX();
        int getY();

        

};
std::ostream& operator<<(std::ostream& out, Coordonate c);
bool operator==(Coordonate c1,Coordonate c2);
bool operator!=(Coordonate c1,Coordonate c2);
#endif