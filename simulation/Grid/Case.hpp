#ifndef CASE_HPP
#define CASE_HPP

#include "../Ant/Ant.hpp"
#include "Coordonate.hpp"

class Case{
	private:
		bool sugar, phero;
		Ant *ant;
		Coordonate *coord;
	public:
		Case(Coordonate c);
		bool hasPhero() const;
		bool hasSugar() const;
		



};





#endif
