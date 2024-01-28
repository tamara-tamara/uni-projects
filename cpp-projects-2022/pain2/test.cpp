#include "iostream"
#include <cstdint>
#include "pain2/View/Game.h"
#include "pain2/Controller/Logic.h"
#include "pain2/Model/Card.h"
#include "pain2/Model/Person.h"
#include "pain2/Model/Computer.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Funtion index to value", "[Logic]") {
    Person person("Toma");
    person.add_cards(Action_cards(Action_cards::REVERSE, Color::BLUE, 100));
    int a = Logic::index_to_value(0, person);
    REQUIRE(a == 100);
    person.add_cards(Action_cards(Action_cards::REVERSE, Color::BLUE, 1));
    int a2 = Logic::index_to_value(0, person);
    REQUIRE(a2 == 1);
    person.add_cards(Action_cards(Action_cards::REVERSE, Color::BLUE, 108));
    int a3 = Logic::index_to_value(0, person);
    REQUIRE(a3 == 108);
    person.add_cards(Action_cards(Action_cards::REVERSE, Color::BLUE, 20));
    int a4 = Logic::index_to_value(0, person);
    REQUIRE(a4 == 20);
}

TEST_CASE("Give Card method", "[Logic]") {
    Person person("Toma");
    Computer computer("computer");
    Logic::give_cards(7, person);
    REQUIRE(person.get_all_cards().size() == 7);

    Logic::give_cards(1, computer);
    REQUIRE(computer.get_all_cards().size() == 1);
}

TEST_CASE("Change top card", "[Logic]") {
    Logic::change_top_card(Action_cards(Action_cards::DRAW_TWO, Color::YELLOW, 12));
    REQUIRE(Logic::get_last_card().get_value() == 12);

    Logic::change_top_card(Wild_cards(Wild_cards::CHANGE_COLOR, 106));
    REQUIRE(Logic::get_last_card().get_value() == 106);
}

TEST_CASE("Have at least one card", "[Logic]") {
    Person person("Toma");
    person.add_cards(Number_cards(Color::GREEN, 5, 5));
    REQUIRE(Logic::have_at_least_one_card(person) == true);

    Person person1("Stormy");
    REQUIRE(Logic::have_at_least_one_card(person1) == false);
}

TEST_CASE("Give cards to", "[Logic]") {
    Person person("Bloom");
    Logic::give_cards(5, person);
    Logic::give_cards_to(person);
    REQUIRE(person.get_all_cards().size() == 6);

    Person person1("Stella");
    Logic::give_cards(10, person);
    Logic::give_cards_to(person);
    REQUIRE(person.get_all_cards().size() == 11);
}

TEST_CASE("Is wild four", "[Logic]") {
    REQUIRE(Logic::is_wild_four(Action_cards(Action_cards::REVERSE, Color::BLUE, 12)) == false);
    REQUIRE(Logic::is_wild_four(Wild_cards(Wild_cards::CHANGE_COLOR, 103)) == false);
    REQUIRE(Logic::is_wild_four(Wild_cards(Wild_cards::PLUS_FOUR, 103)) == true);
    REQUIRE(Logic::is_wild_four(Number_cards(Color::GREEN, 5, 5)) == false);
}

TEST_CASE("Is wild draw", "[Logic]") {
    REQUIRE(Logic::is_wild_draw(Action_cards(Action_cards::REVERSE, Color::BLUE, 12)) == false);
    REQUIRE(Logic::is_wild_draw(Wild_cards(Wild_cards::CHANGE_COLOR, 103)) == true);
    REQUIRE(Logic::is_wild_draw(Wild_cards(Wild_cards::PLUS_FOUR, 103)) == false);
    REQUIRE(Logic::is_wild_draw(Number_cards(Color::GREEN, 5, 5)) == false);
}

TEST_CASE("Is draw two", "[Logic]") {
    REQUIRE(Logic::is_draw_two(Action_cards(Action_cards::REVERSE, Color::BLUE, 12)) == false);
    REQUIRE(Logic::is_draw_two(Action_cards(Action_cards::DRAW_TWO, Color::BLUE, 12)) == true);
    REQUIRE(Logic::is_draw_two(Wild_cards(Wild_cards::CHANGE_COLOR, 103)) == false);
    REQUIRE(Logic::is_draw_two(Wild_cards(Wild_cards::PLUS_FOUR, 103)) == false);
    REQUIRE(Logic::is_draw_two(Number_cards(Color::GREEN, 5, 5)) == false);
}

TEST_CASE("Is reverse", "[Logic]") {
    REQUIRE(Logic::is_reverse(Action_cards(Action_cards::REVERSE, Color::BLUE, 12)) == true);
    REQUIRE(Logic::is_reverse(Action_cards(Action_cards::DRAW_TWO, Color::BLUE, 12)) == false);
    REQUIRE(Logic::is_reverse(Wild_cards(Wild_cards::CHANGE_COLOR, 103)) == false);
    REQUIRE(Logic::is_reverse(Wild_cards(Wild_cards::PLUS_FOUR, 103)) == false);
    REQUIRE(Logic::is_reverse(Number_cards(Color::GREEN, 5, 5)) == false);
}

TEST_CASE("Is skip", "[Logic]") {
    REQUIRE(Logic::is_skip(Action_cards(Action_cards::REVERSE, Color::BLUE, 12)) == false);
    REQUIRE(Logic::is_skip(Action_cards(Action_cards::DRAW_TWO, Color::BLUE, 12)) == false);
    REQUIRE(Logic::is_skip(Action_cards(Action_cards::SKIP, Color::BLUE, 12)) == true);
    REQUIRE(Logic::is_skip(Wild_cards(Wild_cards::CHANGE_COLOR, 103)) == false);
    REQUIRE(Logic::is_skip(Wild_cards(Wild_cards::PLUS_FOUR, 103)) == false);
    REQUIRE(Logic::is_skip(Number_cards(Color::GREEN, 5, 5)) == false);
}

TEST_CASE("Is number card", "[Logic]") {
    REQUIRE(Logic::is_number_card(Action_cards(Action_cards::REVERSE, Color::BLUE, 12)) == false);
    REQUIRE(Logic::is_number_card(Action_cards(Action_cards::DRAW_TWO, Color::BLUE, 12)) == false);
    REQUIRE(Logic::is_number_card(Wild_cards(Wild_cards::CHANGE_COLOR, 103)) == false);
    REQUIRE(Logic::is_number_card(Wild_cards(Wild_cards::PLUS_FOUR, 103)) == false);
    REQUIRE(Logic::is_number_card(Number_cards(Color::GREEN, 5, 5)) == true);
}

TEST_CASE("end game", "[Logic]") {
    Person person("Flora");
    person.add_cards(Number_cards(Color::GREEN, 5, 5));
    Computer computer("com");
    Logic::get_players().push(person);
    Logic::get_players().push(computer);
    REQUIRE(Logic::end_of_game() == true);
}