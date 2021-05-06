#ifndef ANT_HPP
#define  ANT_HPP

#include "../Coordonate.hpp"

class Ant{
	private:
		bool sugar;
		Coordonate coord;
		int id;
	public:	
		Ant(Coordonate c, int ind);
		Coordoonate getCoord() const;
		int getId() const;
		bool wearSug() const;
		void takeSugar() ;
		void laySugar();
		
		
		
};

#endif
