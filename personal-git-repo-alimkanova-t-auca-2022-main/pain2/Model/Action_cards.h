

#ifndef PAIN2_ACTION_CARDS_H
#define PAIN2_ACTION_CARDS_H
#include "Card.h"

class Action_cards : public Card{  //inherits from Card
public:
    enum Action{
        SKIP, REVERSE, DRAW_TWO
    };
    Action_cards(Action action, Color color1,int value) : Card(ACTION_CARD, color1, value, 10){
        this->action = action;
    }
    std::string to_string(){
        return ""+get_color();
    }
private:
    Action action;
};

#endif //PAIN2_ACTION_CARDS_H
