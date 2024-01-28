
#ifndef PAIN2_LOGIC_H
#define PAIN2_LOGIC_H

#include "list"
#include "../Model/Card.h"
#include "queue"
#include "string"
#include "stack"
#include "../Model/Person.h"

#include <algorithm>
#include <random>
#include <iostream>
#include "../Model/Number_cards.h"
#include "../Model/Action_cards.h"
#include "../Model/Wild_cards.h"
#include "typeinfo"
#include "vector"
#include <memory>

using std::shared_ptr;
using namespace std;

class Logic {
private:
    static queue<Person> players;           //queue of players
    static stack<Card> deck;
    static Card last_card;
    Color last_color;
    static vector<Card> penalty_cards;

public:

    static queue<Person> add_players(Person &player) {    // pushes player to the queue
        players.push(player);
        return players;
    }

    static queue<Person> get_players() {    //getter for queue of players
        return players;
    }

    static stack<Card> get_deck() {     // getter for deck of cards
        return deck;
    }

    static vector<Card> get_penalty_cards() {    // getter for penalty cards
        return penalty_cards;
    }

    static Card get_last_card() {    // getter for board card
        return last_card;
    }

    static int
    index_to_value(int index, const Person &person) {   // returns vale of the card by given index of it in hands
        multiset<Card, Compare> list_vec = person.get_all_cards();   //temporary multiset
        int v;
        Card temp;
        int counter = 0;
        int result;
        for (auto it = Person::get_all_cards().begin(); it != Person::get_all_cards().end(); ++it) {
            auto iter = list_vec.begin();              // looks for specific index through each card of the hands
            if (counter == index) {
                result = list_vec.begin()->get_value();       // returns the value of searched card
                break;
            }
            list_vec.erase(iter);
            counter++;

        }

        return result;
    }

    static void give_cards(int num, Person &person) {    // distributes cards for players
        person.get_all_cards().clear();
        for (int n = 0; n < num; n++) {
            person.get_all_cards().insert(deck.top());
            deck.pop();
        }

    }

    static void find_pile_card() {    // looks for board card
        std::stack<Card> tempStack;

        while (!deck.empty()) {

            last_card = deck.top();
            deck.pop();

            if ((last_card.get_value() >= 1 && last_card.get_value() < 20) ||
                // the board card should be the number card
                (last_card.get_value() < 45 && last_card.get_value() >= 26) ||
                (last_card.get_value() >= 51 && last_card.get_value() < 70) ||
                (last_card.get_value() >= 76 && last_card.get_value() < 95)) {
                break;
            }

            // Transfer non-number cards to a temporary stack
            tempStack.push(last_card);
        }

        // Transfer the non-number cards back to the main deck
        while (!tempStack.empty()) {
            deck.push(tempStack.top());
            tempStack.pop();
        }
    }


    static void change_top_card(Card new_card) {   // changes the board card
        deck.push(last_card);
        last_card = new_card;
    }

    static bool check_card(Card chosen_card, Person player) {    //check card for its original value and type
        if (is_wild_draw(chosen_card)) {
            return true;
        }
        if (is_wild_four(chosen_card)) {
            for (Card card: player.get_all_cards()) {
                if (is_wild_four(chosen_card)) {
                    continue;
                }
                if (check_card(card, player)) {
                    return false;
                }
            }
            return true;
        }

        if (is_draw_two(last_card) && penalty_cards.size() != 0) {
            if (is_draw_two(chosen_card)) {
                return true;
            } else {
                return false;
            }
        }

        if (is_number_card(chosen_card) && is_number_card(last_card)) {
            if (chosen_card.get_value() == last_card.get_value()) {
                return true;
            }
        }
        if (chosen_card.get_color() == last_card.get_color()) {
            return true;
        }
        if (is_skip(chosen_card) && is_skip(last_card)) {
            return true;
        }
        if (is_reverse(chosen_card) && is_reverse(last_card)) {
            return true;
        }
        return false;
    }

    static void implement_choice(Card &chosen_card, Color color) {  //handle card of type wild four and draw two
        change_top_card(chosen_card);

        if (is_wild_four(chosen_card)) {
            for (int i = 0; i < 4; ++i) {
                penalty_cards.push_back(deck.top());    // adds additional card as penalty
                deck.pop();
            }
        } else if (is_draw_two(chosen_card)) {
            for (int i = 0; i < 2; ++i) {
                penalty_cards.push_back(deck.top());   // adds two cards to penalty vector
                deck.pop();
            }
        }
    }

    static void make_cards(Color color, int card_value) {   //creates 108 cards for the game
        deck.push(Number_cards(color, ++card_value, 0));
        deck.push(Number_cards(color, ++card_value, 1));
        deck.push(Number_cards(color, ++card_value, 2));
        deck.push(Number_cards(color, ++card_value, 3));
        deck.push(Number_cards(color, ++card_value, 4));
        deck.push(Number_cards(color, ++card_value, 5));
        deck.push(Number_cards(color, ++card_value, 6));
        deck.push(Number_cards(color, ++card_value, 7));
        deck.push(Number_cards(color, ++card_value, 8));
        deck.push(Number_cards(color, ++card_value, 9));

        deck.push(Number_cards(color, ++card_value, 1));
        deck.push(Number_cards(color, ++card_value, 2));
        deck.push(Number_cards(color, ++card_value, 3));
        deck.push(Number_cards(color, ++card_value, 4));
        deck.push(Number_cards(color, ++card_value, 5));
        deck.push(Number_cards(color, ++card_value, 6));
        deck.push(Number_cards(color, ++card_value, 7));
        deck.push(Number_cards(color, ++card_value, 8));
        deck.push(Number_cards(color, ++card_value, 9));

        deck.push(Action_cards(Action_cards::Action::SKIP, color, ++card_value));
        deck.push(Action_cards(Action_cards::Action::SKIP, color, ++card_value));


        deck.push(Action_cards(Action_cards::Action::REVERSE, color, ++card_value));
        deck.push(Action_cards(Action_cards::Action::REVERSE, color, ++card_value));


        deck.push(Action_cards(Action_cards::Action::DRAW_TWO, color, ++card_value));
        deck.push(Action_cards(Action_cards::Action::DRAW_TWO, color, ++card_value));
        // every card has its specific value

    }

