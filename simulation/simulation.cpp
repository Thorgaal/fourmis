#include "simulation.hpp"
#include <exception>
#include "Ants/Ant.hpp"
#include <iostream>

#include <string>

bool isIn(Ant *a,std::vector<Ant *> ants){
    for(Ant *ant : ants){
        if(a == ant) return true;
    }
    return false;
}
bool isIn(Case c, std::vector<Case> cases){
    for(Case ca: cases){
        if(ca == c) return true;
    }
    return false;
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
    for(int i = 0; i<int(ants.size()); i++){
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


/*void AntAction(Grid &g,Ant *a, Case c){
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
    }//debut comentaire de la fonction
    else if(!a->wearSug() && c.isEmpty() && closerN(&g.getCase(a->getCoord().getCol(),a->getCoord().getLig()),&g.getCase(c.getCoord().getCol(),c.getCoord().getLig()),&g.getNest())){
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
    }else if( !a->wearSug() && c.isOnTheWayS() && c.is)

}*/

void mettreAJourEnsFourmis(Grid &gri,std::vector<Ant *> ants){
    for(Ant* a:ants){
        mettreAJourUneFourmi(gri, a);
    } 
    gri.evaporation();
}

void mettreAJourUneFourmi(Grid &gri,Ant *ant){
    Coordonate cant = ant->getCoord();
    Coordonate *pcant;
    pcant = &cant;
    EnsCoord neigh = neighbor(pcant);
    // construction de l ensemble randomizer de coord
    EnsCoord randomNeigh = EnsCoord();
    while(not(neigh.isEmpty())){
        Coordonate newcor = randC(neigh);
        randomNeigh.add(newcor);
        neigh.remove(newcor);
    }
    
    bool action_undone = true;
    for(int i = 1; i <= 6; i++){
        for(Coordonate c: randomNeigh.getEns()){
            if(condition_n(i, ant,gri.getCase(ant->getCoord().getCol(),ant->getCoord().getLig()),gri.getCase(c.getCol() ,c.getLig())) && action_undone ){
                action_undone = false;
                Case c1 = gri.getCase(ant->getCoord().getCol(),ant->getCoord().getLig());
                Case c2 = gri.getCase(c.getCol(), c.getLig());
                action_n(i, ant,c1, c2);
                gri.putCase(c1);
                gri.putCase(c2);
            }
        }
    }
}

bool condition_n(int n, Ant *ant,Case c1, Case c2){
    switch(n){
        case 1:
            return condition1(ant,c1,c2);
            break;
        
        case 2:
            return condition2(ant,c1,c2);
            break;
            
        case 3:
            return condition3(ant,c1,c2);
            break;
            
        case 4:
            return condition4(ant,c1,c2);
            break;
            
        case 5:
            return condition5(ant,c1,c2);
            break;
            
        case 6:
            return condition6(ant,c1,c2);
            break;
    }
    return false;
}

void action_n(int n, Ant *ant,Case &c1, Case &c2){
    switch(n){
        case 1:
            return action1(ant,c1,c2);
            break;
        
        case 2:
            return action2(ant,c1,c2);
            break;
            
        case 3:
            return action3(ant,c1,c2);
            break;
            
        case 4:
            return action4(ant,c1,c2);
            break;
            
        case 5:
            return action5(ant,c1,c2);
            break;
            
        case 6:
            return action6(ant,c1,c2);
            break;
    }  
}

bool condition1(Ant *ant, Case c1, Case c2){
    return (not(ant->wearSug()) && c2.hasSugar());
}
bool condition2(Ant *ant, Case c1, Case c2){
    return (ant->wearSug() && c2.hasNest());
}
bool condition3(Ant *ant, Case c1, Case c2){
    return (ant->wearSug() && c2.isEmpty() && c2.getPheroN() > c1.getPheroN());
}
bool condition4(Ant *ant, Case c1, Case c2){
    return (not(ant->wearSug())&& c1.isOnTheWayS() && c2.isEmpty() && c1.getPheroN() > c2.getPheroN() && c2.isOnTheWayS());
}
bool condition5(Ant *ant, Case c1, Case c2){
    return (not(ant->wearSug()) && c2.isOnTheWayS() && c2.isEmpty());
}
bool condition6(Ant *ant, Case c1, Case c2){
    return (not(ant->wearSug()) && c2.isEmpty());
}

void action1(Ant *ant, Case &c1, Case &c2){
    ant->takeSugar();
    c1.addPheroS();
}
void action2(Ant *ant, Case &c1, Case &c2){
    ant->laySugar();
}
void action3(Ant *ant, Case &c1, Case &c2){
    moveFourmis(ant,c1,c2);
    c2.addPheroS();
}
void action4(Ant *ant, Case &c1, Case &c2){
    moveFourmis(ant,c1,c2);
}
void action5(Ant *ant, Case &c1, Case &c2){
    moveFourmis(ant,c1,c2);
}
void action6(Ant *ant, Case &c1, Case &c2){
    moveFourmis(ant,c1,c2);
}

void moveFourmis(Ant *ant, Case &c1, Case &c2){
    c1.pOAnt();
    c2.addAnt(ant);
}
