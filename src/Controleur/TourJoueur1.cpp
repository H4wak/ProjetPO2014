/*
   Fichier TourJoueur1.cpp

   Définition des méthodes de TourJoueur1
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/////////////////////////////////////////////////////////////////////////

TourJoueur1::TourJoueur1(Jeu* j)
{
	this->jeu = j;
}

/////////////////////////////////////////////////////////////////////////

TourJoueur1::~TourJoueur1()
{
}

/////////////////////////////////////////////////////////////////////////
Jeu* TourJoueur1::getJeu()
{
  return this->jeu;  
}

/////////////////////////////////////////////////////////////////////////
void TourJoueur1::finTour()
{
  jeu->setTour(jeu->getTourJoueur2());
  jeu->echangeJoueur();
  jeu->jouer();
}
