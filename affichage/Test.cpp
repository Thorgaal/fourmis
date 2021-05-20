#include "generationppm.hpp"

int main(){
    Grid gri = Grid(10);
    Ant a1 = Ant(Coordonate{7,4,10*10}, 0);
    Ant a2 = Ant(Coordonate{3,6,10*10}, 0);
    Ant *pa1;
    Ant *pa2;
    pa1 = &a1;
    pa2 = &a2;
    iniGrid(gri, EnsCoord{std::vector<Coordonate>{Coordonate{3,3,100},Coordonate{5,5,100}}},EnsCoord{std::vector<Coordonate>{Coordonate{2,3,100},Coordonate{4,5,100}}}, std::vector<Ant*>{pa1,pa2});
    for(int l = 1; l<= gri.getSide(); l++){
        for(int c = 1; c<= gri.getSide(); c++){
            Case caseCordonne = gri.getCase(c,l);
            std::cout<<"#";
            if(caseCordonne.getPheroS()>0) std::cout<<"p";
            if(caseCordonne.hasNest()) std::cout<<"n";    
            if(caseCordonne.hasSugar()) std::cout<<"s"; 
            if(caseCordonne.getAntId() != -1) std::cout<<"f"; 
        }
        std::cout<<std::endl;
    }   
    
    genererImageGrid(gri,0);
}