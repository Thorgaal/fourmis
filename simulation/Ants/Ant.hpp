#ifndef ANT_HPP
#define  ANT_HPP

#include "../Grid/Coordonate.hpp"

class  Ant{
	private:
		bool sugar;
		Coordonate coord;
		int id;
	public:	
		Ant(Coordonate c, int ind);
		Coordonate getCoord() const;
		int getId() const;
		bool wearSug() const;
		void takeSugar() ;
		void laySugar();
		
		
		
};

#endif
