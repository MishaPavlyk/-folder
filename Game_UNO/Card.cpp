#include "Card.h"

std::string colorToString(Color color) {
    switch (color) {
    case RED: return "RED";
    case BLUE: return "BLUE";
    case GREEN: return "GREEN";
    case YELLOW: return "YELLOW";
    default: return "NONE";
    }
}