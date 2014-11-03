/*
   Fichier TourJoueur1.hpp

*/

#ifndef TourJoueur1_HPP
#define TourJoueur1_HPP
#include <string> // pour le type std::string



/******************************************************************************/
class Jeu;

class TourJoueur1 : public Tour
{

	protected:
		Jeu* jeu;	

	public:
		
		TourJoueur1(Jeu* j);
		~TourJoueur1();

		Jeu* getJeu();
		void finTour();
		
		
		
		
};

#include "../../src/Controleur/TourJoueur1.cpp"
#include "Jeu.hpp"
#endif // TourJoueur1_HPP		
