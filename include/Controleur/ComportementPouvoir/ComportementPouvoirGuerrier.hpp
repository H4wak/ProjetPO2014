/**
* Fichier ComportementPouvoirGuerrier
* @author Pierre Gaultier & Theo Dolez
*/

#ifndef COMPORTEMENTPOUVOIRGUERRIER_HPP
#define COMPORTEMENTPOUVOIRGUERRIER_HPP

#include <string> // pour le type std::string
#include "ComportementPouvoir.hpp"


/******************************************************************************/

class ComportementPouvoirGuerrier : public ComportementPouvoir
{

   private:
	Joueur* joueur;

   public :
	  ComportementPouvoirGuerrier(Joueur* j);
	  ~ComportementPouvoirGuerrier();
	  void pouvoir();
	
};

#include "../../../src/Controleur/ComportementPouvoir/ComportementPouvoirGuerrier.cpp"
#endif // ComportementPouvoirGuerrier_HPP
