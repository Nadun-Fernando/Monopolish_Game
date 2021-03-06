//
// Created by Nadun N. T. Fernando on 2/15/2022.
//

#include "UserInterface.h"
#include "colors.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <iterator>

UserInterface::UserInterface() = default;

UserInterface::~UserInterface() = default;

int UserInterface::rollDice() {
    //return (rand() % 6) + 1;
    return static_cast<int>( static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1 );

}

void UserInterface::intro() {
    printf("\n\n");
    printf("\n                                   888       888 8888888888 888      .d8888b.   .d88888b.  888b     d888 8888888888      88888888888 .d88888b.       ");
    printf("\n                                   888   o   888 888        888     d88P  Y88b d88P\" \"Y88b 8888b   d8888 888                 888    d88P\" \"Y88b  ");
    printf("\n                                   888  d8b  888 888        888     888    888 888     888 88888b.d88888 888                 888    888     888      ");
    printf("\n                                   888 d888b 888 8888888    888     888        888     888 888Y88888P888 8888888             888    888     888      ");
    printf("\n                                   888d88888b888 888        888     888        888     888 888 Y888P 888 888                 888    888     888      ");
    printf("\n                                   88888P Y88888 888        888     888    888 888     888 888  Y8P  888 888                 888    888     888      ");
    printf("\n                                   8888P   Y8888 888        888     Y88b  d88P Y88b. .d88P 888   \"   888 888                 888    Y88b. .d88P     ");
    printf("\n                                   888P     Y888 8888888888 88888888 \"Y8888P\"   \"Y88888P\"  888       888 8888888888          888     \"Y88888P\" ");
    printf("\n\n\n\n");
    printf("\n        888b     d888  .d88888b.  888b    888  .d88888b.  8888888b.   .d88888b.  888    Y88b   d88P             8888888888888 .d888888888 888       888        ");
    printf("\n        8888b   d8888 d88P\" \"Y88b 8888b   888 d88P\" \"Y88b 888   Y88b d88P\" \"Y88b 888     Y88b d88P\t             888      888         888       888      ");
    printf("\n        88888b.d88888 888     888 88888b  888 888     888 888    888 888     888 888      Y88o88P                    888      888         888       888        ");
    printf("\n        888Y88888P888 888     888 888Y88b 888 888     888 888   d88P 888     888 888       Y888P                     888      88888888b.  8888888888888        ");
    printf("\n        888 Y888P 888 888     888 888 Y88b888 888     888 8888888P\"  888     888 888        888                      888             888  888       888         ");
    printf("\n        888  Y8P  888 888     888 888  Y88888 888     888 888        888     888 888        888                      888             888  888       888          ");
    printf("\n        888   \"   888 Y88b. .d88P 888   Y8888 Y88b. .d88P 888        Y88b. .d88P 888        888                      888             888  888       888          ");
    printf("\n        888       888  \"Y88888P\"  888    Y888  \"Y88888P\"  888         \"Y88888P\"  88888888   888\t\t        8888888888888 888888888d. 888       888          ");

}

