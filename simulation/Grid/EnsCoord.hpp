#ifndef ENSCOORD_HPP
#define ENSCOORD_HPP
#include "Coordonate.hpp"
#include <vector>
#include <iostream>


class EnsCoord{
/*
  this class is made for manage an set of coordonnates
*/
    private:

        std::vector<Coordonate> ens ;
        int position(Coordonate c);
    public:
        EnsCoord();
        EnsCoord(std::vector<Coordonate> c);
        std::vector<Coordonate> getEns();
        bool in(Coordonate c);
        bool add(Coordonate c);
        void remove(Coordonate c);
        bool isEmpty();
        std::size_t size();
        Coordonate getElementById(std::size_t i);
        


};


std::ostream& operator<<(std::ostream& out ,  EnsCoord ens);
#endif