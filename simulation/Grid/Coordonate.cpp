#include "Coordonate.hpp"
#include <iostream>

//Creating the coordonate verifying that it is in the grid
Coordonate::Coordonate(int col,int lig){

    if(lig>=this->gridSize && col >= this->gridSize){
            throw("You cannot create this Coordinate because it is out of the grid");
    }else if(lig<0 && col <0){
        throw("You cannot create negative coordinates");
    }
    this->x = col;
    this->y = lig;

}
int Coordonate::tailleGrille(){
    return this->gridSize;
}


int Coordonate::getLig(){
    return this->lig;
}
int Coordonate::getCol(){
    return this->Col;
}

std::ostream& operator<<(std::ostream& out, Coordonate c){
    out << "(" << c.getX() << "," << c.getY() <<")" << std::endl;
    return out;
}
bool operator==(Coordonate c1,Coordonate c2){
    return (c1.getX() == c2.getX() && c1.getY() == c2.getY());
}
bool operator !=(Coordonate c1,Coordonate c2){
    return (c1.getX() != c2.getX() && c1.getY() != c2.getY());
}