    static void create_deck() {   // creates deck through make_cards method by given it color and value
        int value = 0;
        make_cards(Color::GREEN, value);

        value += 25;
        make_cards(Color::RED, value);

        value += 25;
        make_cards(Color::YELLOW, value);

        value += 25;
        make_cards(Color::BLUE, value);
        value += 25;

        for (int i = 0; i < 4; ++i) {    // creation of wild cards
            deck.push(Wild_cards(Wild_cards::Wild::PLUS_FOUR, ++value));
        }

        for (int i = 0; i < 4; ++i) {
            deck.push(Wild_cards(Wild_cards::Wild::CHANGE_COLOR, ++value));
        }
    }

    static void shuffle_cards() {    // shuffle the deck
        vector<Card> ready_cards;
        while (!deck.empty()) {
            ready_cards.push_back(deck.top());   // pushes from stack to vector
            deck.pop();
        }
        std::random_device rd;
        std::shuffle(ready_cards.begin(), ready_cards.end(), rd);  //using standard library function shuffle

        for (const auto &card: ready_cards) {
            deck.push(card);                           //returns to stack of deck
        }
    }

    static bool have_at_least_one_card(Person &person) {   //return true if a player has at least one card
        for (Card card: person.get_all_cards()) {
            if (check_card(card, person)) {
                return true;
            }
        }
        return false;
    }

    static void give_cards_to(Person &player) {   //gives one card to selected player
        player.add_cards(deck.top());
        deck.pop();
    }

    static void reverse_players() {       //reverse the order
        std::stack<Person> s;

        // Push elements from the queue to the stack
        while (!get_players().empty()) {
            s.push(get_players().front());
            get_players().pop();
        }

        // Pop elements from the stack and push them back to the queue
        while (!s.empty()) {
            get_players().push(s.top());
            s.pop();
        }
    }


    static int
    track_queue(Card &chosen_card, int position) {                    //Track queue by controlling posiiton int
        if (is_skip(chosen_card) || is_wild_four(chosen_card)) {
            position = position + 2;
        } else if (is_reverse(chosen_card)) {
            reverse_players();
            position = (players.size() - position);
        } else if (position + 1 == players.size()) {   //the end of round
            position = 0;
        } else {
            position++;
        }
        int result = position % (players.size());
        return result;
    }

    static bool end_of_game() {                     // boolean of the end of game
        queue<Person> temp = players;
        while (!temp.empty()) {
            Person person = temp.front();
            temp.pop();
            if (person.get_all_cards().size() == 0) {   //if one player has zero cards. the game will end
                return true;
            }
        }
        return false;
    }

    static Person access_by_index(const queue<Person> &person, int index) {  // access player by its index in a queue
        queue<Person> temp = person;
        for (int i = 0; i < index; ++i) {
            temp.pop();                            //looks for selected player by using temporary queue
        }
        Person p = temp.front();
        return p;
    }

    static bool is_wild_four(const Card &card) {    // true if card is wild four card
        if (card.get_value() > 100 && card.get_value() <= 104) {  //looks for it through its specific value
            return true;
        }
        return false;
    }

    static bool is_wild_draw(Card card) {   // true if card is wild draw card
        if (card.get_type() == Type::WILD_CARD && !is_wild_four(card)) { //looks for it through its specific value
            return true;
        }
        return false;
    }

    static bool is_skip(const Card &card) {
        if ((card.get_value() > 19 && card.get_value() <= 21) || (card.get_value() > 44 && card.get_value() <= 46) ||
            (card.get_value() > 69 && card.get_value() <= 71) || //looks for it through its specific value
            (card.get_value() > 94 && card.get_value() <= 96)) {
            return true;
        }
        return false;
    }

    static bool is_reverse(const Card &card) {
        if ((card.get_value() <= 98 && card.get_value() > 96) || (card.get_value() > 21 && card.get_value() <= 23) ||
            (card.get_value() > 46 && card.get_value() <= 48) ||
            (card.get_value() > 71 && card.get_value() <= 73)) {  //looks for it through its specific value
            return true;
        }
        return false;
    }

    static bool is_draw_two(const Card &card) {
        if ((card.get_value() <= 100 && card.get_value() > 98) || (card.get_value() > 23 && card.get_value() <= 25) ||
            (card.get_value() > 48 && card.get_value() <= 50) ||
            (card.get_value() > 73 && card.get_value() <= 75)) {   //looks for it through its specific value
            return true;
        }
        return false;
    }

    static bool is_number_card(Card card) {
        if (card.get_type() == Type::NUMBER_CARD) {   //looks for number card by Type enum
            return true;
        }
        return false;
    }

    static Person get_player_by_index(int index) {
        std::queue<Person> tempQueue = players;  //return player by its index
        Person result;

        for (int i = 0; i <= index; ++i) {
            result = tempQueue.front();
            tempQueue.pop();
        }
        return result;
    }

    static void reset() {   //resets the data structures of the game
        players = queue<Person>();
        deck = stack<Card>();
        penalty_cards = vector<Card>();
    }

};


#endif //PAIN2_LOGIC_H
