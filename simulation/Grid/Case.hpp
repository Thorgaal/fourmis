#ifndef CASE_HPP
#define CASE_HPP

#include "../Ants/Ant.hpp"
#include "Coordonate.hpp"
#include <vector>



class Case{
	private:
		int maxPheroS = 255,evaoration = 5;
		bool sugar,nest;
		int pheroS;
		float pheroN,maxPheroN = 1;
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
		float getPheroN() const;
		int getAntId() const ;	
		bool hasNest() const;
		bool isOnTheWayS() const;
		Ant* getAnt() const;
		float getMaxPheroN();
		//setters
		//for add		
        void pSugar();
        void pPheroN(float intensity);
		void addAnt(Ant *a);
		void addPheroS();
		void addNest();
		//for put off
        bool pOSugar();
		bool pOAnt();
		void evaporate();
		void replace(Case c);

		//check if the case is empty

		bool isEmpty() const;

};
void moveA(Ant *a, Case *c1, Case *c2) ;
float norme(Coordonate c);
float distancePoint(Coordonate c1,  Coordonate c2);
bool closerN(Case *c1, Case *c2,Case *nest);
bool operator ==(Case c1,Case c2);



#endif
