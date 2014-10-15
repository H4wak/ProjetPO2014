/* 
   Fichier Deck.hpp

   Définition du type Deck
*/

#ifndef DECK_HPP
#define DECK_HPP

#include <string> // pour les chaines de caracteres
#include <iostream> // pour les entrées/sorties
#include <fstream> // pour la gestion des flux de fichier
#include <sstream> // pour la gestion des flux de string
#include <stack>
#include <string> // pour le type std::string
#include "Carte.hpp"

/******************************************************************************/
class Deck
{
   private :
      int taille;
      std::stack<Carte> d;
      
   public :
   	  
   	  Deck(std::string fichier);
   	  ~Deck();
   	  
   	  int getTaille();
   	  void setTaille(int t);
   	  std::stack<Carte> getStack();
   	  
   	  Carte tirerCarte();
   	  
};

/******************************************************************************/
#include "Deck.cpp"
#endif // DECK_HPP
