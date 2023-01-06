#include <bits/stdc++.h>
using namespace std;

class Card {
public:
  virtual void display() { cout << "Card" << endl; }

  virtual string getColor() { return ""; }
};
class PlayingCard : public Card {
public:
  string suit;
  string value;

  void display() override { cout << value << " of " << suit << endl; }

  string getColor() override {
    if (suit == "Spades" || suit == "Clubs") {
      return "Black";
    } else {
      return "Red";
    }
  }
};
class RandomCard : public PlayingCard {
public:
  void generate() {
    srand(time(0));
    // Generate a random suit
    const string suits[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    suit = suits[rand() % 4];

    // Generate a random value
    const string values[13] = {"Ace", "2", "3",  "4",    "5",     "6",   "7",
                               "8",   "9", "10", "Jack", "Queen", "King"};
    value = values[rand() % 13];
  }
  int lcm(int a, int b) { return (a * b) / hcf(a, b); }

  int hcf(int a, int b) {
    if (b == 0) {
      return a;
    }
    return hcf(b, a % b);
  }

  void display() override {
    cout << "Color: " << getColor() << endl;
    if (value == "Jack" || value == "Queen" || value == "King") {
      cout << "This is a face card (Jack/Queen/King)." << endl;
    } else {
      srand(time(0));
      // Generate a random number between 1 and 10
      int number = rand() % 10 + 1;
      cout << "The LCM of Card number and " << number << " is "
           << lcm(stoi(value), number) << endl;
      cout << "The HCF of Card number and " << number << " is "
           << hcf(stoi(value), number) << endl;
    }
  }
};

int main() {
  RandomCard card;
  card.generate();
  card.display();

  int chances = 5;
  while (chances > 0) {
    cout << "Enter the suit and value of the card "
            "(Spades/Hearts/Diamonds/Clubs):";
    string suit, value;
    cin >> suit >> value;

    if (suit == card.suit && value == card.value) {
      cout << "You guessed correctly!" << endl;
      return 0;
    } else {
      cout << "Incorrect guess. You have " << --chances << " chances left."
           << endl;
    }
  }

  cout << "You ran out of chances. The correct card was " << card.suit << " "
       << card.value << "." << endl;
  return 0;
}
