#ifndef IPLAYERSTRATEGY_H
#define IPLAYERSTRATEGY_H

#include "Card.h"
#include <vector>

class IPlayerStrategy {
public:
    virtual ~IPlayerStrategy() = default;
    virtual Card playCard(const std::vector<Card>& hand, const Card& topCard) = 0;
    virtual Color chooseColor() = 0;
};

#endif