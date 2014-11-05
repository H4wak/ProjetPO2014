/*
   Fichier ComportementPouvoirChasseur.hpp

*/

#ifndef COMPORTEMENTPOUVOIRCHASSEUR_HPP
#define COMPORTEMENTPOUVOIRCHASSEUR_HPP

#include <string> // pour le type std::string
#include "ComportementPouvoir.hpp"


/******************************************************************************/

class ComportementPouvoirChasseur : public ComportementPouvoir
{

   public :
	  std::string pouvoir();
	
};

#include "../../../../src/Modele/Joueur/Personnage/ComportementPouvoirChasseur.cpp"
#endif // ComportementPouvoirChasseur_HPP
