/**
* Fichier ComportementPouvoirPretre
* @author Pierre Gaultier & Theo Dolez
*/

#ifndef COMPORTEMENTPOUVOIRPRETRE_HPP
#define COMPORTEMENTPOUVOIRPRETRE_HPP

#include <string> // pour le type std::string
#include "ComportementPouvoir.hpp"
#include "../../Vue/VueConsole.hpp"


/******************************************************************************/

class ComportementPouvoirPretre : public ComportementPouvoir
{

   private:
	Joueur* joueur;
  VueConsole* vue;

   public :
	  ComportementPouvoirPretre(Joueur* j);
	  ~ComportementPouvoirPretre();
	  void pouvoir();
	
};

#include "../../../src/Modele/Joueur/ComportementPouvoirPretre.cpp"
#endif // ComportementPouvoirPretre_HPP
