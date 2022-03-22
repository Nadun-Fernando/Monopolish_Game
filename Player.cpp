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
