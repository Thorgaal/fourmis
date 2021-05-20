#ifndef COORDONATE_HPP
#define COORDONATE_HPP
#include <iostream>

class Coordonate{
    /*
      this class is made to hold coordonates
    */
    private:
        int gridSize;
        unsigned int col, lig;

    public:
        Coordonate() = default;
        
        // constructor 
        Coordonate(int c,int l, int gSize=20);
    
        // gives the size of the grid
        int tailleGrille(); 
    
        //gives the ligne of the coordonates
        int getLig();
        //gives the columne of the coordonates
        int getCol();
        
        // gives the size of the grid
        int getSize() const;

        

};

//echo out the coordonates
std::ostream& operator<<(std::ostream& out, Coordonate c);
//return true if c1 and c2 are the same else false
bool operator==(Coordonate c1,Coordonate c2);
//return false if c1 and c2 are the same else true
bool operator!=(Coordonate c1,Coordonate c2);
#endif