//
// Created by Nadun N. T. Fernando on 2/13/2022.
//

#include "Player.h"

#include <utility>

Player::Player() {}

Player::Player(string playerName, float playerMoney, int playerPosition) : playerName(std::move(playerName)),
                                                                                  playerMoney(playerMoney),
                                                                                  playerPosition(playerPosition) {}

Player::~Player() {

}

const string &Player::getPlayerName() const {
    return playerName;
}

void Player::setPlayerName(const string &playerName) {
    Player::playerName = playerName;
}

float Player::getPlayerMoney() const {
    return playerMoney;
}

void Player::setPlayerMoney(float playerMoney) {
    Player::playerMoney = playerMoney;
}

int Player::getPlayerPosition() const {
    return playerPosition;
}

void Player::setPlayerPosition(int playerPosition) {
    Player::playerPosition = playerPosition;
}

void Player::addLentMoney(float mortgageValue) {
    setPlayerMoney(getPlayerMoney() + mortgageValue);
}

void Player::repayMortgage(float repayAmount) {
    setPlayerMoney(getPlayerMoney() - repayAmount);
}

bool Player::isBankrupt() {
    if (getPlayerMoney() < 0) {
        return true;
    } else {
        return false;
    }
}

bool Player::haveSufficientFunds(float propertyCost) {
    if ((getPlayerMoney() - propertyCost) >= 0) {
        return true;
    } else {
        return false;
    }
}


