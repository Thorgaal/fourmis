#include <iostream>
#include "simulation/simulation.hpp"
#include "affichage/generationppm.hpp"

int main(){
    std::cout<<"yo"<<std::endl;
    int nombre_iteration = 200;
    
    Grid gri = Grid(20);
    
    Ant a1 = Ant{Coordonate{8,9,20*20}, 1};
    Ant a2 = Ant{Coordonate{11,10,20*20}, 2};
    Ant a3 = Ant{Coordonate{9,11,20*20}, 3};
    std::vector<Ant *> ants;
    ants.push_back(&a1);
    ants.push_back(&a2);
    ants.push_back(&a3);
    
    
    iniGrid(gri,EnsCoord{std::vector<Coordonate>{Coordonate{9,9,20*20},Coordonate{10,9,20*20},Coordonate{9,10,20*20},Coordonate{10,10,20*20}}},                  EnsCoord{std::vector<Coordonate>{Coordonate{1,1,20*20},Coordonate{15,17,20*20},Coordonate{13,19,20*20}}},ants);
    for(int i = 0; i < nombre_iteration;i++){
        genererImageGrid(gri,i,"images/");
        mettreAJourEnsFourmis(gri,ants);
    }
    return 0;
}