/*
   Fichier TourJoueur2.cpp

   Définition des méthodes de TourJoueur2
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/////////////////////////////////////////////////////////////////////////

TourJoueur2::TourJoueur2(Jeu* j)
{
	this->jeu = j;
}

/////////////////////////////////////////////////////////////////////////

TourJoueur2::~TourJoueur2()
{
}

/////////////////////////////////////////////////////////////////////////
Jeu* TourJoueur2::getJeu()
{
  return this->jeu;  
}

/////////////////////////////////////////////////////////////////////////
void TourJoueur2::finTour()
{
  jeu->setTour(jeu->getTourJoueur1());
  jeu->echangeJoueur();
  jeu->jouer();
}

