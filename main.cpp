#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "JokerPool.h"
#include "ShopItem.h"
#include <iostream>
#include <cctype>
#include <random>
using namespace std;

void printHandType(Hand& hand) {
  switch (hand.getHandType()) {
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
}

int main() {
  Deck deck;
  Player you;
  Hand tempHand;
  JokerPool pool;
  random_device randy;


// Mrs. Griffin, what are your plans for cleaning up our environment?
  bool gameing = true;
  float scoreGoal = 0;
  int rounds = 0;
  

  while (gameing) {

    you.clearHand();
    Deck tempDeck = deck;
    tempDeck.shuffle();
    you.setHand(tempDeck, you.handSize);

    you.handsPlayed = 0;
    you.discardsUsed = 0;

    bool sent = false;
    bool read = false;
    bool loser = false;
    int cardsPlayed = 0;
    int playLimit = 5;
    scoreGoal += 300;
    rounds += 1;

    tempHand.addJokers(you.jokers);

    bool gamePhase = true;

    while (gamePhase) {
      cardsPlayed = tempHand.getHandSize();
//  What the name suggests: the phase where you're playing cards to hit the score
      sent = false;

//  Before doing anything, if you're out of cards, you LOSE.
      if (tempHand.getHandSize() == 0 && you.currentHand.getHandSize() == 0) {
        cout << "You're out of cards!" << endl;
        loser = true;
        gamePhase = false;
        break;
      }

//  Also making sure that you haven't used all your hands
      if (you.handsPlayed == you.handsCap) {
        cout << "You're out of moves!" << endl;
        loser = true;
        gamePhase = false;
        break;
      }


//  Displaying your hand
      
      if (!read) {    // This will only display if it hasn't been read before in the current round
        cout << you.getStr() << endl;
        cout << "Select up to 5 cards. Input 's' to play the hand or 'q' to quit." << endl;
        read = true;
      } else {
        cout << "Remaining Card(s): " << you.getStr() << endl;
      }

//  Getting the input
      string input;
      cin >> input;
      int choice = -1;
      bool valid = false;
      bool isNum = false;
      
//  Input handling
      while (!valid) {
        isNum = false;

//  Quitting
        if (input.at(0) == 'q') {
          cout << "Quitting now" << endl;
          return 0;
        }

//  Checking if the input was 's'
        if (input.at(0) == 's') {
          valid = true;
        }

//  Just adding a debug to skip the round
        if (input.at(0) == 'h') {
          valid = true;
          you.score += scoreGoal;
          you.giveMuns(50);
          input.at(0) = 's';
        }

//  If both previous failed, then check to see if it's all numbers
        if (!valid) {
          isNum = true;
          for (int i = 0; i < (int)input.length(); i++) {
            if (isalpha(input.at(i))) {
              isNum = false;
            }
          }
        }

//  Now we see if the choice is within bounds
        if (isNum && !valid) {
          choice = stoi(input);
          if (choice < 0 || choice > you.currentHand.getHandSize()) {
            cout << "That's not a card you have!" << endl;
          } else {
            valid = true;
          }
        }

        if (!valid) {
          cout << "Invalid input!" << endl;
          cin >> input;
        }

      }

//  Finally, now that the input is valid, we check if it's also a number, and if it is, it becomes choice.
      if (valid && isNum) {
        choice = stoi(input);
      }

//  Now that input is handled, we handle playing a card.
      if (choice != -1) {   //  -1 is our "not playing" number
        Card tempCard = you.currentHand.dealCard(choice);
        tempHand.addCard(tempCard);
        cardsPlayed = tempHand.getHandSize();

        if (!(cardsPlayed >= playLimit) && !(you.currentHand.getHandSize() == 0)) { //  If you still have options, print your selected cards
          cout << "Selected Card(s):\n" << tempHand.strHand() << endl;
        }
      }

//  This is where the hand gets played
      if (choice == -1 || cardsPlayed >= playLimit || you.currentHand.getHandSize() == 0) {
        bool playLoop = true;
        while (playLoop) {
          cout << "Current hand: " << tempHand.strHand() << endl;
          cout << you.discardsCap - you.discardsUsed << " discards remaining" << endl;
          cout << you.handsCap - you.handsPlayed << " hands remaining" << endl;
          cout << "What do you want to do with it?" << endl;
          cout << "'s' to play your hand\n'd' to discard it\n'c' to cancel" << endl;

          valid = false;

          while (!valid) {  //  Handling this input
            cin >> input;
            if (input.at(0) == 's' || input.at(0) == 'd' || input.at(0) == 'c') {
              valid = true;
            } else {
              cout << "Invalid input!" << endl;
            }
          }

  //  Now handling each option
          if (input.at(0) == 's') { //  Playing the hand
            if (tempHand.getHandType() == Hand::nothing) {
              cout << "You can't play nothing!" << endl;
            } else {
              you.handsPlayed += 1;
              sent = true;
              you.setHand(tempDeck, you.handSize);
              playLoop = false;
            }
          } 

          if (input.at(0) == 'd') { //  Discarding
            if (you.discardsUsed == you.discardsCap) {
              cout << "You're out of discards!" << endl;
            } else {
              you.discardsUsed += 1;
              tempHand.empty();
              you.setHand(tempDeck, you.handSize);
              playLoop = false;
            }
          }

          if (input.at(0) == 'c') {
            you.currentHand.returnCards(tempHand);
            playLoop = false;
          }
        }

//  Now finally, if it's time to send it, we send it.
        if (sent) {
          bool modified = false;
          printHandType(tempHand);
          float scored = tempHand.calculateHandScore(modified, you.muns, you.discardsCap - you.discardsUsed, you.handsCap - you.handsPlayed, you.currentHand);
          you.updateScore(scored);
          cout << "Your hand scored: " << scored << " points." << endl;
          cout << "Target score: " << scoreGoal << endl;
          cout << "Current score: " << you.score << "\n" << endl;

          if (modified) { // Will only trigger if a Joker modified at least one of your cards
            for (int i = 0; i < tempHand.getHandSize(); i++) {
              if (tempHand.swapping(i)) {
                Card tempCard = tempHand.getCard(i);
                deck.swapCard(tempCard);
              }
            }
          }

          tempHand.empty();
          sent = false;
          
          if (you.score >= scoreGoal) {
            you.resetScore();
            gamePhase = false;
          }
        }

      }

    }

    if (loser) {
      scoreGoal = 0;
      cout << "You LOST!!!" << endl;
      return 0;
    }

    you.giveMuns(you.handsCap - you.handsPlayed);
    you.giveMuns(4);
    

    bool shopLoop = true;
    vector<ShopItem> shop;
    shop.resize((randy() % 3) + 2);
    for (int i = 0; i < (int)shop.size(); i++) {
      Joker tempJoker = pool.drawJoker();
      shop.at(i).setJoker(tempJoker);
    }
    while (shopLoop) {
      cout << "You have $" << you.muns << endl;

      for (int i = 0; i < (int)shop.size(); i++) {
        cout << "[" << i + 1 << "] " << shop.at(i).displayItem() << endl;
      }

      cout << "Choose what you want to buy, or enter 'e' to exit" << endl;
      string input = "";


      bool valid = false;
      int choice = -1;
      bool isNum = false;

      while (!valid) {
        isNum = false;
        cin >> input;

        if (input.at(0) == 'e') {
          valid = true;
          shopLoop = false;
          break;
        }

        isNum = true;
        for (int i = 0; i < (int)input.length(); i++) {
          if (isalpha(input.at(i))) {
            isNum = false;
          }
        }

        if (isNum) {
          choice = stoi(input);
        }
        if (choice > 0 && choice < (int)shop.size() + 1) {
          valid = true;
          break;
        }
        cout << "That's not a valid input!" << endl;
      }
      choice -= 1;

      if (choice > -1) {
        if (shop.at(choice).getPrice() > you.muns) {
          cout << "You don't have enough money!" << endl;
        } else {
          if (shop.at(choice).getItemType() == ShopItem::joker) {
            if (!you.hasJokerRoom()) {
              cout << "You don't have enough space!" << endl;
            } else {
              Joker tempJoker = shop.at(choice).getJoker();
              you.addJoker(tempJoker);
              you.takeMuns(shop.at(choice).getPrice());
              shop.erase(shop.begin() + choice);
            }
          }
        } 
      }
    }
    for (int i = 0; i < (int)shop.size(); i++) {
      if (shop.at(i).getItemType() == ShopItem::joker) {
        Joker tempJoker = shop.at(i).getJoker();
        pool.returnJoker(tempJoker);
      }
    }

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
