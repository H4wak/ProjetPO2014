#include <string> // pour les chaines de caracteres
#include <iostream> // pour les entrées/sorties
#include <fstream> // pour la gestion des flux de fichier
#include <sstream> // pour la gestion des flux de string
using namespace std;
                       //toutes les fonctionnalités de la bibliothèque standard
#include "Joueur.hpp"//importe le fichier Joueur
#include "Guerrier.hpp"//importe le fichier Joueur

int main()
{

  Personnage* guerrier = new Guerrier();
	cout << guerrier->toString();
  Joueur* Pierre = new Joueur("Pierre", *guerrier,"test.txt");
  cout << Pierre->getDeck()->tirerCarte().toString();
  Pierre->getPersonnage().setCP(new ComportementPouvoirGuerrier());
  cout << Pierre->getPersonnage().utiliserPouvoir();
 

  return 0;
}