void UserInterface::displayBoard() {
    cout << ("\n");
    cout << ("\n                BROWN BROWN  RAILWAY ORANGE ORANGE ORANGE   FREE         ");
    cout << ("\n                  RD  STREET STATION   RD   STREET   WAY    PARK         ");
    cout << ("\n        _______________________________________________________        ");
    cout << ("\n VISIT |      |" + dye::on_light_red("      ")+"|" + dye::on_light_red("      ")+"|      |" + dye::on_yellow("      ")+"|" + dye::on_yellow("      ")+"|" + dye::on_yellow("      ")+"|      |       ");
    cout << ("\n  JAIL |" + dye::aqua("  VJ  ")+"|" + dye::on_light_red("      ")+"|" + dye::on_light_red("      ")+"|" + dye::aqua("  RS  ")+"|" + dye::on_yellow("      ")+"|" + dye::on_yellow("      ")+"|" + dye::on_yellow("      ")+"|" + dye::aqua("  FP  ")+"|       ");
    cout << ("\n       |______|" + dye::white_on_light_red("______")+"|" + dye::white_on_light_red("______")+"|______|" + dye::white_on_yellow("______")+"|" + dye::white_on_yellow("______")+"|" + dye::white_on_yellow("______")+"|______|       ");
    cout << ("\n  GREY |" + dye::on_grey("      ")+"|                                         |" + dye::on_light_yellow("      ")+"| YELLOW");
    cout << ("\n STREET|" + dye::on_grey("      ")+"|                                         |" + dye::on_light_yellow("      ")+"|   RD  ");
    cout << ("\n       |" + dye::white_on_grey("______")+"|                                         |" + dye::white_on_light_yellow("______")+"|       ");
    cout << ("\n  GREY |" + dye::on_grey("      ")+"|                                         |" + dye::on_light_yellow("      ")+"| YELLOW");
    cout << ("\n   RD  |" + dye::on_grey("      ")+"|                                         |" + dye::on_light_yellow("      ")+"| STREET");
    cout << ("\n       |" + dye::white_on_grey("______")+"|                                         |" + dye::white_on_light_yellow("______")+"|       ");
    cout << ("\n       |      |                                         |      |       ");
    cout << ("\n  BONUS|" + dye::aqua(" BONUS")+"|                                         |" + dye::aqua("  PN  ")+"|PENALTY");
    cout << ("\n       |______|                                         |______|       ");
    cout << ("\n  RED  |" + dye::on_red("      ")+"|                                         |" + dye::on_green("      ")+"| GREEN ");
    cout << ("\n STREET|" + dye::on_red("      ")+"|                                         |" + dye::on_green("      ")+"|   RD  ");
    cout << ("\n       |" + dye::white_on_red("______")+"|                                         |" + dye::white_on_green("______")+"|       ");
    cout << ("\n  RED  |" + dye::on_red("      ")+"|                                         |" + dye::on_green("      ")+"| GREEN ");
    cout << ("\n   RD  |" + dye::on_red("      ")+"|                                         |" + dye::on_green("      ")+"| STREET");
    cout << ("\n       |" + dye::white_on_red("______")+"|_________________________________________|" + dye::white_on_green("______")+"|       ");
    cout << ("\n       |      |" + dye::on_purple("      ")+"|" + dye::on_purple("      ")+"|      |" + dye::on_blue("      ")+"|" + dye::on_blue("      ")+"|" + dye::on_blue("      ")+"|      | GO TO ");
    cout << ("\n START |" + dye::aqua("  GO  ")+"|" + dye::on_purple("      ")+"|" + dye::on_purple("      ")+"|" + dye::aqua("  BS  ")+"|" + dye::on_blue("      ")+"|" + dye::on_blue("      ")+"|" + dye::on_blue("      ")+"|" + dye::aqua(" JAIL ")+"|  JAIL ");
    cout << ("\n       |______|" + dye::white_on_purple("______")+"|" + dye::white_on_purple("______")+"|______|" + dye::white_on_blue("______")+"|" + dye::white_on_blue("______")+"|" + dye::white_on_blue("______")+"|______|       ");
    cout << ("\n               PURPLE PURPLE   BUS   BLUE   BLUE   BLUE                ");
    cout << ("\n               STREET   RD   STATION  WAY  STREET   RD                 ");
}

void UserInterface::displayRandomNumber() {

}

void UserInterface::displayMove(int randomNumber, const string& playerName, const string& squareName, bool passesGO, bool bonus, bool penalty, int rollBonusPenalty) {
    cout << "\n" + playerName + " rolls " + to_string(randomNumber);

    if (squareName == "Jail") {

        cout << "\n" + playerName + " lands on " + squareName;
        cout << "\n" + playerName + " is just visiting!";

    } else if (squareName == "Go to Jail") {

        cout << "\n" + playerName + " lands on " + squareName;
        cout << "\n" + playerName + " goes to " + squareName;
        cout << "\n" + playerName + " pays " + pound + "50.00";

    } else if (squareName == "Free Parking") {

        cout << "\n" + playerName + " lands on " + squareName;
        cout << "\n" + playerName + " is resting";

    } else {
        cout << "\n" + playerName + " lands on " + squareName;
    }

    if (passesGO) {
        cout << "\n" + playerName + " passes GO and collects "+ pound +"200.00" << endl;
    }

    if (bonus) {
        switch (rollBonusPenalty) {
            case 1:
                cout << "\n" + playerName + " find some money. Gain " + pound + "20" << endl;
                break;

            case 2:
                cout << "\n" + playerName + " win a coding competition. Gain " + pound + "50" << endl;
                break;

            case 3:
                cout << "\n" + playerName + " receive a rent rebate. Gain " + pound + "100" << endl;
                break;

            case 4:
                cout << "\n" + playerName + " win the lottery. Gain " + pound + "150" << endl;
                break;

            case 5:
                cout << "\n" + playerName + " receive the bequest. Gain " + pound + "200" << endl;
                break;

            case 6:
                cout << "\n" + playerName + " it's your birthday. Gain " + pound + "300" << endl;
                break;

            default:
                break;
        }
    } else if (penalty) {
        switch (rollBonusPenalty) {
            case 1:
                cout << "\n" + playerName + " buy a coffee in StarBucks. Lose " + pound + "20" << endl;
                break;

            case 2:
                cout << "\n" + playerName + " pay your broadband bill. Lose " + pound + "50" << endl;
                break;

            case 3:
                cout << "\n" + playerName + " visit the SU shop for food. Lose " + pound + "100" << endl;
                break;

            case 4:
                cout << "\n" + playerName + " buy and assignment solution. Lose " + pound + "150" << endl;
                break;

            case 5:
                cout << "\n" + playerName + " go for a romantic meal. Lose " + pound + "200" << endl;
                break;

            case 6:
                cout << "\n" + playerName + " pay some university fees. Lose " + pound + "300" << endl;
                break;

            default:
                break;
        }
    }
//    for (const auto& keyval : positionMap) // Look at each key-value pair
//    {
//        if (keyval.first == playerPosition) // If the value is 0...
//        {
//            positionedSquare = keyval.second; // ...return the first element in the pair
//        }
//    }
}

