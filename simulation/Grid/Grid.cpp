#include "Grid.hpp"
#include "EnsCoord.hpp"
#include "Coordonate.hpp"
#include <stdlib.h> 



EnsCoord neighbor(Coordinate c){
    int imin = std::max(c.getLig()-1,0), imax = std::min(c.getLig()-1,Coordonate::tailleGrille),jmin = std::max(c.getCol-1,0),jmax = std::min(c.getCol(), Coordonate::tailleGrille) ;
    EnsCoord ens;
    for( int i = imin; i<imax; i++){
        for(int j = jmin, j<jmax, j++){
            if(i!=c.getLig() && j!=c.getCol()) ens.add(Coordonate{i,j});
        }
    }
    return ens;
    
}
Coordonate randC(EnsCoord c){
    return c.getElementById(rand %(c.getEns().size()));
}







