
#include "Logic.h"

std::queue<Person> Logic::players = queue<Person>();
std::stack<Card> Logic::deck = stack<Card>();
Card Logic::last_card = Card();
std::vector<Card> Logic::penalty_cards = vector<Card>();
// cpp file for definition of data structures