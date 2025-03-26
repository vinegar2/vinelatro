#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
using namespace std;

int main() {
  Deck deck;
  


  Player you;

// Mrs. Griffin, what are your plans for cleaning up our environment?
  bool gameing = true;

  while (gameing) {
    you.clearHand();
    Deck tempDeck = deck;
    tempDeck.shuffle();
    you.setHand(tempDeck, 7);

    you.orderHand();
    cout << you.getStr() << endl;

    cout << "Select up to 5 of your cards, or input 0 to send it: " << flush;

    Hand tempHand;

    bool running = true;
    int cardsPlayed = 0;
    int playLimit = 5;

    while (running) {

      if (tempHand.getHandSize() == 0 && you.currentHand.getHandSize() == 0) {
        cout << "You have NONE CARDS" << endl;
        break;
      }

      int choice;
      cin >> choice;

      while (choice < 0) {
        cout << "Wrong." << endl;
        cin >> choice;
      }

      if (tempHand.getHandSize() == 0 && you.currentHand.getHandSize() == 0) {
        cout << "You have NONE CARDS" << endl;
        break;
      }
      
      if (choice > 0) {
        if (choice <= you.currentHand.getHandSize()) {
          Card tempCard = you.currentHand.dealCard(choice);
          tempHand.addCard(tempCard);
          cardsPlayed = tempHand.getHandSize();

          cout << "Selected Card(s):\n" << tempHand.strHand() << endl;
          cout << "Remaining Card(s):\n" << you.getStr() << "\n" << endl;
        } else {
          cout << "That's not a card you have!" << endl;
        }
      } 

      if (choice == 0 || cardsPlayed >= playLimit || you.currentHand.getHandSize() == 0) {

        cout << "Current hand: " << tempHand.strHand() << endl;
        cout << "What do you wanna do with it?" << endl;
        cout << "[1] Send it\n[2] Discard it\n[3] Cancel" << endl;

        int choice2;

        cin >> choice2;

        while (choice2 < 1 || choice2 > 3) {
          cout << "Wrong." << endl;
          cin >> choice2;
        }

        if (choice2 == 1) {
          if (tempHand.getHandType() == Hand::nothing) {
            cout << "You can't play nothing!" << endl;
            you.currentHand.returnCards(tempHand);
            cardsPlayed = tempHand.getHandSize();

            you.orderHand();

            cout << you.getStr() << endl;
            cout << "Select up to 5 of your cards, or input 0 to send it: " << flush;
          } 

          else {          
            running = false;
          }

        } 
        else if (choice2 == 2) {
          tempHand.empty();
          you.currentHand.fillHand(tempDeck, 7);
          cardsPlayed = tempHand.getHandSize();

          you.orderHand();

          cout << you.getStr() << endl;
          cout << "Select up to 5 of your cards, or input 0 to send it: " << flush;

        }
        else if (choice2 == 3) {
          you.currentHand.returnCards(tempHand);
          cardsPlayed = tempHand.getHandSize();

          you.orderHand();

          cout << you.getStr() << endl;
          cout << "Select up to 5 of your cards, or input 0 to send it: " << flush;
        }


      }

    }
    cout << "\n" << flush;

    switch (tempHand.getHandType()) {
      case Hand::straight_flush: 
        cout << "Straight flush?!?! EaauaghuhH??" << endl;
        break;
      case Hand::four:
        cout << "Four of a kind!" << endl;
        break;
      case Hand::full_house:
        cout << "Full House!" << endl;
        break;
      case Hand::flush:
        cout << "Flush!" << endl;
        break;
      case Hand::straight:
        cout << "Straight!" << endl;
        break;
      case Hand::three:
        cout << "Three of a Kind!" << endl;
        break;
      case Hand::two_pair:
        cout << "Two Pair!" << endl;
        break;
      case Hand::pair:
        cout << "Pair!" << endl;
        break;
      case Hand::high:
        cout << "High Card!" << endl;
        break;
      case Hand::nothing:
        cout << "Absolutely nothing." << endl;
        break;
      default:
        cout << "What the fuck did you do" << endl;
        break;
    }

    cout << "\nYour hand scored: " << tempHand.calculateHandScore() << " points." << endl;



    cout << "\nAgain? (y/n) " << flush;
    char againAGAIN;
    cin >> againAGAIN;

    while (againAGAIN != 'y' && againAGAIN != 'n') {
      bool evilMode = true;
      cout << "That is neither y nor n. " << flush;
      cin >> againAGAIN;
      if (evilMode) {}
    }
    if (againAGAIN == 'y') {
      gameing = true;
    } else {
      gameing = false;
    }
  }


  

  return 0;
}
