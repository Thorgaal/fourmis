#ifndef ENSCOORD_HPP
#define ENSCOORD_HPP
#include "Coordonate.hpp"
#include <vector>
#include <iostream>


class EnsCoord{
/*
  this class is made for manage a set of coordonnates
*/
    private:
        std::vector<Coordonate> ens ;
        int position(Coordonate c);
    public:
        //default constructor
        EnsCoord();
    
        // constructor who uses a vector of coordonnates
        EnsCoord(std::vector<Coordonate> c);
        
        // return true if the set is empty else false
        bool isEmpty();
        
        //return the size of the set
        std::size_t size();
        
        //return the vector of coordonnates
        std::vector<Coordonate> getEns();
    
        //return true if c is in the set else false
        bool in(Coordonate c);
        
        // return the id in the set of a given coordonnate
        Coordonate getElementById(std::size_t i);
    
        //add a coordonate to the set
        bool add(Coordonate c);
        
        //remove a coordonate of the set
        void remove(Coordonate c);
        
};

// echo out the list of coordonnates
std::ostream& operator<<(std::ostream& out ,  EnsCoord ens);
#endif