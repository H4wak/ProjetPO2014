/*
   Fichier TourJoueur2.hpp

*/

#ifndef TourJoueur2_HPP
#define TourJoueur2_HPP
#include <string> // pour le type std::string
#include "Tour.hpp"

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


#include "Jeu.hpp"
#include "../../src/Controleur/TourJoueur2.cpp"
#endif // TourJoueur2_HPP		
