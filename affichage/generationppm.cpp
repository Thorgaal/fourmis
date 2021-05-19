#include <iostream>// pour cout
#include <iomanip>// pour setfill, setw
#include <sstream>// pour ostringstream
#include <fstream>// pour ofstream
#include <string>
#include "generationppm.hpp"

void genererImageGrid(Grid gri, int num_fichier, std::string directory, int taillecase){
    int r,g,b;
    std::ostringstream filename;
    filename << directory << "img" << num_fichier << ".ppm";
    std::ofstream fic(filename.str(), std::ios::out | std::ios::trunc);
    fic << "P3" << std::endl;
    fic<< gri.getSide()*taillecase << " " << gri.getSide()*taillecase << " " << std::endl;
    fic<< 255 << " " << std::endl;
    for(int l = 1; l<= gri.getSide(); l++){
        for(int h = 0; h<taillecase; h++){
            for(int c = 1; c<= gri.getSide(); c++){
                Case caseCordonne = gri.getCase(c,l);
                r = 0; g= 0; b=0;
                if(caseCordonne.getPheroS()>0)   {r = 3; g= 40; b=3;}
                if(caseCordonne.hasNest())      {r = 0; g= 0; b=128;}
                if(caseCordonne.hasSugar()) {r = 255; g= 255; b=255;}
                if(caseCordonne.getAntId() != -1){r = 0; g= 128; b=0;}
                for(int k = 0; k<taillecase; k++){
                    fic<<r<<" "<<g<<" "<<b<<"   ";
                }
            }
        }
        fic<<std::endl;
    }   
    fic.close();
}