
#ifndef PAIN2_COMPUTER_H
#define PAIN2_COMPUTER_H

#include <queue>
#include <ctime>
#include "Person.h"
#include "typeinfo"
#include "Wild_cards.h"
#include "../Controller/Logic.h"

class Computer : public Person{   //inherits from Person
private:
    string name;
    string computer = "computer";
public:

     Computer(string name) : Person("Computer" + name){  //has its own specific name
        set_name("Computer");
        set_type("computer");

    }


    static Card computer_play(queue<Person> players, vector<Card> penalty_cards, int bot_num, Person computer){ //the logic of computer playing
        Card com_card = Wild_cards(Wild_cards::Wild::PLUS_FOUR,1 );
        auto it = Person:: get_all_cards().begin();
        for (auto it = Person:: get_all_cards().begin(); it!=Person::get_all_cards().end(); it++) {  //looks for proper card
            com_card = *it;
            if (Logic::check_card(com_card, computer)){
                Person::get_all_cards().erase(it);
                break;
            }
        }
        if (typeid(com_card) == typeid(Wild_cards)){  //if computer chose wild card
            std::srand(std::time(0));
            switch (std::rand() %4 +1) {     // it randomly selects the next color
                case 1:
                    Logic::implement_choice(com_card, Color::RED);
                    break;
                case 2:
                    Logic:: implement_choice(com_card, Color::YELLOW);
                    break;
                case 3:
                    Logic:: implement_choice(com_card, Color::GREEN);
                    break;
                case 4:
                    Logic:: implement_choice(com_card, Color::BLUE);
                    break;
            }
        } else{
            Logic:: implement_choice(com_card, com_card.get_color());
        }

        if (typeid(com_card) == typeid(Wild_cards)){
            int index = (bot_num +1)%players.size();
            for (int i = penalty_cards.size(); i > 0; i--) {
                Logic::get_player_by_index(index).add_cards(penalty_cards[0]);
                penalty_cards.erase(penalty_cards.begin());
            }
        }
        return com_card;
    }

    string get_type_of_p() override{
        return computer;
    }
};

#endif //PAIN2_COMPUTER_H