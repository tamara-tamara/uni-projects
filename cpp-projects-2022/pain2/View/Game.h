#ifndef PAIN1_GAME_H
#define PAIN1_GAME_H

#include <iostream>
#include "../Controller/Logic.h"
#include "../Controller/Logic.cpp"

#include "queue"
#include "../Model/Person.h"
#include "../Model/Person.cpp"
#include "../Model/Computer.h"
#include "list"
#include "../Model/Number_cards.h"
#include "exception"

class Game {
public:
    static void process_of_game(int round) {

        Person player;
        int position = 0;
        Card chosen_card;
        string choice_of_color;
        string index_of_card;

        while (!Logic::end_of_game()) {
            player = Logic::access_by_index(Logic::get_players(), position);  //player from certain position

            if (Logic::get_penalty_cards().size() != 0) { //if player should draw cards
                bool should_get_extra = false;
                for (const Card &card: Person::get_all_cards()) {
                    if (Logic::is_draw_two(card)) {  //if player has its own draw card, he will use it
                        should_get_extra = true;
                        break;
                    }
                }
                if (!should_get_extra) {   //if player does not have any draw cards
                    for (int i = Logic::get_penalty_cards().size(); i > 0; --i) {
                        player.add_cards(Logic::get_penalty_cards()[0]);  //draw certain amount of cards
                        Logic::get_penalty_cards().erase(Logic::get_penalty_cards().begin());

                    }
                }
                position = ((position + 1) % (Logic::get_players().size()));  //changes the position to the next player
                continue;                      // going to the next player

            }
            if (!Logic::have_at_least_one_card(player)) {   // check the player's cards
                Logic::give_cards_to(player);
                if (!Logic::have_at_least_one_card(player)) {
                    show_last_card(Logic::get_last_card(), Logic::get_last_card().get_color()); //print game boards
                    show_amount_of_cards(Logic::get_players());
                    show_player_hands(player);

                    if (player.get_type_of_p() != "computer") {
                        show_no_option();    //player should get one more card
                    }
                    position = ((position + 1) % (Logic::get_players().size()));  //position changes to the next player
                    continue;
                }
            }
            if (player.get_type_of_p() == "computer") {   //if player is a computer
                chosen_card = Computer::computer_play(Logic::get_players(), Logic::get_penalty_cards(), position,
                                                      player);
                position = Logic::track_queue(chosen_card, position);  //changes position to the next player
                continue;
            }
            while (true) {
                while (true) {
                    show_last_card(Logic::get_last_card(), Logic::get_last_card().get_color()); //prints board
                    std::cout << std::endl;
                    show_amount_of_cards(Logic::get_players());
                    show_player_hands(player);
                    show_choice_msg(player);

                    std::cin >> index_of_card;      //gets the index of card
                    if (player.get_all_cards().size() == 1) {    //if player has one card left
                        string s = index_of_card.substr(1, index_of_card.size() - 1);
                        for (int i = 0; i < s.size(); ++i) {
                            s[0] = tolower(s[0]);  //converting all to lower and dividing it
                        }
                        if (s != "uno") {    //looking for uno word
                            Person person1 = Logic::access_by_index(Logic::get_players(), position);
                            person1.add_cards(Logic::get_penalty_cards().at(0));
                            Logic::get_penalty_cards().erase(Logic::get_penalty_cards().begin());
                            person1.add_cards(Logic::get_penalty_cards().at(0));
                            Logic::get_penalty_cards().erase(
                                    Logic::get_penalty_cards().begin());//if player did not eneter 'uno' he will get two cards
                        }
                    }
                    int a = stoi(index_of_card);
                    if (a > -1 && a < player.get_all_cards().size()) {
                        break;
                    }
                    throw invalid_argument(
                            "Enter the correct index of your cards");   //exception handling for incorrect index

                }
                int a = stoi(index_of_card);
                int temp = Logic::index_to_value(a, player);
                chosen_card = player.remove_card(temp);

                if (Logic::check_card(chosen_card, player)) {  //checking card
                    if (chosen_card.get_type() == Type::WILD_CARD) {
                        while (true) {
                            show_color_choices();
                            std::cin >> choice_of_color;
                            int choice = stoi(choice_of_color);
                            if (choice > 0 && choice < 5) {
                                break;
                            }

                            show_last_card(Logic::get_last_card(), Logic::get_last_card().get_color());
                            show_amount_of_cards(Logic::get_players());
                            show_player_hands(player);
                        }
                        int choice = stoi(choice_of_color);
                        switch (choice) {     // according to entered number we implement color
                            case 1:
                                Logic::implement_choice(chosen_card, Color::RED);
                                cout << endl << "The next card should be red" << endl;
                                break;
                            case 2:
                                Logic::implement_choice(chosen_card, Color::YELLOW);
                                cout << endl << "The next card should be yellow" << endl;
                                break;
                            case 3:
                                Logic::implement_choice(chosen_card, Color::BLUE);
                                cout << endl << "The next card should be blue" << endl;
                            case 4:
                                Logic::implement_choice(chosen_card, Color::GREEN);
                                cout << endl << "The next card should be green" << endl;
                                break;

                        }
                    } else {
                        Logic::implement_choice(chosen_card, chosen_card.get_color());
                    }
                    break;

                }
                player.add_cards(chosen_card);

            }
            if (Logic::is_wild_four(chosen_card)) {   //if is wild four, nest player got penalty_cards
                int index_of_p = (position + 1) % Logic::get_players().size();
                for (int i = Logic::get_penalty_cards().size(); i > 0; i--) {
                    Person person1 = Logic::access_by_index(Logic::get_players(), index_of_p);
                    person1.add_cards(Logic::get_penalty_cards().at(0));
                    Logic::get_penalty_cards().erase(Logic::get_penalty_cards().begin());
                }
            }
            position = Logic::track_queue(chosen_card, position);

        }
        scoreboard(Logic::get_players(), round);
    }

