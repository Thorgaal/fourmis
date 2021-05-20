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
    int imin = std::max(c->getLig()-1,1), imax = min(c->getLig()+1,c->getSize());
    int jmin = std::max(c->getCol()-1,1),jmax = min(c->getCol()+1, c->getSize()) ;
    EnsCoord ens;
    for( int i = imin; i<=imax; i++){
        for(int j = jmin; j<=jmax; j++){
            if((i!=c->getLig() || j!=c->getCol()) && isInG(i,j,c->getSize())) ens.add(Coordonate{i,j,c->getSize()});
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
    for(int i = 0; i< int(cases.size());i++){
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
    for(int  i =1;i<=side;i++){
        for(int j = 1 ; j <= side; j++){
            this->cases[compteur] = Case{Coordonate{j,i,side*side}};
            compteur++;
        }
    }
}

Case Grid::getCase(int col,int lig) const{
    Coordonate c = Coordonate{col,lig,this->side*this->side};
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
    for(int i=1;i<int(this->cases.size());i++){
        if(cases[i].hasNest()) cases[i].pPheroN(cases[i].getMaxPheroN()); 
        else cases[i].pPheroN(0);
    }
    
    for(int h =0; h<int(this->side);h++){
        for(int i = 0; i< int(this->side*this->side);i++){
            if(cases[i].getPheroN()<1){
                Coordonate *casecordp;
                Coordonate casecord = this->cases[i].getCoord();
                casecordp = &casecord;
                EnsCoord around = neighbor(casecordp);
                std::vector<Case> c = std::vector<Case>(around.getEns().size());
                for(int k =0; k<int(c.size());k++){
                    c[k] = this->getCase(around.getEns()[k].getCol(),around.getEns()[k].getLig());
                }
                cases[i].pPheroN(std::max(getMaxPhero(c) - 1/float(this->side),0.0f));
            }
        }
    }
}
void Grid::evaporation(){
    for(int i = 0; i<int(this->cases.size());i++){
        this->cases[i].evaporate();
    }
}
void Grid::setNest(Case n){
    this->nest = n;
}

void placeNest(Grid &g, EnsCoord c){
    for(Coordonate ca : c.getEns()){
        Case modifie = g.getCase(ca.getCol(),ca.getLig());
        modifie.addNest();
        g.setNest(modifie.getCoord());
        g.putCase(modifie);
    }
}
Case Grid::getNest() const{
    return this->nest;
}
std::vector<Case> Grid::getCases() const{
    return this->cases;
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

int Grid::getSide(){
    return side;
}
