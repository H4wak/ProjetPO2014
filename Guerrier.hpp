/*
   Fichier Guerrier.hpp

*/

#ifndef GUERRIER_HPP
#define GUERRIER_HPP

#include <string> // pour le type std::string
#include "ComportementPouvoirGuerrier.hpp"


/******************************************************************************/

class Guerrier: public Personnage
{   
   private :
    
   public :
			Guerrier();
      ~Guerrier();
			void utiliserPouvoir();
   
  
};

#include "Guerrier.cpp"

#endif // Guerrier_HPP
