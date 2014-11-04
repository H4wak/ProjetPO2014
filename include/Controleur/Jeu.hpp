/*
   Fichier Jeu.hpp

*/

#ifndef Jeu_HPP
#define Jeu_HPP
#include <string> // pour le type std::string
#include "../Modele/Joueur/Joueur.hpp"



class Tour;
class TourJoueur1;
class TourJoueur2;
/******************************************************************************/

class Jeu
{


	private:
		Joueur* joueurCourant;
		Joueur* joueurAutre;
		Tour* tourCourant;
		TourJoueur1* tourJoueur1;
		TourJoueur2* tourJoueur2;
 
	
	public:
		Jeu(Joueur* j1,Joueur* j2);
		~Jeu();
		
		Joueur* getJoueurCourant();
		Joueur* getJoueurAutre();
		Tour* getTourCourant();
		Tour* getTourJoueur1();
		Tour* getTourJoueur2();
		void echangeJoueur(); // echange les deux joueurs dans joueurCourant et joueurAutre
		void setTour(Tour* t); //setEtat
		void finTour(); 
		void jouer();// lance le tour
		
		
		
		
};


#include "Tour.hpp"
#include "TourJoueur1.hpp"
#include "TourJoueur2.hpp"
#include "../../src/Controleur/Jeu.cpp"
#endif // JEU_HPP		
