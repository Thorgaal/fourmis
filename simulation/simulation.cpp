#include "simulation.hpp"
#include <exception>
#include "Ants/Ant.hpp"
#include <iostream>

#include <string>

bool isIn(Ant *a,std::vector<Ant *> ants){
    for(Ant *ant : ants){
        if(a = ant) return true;
    }
    return false;
}
bool isIn(Case c, std::vector<Case> cases){
    for(Case ca: cases){
        if(ca == c) return true;
    }
}  

void testIntegrity(Grid g,std::vector<Ant *> ants){
    
    for(Case c:g.getCases()){
        Ant *a = c.getAnt();
        if(a!=NULL){
            try{
                if(!isIn(a,ants)){ 
                    std::string error = "The case  : (" + c.getCoord().getCol();
                    error +=  ","+ c.getCoord().getCol();
                    error += ") cotain the ant with this id : " + a->getId(); 
                    error +=  "that is not in the ants alive at least";
                    throw std::runtime_error(error);
                }

            }catch(std::runtime_error const& r){
                std::cerr << r.what() << std::endl;
            }
        }
    }
    for(int i = 0; i<ants.size(); i++){
        try{
                if(ants[i]->getId()!=i){
                    std::string error = "The " + i;
                    error += " th has an incorrect id";
                    throw std::runtime_error(error);
                }
        }catch(std::runtime_error const& r){
                std::cerr << r.what() << std::endl;
        }
        try{    
            if(g.getCase(ants[i]->getCoord().getCol(),ants[i]->getCoord().getLig()).isEmpty()) throw std::runtime_error("One ant is on an empty case : " + ants[i]->getId());
            
        }catch(std::runtime_error const& r){
            std::cerr << r.what() << std::endl;
        }
    }
}


void roundAnt(Grid &g,Ant *a, Case c){
    if(a->wearSug() && c.hasSugar()){
        a->takeSugar();
        g.getCase(c.getCoord().getCol(),c.getCoord().getLig()).pOSugar();
        g.getCase(a->getCoord().getCol(),a->getCoord().getLig()).addPheroS();
    }else if(!a->wearSug() && c.hasNest()){
        a->laySugar();

    }else{
        Case modifie = g.getCase(a->getCoord().getCol(),a->getCoord().getLig());
        modifie.pOAnt();
        a->move(c.getCoord());
        modifie = g.getCase(a->getCoord().getCol(),a->getCoord().getLig());
        g.putCase(modifie);
    }/*else if(!a->wearSug() && c.isEmpty() && closerN(&g.getCase(a->getCoord().getCol(),a->getCoord().getLig()),&g.getCase(c.getCoord().getCol(),c.getCoord().getLig()),&g.getNest())){
        Case modifie = g.getCase(a->getCoord().getCol(),a->getCoord().getLig());
        modifie.pOAnt();
        a->move(c.getCoord());
        modifie = g.getCase(a->getCoord().getCol(),a->getCoord().getLig());
        g.putCase(modifie);
    }else if(a->wearSug() && g.getCase(a->getCoord().getCol(),a->getCoord().getLig()).isOnTheWayS() && c.isEmpty() & !closerN(&g.getCase(a->getCoord().getCol(),a->getCoord().getLig()),&g.getCase(c.getCoord().getCol(),c.getCoord().getLig()),&g.getNest())){
            Case modifie = g.getCase(a->getCoord().getCol(),a->getCoord().getLig());
        modifie.pOAnt();
        a->move(c.getCoord());
        modifie = g.getCase(a->getCoord().getCol(),a->getCoord().getLig());
        g.putCase(modifie);
    }else if( !a->wearSug() && c.isOnTheWayS() && c.is)*/

}