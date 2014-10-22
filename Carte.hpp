/* 
   Fichier Carte.hpp

   Définition du type Carte
*/

#ifndef CARTE_HPP
#define CARTE_HPP

#include <string> // pour le type std::string


/******************************************************************************/
class Carte
{
   private :
   int pdv;
   int pdvmax;
   int pa;
   std::string nom;
   int coutmana;
   bool charge;
   bool provoc;
   bool malinvoc;
   
   
   
   public :
  /* création/destruction */
  	Carte();
	Carte(int pdv, int pa, std::string nom, int coutmana, bool charge, bool provoc); // constructeur par défaut 
	~Carte(); // destructeur

  int getPdv();
  void setPdv(int i);
  
  int getPdvmax();
  void setPdvmax(int i);

  int getPa();
  void setPa(int i);

  std::string getNom();
  void setNom(std::string n);

  int getCoutmana();
  void setCoutmana(int i);
  
  bool getCharge();
  void setCharge(bool c);
  
  bool getProvoc();
  void setProvoc(bool p);
  
  bool getMalinvoc();
  void setMalinvoc(bool m);


  std::string toString();


			
}; // class Carte
/******************************************************************************/
#include "Carte.cpp"
#endif // CARTE_HPP
