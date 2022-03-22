#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "FileOperations.h"
#include "CSquare.h"
#include "Properties.h"
#include "UserInterface.h"
#include "Player.h"
using namespace std;





int main(int argc, char ** argv) {
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1980, 1080, TRUE);

//    UserInterface ui;
//    ui.displayBoard();

    string squareName;


    FileOperations *fileOperations = new FileOperations("../Resources/monopoly.txt");

    Player *playerOne = new Player("dog", 1500,0);
    Player *playerTwo = new Player("car",1500,0);

    UserInterface *userInterface = new UserInterface();

    fileOperations->readMonopolyData();
    userInterface->setChance("playerOne");

    for (int i = 0; i < 20; ++i) {
        cout << "\n\n\n======================Round " + to_string(i + 1) + "==============================";
        for (int j = 0; j < 2; ++j) {
            if (userInterface->getChance() == "playerOne") {
                float cost;
                char caseValue;

                cout << "\n============== Chance of the Player One ==================";
                userInterface->setRandomNumber(userInterface->rollDice());

                if (25 > (playerOne->getPlayerPosition() + userInterface->getRandomNumber())) {
                    playerOne->setPlayerPosition(playerOne->getPlayerPosition() + userInterface->getRandomNumber());
                    squareName = fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getSquareName();
                    userInterface->setPassesGo(false);
                } else if (25 < (playerOne->getPlayerPosition() + userInterface->getRandomNumber())) {
                    playerOne->setPlayerPosition((playerOne->getPlayerPosition() + userInterface->getRandomNumber()) - 26);
                    squareName = fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getSquareName();
                    playerOne->setPlayerMoney(playerOne->getPlayerMoney() + 200);
                    userInterface->setPassesGo(true);
                }

                userInterface->displayMove(userInterface->getRandomNumber(),playerOne->getPlayerName(),squareName,userInterface->isPassesGo());

                if (fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getSquareType() == 1) {
                    if (fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getPropertyOwner().empty() && playerOne->getPlayerMoney() > 0) {
                        cost = fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getPropertyCost();
                        caseValue = 'A';
                        fileOperations->getMySquare()[playerOne->getPlayerPosition()]->setPropertyOwner(playerOne->getPlayerName());
                        playerOne->setPlayerMoney(playerOne->getPlayerMoney() - cost);
                        //userInterface->displayPropertyTransactions(playerOne->getPlayerName(),squareName,cost,false);
                    } else if (fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getPropertyOwner() == playerOne->getPlayerName()) {
                        cost = 0;
                        caseValue = 0;
                    } else {
                        cost = fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getPropertyRent();
                        caseValue = 'B';
                        playerOne->setPlayerMoney(playerOne->getPlayerMoney() - cost);
                        if (playerTwo->getPlayerName() == fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getPropertyOwner()) {
                            playerTwo->setPlayerMoney(playerTwo->getPlayerMoney() + cost);
                        }
                    }

                    userInterface->displayPropertyTransactions(playerOne->getPlayerName(),squareName,cost,caseValue);
                }

                userInterface->displayPlayerAmount(playerOne->getPlayerName(),playerOne->getPlayerMoney());

                userInterface->setChance("playerTwo");
                cout << "\n============== End of the Chance of the Player One =================="  << endl;

            } else if (userInterface->getChance() == "playerTwo") {
                float cost;
                char caseValue;

                cout << "\n============== Chance of the Player Two ==================";
                userInterface->setRandomNumber(userInterface->rollDice());

                if (25 > (playerTwo->getPlayerPosition() + userInterface->getRandomNumber())) {
                    playerTwo->setPlayerPosition(playerTwo->getPlayerPosition() + userInterface->getRandomNumber());
                    squareName = fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getSquareName();
                    userInterface->setPassesGo(false);
                } else if (25 < (playerTwo->getPlayerPosition() + userInterface->getRandomNumber())) {
                    playerTwo->setPlayerPosition((playerTwo->getPlayerPosition() + userInterface->getRandomNumber()) - 26);
                    squareName = fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getSquareName();
                    playerTwo->setPlayerMoney(playerTwo->getPlayerMoney() + 200);
                    userInterface->setPassesGo(true);
                }

                userInterface->displayMove(userInterface->getRandomNumber(),playerTwo->getPlayerName(),squareName,userInterface->isPassesGo());

                if (fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getSquareType() == 1) {
                    if (fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getPropertyOwner().empty() && playerTwo->getPlayerMoney() > 0) {
                        cost = fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getPropertyCost();
                        caseValue = 'A';
                        fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->setPropertyOwner(playerTwo->getPlayerName());
                        playerTwo->setPlayerMoney(playerTwo->getPlayerMoney() - cost);
                        //userInterface->displayPropertyTransactions(playerOne->getPlayerName(),squareName,cost,false);
                    } else if (fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getPropertyOwner() == playerTwo->getPlayerName()) {
                        cost = 0;
                        caseValue = 0;
                    } else {
                        cost = fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getPropertyRent();
                        caseValue = 'B';
                        playerTwo->setPlayerMoney(playerTwo->getPlayerMoney() - cost);
                        if (playerOne->getPlayerName() == fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getPropertyOwner()) {
                            playerOne->setPlayerMoney(playerOne->getPlayerMoney() + cost);
                        }
                    }

                    userInterface->displayPropertyTransactions(playerTwo->getPlayerName(),squareName,cost,caseValue);
                }

                userInterface->displayPlayerAmount(playerTwo->getPlayerName(),playerTwo->getPlayerMoney());

                userInterface->setChance("playerOne");
                cout << "\n============== End of the Chance of the Player Two =================="  << endl;
            }
        }
    }



    if (playerOne->getPlayerMoney() < playerTwo->getPlayerMoney()) {
        userInterface->displayEndResult(playerTwo->getPlayerName(),playerTwo->getPlayerMoney(),playerOne->getPlayerName(),playerOne->getPlayerMoney());
    } else if (playerOne->getPlayerMoney() > playerTwo->getPlayerMoney()) {
        userInterface->displayEndResult(playerOne->getPlayerName(),playerOne->getPlayerMoney(),playerTwo->getPlayerName(),playerTwo->getPlayerMoney());
    } else if (playerTwo->getPlayerMoney() == playerOne->getPlayerMoney()) {
        cout << "ERROR!!!!" << endl;
    }