    static void show_last_card(Card card, Color color) {   //prints the top card of deck
        std::cout << endl << "The top card is " << card.to_string() << endl;
    }

    static void show_amount_of_cards(queue<Person> players) {   // prints the total number of cards of each player
        queue<Person> temp = players;
        cout << "Amount of players' cards :" << endl;
        while (!temp.empty()) {
            Person person = temp.front();
            std::cout << person.get_name() << ": " << Person::get_all_cards().size() << endl;
            temp.pop();
        }
        std::cout << endl;

    }

    static int scoreboard(queue<Person> players, int round) {  //prints scoreboard
        queue<Person> temp = players;
        int n = players.size();
        bool is_p = false;
        for (int i = 0; i < n; ++i) {
            if (!Logic::have_at_least_one_card(temp.front()) &&
                temp.front().get_type_of_p() != "computer") {  // prints the result of user
                round++;
                cout << temp.front().get_name() << " wins this round. Number of total wins is  " << round << endl;
                is_p = true;
                break;
            }
            temp.pop();
        }
        if (!is_p) {
            cout << " You lost this round. Number of total wins is " << round << endl;
        }
    }

    static void show_player_hands(const Person &player) {  // shows the cards of player's hand
        for (Card card: Person::get_all_cards()) {
            std::cout << card.to_string() << ", ";
        }
    }

    static void
    show_no_option() {           // shows no option message if in the hands of a player there is no proper card
        cout << "You cannot choose any card from your hand. One card has given to you." << endl;
    }

    static void show_color_choices() {                     //color choice for wild cards
        std::cout << "You used a wild card. Now choose a color. "
                     "1 - red, 2 - yellow, 3 - green, 4 - blue" << endl;
    }

    static void show_choice_msg(Person person) {     // prints message by asking to enter the index of card
        cout << endl << person.get_name() << " choose a card (enter the index 0 - ...): " << endl;
    }

    static void show_number_msg() {
        cout << "Please, enter the number of the players (max is 10)." << endl <<
             "The rest of players will be computers: ";
    }

    static void show_name_msg() {        // name message for user
        cout << "Please, type your name: ";
    }

    static void start_the_game() {  //starts the game
        string name;
        int game_keys;
        int number_of_players;
        while (true) {
            show_number_msg();
            Logic::create_deck();
            Logic::shuffle_cards();
            cout << endl;
            cin >> game_keys;
            number_of_players = game_keys;
            show_name_msg();
            cin >> name;
            cout << endl;
            Person name_p = Person();
            name_p.set_name(name);

            Logic::add_players(name_p);
            Logic::give_cards(7, name_p);
            cout << endl;

            for (int i = 0; i < (number_of_players - 1); ++i) {   //creates computer players
                Computer computer = Computer(to_string(i + 1));
                Logic::add_players(computer);
                Logic::give_cards(7, computer);
            }
            Logic::find_pile_card();
            int round;
            process_of_game(round);   // the main process of the game
            Logic::reset();
            break;

        }
    }


};


#endif //PAIN1_GAME_H