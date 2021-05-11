#ifndef CASE_HPP
#define CASE_HPP

#include "../Ant/Ant.hpp"
#include "Coordonate.hpp"
#include <vector>



class Case{
	private:
		bool sugar, phero;
		Ant *ant;
		Coordonate *coord;
	public:
		Case(Coordonate c);
        Case(Coordonate c, std::vector<bool> sP,Ant *a, Coordonate *c);
		bool hasPhero() const;
		bool hasSugar() const;
        void pSugar();
        void pPhero();
        bool pOSugar();
        bool pOPhero();
		



};





#endif
