
#ifndef PAIN2_NUMBER_CARDS_H
#define PAIN2_NUMBER_CARDS_H

#include "Card.h"
class Number_cards : public Card{  //inherits from card
private:
     int num;
public:
    Number_cards(Color color1, int val, int number) : Card(NUMBER_CARD, color1, val, number){
        this->num = number;
    }
    Number_cards() = default;
    int get_number(){
        return num;
    }
    std::string to_string() override{
        return std::to_string(get_number());
    }

};

#endif //PAIN2_NUMBER_CARDS_H
