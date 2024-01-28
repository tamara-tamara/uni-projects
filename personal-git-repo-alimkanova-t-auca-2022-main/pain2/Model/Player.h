
#ifndef PAIN2_PLAYER_H
#define PAIN2_PLAYER_H

#include "string"
#include "Person.h"

using namespace std;

class Player : public Person {

public:
    string name;
    Player(string name) : Person(name){
        //this->name = name;
    }

    void set_name(string new_name) {
        name = new_name;

    }

    string get_name() {
        return this->name;
    }


};

#endif //PAIN2_PLAYER_H
