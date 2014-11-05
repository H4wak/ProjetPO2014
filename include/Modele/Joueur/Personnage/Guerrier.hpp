/**
* Fichier Guerrier
* @author Pierre Gaultier & Theo Dolez
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

#include "../../../../src/Modele/Joueur/Personnage/Guerrier.cpp"

#endif // Guerrier_HPP
