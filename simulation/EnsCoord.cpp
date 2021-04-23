#include "EnsCoord.hpp"
#include <vector>
#include <iostream>
/*
tester et faire les commentaires de cette class



*/

using std::vector;

std::vector<Coordoonnees> EnsCoord::getEns(){
    return this->ens;
}


EnsCoord::EnsCoord(std::vector<Coordoonnees> e){
    ens = e;
}


int EnsCoord::position(Coordoonnees c ){
    for(std::size_t i = 0; i<this->ens.size(); i++){
        if(this->ens[i] == c) return i;
    }
    return -1;
}


bool EnsCoord::in(Coordoonnees c){
    return this->position(c)!=-1;
}


bool EnsCoord::add(Coordoonnees c){
    if( this->position(c) == -1){
        return false;
    }
    this->ens.push_back(c);
    return true;

}

void EnsCoord::remove(Coordoonnees c){
    int pos  = this->position(c);
    if(pos == -1){
        throw ("Please to remove an existant coordoonate");
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

Coordoonnees EnsCoord::getElementById(std::size_t i){
    return this->ens[i];
}

// a bien tester
std::ostream& operator<<(std::ostream& out , EnsCoord ens){
    for(Coordoonnees cord:ens.getEns()){
            out << cord << " ";
        }
    return out;
}

