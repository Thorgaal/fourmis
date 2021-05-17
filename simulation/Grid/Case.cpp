#include "Case.hpp"
#include "../Ants/Ant.hpp"
#include "Coordonate.hpp"
#include <vector>
#include <cstdlib>
#include <cmath>

Case::Case(Coordonate c){
    this->ant = NULL;
    this->coord = c;
    this->sugar = false;
    this->pheroS = 0;
    this->nest = false;
    this->pheroN = 0;
}

Case::Case(Coordonate c, bool s,Ant *a, bool n){
    this->sugar = s;
    this->ant = a;
    this->coord = c;
    this->nest = n;
    this->pheroN = 0;
    this->pheroS = 0;

}



Coordonate Case::getCoord() const{
    return this->coord;
}


int Case::getPheroS() const{
    return this->pheroS;
}

float Case::getPheroN() const{
    return this->pheroN;
}

int Case::getAntId() const{
    if(this->ant!=NULL) return -1;
    return this->ant->getId();
}

bool Case::hasNest() const{
    return this->nest;
}


bool Case::isOnTheWayS() const{
    return this->pheroS >0;
}



bool Case::hasSugar()const {
    return this->sugar;
}

Ant* Case::getAnt() const{
    return this->ant;
}

float Case::getMaxPheroN(){
    return this->maxPheroN;
}

void Case::pSugar(){
    this->sugar = true;
}

void Case::pPheroN(float intensity){
    this->pheroN = intensity;
}


bool Case::pOSugar(){
    if(this->sugar){
        this->sugar = false;
        return true;
    }
    return false;
}
void Case::addAnt(Ant *a){
    this->ant = a;
}

bool Case::pOAnt(){
    if(this->ant!=NULL){
        this->ant = NULL;
        return true;
    }
    return false;
    
}
void Case::addPheroS(){
    this->pheroS = this->maxPheroS;
}

void Case::addNest(){
    this->nest = true;
}

void Case::evaporate(){
    this->pheroS-= this->evaoration;
}

bool Case::isEmpty()const{ 
    return (this->ant == NULL && !this->sugar && !this->nest);
}

void Case::replace(Case c){
    this->sugar = c.hasSugar();
    this->nest = c.hasNest();
    this->pheroN = c.getPheroN();
    this->pheroS = c.getPheroS();
    this->coord = c.getCoord();
    this->ant = c.getAnt();
}


void moveA(Ant *a, Case *c1, Case *c2){
    if(a != c1->getAnt()) throw("you have to give the case where the ant is");
    c1->pOAnt();
    c2->addAnt(a);

}
int norme(Coordonate c){
    return sqrt(c.getLig() * c.getLig() + c.getCol() *c.getCol());
}
int distancePoints(Coordonate c1,  Coordonate c2){
    return abs(norme(c1)-norme(c2));
}
bool closerN(Case *c1, Case *c2,Case *nest){
    return distancePoint(c1->getCoord(),nest->getCoord())>distancePoint(c2->getCoord(),nest->getCoord());
}


