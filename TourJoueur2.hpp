/*
   Fichier TourJoueur2.hpp

*/

#ifndef TourJoueur2_HPP
#define TourJoueur2_HPP
#include <string> // pour le type std::string



/******************************************************************************/

class TourJoueur2 : public Tour
{

	public:
		
		TourJoueur2(Jeu* j);
		~TourJoueur2();
		
		Jeu* getJeu();
		void finTour();
		
		
		
		
};

#include "TourJoueur2.cpp"
#endif // TourJoueur2_HPP		
