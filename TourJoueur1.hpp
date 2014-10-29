/*
   Fichier TourJoueur1.hpp

*/

#ifndef TourJoueur1_HPP
#define TourJoueur1_HPP
#include <string> // pour le type std::string



/******************************************************************************/

class TourJoueur1 : public Tour
{

	public:
		
		TourJoueur1(Jeu* j);
		~TourJoueur1();
		Jeu* getJeu();
		void finTour();
		
		
		
		
};

#include "TourJoueur1.cpp"
#endif // TourJoueur1_HPP		
