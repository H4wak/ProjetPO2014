/**
* Fichier ComportementPouvoir
* @author Pierre Gaultier & Theo Dolez
*/

#ifndef COMPORTEMENTPOUVOIR_HPP
#define COMPORTEMENTPOUVOIR_HPP

#include <string> // pour le type std::string


class Jeu;
class Joueur;
/******************************************************************************/

class ComportementPouvoir
{
   public :
		virtual void pouvoir(Jeu* j) = 0;
   
};

//#include "../../../Controleur/Jeu.hpp"
#endif // ComportementPouvoir_HPP
