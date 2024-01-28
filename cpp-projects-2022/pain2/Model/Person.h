
#ifndef PAIN1_PERSON_H
#define PAIN1_PERSON_H

#include <set>
#include <vector>
#include <memory>
#include "Card.h"
#include "list"
#include "string"


using namespace std;

struct Compare {                  // Compare struct for creating multiset
    bool operator()(const Card &first, const Card &second) const {   //sorts by color, and by value
        if (first.get_color() < second.get_color())return true;
        else if (first.get_color() > second.get_color())return false;
        return first.get_value() < second.get_value();
    }
};

class Person {
private:
    string name;
    static int score;
    string person = "person";
    static multiset<Card, Compare> cards_of_p;

public:
    Person(string name) {
        this->name = name;
        this->score = 0;
    }

    static void add_cards(Card new_card) {   //add cards to multiset
        cards_of_p.insert(new_card);
    }

    static multiset<Card, Compare> &get_all_cards() {
        return cards_of_p;

    }

    static int get_score() {
        return score;
    }

    static Card remove_card(int card_code) {
        Card past_card = Card();
        auto iter = cards_of_p.begin();
        int index = 0;

        for (auto it = cards_of_p.begin(); it != cards_of_p.end(); ++it) {   // looks for card by its value(code)

            if ((*it).get_value() == card_code) {
                past_card = (*it);
                break;
            }
            index++;
        }

        advance(iter, index);
        cards_of_p.erase(iter);   // erase founded card

        return past_card;
    }

    static bool has_card(int card_value) {
        for (Card card: cards_of_p) {
            if (card.get_value() == card_value) {
                return true;
            }
        }
        return false;
    }

    void set_name(string new_name) {
        name = new_name;

    }

    string get_name() {
        return this->name;
    }


    Person() = default;

    virtual string get_type_of_p() {
        return person;
    }

    void set_type(string s) {
        person = s;
    }
};


#endif //PAIN1_PERSON_H
