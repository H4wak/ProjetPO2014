#include <string> // pour les chaines de caracteres
#include <iostream> // pour les entrées/sorties
#include <fstream> // pour la gestion des flux de fichier
#include <sstream> // pour la gestion des flux de string
using namespace std;
#include "../Modele/Joueur/Joueur.hpp"
#include "Jeu.hpp"
#include "FinDeJeu.hpp"
int main()
{

	Guerrier cheval;
	Chasseur poney;
	
	Joueur* Pierre = new Joueur("Pierre", cheval,"DeckGuerrier.txt");
	Joueur* Theo = new Joueur("Théo", poney,"DeckGuerrier.txt");
	Jeu* game = new Jeu(Pierre, Theo);
	FinDeJeu* ob = new FinDeJeu(game);
	
	Pierre->setARMURE(5);

	
	game->jouer();
	
	
	/*
	game->finTour();
	
	cout << game->getJoueurCourant()->getNom() << endl;
	cout << game->getJoueurAutre()->getNom() << endl;*/
	

  return 0;
}
