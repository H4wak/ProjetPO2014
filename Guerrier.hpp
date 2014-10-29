/*
   Fichier Guerrier.hpp

*/

#ifndef GUERRIER_HPP
#define GUERRIER_HPP

#include <string> // pour le type std::string
#include "Personnage.hpp"
#include "ComportementPouvoirGuerrier.hpp"


/******************************************************************************/

class Guerrier: public Personnage
{   
   private :
    
   public :
      Guerrier();
      ~Guerrier();
   
  
};

#include "Guerrier.cpp"

#endif // Guerrier_HPP
