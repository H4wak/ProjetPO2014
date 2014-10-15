/*
   Fichier ComportementPouvoirGuerrier.hpp

*/

#ifndef COMPORTEMENTPOUVOIRGUERRIER_HPP
#define COMPORTEMENTPOUVOIRGUERRIER_HPP

#include <string> // pour le type std::string
#include "ComportementPouvoir.hpp"


/******************************************************************************/

class ComportementPouvoirGuerrier : public ComportementPouvoir
{

   public :
	  std::string pouvoir();
	
};

#include "ComportementPouvoirGuerrier.cpp"
#endif // ComportementPouvoirGuerrier_HPP
