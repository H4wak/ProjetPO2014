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

#include "../../Controleur/ComportementPouvoir/ComportementPouvoir.hpp"



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
    int pdmTour;
		int pdvmax;
		bool pouvoirUtilise;
	 	ComportementPouvoir* CP;
		Deck* d;
		std::vector<Carte>* main;
		std::vector<Carte>* board;
		std::string nom;
		Joueur* joueurAutre;
	
	public:
		
		Joueur(std::string nom,std::string fichier);
		~Joueur();
		
		int getPdv();
    	void setPdv(int npdv);
     	int getArmure();
      	void setArmure(int narmure);
      	int getPdm();
      	void setPDM(int npdm);
      	int getPdmTour();
      	void setPDMTour(int npdmt);
		bool getPouvoirUtilise();
		void setPouvoirUtilise(bool p);

		Joueur* getJoueurAutre();
      	void setJoueurAutre(Joueur* j);
     
		ComportementPouvoir* getCP();
    	void setCP(ComportementPouvoir* CP);
    	std::string toString();
		void utiliserPouvoir(); 
		
		Deck* getDeck();
		
		std::vector<Carte>* getMain();		
		
		std::vector<Carte>* getBoard();		
		
		std::string getNom();
		void setNom(std::string n);
		
		
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
