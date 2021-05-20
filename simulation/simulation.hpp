#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Grid/Grid.hpp"
#include "Ants/Ant.hpp"
#include <vector>

bool isIn(Ant *a,std::vector<Ant *> ants);
bool isIn(Case c, std::vector<Case> cases);
//void testIntegrity(Grid g,std::vector<Ant *> a);

//void AntAction(Grid &g,Ant *a, Case c);

void mettreAJourEnsFourmis(Grid &gri,std::vector<Ant *> ants);
void mettreAJourUneFourmi(Grid &gri, Ant *ant);

bool condition_n(int n, Ant *ant,Case c1, Case c2);
void action_n(int n, Ant *ant,Case &c1, Case &c2);

bool condition1(Ant *ant, Case c1, Case c2);
bool condition2(Ant *ant, Case c1, Case c2);
bool condition3(Ant *ant, Case c1, Case c2);
bool condition4(Ant *ant, Case c1, Case c2);
bool condition5(Ant *ant, Case c1, Case c2);
bool condition6(Ant *ant, Case c1, Case c2);

void action1(Ant *ant, Case &c1, Case &c2);
void action2(Ant *ant, Case &c1, Case &c2);
void action3(Ant *ant, Case &c1, Case &c2);
void action4(Ant *ant, Case &c1, Case &c2);
void action5(Ant *ant, Case &c1, Case &c2);
void action6(Ant *ant, Case &c1, Case &c2);

void moveFourmis(Ant *ant, Case &c1, Case &c2);

#endif