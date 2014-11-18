/**
* Fichier Jeu.hpp
* @author Pierre Gaultier & Theo Dolez
*/

#ifndef Jeu_HPP
#define Jeu_HPP
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include <vector>
#include <string> // pour le type std::string
#include "../Modele/Joueur/Joueur.hpp"
#include "../Modele/Joueur/ComportementPouvoirGuerrier.hpp"
#include "../Modele/Joueur/Guerrier.hpp"
#include "../Modele/Joueur/ComportementPouvoirChasseur.hpp"
#include "../Modele/Joueur/Chasseur.hpp"
#include "../Modele/Joueur/ComportementPouvoirMage.hpp"
#include "../Modele/Joueur/Mage.hpp"
#include "../Modele/Joueur/ComportementPouvoirDemoniste.hpp"
#include "../Modele/Joueur/Demoniste.hpp"
#include "../Modele/Joueur/ComportementPouvoirPretre.hpp"
#include "../Modele/Joueur/Pretre.hpp"
#include "../Vue/VueConsole.hpp"
#include "Sujet.hpp"
#include "Observer.hpp"


class Etat;
class EtatDebutTour;
class EtatNoMana;
class EtatNoAttaque;
class EtatDoubleNo;
/******************************************************************************/

class Jeu : public Sujet
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
		vector<Observer*>* obs;     

 
	
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
		VueConsole getVue();
		
		void attaqueCvC(int index1, int index2);
		void attaqueCvJ(int index);
		void enleverMalinvoc();
		bool testNoMana();
		bool testProvoc();
		bool testNoAttaque();
		void echangeJoueur(); // echange les deux joueurs dans joueurCourant et joueurAutre
		void setEtat(Etat* e); //setEtat
		void finTour(); 
		void jouer();// lance le tour
		void enregistrerObs(Observer* O);
		void supprimerObs(Observer* O);
		void notifierObs();
		void fonctionsCarte(int f);
		
		
		
		
};


#include "Etat.hpp"
#include "EtatDebutTour.hpp"
#include "EtatNoMana.hpp"
#include "EtatNoAttaque.hpp"
#include "EtatDoubleNo.hpp"
#include "../../src/Controleur/Jeu.cpp"
#endif // JEU_HPP		
