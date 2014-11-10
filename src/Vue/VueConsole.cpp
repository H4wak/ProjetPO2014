/*
   Fichier VueConsole.cpp

   Définition des méthodes de VueConsole
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/////////////////////////////////////////////////////////////////////////

VueConsole::VueConsole()
{

}
/////////////////////////////////////////////////////////////////////////

VueConsole::~VueConsole()
{

}

/////////////////////////////////////////////////////////////////////////
int VueConsole::getChoixActionTour()
{
	int i =0;
  cin >> i;
	return i;
}

/////////////////////////////////////////////////////////////////////////
int VueConsole::getChoixCarteAJouer()
{
  int i =0;
  cin >> i;
	return i;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherMain(Joueur* j)
{
  cout << "\n●●--●●--●● VOTRE MAIN ●●--●●--●●" << endl;
	cout <<  j->afficherMain() << endl; 
	cout << "●●--●●--●●--●●--●●--●●--●●--●●--●●\n" << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherChoixDebutTour()
{
	cout << "Que voulez vous faire ?" << endl;
	cout << "0 -> passer votre tour. \n1 -> afficher votre main. \n2 -> jouer une carte. \n3 -> afficher le board. \n4 -> afficher les 2 boards. \n5 -> Afficher les Personnages.\n6 -> Attaquer une carte. \n7 -> utiliser le pouvoir heroique \n8 -> attaquer le heros adverse." << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherChoixNoMana()
{
	cout << "Que voulez vous faire ?" << endl;
	cout << "0 -> passer votre tour. \n1 -> afficher votre main. \n2 -> afficher le board. \n3 -> afficher les 2 boards. \n4 -> Afficher votre Personnages. \n5 -> Attaquer une carte. \n6 -> attaquer le heros adverse" << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherChoixNoAttaque()
{
	cout << "Que voulez vous faire ?" << endl;
	cout << "0 -> passer votre tour. \n1 -> afficher votre main. \n2 -> jouer une carte. \n3 -> afficher le board. \n4 -> afficher les 2 boards. \n5 -> Afficher les Personnages. \n6 -> utiliser le pouvoir heroique." << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherChoixDoubleNo()
{
	cout << "Que voulez vous faire ?" << endl;
	cout << "0 -> passer votre tour. \n1 -> afficher votre main.  \n2 -> afficher le board. \n3 -> afficher les 2 boards.  \n4 ->  Afficher les Personnages." << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherBoard(Joueur* j)
{
  cout << "\n°•. °•. °•. VOTRE BOARD .•° .•° .•°" << endl;
  cout << j->afficherBoard() << endl;
  cout << "°•. °•. °•. °•. °•. .•° .•° .•° .•° .•°\n" << endl; 
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficher2Board(Joueur* j1, Joueur* j2)
{
  cout << "\n°•. °•. °•. VOTRE BOARD .•° .•° .•°" << endl;
  cout << j1->afficherBoard() << endl;
  cout << "°•. °•. °•. °•. °•. .•° .•° .•° .•° .•°\n" << endl; 
  
  cout << "\n°•. °•. °•. SON BOARD .•° .•° .•°" << endl;
  cout << j2->afficherBoard() << endl;
  cout << "°•. °•. °•. °•. °•. .•° .•° .•° .•° .•°\n" << endl; 
  
  
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherDebutTour(Joueur* j)
{
	cout << "C'est à " + j->getNom() + " de jouer." << endl;	
  string spdm = static_cast<ostringstream*>( &(ostringstream() << j->getPersonnage().getPdm())  )->str();
	cout <<  "Vous avez " + spdm + " points de Mana." << endl;
	cout << j->afficherMain() << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherFinTour()
{
  cout << "\n▁ ▂ ▄ ▅ ▆ ▇ █ Fin du Tour █ ▇ ▆ ▅ ▄ ▂ ▁\n" << endl;  
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherJouerCarte()
{
  cout << "Quelle carte voulez-vous jouez ?" << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherPdmnRestant(int i)
{
  string si = static_cast<ostringstream*>( &(ostringstream() << i)  )->str();
	cout << "Il vous reste " + si + " points de Mana." << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherPasAssezDeMana()
{
  cout << "Pas assez de Mana !" << endl;
}
/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherChoixCvC()
{
	cout << "Entrez le numéro de votre Carte, appuyez sur Entrée, puis faites de même avec la Carte de l'adversaire" << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherChoixCvJ()
{
	cout << "Entrez le numéro de votre Carte, appuyez sur Entrée" << endl;
}


/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherPersonnage(Joueur* j)
{
   int pdvv = j->getPersonnage().getPdv();
   int pdmn = j->getPersonnage().getPdm();
   int armm = j->getPersonnage().getArmure();
   string pdv = static_cast<ostringstream*>( &(ostringstream() << pdvv)  )->str();
   string pdm = static_cast<ostringstream*>( &(ostringstream() << pdmn)  )->str();
   string arm = static_cast<ostringstream*>( &(ostringstream() << armm)  )->str();
    			
   cout << "\n Vous avez " + pdv + " points de vie. " << endl;
   cout << " Vous avez " + pdm + " points de Mana. " << endl;
   cout << " Vous avez " + arm + " points d'armure. \n" << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherPersonnageAutre(Joueur* j)
{
   int pdvv = j->getPersonnage().getPdv();
   int pdmn = j->getPersonnage().getPdm();
   int armm = j->getPersonnage().getArmure();
   string pdv = static_cast<ostringstream*>( &(ostringstream() << pdvv)  )->str();
   string pdm = static_cast<ostringstream*>( &(ostringstream() << pdmn)  )->str();
   string arm = static_cast<ostringstream*>( &(ostringstream() << armm)  )->str();
    			
   cout << "\n Il a " + pdv + " points de vie. " << endl;
   cout << " Il a " + pdm + " points de Mana. " << endl;
   cout << " Il a " + arm + " points d'armure. \n" << endl;
}







