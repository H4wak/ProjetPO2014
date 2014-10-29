/*
   Fichier Tour.hpp

*/

#ifndef Tour_HPP
#define Tour_HPP
#include <string> // pour le type std::string



/******************************************************************************/

class Tour
{
	protected:
		Jeu* jeu;	
	
	private:
		
	
	public:
		
		Tour(Jeu* j);
		~Tour();
		
		Jeu* getJeu();
		void virtual finTour()= 0;
		
		
		
		
};

#include "Tour.cpp"
#endif // Tour_HPP		