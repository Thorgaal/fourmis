#pragma once
#include "Coordoonees.hpp"
#include <vector>
#include <iostream>


class EnsCoord{
    private:
        std::vector<Coordoonnees> ens;
        int position(Coordoonnees c);
    public:
        std::vector<Coordoonnees> getEns();
        EnsCoord(std::vector<Coordoonnees> c);
        bool in(Coordoonnees c);
        bool add(Coordoonnees c);
        void remove(Coordoonnees c);
        bool isEmpty();
        std::size_t size();
        Coordoonnees getElementById(std::size_t i);


};


std::ostream& operator<<(std::ostream& out , EnsCoord ens);
