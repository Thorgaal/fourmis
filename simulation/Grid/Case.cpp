#include "Case.hpp"
#include "../Ant/Ant.hpp"
#include "Coordonate.hpp"
#include <vector>
#include <cstdlib>


Case::Case(Coordonate *c){
    this->ant = NULL;
    this->coord = c;
    this->sugar = false;
    this->phero = false;
}

Case::Case(Coordonate c, std::vector<bool> sP,Ant *a, Coordonate *c){
    if(sP.size() != 2) throw ValueError("You have to pass an vector of size 2");
    this->sugar = sP[0];
    this->phero = sP[1];
    this ant = a;
    this->coord = c;
}

bool Case::hasPhero(){
    return this->phero;
}
bool Case::hasSugar(){
    return this->sugar;
}

void Case::pSugar(){
    this->sugar = true;
}

void Case::pPhero(){
    this->phero = true;
}


bool Case::pOSugar(){
    if(this->sugar){
        this->sugar = false;
        return true;
    }
    return false;
}
bool Case::pOPhero(){
    if(this->phero){
        this->phero = false;
        return true;
    }
    return false;
}










