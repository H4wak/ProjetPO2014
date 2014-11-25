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
int VueConsole::getChoixJoueur()
{
	
	int i =0;
    cin >> i;
	return i;
}
/////////////////////////////////////////////////////////////////////////
string VueConsole::getNomJoueur()
{
	
	string s ="";
    cin >> s;
	return s;
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
	cout << "0 -> Passer votre tour. \n1 -> Afficher votre main. \n2 -> Jouer une carte. \n3 -> Afficher le board. \n4 -> Afficher les 2 boards. \n5 -> Afficher les Personnages.\n6 -> Attaquer une carte. \n7 -> Utiliser le pouvoir heroique \n8 -> Attaquer le héros adverse." << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherChoixNoMana()
{
	cout << "Que voulez vous faire ?" << endl;
	cout << "0 -> Passer votre tour. \n1 -> Afficher votre main. \n2 -> Afficher le board. \n3 -> Afficher les 2 boards. \n4 -> Afficher les personnages. \n5 -> Attaquer une carte. \n6 -> Attaquer le héros adverse" << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherChoixNoAttaque()
{
	cout << "Que voulez vous faire ?" << endl;
	cout << "0 -> Passer votre tour. \n1 -> Afficher votre main. \n2 -> Jouer une carte. \n3 -> Afficher le board. \n4 -> Afficher les 2 boards. \n5 -> Afficher les personnages. \n6 -> Utiliser le pouvoir héroïque." << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherChoixDoubleNo()
{
	cout << "Que voulez vous faire ?" << endl;
	cout << "0 -> Passer votre tour. \n1 -> Afficher votre main.  \n2 -> Afficher le board. \n3 -> Afficher les 2 boards.  \n4 -> Afficher les Personnages." << endl;
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
  string spdm = static_cast<ostringstream*>( &(ostringstream() << j->getPdm())  )->str();
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
  cout << "Quelle carte voulez-vous jouer ?" << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherPdmnRestant(int i)
{
  string si = static_cast<ostringstream*>( &(ostringstream() << i)  )->str();
	cout << "Il vous reste " + si + " point(s) de Mana." << endl;
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
   int pdvv = j->getPdv();
   int pdmn = j->getPdmTour();
   int armm = j->getArmure();
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
   int pdvv = j->getPdv();
   int pdmn = j->getPdm();
   int armm = j->getArmure();
   string pdv = static_cast<ostringstream*>( &(ostringstream() << pdvv)  )->str();
   string pdm = static_cast<ostringstream*>( &(ostringstream() << pdmn)  )->str();
   string arm = static_cast<ostringstream*>( &(ostringstream() << armm)  )->str();
    			
   cout << "\n Il a " + pdv + " points de vie. " << endl;
   cout << " Il a " + pdm + " points de Mana. " << endl;
   cout << " Il a " + arm + " points d'armure. \n" << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherChoixPouvoirMage()
{  			
	cout << "Entrez le numéro 1 pour attaquer le heros adverse,"<< endl << "sinon entrez un autre chiffre, puis la position sur le board de la carte a attaquer" << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherChoixPouvoirPretre()
{  			
	cout << "Entrez le numéro 1 pour soigner votre heros,"<< endl << "sinon entrez un autre chiffre, puis la position sur le board de la carte a soigner" << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherIntro()
{
	cout << "Bienvenue ! \n Vous allez commencer une partie du Jeu Hearthstone, un jeu convivial et divertissant ! \n";
	cout << "Mais pour cela vous devez choisir, votre adversaire et vous, un personnage que vous incarnerez ! \n";
	cout << "Vous avez le choix parmi 5 valeureux champions : \n 1- Le Guerrier : Son pouvoir héroïque vous permet de gagner 2 points d'armure ! \n 2- Le Chasseur : Son pouvoir héroïque vous permet d'infliger 2 points de dégats au Champion ennemi ! Wow ! \n 3- Le Mage : Son pouvoir héroïque vous permet d'infliger 1 point de dégat à n'importe qui, une créature ennemie ou le joueur adverse ! \n 4- Le Démoniste : Son pouvoir héroïque vous permet de piocher une carte contre 2 de vos points de vie ! \n 5- Le Prêtre : Son pouvoir héroïque vous permet de soigner 2 points de vie à un de vos serviteurs ou à vous même !\n 666- Le légendaire JXR : Son pouvoir héroïque détruit à l'aide d'une induction Noeutherienne n'importe quel serviteur ennemi! \n";  
	cout << "Indiquez votre nom puis le numéro du champion que vous choisissez, de même pour votre adversaire.\n";
} 

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherFinIntro()
{
	cout << "\n Merci ! Vos Decks vont maintenant être construits, bonne partie !\n";

}


/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherChoixCarte()
{
	cout << "Veuillez indiquer le numéro de la carte cible. " << endl;
}

/////////////////////////////////////////////////////////////////////////
void VueConsole::afficherChoixPouvoirInduction()
{
	cout << "Choisissez la carte adverse qui subira L'INDUCTION NOEUTHERIENNE ! MUAHAHAHAHHA!" << endl;
}






