#include "Ant.hpp"
#include "../Coordonate.hpp"
Ant::Ant(Coordonate c, int ind){
	this->coord = c;
	this->id = ind;
}
Coordonnate Ant::getCoord() const{
	return this->coord;
}

int Ant::getId() const{
	return this->id;
}
bool Ant::wearSug() const{
	return this->sugar;
}

void Ant::takeSugar(){
	this->sugar = true;
}
void Ant::laySugar(){
	this->sugar = false;
}
	
