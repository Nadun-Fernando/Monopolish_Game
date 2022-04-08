//
// Created by Nadun N. T. Fernando on 2/13/2022.
//

#ifndef CO2402ASSIGNMENT_PLAYER_H
#define CO2402ASSIGNMENT_PLAYER_H

#include <string>

using namespace std;

class Player {
private:
    string playerName;
    float playerMoney;
    int playerPosition;
    bool bankrupt = false;
    bool lentMoney = false;

public:
    Player();

    Player(string playerName, float playerMoney, int playerPosition);

    virtual ~Player();

    const string &getPlayerName() const;

    void setPlayerName(const string &playerName);

    float getPlayerMoney() const;

    void setPlayerMoney(float playerMoney);

    int getPlayerPosition() const;

    void setPlayerPosition(int playerPosition);

    void addLentMoney(float mortgageValue);

    void repayMortgage(float repayAmount);

    bool haveSufficientFunds(float propertyCost);

    bool isBankrupt() const;

    void setBankrupt(bool bankrupt);

    bool isLentMoney() const;

    void setLentMoney(bool lentMoney);
};


#endif //CO2402ASSIGNMENT_PLAYER_H
