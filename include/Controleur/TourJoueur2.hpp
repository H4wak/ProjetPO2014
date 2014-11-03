/*
   Fichier TourJoueur2.hpp

*/

#ifndef TourJoueur2_HPP
#define TourJoueur2_HPP
#include <string> // pour le type std::string


/******************************************************************************/
class Jeu;
class TourJoueur2 : public Tour
{


	protected:
		Jeu* jeu;	

	public:
		
		TourJoueur2(Jeu* j);
		~TourJoueur2();
		
		Jeu* getJeu();
		void finTour();
		
	
		
		
};

#include "../../src/Controleur/TourJoueur2.cpp"
#include "Jeu.hpp"
#endif // TourJoueur2_HPP		
