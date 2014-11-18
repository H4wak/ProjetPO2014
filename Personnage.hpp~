/*
   Fichier Personnage.hpp

*/

#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include <string> // pour le type std::string

#include "ComportementPouvoirGuerrier.hpp"

int const pdvmax(30);
/******************************************************************************/

class Personnage
{
   private :
      int pdv;
      int armure;
      int pdm;
			ComportementPouvoir* CP;
      
    
   public :
   
      Personnage();
      ~Personnage();
      
      int getPdv();
      void setPdv(int npdv);
      int getArmure();
      void setArmure(int narmure);
      int getPdm();
      void setPdm(int npdm);
			ComportementPouvoir* getCP();
      void setCP(ComportementPouvoir* CP);
      std::string toString();
			std::string utiliserPouvoir();        
  
};

#include "Personnage.cpp"

#endif // Personnage_HPP
