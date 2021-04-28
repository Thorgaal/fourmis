#include "EnsCoord.hpp"
#include <vector>
#include <iostream>
#include "Coordonate.hpp"

int EnsCoord::position(Coordonate c ){
    for(std::size_t i = 0; i<this->ens.size(); i++){
        if(this->ens[i] == c) return i;
    }
    return -1;
}
std::vector<Coordonate> EnsCoord::getEns() {
    return this->ens;
}


    EnsCoord::EnsCoord(std::vector<Coordonate> e){  
        this->ens = std::move(e);
    }


bool EnsCoord::in(Coordonate c){
    return this->position(c)!=-1;
}


bool EnsCoord::add(Coordonate c){
    if( this->position(c) == -1){
        return false;
    }
    this->ens.push_back(c);
    return true;

}

void EnsCoord::remove(Coordonate c){
    int pos  = this->position(c);
    if(pos == -1){
        throw ("Please remove an existing coordinate");
    }
    this->ens.erase(this->ens.begin() + pos);

    

}
bool EnsCoord::isEmpty(){
    return this->ens.empty();
}

std::size_t EnsCoord::size(){
    if(this->ens.empty()){
        return 0;
    }
    return this->ens.size();

}

Coordonate EnsCoord::getElementById(std::size_t i){
    return this->ens[i];
}

// a bien tester
std::ostream& operator<<(std::ostream& out , EnsCoord ens)  {
    for(Coordonate cord:ens.getEns()){
            out << cord << " ";
        }
    return out;
}
