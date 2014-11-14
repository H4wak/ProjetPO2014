/**
* Fichier Joueur.hpp
* @author Pierre Gaultier &  Theo Dolez
*/

#ifndef Joueur_HPP
#define Joueur_HPP
#include <string> // pour le type std::string
#include <list>
#include <vector>
#include "Deck/Deck.hpp"
#include "Guerrier.hpp"
#include "Chasseur.hpp"
#include "ComportementPouvoir.hpp"
#include "ComportementPouvoirGuerrier.hpp"
#include "ComportementPouvoirChasseur.hpp"

int const tailleMain(8);
int const tailleBoard(8);
int const pdvmax(30);
/******************************************************************************/

class Joueur
{
	private:
		int pdv;
     	int armure;
      	int pdm;
	 	ComportementPouvoir* CP;
		Deck* d;
		std::vector<Carte>* main;
		std::vector<Carte>* board;
		Personnage p;
		std::string nom;
	
	public:
		
		Joueur(std::string nom,std::string fichier);
		~Joueur();
		
		int getPdv();
    	void setPdv(int npdv);
     	int getArmure();
      	void setArmure(int narmure);
      	int getPdm();
      	void setPdm(int npdm);
     
		ComportementPouvoir* getCP();
    	void setCP(ComportementPouvoir* CP);
    	std::string toString();
		void utiliserPouvoir(Jeu* j); 
		
		Deck* getDeck();
		
		std::vector<Carte>* getMain();		
		
		std::vector<Carte>* getBoard();		
		
		std::string getNom();
		void setNom(std::string n);
		
		Personnage getPersonnage();
		void setPersonnage(Personnage p);
		
		void setPDM(int npdm);
		void setPDV(int npdv);
		void setARMURE(int arm);
		
		
		std::string afficherMain();
		std::string afficherBoard();
		
		bool ajouterMain(Carte c); // renvoie vrai si l'opération a réussie
		bool ajouterBoard(Carte c); // renvoie vrai si l'opération a réussie
		bool supprimerMain(int index);
		bool supprimerBoard(int index);
		
		
		
		
};

#include "../../../src/Modele/Joueur/Joueur.cpp"
#endif // JOUEUR_HPP		
