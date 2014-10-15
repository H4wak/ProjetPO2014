/*
   Fichier Personnage.hpp

*/

#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include <string> // pour le type std::string
#include "Carte.hpp"
#include "ComportementPouvoir.hpp"


/******************************************************************************/

class Personnage
{
   private :
      int pdvmax;
      int pdv;
      int armure;
      int pdm;
			ComportementPouvoir* CP;
      
    
   public :
   
      Personnage();
      ~Personnage();
      
      int getPdvmax();
      void setPdvmax(int npdvmax);
      int getPdv();
      void setPdv(int npdv);
      int getArmure();
      void setArmure(int narmure);
      int getPdm();
      void setPdm(int npdm);
			ComportementPouvoir* getCP();
      void setCP(ComportementPouvoir* CP);
      std::string toString();
			void utiliserPouvoir();        
  
};

#include "Personnage.cpp"

#endif // Personnage_HPP