//    cout << "\n\n\n\n\n" << fileOperations->getMySquare()[1]->getPropertyOwner();








//
//
//
//    FileOperations *fileOperations = new FileOperations("../Resources/monopoly.txt");
//    fileOperations->readMonopolyData();
//
//
//    for (int i = 0; i < fileOperations->getMySquare().size(); ++i) {
//        if (fileOperations->getMySquare()[i]->getSquareType() == 1) {
//            cout << "=============Property=================\n";
//            cout << fileOperations->getMySquare()[i]->getSquareType() << endl;
//            cout << fileOperations->getMySquare()[i]->getSquareName() << endl;
//            cout << fileOperations->getMySquare()[i]->getPropertyRent() << endl;
//            cout << fileOperations->getMySquare()[i]->getPropertyCost() << endl;
//            cout << fileOperations->getMySquare()[i]->getColorGroup() << endl;
//            cout << endl;
//        } else {
//            cout << "=============Square=================\n";
//            cout << fileOperations->getMySquare()[i]->getSquareType() << endl;
//            cout << fileOperations->getMySquare()[i]->getSquareName() << endl;
//            cout << endl;
//        }
//    }
    ///before create the object needs to check whether it's a property or a normal square
    delete fileOperations;
    delete playerTwo;
    delete playerOne;
    delete userInterface;
    string().swap(squareName);

    system("pause");

    return 0;
    cout  << _CrtDumpMemoryLeaks();
}