void UserInterface::thankYou() {
    printf("\n\n");
    printf("\n                              88888888888 888    888        d8888 888b    888 888    d8P   .d8888b.       8888888888 .d88888b.  8888888b.  ");
    printf("\n                                  888     888    888       d88888 8888b   888 888   d8P   d88P  Y88b      888       d88P\" \"Y88b 888   Y88b ");
    printf("\n                                  888     888    888      d88P888 88888b  888 888  d8P    Y88b.           888       888     888 888    888 ");
    printf("\n                                  888     8888888888     d88P 888 888Y88b 888 888d88K      \"Y888b.        8888888   888     888 888   d88P ");
    printf("\n                                  888     888    888    d88P  888 888 Y88b888 8888888b        \"Y88b.      888       888     888 8888888P\"  ");
    printf("\n                                  888     888    888   d88P   888 888  Y88888 888  Y88b         \"888      888       888     888 888 T88b   ");
    printf("\n                                  888     888    888  d8888888888 888   Y8888 888   Y88b  Y88b  d88P      888       Y88b. .d88P 888  T88b  ");
    printf("\n                                  888     888    888 d88P     888 888    Y888 888    Y88b  \"Y8888P\"       888        \"Y88888P\"  888   T88b ");
    printf("\n\n\n\n");
    printf("\n                                              8888888b.  888             d8888 Y88b   d88P 8888888 888b    888  .d8888b.  888              ");
    printf("\n                                              888   Y88b 888            d88888  Y88b d88P    888   8888b   888 d88P  Y88b 888              ");
    printf("\n                                              888    888 888           d88P888   Y88o88P     888   88888b  888 888    888 888              ");
    printf("\n                                              888   d88P 888          d88P 888    Y888P      888   888Y88b 888 888        888              ");
    printf("\n                                              8888888P\"  888         d88P  888     888       888   888 Y88b888 888  88888 888              ");
    printf("\n                                              888        888        d88P   888     888       888   888  Y88888 888    888 Y8P              ");
    printf("\n                                              888        888       d8888888888     888       888   888   Y8888 Y88b  d88P  \"               ");
    printf("\n                                              888        88888888 d88P     888     888     8888888 888    Y888  \"Y8888P88 888              ");
    printf("\n\n\n\n");
}

void UserInterface::displayEndResult(const string& winnerName, float winnerMoney, const string& loserNameOne, float loserMoneyOne,const string& loserNameTwo, float loserMoneyTwo, const string& loserNameThree, float loserMoneyThree ) {
    cout << "\n GAME OVER!!!";
    cout << "\n" + winnerName + " has "  << fixed << setprecision(2) <<  winnerMoney;
    cout << "\n" + loserNameOne + " has " << fixed << setprecision(2) << loserMoneyOne;
    cout << "\n" + loserNameTwo + " has " << fixed << setprecision(2) << loserMoneyTwo;
    cout << "\n" + loserNameThree + " has " << fixed << setprecision(2) << loserMoneyThree;
    cout << "\n" + winnerName + " has WON";
}

bool UserInterface::isPassesGo() const {
    return passesGO;
}

void UserInterface::setPassesGo(bool passesGo) {
    UserInterface::passesGO = passesGo;
}

int UserInterface::getRandomNumber() const {
    return randomNumber;
}

void UserInterface::setRandomNumber(int random) {
    UserInterface::randomNumber = random;
}

const string &UserInterface::getChance() const {
    return chance;
}

void UserInterface::setChance(const string &chance) {
    UserInterface::chance = chance;
}

void UserInterface::displayPropertyTransactions(const string &playerName, const string &squareName, float cost,
                                                char value) const {
    switch (value) {
        case 'A' :
            cout <<"\n" + playerName +" buys " + squareName + " for " + pound << fixed << setprecision(2) << cost << endl;
            break;
        case 'B' :
            cout <<"\n" + playerName +" pays rent for " + squareName + " : " + pound << fixed << setprecision(2) << cost << endl;
            break;
        case 'C':
            cout <<"\n" + playerName +" pays " + pound + "10 for the ticket." << endl;
            break;
        default:
            break;
    }
//    if (!payRent) {
//        cout <<"\n" + playerName +" buys " + squareName + " for " + pound + to_string(cost) << endl;
//    } else {
//        cout <<"\n" + playerName +" pays rent for " + squareName + " : " + pound + to_string(cost) << endl;
//    }

}

void UserInterface::displayPlayerAmount(const string& playerName, float playerMoney) const {
    cout << "\n\n" + playerName + " has " + pound << fixed << setprecision(2) << playerMoney;
}

bool UserInterface::isBonus() const {
    return bonus;
}

void UserInterface::setBonus(bool bonus) {
    UserInterface::bonus = bonus;
}

bool UserInterface::isPenalty() const {
    return penalty;
}

void UserInterface::setPenalty(bool penalty) {
    UserInterface::penalty = penalty;
}

int UserInterface::getRollBonusPenalty() const {
    return rollBonusPenalty;
}

void UserInterface::setRollBonusPenalty(int rollBonusPenalty) {
    UserInterface::rollBonusPenalty = rollBonusPenalty;
}







