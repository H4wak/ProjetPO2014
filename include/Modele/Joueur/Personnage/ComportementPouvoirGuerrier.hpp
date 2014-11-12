/**
* Fichier ComportementPouvoir
* @author Pierre Gaultier & Theo Dolez
*/

#ifndef COMPORTEMENTPOUVOIRGUERRIER_HPP
#define COMPORTEMENTPOUVOIRGUERRIER_HPP

#include <string> // pour le type std::string
#include "ComportementPouvoir.hpp"

class Jeu;
class Joueur;
/******************************************************************************/

class ComportementPouvoirGuerrier : public ComportementPouvoir
{

   public :
	  void pouvoir(Jeu* j);
	
};
//#include "../../../Controleur/Jeu.hpp"
#include "../../../../src/Modele/Joueur/Personnage/ComportementPouvoirGuerrier.cpp"
#endif // ComportementPouvoirGuerrier_HPP
