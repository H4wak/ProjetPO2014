/**
* Fichier ComportementPouvoirMage
* @author Pierre Gaultier & Theo Dolez
*/

#ifndef COMPORTEMENTPOUVOIRMAGE_HPP
#define COMPORTEMENTPOUVOIRMAGE_HPP

#include <string> // pour le type std::string
#include "ComportementPouvoir.hpp"
#include "../../Vue/VueConsole.hpp"


/******************************************************************************/

class ComportementPouvoirMage : public ComportementPouvoir
{

   private:
	Joueur* joueur;
	VueConsole* vue;

   public :
	  ComportementPouvoirMage(Joueur* j);
	  ~ComportementPouvoirMage();
	  void pouvoir();
	
};

#include "../../../src/Modele/Joueur/ComportementPouvoirMage.cpp"
#endif // ComportementPouvoirMage_HPP
