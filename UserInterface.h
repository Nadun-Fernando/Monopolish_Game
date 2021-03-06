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
    int rollBonusPenalty;
    bool passesGO;
    bool bonus;
    bool penalty;
    string chance;
    const char pound = 156;

public:
    UserInterface();

    virtual ~UserInterface();

    int rollDice();

    int getRandomNumber() const;

    void setRandomNumber(int random);

    int getRollBonusPenalty() const;

    void setRollBonusPenalty(int rollBonusPenalty);

    const string &getChance() const;

    void setChance(const string &chance);

    bool isPassesGo() const;

    void setPassesGo(bool passesGo);

    bool isBonus() const;

    void setBonus(bool bonus);

    bool isPenalty() const;

    void setPenalty(bool penalty);

    static void intro();

    static void displayBoard();

    void displayRandomNumber();

    void displayMove(int randomNumber,const string& playerName, const string& squareName, bool passesGO, bool bonus, bool penalty, int rollBonusPenalty);

    static void thankYou();

    void displayEndResult(const string& winnerName, float winnerMoney, const string& loserNameOne, float loserMoneyOne,const string& loserNameTwo, float loserMoneyTwo, const string& loserNameThree, float loserMoneyThree);

    void displayPropertyTransactions(const string& playerName, const string& squareName, float cost, char value) const;

    void displayPlayerAmount(const string& playerName, float playerMoney) const;

};


#endif //CO2402ASSIGNMENT_USERINTERFACE_H
