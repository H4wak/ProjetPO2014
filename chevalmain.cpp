#include <string> // pour les chaines de caracteres
#include <iostream> // pour les entrées/sorties
#include <fstream> // pour la gestion des flux de fichier
#include <sstream> // pour la gestion des flux de string
using namespace std;
                       //toutes les fonctionnalités de la bibliothèque standard
#include "Personnage.hpp"//importe le fichier Personnage
#include "Carte.hpp"
#include "Deck.hpp"
#include "Joueur.hpp"



int main()
{
  Personnage guerrier;
  Joueur* Pierre = new Joueur("Pierre", guerrier,"test.txt");
  cout << Pierre->getDeck()->tirerCarte().toString() << endl;
 
  
  cout << Pierre->getDeck()->tirerCarte().toString() << endl;
  
  Carte * bla = new Carte(42,45,"ESSAI",56);
  Carte * bli = new Carte(42,45,"FLEUR",56);
  Carte * blo = new Carte(42,45,"CHEVAL",56);
  Carte * blu = new Carte(42,45,"SYNTHESE",56);
  Carte * bly = new Carte(42,45,"VIRAL",56);
  Carte * blmmmm = new Carte(42,45,"ERREUR",56);
  
  Pierre->ajouterMain(bla);
  Pierre->ajouterMain(bli);
  Pierre->ajouterMain(blo);
  Pierre->ajouterMain(blu);
  Pierre->ajouterMain(bly);
  cout << "baby" << endl;
  Pierre->ajouterMain(blmmmm);
  cout << "babyt" << endl;
  
  Pierre->ajouterBoard(bla);
  Pierre->ajouterBoard(bli);
  Pierre->ajouterBoard(blo);
  Pierre->ajouterBoard(blu);
  Pierre->ajouterBoard(bly);
  
  cout << "BLAvovo" << endl;
  
  cout << Pierre->afficherMain() << endl;

  return 0;
}
