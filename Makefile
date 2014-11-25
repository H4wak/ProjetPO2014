all:Joueur.o Deck.o Carte.o ComportementPouvoir.o ComportementPouvoirGuerrier.o ComportementPouvoirChasseur.o ComportementPouvoirPretre.o ComportementPouvoirMage.o ComportementPouvoirDemoniste.o Guerrier.o Chasseur.o Pretre.o Mage.o Demoniste.o Jeu.o Etat.o EtatDebutTour.o EtatNoAttaque.o EtatDoubleNo.o EtatNoMana.o Sujet.o Observer.o FinDeJeu.o VueConsole.o LancementJeu.o  Main.o
	g++ -Wall -g bin/Modele/Joueur/Deck/Carte.o bin/Modele/Joueur/Deck/Deck.o bin/Controleur/ComportementPouvoir/ComportementPouvoir.o ComportementPouvoirGuerrier.o ComportementPouvoirChasseur.o ComportementPouvoirPretre.o ComportementPouvoirMage.o ComportementPouvoirDemoniste.o Joueur.o VueConsole.o Sujet.o Observer.o Jeu.o Etat.o EtatDebutTour.o EtatDoubleNo.o EtatNoMana.o EtatNoAttaque.o Guerrier.o Chasseur.o Pretre.o Mage.o Demoniste.o FinDeJeu.o LancementJeu.o Main.o -o main

Carte.o:
	g++ -g -Wall include/Modele/Joueur/Deck/Carte/Carte.hpp -o bin/Modele/Joueur/Deck/Carte/Carte.o -c

Deck.o:
	g++ -g -Wall include/Modele/Joueur/Deck/Deck.hpp -o bin/Modele/Joueur/Deck/Deck.o -c

ComportementPouvoir.o:
	g++ -g -Wall include/Controleur/ComportementPouvoir/ComportementPouvoir.hpp -o bin/Controleur/ComportementPouvoir/ComportementPouvoir.o -c

ComportementPouvoirGuerrier.o:ComportementPouvoir.o
	g++ -g -Wall include/Controleur/ComportementPouvoir/ComportementPouvoirGuerrier.hpp -o bin/Controleur/ComportementPouvoir/ComportementPouvoirGuerrier.o -c

ComportementPouvoirChasseur.o:ComportementPouvoir.o
	g++ -g -Wall include/Controleur/ComportementPouvoir/ComportementPouvoirChasseur.hpp -o bin/Controleur/ComportementPouvoir/ComportementPouvoirChasseur.o -c

ComportementPouvoirPretre.o:ComportementPouvoir.o
	g++ -g -Wall include/Controleur/ComportementPouvoir/ComportementPouvoirPretre.hpp -o bin/Controleur/ComportementPouvoir/ComportementPouvoirPretre.o -c

ComportementPouvoirMage.o:ComportementPouvoir.o
	g++ -g -Wall include/Controleur/ComportementPouvoir/ComportementPouvoirMage.hpp -o bin/Controleur/ComportementPouvoir/ComportementPouvoirMage.o -c

ComportementPouvoirDemoniste.o:ComportementPouvoir.o
	g++ -g -Wall include/Controleur/ComportementPouvoir/ComportementPouvoirDemoniste.hpp -o bin/Controleur/ComportementPouvoir/ComportementPouvoirDemoniste.o -c

Joueur.o:
	g++ -g -Wall include/Modele/Joueur/Joueur.hpp -o bin/Modele/Joueur/Joueur.o -c

VueConsole.o:
	g++ -g -Wall include/Vue/VueConsole.hpp -o bin/Vue/VueConsole.o -c

Sujet.o:
	g++ -g -Wall include/Controleur/Sujet.hpp -o bin/Controleur/Sujet.o -c

Observer.o:
	g++ -g -Wall include/Controleur/Sujet.hpp -o bin/Controleur/Observer.o -c

Jeu.o:Sujet.o
	g++ -g -Wall include/Controleur/Jeu.hpp -o bin/Controleur/Jeu.o -c

Etat.o:
	g++ -g -Wall include/Controleur/Etat.hpp -o bin/Controleur/Etat.o -c

EtatDebutTour.o:Etat.o
	g++ -g -Wall include/Controleur/EtatDebutTour.hpp -o bin/Controleur/EtatDebutTour.o -c

EtatDoubleNo.o:Etat.o
	g++ -g -Wall include/Controleur/EtatDoubleNo.hpp -o bin/Controleur/EtatDoubleNo.o -c

EtatNoMana.o:Etat.o
	g++ -g -Wall include/Controleur/EtatNoMana.hpp -o bin/Controleur/EtatNoMana.o -c

EtatNoAttaque.o:Etat.o
	g++ -g -Wall include/Controleur/EtatNoAttaque.hpp -o bin/Controleur/EtatNoAttaque.o -c

Guerrier.o: Joueur.o
	g++ -g -Wall include/Modele/Joueur/Guerrier.hpp -o include/Modele/Joueur/Guerrier.o -c

Chasseur.o: Chasseur.o
	g++ -g -Wall include/Modele/Joueur/Chasseur.hpp -o include/Modele/Joueur/Chasseur.o -c

Pretre.o: Pretre.o
	g++ -g -Wall include/Modele/Joueur/Pretre.hpp -o include/Modele/Joueur/Pretre.o -c

Mage.o: Joueur.o
	g++ -g -Wall include/Modele/Joueur/Mage.hpp -o include/Modele/Joueur/Mage.o -c

Demoniste.o: Joueur.o
	g++ -g -Wall include/Modele/Joueur/Demoniste.hpp -o include/Modele/Joueur/Demoniste.o -c

FinDeJeu.o:Observer.o
	g++ -g -Wall include/Controleur/FinDeJeu.hpp -o bin/Controleur/FinDeJeu.o -c

LancementJeu.o:
	g++ -g -Wall include/Controleur/LancementJeu.hpp -o bin/Controleur/LancementJeu.o -c

Main.o:
	g++ -g -Wall Main.cpp -o Main.exe -c



