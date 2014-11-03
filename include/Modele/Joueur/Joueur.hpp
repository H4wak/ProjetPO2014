/*
   Fichier Joueur.hpp

*/

#ifndef Joueur_HPP
#define Joueur_HPP
#include <string> // pour le type std::string
#include <list>
#include <vector>
#include "Deck/Deck.hpp"
#include "Personnage/Guerrier.hpp"

int const tailleMain(5);
int const tailleBoard(3);
/******************************************************************************/

class Joueur
{
	private:
		Deck* d;
		std::vector<Carte>* main;
		std::vector<Carte>* board;
		Personnage p;
		std::string nom;
	
	public:
		
		
		Joueur(std::string nom, Personnage p,std::string fichier);
		~Joueur();
		
		Deck* getDeck();
		
		std::vector<Carte>* getMain();		
		
		std::vector<Carte>* getBoard();		
		
		std::string getNom();
		void setNom(std::string n);
		
		Personnage getPersonnage();
		void setPersonnage(Personnage p);
		
		std::string afficherMain();
		std::string afficherBoard();
		
		bool ajouterMain(Carte* c); // renvoie vrai si l'opération a réussie
		bool ajouterBoard(Carte* c); // renvoie vrai si l'opération a réussie
		bool supprimerMain(int index);
		bool supprimerBoard(int index);
		
		
		
		
};

#include "../../../src/Modele/Joueur/Joueur.cpp"
#endif // JOUEUR_HPP		
