#include "cards.h"
#include <cstdlib>
#include <iostream>

//cards.cpp is for all the member functions definitions in cards.h


/*
 You might or might not need these two extra libraries
 #include <algorithm>
 #include <iomanip>
 */


/* *************************************************
 Card class
 ************************************************* */

/*
 Default constructor for the Card class.
 It could give repeated cards. This is OK.
 Most variations of Blackjack are played with
 several decks of cards at the same time.
 */
Card::Card(){
    int r = 1 + rand() % 4;
    switch (r) {
        case 1: suit = OROS; break;
        case 2: suit = COPAS; break;
        case 3: suit = ESPADAS; break;
        case 4: suit = BASTOS; break;
        default: break;
    }
    
    r = 1 + rand() % 10;
    switch (r) {
        case  1: rank = AS; break;
        case  2: rank = DOS; break;
        case  3: rank = TRES; break;
        case  4: rank = CUATRO; break;
        case  5: rank = CINCO; break;
        case  6: rank = SEIS; break;
        case  7: rank = SIETE; break;
        case  8: rank = SOTA; break;
        case  9: rank = CABALLO; break;
        case 10: rank = REY; break;
        default: break;
    }
}

// Accessor: returns a string with the suit of the card in Spanish
string Card::get_spanish_suit() const {
    string suitName;
    switch (suit) {
        case OROS:
            suitName = "oros";
            break;
        case COPAS:
            suitName = "copas";
            break;
        case ESPADAS:
            suitName = "espadas";
            break;
        case BASTOS:
            suitName = "bastos";
            break;
        default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish
string Card::get_spanish_rank() const {
    string rankName;
    switch (rank) {
        case AS:
            rankName = "As";
            break;
        case DOS:
            rankName = "Dos";
            break;
        case TRES:
            rankName = "Tres";
            break;
        case CUATRO:
            rankName = "Cuatro";
            break;
        case CINCO:
            rankName = "Cinco";
            break;
        case SEIS:
            rankName = "Seis";
            break;
        case SIETE:
            rankName = "Siete";
            break;
        case SOTA:
            rankName = "Sota";
            break;
        case CABALLO:
            rankName = "Caballo";
            break;
        case REY:
            rankName = "Rey";
            break;
        default: break;
    }
    return rankName;
}



// Accessor: returns a string with the suit of the card in English
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
    string english_suit;
    if (suit == OROS)
        {english_suit = "coins";}
    else if (suit == COPAS )
        {english_suit = "cups";}
    else if (suit == BASTOS)
        {english_suit = "clubs";}
    else if (suit == ESPADAS)
        {english_suit = "swords";}
    return english_suit;
}

// Accessor: returns a string with the rank of the card in English
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
    string english_rank;
    if (rank == AS)
        {english_rank = "Ace";}
    else if (rank == DOS)
        {english_rank = "Two";}
    else if (rank == TRES)
        {english_rank = "Three";}
    else if (rank == CUATRO)
        {english_rank = "Four";}
    else if (rank == CINCO)
        {english_rank = "Five";}
    else if (rank == SEIS)
        {english_rank = "Six";}
    else if (rank == SIETE)
        {english_rank = "Seven";}
    else if (rank == SOTA)
        {english_rank = "Jack";}
    else if (rank == CABALLO)
        {english_rank = "Knight";}
    else if (rank == REY)
        {english_rank = "King";}
    return english_rank;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
    return static_cast<int>(rank) + 1 ;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
    return rank < card2.rank;
}



/* *************************************************
 Hand class
 ************************************************* */
// Implemente the member functions of the Hand class here.
Hand::Hand()
{
    Card c1;
    //first_card = c.get_spanish_rank() + " de " + c.get_spanish_suit() + "        (" + c.get_english_rank() + " of " + c.get_english_suit() + ")";
    
    cards.push_back(c1);
    int x = c1.get_rank();
    total = calc_value(x);
}

void Hand::return_first_card() const
{
    string first_card;
    first_card = cards[0].get_spanish_rank() + " de " + cards[0].get_spanish_suit() + "        (" + cards[0].get_english_rank() + " of " + cards[0].get_english_suit() + ")";
    cout << "        " << first_card << endl;
}

void Hand::new_card()
{
    Card c;
    string new_card;
    new_card = c.get_spanish_rank() + " de " + c.get_spanish_suit() + "        (" + c.get_english_rank() + " of " + c.get_english_suit() + ")";
    cout << "        " << new_card << endl;
    
    //sorting cards in hand
    int pos;
    for (int i=0; i < cards.size(); i++)
    {
        if (cards[i] < c)
        {
            pos = i+1;
        }
    }
    
    int last = cards.size()-1;
    cards.push_back(cards[last]);
    for (int j=last; j>pos; j--)
        cards[j] = cards[j-1];
    cards[pos] = c;
    
    //calc total value of hand
    int x = c.get_rank();
    total = total + calc_value(x);
}

void Hand::return_cards() const
{
    for (int i=0; i<cards.size(); i++)
    {
        cout << "        " << cards[i].get_spanish_rank() + " de " + cards[i].get_spanish_suit() + "        (" + cards[i].get_english_rank() + " of " + cards[i].get_english_suit() + ")" << endl;
    }
}

double Hand::calc_value(int x)
{
    double value = 0.0;
    if (x <=7)
    {value = x; }
    else if (x == (10)||(11)||(12))
    {value = 0.5; }
    return value;
}

double Hand::return_total() const
{
    return total;
}


/* *************************************************
 Player class
 ************************************************* */
// Implemente the member functions of the Player class here.
Player::Player(int m)
{
    money = m;
}

int Player::get_money() const
{
    return money;
}

void Player::change_money(int n)
{
    money = money + n;
}

