/*
   Fichier ComportementPouvoirChasseur.hpp

*/

#ifndef COMPORTEMENTPOUVOIRCHASSEUR_HPP
#define COMPORTEMENTPOUVOIRCHASSEUR_HPP

#include <string> // pour le type std::string
#include "ComportementPouvoir.hpp"


/******************************************************************************/
class Jeu;
class Joueur;

class ComportementPouvoirChasseur : public ComportementPouvoir
{

   public :
	  void pouvoir(Jeu* j);
	
};

//#include "../../../Controleur/Jeu.hpp"
#include "../../../../src/Modele/Joueur/Personnage/ComportementPouvoirChasseur.cpp"
#endif // ComportementPouvoirChasseur_HPP
