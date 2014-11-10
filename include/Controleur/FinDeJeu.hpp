/**
* Fichier FinDeJeu.hpp
* @author Pierre Gaultier & Theo Dolez
*/

#ifndef FinDeJeu_HPP
#define FinDeJeu_HPP
#include <string> // pour le type std::string
#include "Observer.hpp"




/******************************************************************************/

class FinDeJeu : public Observer
{

	private:
		Sujet* suj;
		
		
	
	public:
		FinDeJeu(Sujet* s);
		~FinDeJeu();
		void actualiser();
		
		
		
		
};

#endif // Observer_HPP		
