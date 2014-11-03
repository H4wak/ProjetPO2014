/* 
   Fichier Carte.hpp

   Définition du type Carte
*/

#ifndef CARTE_HPP
#define CARTE_HPP

#include <string> // pour le type std::string


/******************************************************************************/

/**
* La classe Carte représente une Carte.
* @author Pierre Gaultier, Théo Dolez
*/

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
	/*
	* Constructeur.
	* Créer une carte.
	* @param pdv Point de vie de la carte.
	* @param pa Point d'attaque de la carte.
	* @param nom Nom de la carte.
	* @param coutmana Cout en mana de la carte.
	* @param charge Booléen, vrai si la carte à la capacité Charge.
	* @param provoc Booléen, vrai si la carte à la capacité Provocation.
	*/
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
#include "../../../../../src/Modele/Joueur/Deck/Carte/Carte.cpp"
#endif // CARTE_HPP
