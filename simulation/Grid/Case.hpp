#ifndef CASE_HPP
#define CASE_HPP

#include "../Ants/Ant.hpp"
#include "Coordonate.hpp"
#include <vector>



class Case{
	private:
		int maxPheroS = 100, maxPheroN = 100,evaoration = 1;
		bool sugar,nest;
		int pheroN,pheroS;
		Ant *ant;
		Coordonate coord;
	public:
		Case() = default;
		Case(Coordonate c);
        Case(Coordonate c, bool s,Ant *a,bool n);
		//getters
		bool hasSugar() const;
		Coordonate getCoord() const;
		int getPheroS() const ;
		int getPheroN() const;
		int getAntId() const ;	
		bool hasNest() const;
		bool isOnTheWayS() const;
		Ant* getAnt() const;
		//setters
		//for add		
        void pSugar();
        void pPheroN(int intensity);
		void addAnt(Ant *a);
		void addPheroS();
		//for put off
        bool pOSugar();
		bool pOAnt();
		void evaporate();

		//check if the case is empty

		bool isEmpty() const;

};
void moveA(Ant a, Case c1, Case c2) ;
int norme(Coordonate c);
int distancePoint(Coordonate c1,  Coordonate c2);
bool closerN(Case *c1, Case *c2,Case *nest);




#endif
