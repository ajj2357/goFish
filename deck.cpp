#include "deck.h"
#include "card.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

Deck::Deck()
{
   myIndex = 0;
   Card::Suit currSuit = Card::spades;
   while(currSuit <= Card::clubs)
   {
      for(int i = 1; i <= 13; i++)
      {
         myCards[i] = Card(i,currSuit);
      }
   }
}

void Deck::shuffle()
{
   srand(time(0));
   for(int i=0; i<SIZE; i++)
   {
      int i_rand = 1+(rand()%(SIZE-1));
      swap(myCards[i], myCards[i_rand]);
   }
}

Card Deck::dealCard()
{
//what do I include for a Fail?
   if(this->size() > 0)
   {
      Card::Card temp = myCards[myIndex];
      myIndex--;
      return temp;
   }
}

int Deck::size() const
{
   switch (myIndex)
   {
      case 0:
         return myIndex;
	 break;
      default:
	 return myIndex+1;
   }
}
