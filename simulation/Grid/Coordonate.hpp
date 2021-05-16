#ifndef COORDONATE_HPP
#define COORDONATE_HPP
#include <iostream>

class Coordonate{
    private:
        int gridSize;
        unsigned int col, lig;

    public:
        Coordonate() = default;
        Coordonate(int l,int c, int gSize =20);
        int tailleGrille(); 
        int getLig();
        int getCol();
        int getSize() const;

        

};
std::ostream& operator<<(std::ostream& out, Coordonate c);
bool operator==(Coordonate c1,Coordonate c2);
bool operator!=(Coordonate c1,Coordonate c2);
#endif