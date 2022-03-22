//
// Created by Nadun N. T. Fernando on 2/15/2022.
//

#ifndef CO2402ASSIGNMENT_USERINTERFACE_H
#define CO2402ASSIGNMENT_USERINTERFACE_H

#include <string>
#include <map>

using namespace std;

class UserInterface {
private:
    int randomNumber;
    bool passesGO;
    string chance;
    const char pound = 156;

public:
    UserInterface();

    virtual ~UserInterface();

    static int rollDice();

    int getRandomNumber() const;

    void setRandomNumber(int random);

    const string &getChance() const;

    void setChance(const string &chance);

    bool isPassesGo() const;

    void setPassesGo(bool passesGo);

    static void intro();

    static void displayBoard();

    void displayRandomNumber();

    void displayMove(int randomNumber,const string& playerName, const string& squareName, bool passesGO);

    static void thankYou();

    void displayEndResult(const string& winnerName, float winnerMoney, const string& loserName, float loserMoney);

    void displayPropertyTransactions(const string& playerName, const string& squareName, float cost, char value) const;

    void displayPlayerAmount(const string& playerName, float playerMoney) const;

};


#endif //CO2402ASSIGNMENT_USERINTERFACE_H
