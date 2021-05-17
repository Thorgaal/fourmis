#include "Coordonate.hpp"
#include <iostream>
#include <cmath>

//Creating the coordonate verifying that it is in the grid
Coordonate::Coordonate(int c,int l, int gSizes){
    this->gridSize = gSizes;
    if(l>sqrt(this->gridSize) || c > sqrt(this->gridSize)){
             throw("You cannot create this Coordinate because it is out of the grid");
    }else if(c<1 || l <1){
        throw("You cannot create  coordinates under (1,1)");
    }else{
        this->col = c;
        this->lig  = l;
    }
}
int Coordonate::tailleGrille(){
    return this->gridSize;
}


int Coordonate::getLig(){
    return this->lig;
}
int Coordonate::getCol(){
    return this->col;
}



int Coordonate::getSize() const{
    return this->gridSize;
}

std::ostream& operator<<(std::ostream& out, Coordonate c){
    out << "(" << c.getCol() << "," << c.getLig() <<")";
    return out;
}
bool operator ==(Coordonate c1,Coordonate c2){
    return (c1.getCol() == c2.getCol() && c1.getLig() == c2.getLig());
}
bool operator !=(Coordonate c1,Coordonate c2){
    return (c1.getCol() != c2.getCol() || c1.getLig() != c2.getLig());
}