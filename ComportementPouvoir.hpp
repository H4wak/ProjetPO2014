/*
   Fichier ComportementPouvoir.hpp

*/

#ifndef COMPORTEMENTPOUVOIR_HPP
#define COMPORTEMENTPOUVOIR_HPP

#include <string> // pour le type std::string



/******************************************************************************/

class ComportementPouvoir
{
   public :
		virtual std::string pouvoir() = 0;
   
};


#endif // ComportementPouvoir_HPP
