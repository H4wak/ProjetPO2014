/*
   Fichier Chasseur.hpp

*/

#ifndef CHASSEUR_HPP
#define CHASSEUR_HPP

#include <string> // pour le type std::string
#include "Personnage.hpp"
#include "ComportementPouvoirChasseur.hpp"


/******************************************************************************/

class Chasseur: public Personnage
{   
   private :
    
   public :
      Chasseur();
      ~Chasseur();
   
  
};

#include "../../../../src/Modele/Joueur/Personnage/Chasseur.cpp"

#endif // Chasseur_HPP
