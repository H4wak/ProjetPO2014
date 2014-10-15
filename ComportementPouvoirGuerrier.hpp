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
   private :
      
    
   public :
		ComportementPouvoirGuerrier();
		~ComportementPouvoirGuerrier();
	  void pouvoir();
			
   
};


#endif // ComportementPouvoirGuerrier_HPP
