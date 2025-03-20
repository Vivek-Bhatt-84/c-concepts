#include <bits/stdc++.h>
using namespace std;


const vector<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
const vector<string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};


vector<string> createDeck() {
    vector<string> deck;
    for (const string& suit : suits) {
        for (const string& rank : ranks) {
            deck.push_back(rank + " of " + suit);
        }
    }
    return deck;
}


void shuffleDeck(vector<string>& deck) {
    int n = deck.size();
    srand(time(0)); 

    for (int i = 0; i < n; i++) {
        int randomCardNumber = i + (rand() % (n - i)); 
        swap(deck[i], deck[randomCardNumber]); 
    }
}


vector<vector<string>> distributeCards(vector<string>& deck, int numCards, int numPlayers) {
    if (numCards * numPlayers > deck.size()) {
        cout << "Error: Not enough cards to distribute!\n";
        return {};
    }

    vector<vector<string>> players(numPlayers); 
    int index = 0;

    for (int i = 0; i < numCards; i++) {
        for (int j = 0; j < numPlayers; j++) {
            players[j].push_back(deck[index++]);
        }
    }

    return players;
}

// Function to print the players and their cards
void printPlayers(const vector<vector<string>>& players) {
    for (int i = 0; i < players.size(); i++) {
        cout << "\nPlayer " << i + 1 << " cards: ";
        for (const string& card : players[i]) {
            cout << card << ", ";
        }
        cout << endl;
    }
}

int main() {
    int numCards, numPlayers;

    cout << "Enter number of players: ";
    cin >> numPlayers;
    cout << "Enter number of cards per player: ";
    cin >> numCards;

    vector<string> deck = createDeck();
    shuffleDeck(deck);

    vector<vector<string>> players = distributeCards(deck, numCards, numPlayers);

    if (!players.empty()) {
        printPlayers(players);
    }

    return 0;
}

