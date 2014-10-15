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
   int pa;
   std::string nom;
   int coutmana;
   
   
   public :
  /* création/destruction */
  	Carte();
	Carte(int pdv, int pa, std::string nom, int coutmana); // constructeur par défaut 
	~Carte(); // destructeur

  int getPdv();
  void setPdv(int i);

  int getPa();
  void setPa(int i);

  std::string getNom();
  void setNom(std::string n);

  int getCoutmana();
  void setCoutmana(int i);

  std::string toString();


			
}; // class Carte
/******************************************************************************/
#include "Carte.cpp"
#endif // CARTE_HPP
