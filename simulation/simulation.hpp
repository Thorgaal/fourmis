#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Grid/Grid.hpp"
#include "Ants/Ant.hpp"
#include <vector>

bool isIn(Ant *a,std::vector<Ant *> ants);
bool isIn(Case c, std::vector<Case> cases);
void testIntegrity(Grid g,std::vector<Ant *> a);

void roundAnt(Grid &g,Ant *a, Case c);




#endif