#include "Coordoonees.hpp"
#include <iostream>


int Coordoonnees::tailleGrille(){
    return this->gridSize;
}


Coordoonnees::Coordoonnees(int col,int lig){
    if(lig<=this->gridSize && col <= this->gridSize){
            throw("You cannot create this coordonates because it is out of the grid");
    }
    this->x = col;
    this->y = lig;

}
int Coordoonnees::getX(){
    return this->x;
}
int Coordoonnees::getY(){
    return this->y;
}

std::ostream& operator<<(std::ostream& out, Coordoonnees c){
    out << "(" << c.getX() << "," << c.getY() <<")" << std::endl;
    return out;
}
bool operator==(Coordoonnees c1,Coordoonnees c2){
    return (c1.getX() == c2.getX() && c1.getY() == c2.getY());
}
bool operator !=(Coordoonnees c1,Coordoonnees c2){
    return (c1.getX() != c2.getX() && c1.getY() != c2.getY());
}