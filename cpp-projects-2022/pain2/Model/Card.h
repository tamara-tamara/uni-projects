
#ifndef PAIN1_CARD_H
#define PAIN1_CARD_H

#include <string>
#include "Type_of_cards.h"
#include "Color_of_cards.h"



class Card {
private:
    Type type;
    Color color;
    int value;
    int score;
    int hands = 8;
    int total_cards = 108;
public:
    Card() = default;
    Card(Type type, Color color, int value, int score){
       this->type = type;
       this->color=color;
       this->value = value;
       this->score = score;
   }

    Color get_color()const{
        return color;
   }

    int get_value() const {
       return value;
   }
    int get_score(){
        return score;
    }
    int get_type(){
        return type;
    }

    virtual
    std::string to_string(){     //to_string overloaded method for cards
        std::string result;
        if(type == Type::NUMBER_CARD){
            result = "Card "+ std::to_string(get_score())+" "+ colorToString(get_color());
        }
        else if(type == Type::WILD_CARD ){
            if(get_value()>100 && get_value()<=104){
                result = "Draw Four Card";
            }
            else {
                result = "Draw Card";
            }
//
        }
        else{
            if((get_value()<=100 && get_value()>98) || (get_value()>23 && get_value()<=25) || (get_value()>48 && get_value()<=50) ||
                    (get_value()>73 && get_value()<=75)){
                result = "Draw Two "+ colorToString(get_color());
            }
            else if((get_value()<=98 && get_value()>96) || (get_value()>21 && get_value()<=23) || (get_value()>46 && get_value()<=48) ||
                    (get_value()>71 && get_value()<=73)){
                result = "Reverse "+ colorToString(get_color());
            }
            else if ((get_value()>19 && get_value()<=21) || (get_value()>44 && get_value()<=46) || (get_value()>69 && get_value()<=71) ||
                    (get_value()>94 && get_value()<=96)){
                result = "Skip "+ colorToString(get_color());
            }
        }
       return result;
   }
    bool operator==(const Card& other)const{    // overloading of == operator
        return value == other.value;
    }
};


#endif //PAIN1_CARD_H
