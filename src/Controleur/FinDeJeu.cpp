/**
*Fichier FinDeJeu.cpp
* @author Pierre Gaultier & Theo Dolez
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/////////////////////////////////////////////////////////////////////////
/**
* Constructeur
* @param s Sujet de l'observer
*/
FinDeJeu::FinDeJeu(Sujet* s)
{
   this->suj = s;
   this->suj->engistrerObs(this);
}

/////////////////////////////////////////////////////////////////////////
/**
* Destructeur
*/
FinDeJeu::~FinDeJeu()
{
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui actualise le jeu

*/
void FinDeJeu::actualiser()
{
  if(this->suj->getJoueurCourant().getPersonnage().getPdv() < 0){
	cout <<   this->suj->getJoueurCourant().getNom() + " a gagné!!!";
  }
  if(this->suj->getJoueurAutre().getPersonnage().getPdv() < 0){
	cout <<   this->suj->getJoueurAutre().getNom() + " a gagné!!!";
  }
}



