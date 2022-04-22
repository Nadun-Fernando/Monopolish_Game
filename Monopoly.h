//
// Created by User on 4/22/2022.
//

#ifndef CO2402ASSIGNMENT_MONOPOLY_H
#define CO2402ASSIGNMENT_MONOPOLY_H
#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <cstdlib>
#include <cstdio>

#include "FileOperations.h"
#include "CSquare.h"
#include "Properties.h"
#include "UserInterface.h"
#include "Player.h"
#include "Station.h"

using namespace std;

class Monopoly {
private:
    string rightTrim(string word);
    void playTurn(unique_ptr<Player>& mainPlayer, unique_ptr<UserInterface>& userInterface, unique_ptr<FileOperations>& fileOperations);
    void mortgageAndBanckruptancy(unique_ptr<Player>& mainPlayer, unique_ptr<UserInterface>& userInterface, unique_ptr<FileOperations>& fileOperations);
    void propertyTransactions(unique_ptr<Player>& mainPlayer,
                              unique_ptr<Player>& secondPlayer,
                              unique_ptr<Player>& thirdPlayer,
                              unique_ptr<Player>& fourthPlayer,
                              unique_ptr<UserInterface>& userInterface,
                              unique_ptr<FileOperations>& fileOperations,
                              string& squareName);
public:
    Monopoly();

    void playGame();

    virtual ~Monopoly();

};


#endif //CO2402ASSIGNMENT_MONOPOLY_H
