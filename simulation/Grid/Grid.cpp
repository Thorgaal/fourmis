#include "Grid.hpp"
#include "EnsCoord.hpp"
#include "Coordonate.hpp"
#include <stdlib.h> 
#include <cmath>

int min(int a, int b){
    if( a<b) return a;
    return b;
}

bool isInG(int c,int l, int s){
    if(l>sqrt(s) || c > sqrt(s)){
            return false;
    }else if(c<1 || l <1){
        return false;
    }
    return true;
}

EnsCoord neighbor(Coordonate *c){
    int imin = std::max(c->getLig()-1,0), imax = min(c->getLig()-1,c->getSize());
    int jmin = std::max(c->getCol()-1,0),jmax = min(c->getCol(), c->getSize()) ;
    EnsCoord ens;
    for( int i = imin; i<imax; i++){
        for(int j = jmin; j<jmax; j++){
            if(i!=c->getLig() && j!=c->getCol() && isInG(i,j,c->getSize())) ens.add(Coordonate{i,j,c->getSize()});
        }
    }
    return ens;
    
}
Coordonate randC(EnsCoord c){
    return c.getElementById(rand()%(c.getEns().size()));
}



float getMaxPhero(std::vector<Case> c){
    if(c.size()>0){
        float m = c[0].getPheroN();
        for(Case ci:c){
            if(ci.getPheroN()>m) m=ci.getPheroN();
        }
        return  m;
    }
    return -1;
}

int Grid::getId(Case c){
    Coordonate c1 = c.getCoord();
    for(int i = 0; i< cases.size();i++){
        if(cases[i].getCoord() == c1 ){
            return i;
        }
    }
    
    return -1; 
}


Grid::Grid(int s){
    this->side = s;
    this->cases = std::vector<Case>(side*side);
    int compteur = 0;
    for(int  i =0;i<side;i++){
        for(int j = 0 ; j < side; j++){
            this->cases[compteur] = Case{Coordonate{(j%side) +1,i,side}};
            compteur++;
        }
    }
}

Case Grid::getCase(int col,int lig) const{
    Coordonate c = Coordonate{col,lig};
    for(Case ci : this->cases){
        if(ci.getCoord() == c ){
            return ci;
        }
    }
    throw("you have to give an existant case");
    return Case{Coordonate{col,lig}}; 
}

void Grid::putCase(Case c){
    int i = this->getId(c);
    if(i!=-1)cases[i].replace(c);
    else throw("you have to give an existant place");
}

void Grid::linearisePheroN(){
    for(int i=0;i<this->cases.size();i++){
        if(cases[i].hasNest()) cases[i].pPheroN(cases[i].getMaxPheroN()); 
        else cases[i].pPheroN(0);
    }
    for(int i =0; i<this->side; i++){
        for(int j =0; j<this->cases.size();j++){
            if(cases[j].getPheroN()<1){
                EnsCoord around = neighbor(&cases[i].getCoord());
                std::vector<Case> c = std::vector<Case>(around.getEns().size());
                for(int k =0; k<c.size();k++){
                    c[0] = this->getCase(around.getElementById(k).getCol(),around.getElementById(k).getLig());
                }
                cases[j].pPheroN(getMaxPhero(c) - 1/this->side);
            }
        }
    }

}
void Grid::evaporation(){
    for(int i = 0; i<this->cases.size();i++){
        this->cases[i].evaporate();
    }
}

void placeNest(Grid &g, EnsCoord c){
    for(Coordonate ca : c.getEns()){
        Case modifie = g.getCase(ca.getCol(),ca.getLig());
        modifie.addNest();
        g.putCase(modifie);
    }
}

void placeSugar(Grid &g, EnsCoord c){
    for(Coordonate ca : c.getEns()){
        Case modifie = g.getCase(ca.getCol(),ca.getLig());
        modifie.pSugar();
        g.putCase(modifie);
    }
}

void placeAnts(Grid &g,std::vector<Ant *> a){
    for(Ant *ant : a){
        Case modifie = g.getCase(ant->getCoord().getCol(),ant->getCoord().getLig());
        modifie.addAnt(ant);
        g.putCase(modifie);
    }
}

void iniGrid(Grid &g, EnsCoord coordN, EnsCoord coordS, std::vector<Ant *> a){
    placeNest(g,coordN);
    placeSugar(g,coordS);
    placeAnts(g,a);
    g.linearisePheroN();
}


