/**
* Fichier Jeu.hpp
* @author Pierre Gaultier & Theo Dolez
*/

#ifndef Jeu_HPP
#define Jeu_HPP
#include <string> // pour le type std::string
#include "../Modele/Joueur/Joueur.hpp"
#include "../Vue/VueConsole.hpp"


class Etat;
class EtatDebutTour;
class EtatNoMana;
class EtatNoAttaque;
class EtatDoubleNo;
/******************************************************************************/

class Jeu
{


	private:
		Joueur* joueurCourant;
		Joueur* joueurAutre;
		Etat* etatCourant;
		EtatDebutTour* etatDebutTour;
		EtatNoMana* etatNoMana;
		EtatNoAttaque* etatNoAttaque;
		EtatDoubleNo* etatDoubleNo;
		VueConsole vue;
 
	
	public:
		Jeu(Joueur* j1,Joueur* j2);
		~Jeu();
		
		Joueur* getJoueurCourant();
		Joueur* getJoueurAutre();
		Etat* getEtatCourant();
		Etat* getEtatNoMana();
		Etat* getEtatNoAttaque();
		Etat* getEtatDoubleNo();
		Etat* getEtatDebutTour();
		
		void attaqueCvC(int index1, int index2);
		//void attaqueCvJ(int index);
		void enleverMalinvoc();
		bool testNoMana();
		bool testNoAttaque();
		void echangeJoueur(); // echange les deux joueurs dans joueurCourant et joueurAutre
		void setEtat(Etat* e); //setEtat
		void finTour(); 
		void jouer();// lance le tour
		
		
		
		
};


#include "Etat.hpp"
#include "EtatDebutTour.hpp"
#include "EtatNoMana.hpp"
#include "EtatNoAttaque.hpp"
#include "EtatDoubleNo.hpp"
#include "../../src/Controleur/Jeu.cpp"
#endif // JEU_HPP		
