
#ifndef PAIN2_WILD_CARDS_H
#define PAIN2_WILD_CARDS_H

#include <string>
#include "Card.h"

#include "exception"

class Wild_cards : public Card{  //inherits from Card
public:
    enum Wild{   // has enum for its types
        CHANGE_COLOR, PLUS_FOUR
    };
    Wild_cards(Wild type, int val) : Card(WILD_CARD, BLACK, val, 20){
   this->wild = type;
    }

    std::string to_string() {  //overloading of to_string
        return "Wild Card"+get_color();
    }
private:
    Wild wild;

};

#endif //PAIN2_WILD_CARDS_H
