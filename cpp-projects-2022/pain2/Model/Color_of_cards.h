

#ifndef PAIN2_COLOR_OF_CARDS_H
#define PAIN2_COLOR_OF_CARDS_H

enum Color {
    RED, GREEN, BLUE, YELLOW, BLACK

};
std::string colorToString(Color color) {   //returns the string name of each color
    switch (color) {
        case Color::RED:
            return "RED";
        case Color::GREEN:
            return "GREEN";
        case Color::YELLOW:
            return "YELLOW";
        case Color::BLUE:
            return "BLUE";
    }
}

#endif //PAIN2_COLOR_OF_CARDS_H
