#include "Grid.hpp"
#include "EnsCoord.hpp"
#include "Coordonate.hpp"
#include <stdlib.h> 

int min(int a, int b){
    if( a<b) return a;
    return b;
}


Grid::Grid(int size){
    this->cases = std::vector<Case>(size*size);
    int compteur = 0;
    for(int  i =0;i<size;i++){
        for(int j = 0 ; j < size; j++){
            this->cases[compteur] = Case(Coordonate((j%size) +1,i,size));
        }
    }
}

/*Case Grid::getCase(int col,int lig){

} */

EnsCoord neighbor(Coordonate *c){
    int imin = std::max(c->getLig()-1,0), imax = min(c->getLig()-1,c->getSize());
    int jmin = std::max(c->getCol()-1,0),jmax = min(c->getCol(), c->getSize()) ;
    EnsCoord ens;
    for( int i = imin; i<imax; i++){
        for(int j = jmin; j<jmax; j++){
            if(i!=c->getLig() && j!=c->getCol()) ens.add(Coordonate{i,j,c->getSize()});
        }
    }
    return ens;
    
}
Coordonate randC(EnsCoord c){
    return c.getElementById(rand()%(c.getEns().size()));
}







