#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
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
#include "Station.h"

using namespace std;


string rightTrim(string word) {
    return word.erase(word.find_last_not_of(" \n\r\t")+1);
}


int main() {
//    HWND console = GetConsoleWindow();
//    RECT ConsoleRect;
//    GetWindowRect(console, &ConsoleRect);
//
//    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1980, 1080, TRUE);

//    UserInterface ui;
//    ui.displayBoard();




    unique_ptr<FileOperations> fileOperations(make_unique<FileOperations>(("../Resources/monopoly.txt")));


    unique_ptr<Player> playerOne(make_unique<Player>("dog", float (1500),0));
    unique_ptr<Player> playerTwo(make_unique<Player>("car",float  (1500),0));// new Player("car",1500,0);
    unique_ptr<Player> playerThree(make_unique<Player>("shoe", float (1500),0));
    unique_ptr<Player> playerFour(make_unique<Player>("hat",float  (1500),0));

    unique_ptr<UserInterface> userInterface(make_unique<UserInterface>()); //new UserInterface();



    unique_ptr<Station> station(make_unique<Station>());//new Station();

    fileOperations->readMonopolyData();
    fileOperations->createValueOrder();
    userInterface->setChance("playerOne");
    srand(5);///read seed file needs to be added
    //cout << fileOperations->getMySquare().size() << endl;
    for (int i = 0; i < 20; ++i) {
        string squareName;
        cout << "\n\n\n======================Round " + to_string(i + 1) + "==============================";
        for (int j = 0; j < 4; ++j) {
            if (userInterface->getChance() == "playerOne" && (!playerOne->isBankrupt())) {
                int colorGroup = 0;
                float cost = 0;
                char caseValue = 0;

                cout << "\n============== Chance of the Player One ==================";
                userInterface->setRandomNumber(userInterface->rollDice());

                if (25 >= (playerOne->getPlayerPosition() + userInterface->getRandomNumber())) {
                    playerOne->setPlayerPosition(playerOne->getPlayerPosition() + userInterface->getRandomNumber());
                    squareName = fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getSquareName();
                    userInterface->setPassesGo(false);
                } else if (25 < (playerOne->getPlayerPosition() + userInterface->getRandomNumber())) {
                    playerOne->setPlayerPosition((playerOne->getPlayerPosition() + userInterface->getRandomNumber()) - 25);
                    squareName = fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getSquareName();
                    playerOne->setPlayerMoney(playerOne->getPlayerMoney() + 200);
                    userInterface->setPassesGo(true);
                }

                if (rightTrim(squareName) == "Bonus") {
                    userInterface->setRollBonusPenalty(userInterface->rollDice());
                    playerOne->setPlayerMoney(playerOne->getPlayerMoney() + fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getBonusMoney(userInterface->getRollBonusPenalty()));
                    userInterface->setBonus(true);
                } else if (rightTrim(squareName) == "Penalty") {
                    userInterface->setRollBonusPenalty(userInterface->rollDice());
                    playerOne->setPlayerMoney(playerOne->getPlayerMoney() - fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getBonusMoney(userInterface->getRollBonusPenalty()));
                    userInterface->setPenalty(true);
                } else {
                    userInterface->setBonus(false);
                    userInterface->setPenalty(false);
                }

                userInterface->displayMove(userInterface->getRandomNumber(),playerOne->getPlayerName(),rightTrim(squareName),userInterface->isPassesGo(),userInterface->isBonus(),userInterface->isPenalty(),userInterface->getRollBonusPenalty());

                if (rightTrim(squareName) == "Go to Jail") {
                    playerOne->setPlayerMoney(playerOne->getPlayerMoney() - fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getPropertyCost());
                    playerOne->setPlayerPosition(fileOperations->findPosition("Jail "));

                }

                if (fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getSquareType() == 1 ||
                    fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getSquareType() == 3 ) {

                    if (fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getPropertyOwner().empty() &&
                        playerOne->getPlayerMoney() > 0) {

                        cost = fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getPropertyCost();

                        caseValue = 'A';

                        fileOperations->getMySquare()[playerOne->getPlayerPosition()]->setPropertyOwner(
                                playerOne->getPlayerName());

                        playerOne->setPlayerMoney(playerOne->getPlayerMoney() - cost);

                        //userInterface->displayPropertyTransactions(playerOne->getPlayerName(),squareName,cost,false);
                    } else if (fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getPropertyOwner() ==
                               playerOne->getPlayerName()) {

                        cost = 0;
                        caseValue = 0;

                    } else if ((playerTwo->getPlayerName() ==
                                fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getPropertyOwner()) && (!fileOperations->getMySquare()[playerOne->getPlayerPosition()]->isMortgaged())){

                        cost = fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getPropertyRent();

                        if (fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getSquareType() == 1) {
                            //cut a code set
                            cost = fileOperations->calculateColorGroupCost(cost, playerOne->getPlayerPosition(), playerTwo->getPlayerName());
                            caseValue = 'B';
                        } else if (fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getSquareType() == 3){
                            caseValue = 'C';
                        }

                        playerOne->setPlayerMoney(playerOne->getPlayerMoney() - cost);


                        playerTwo->setPlayerMoney(playerTwo->getPlayerMoney() + cost);

                    } else if ((playerThree->getPlayerName() ==
                                fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getPropertyOwner()) && (!fileOperations->getMySquare()[playerOne->getPlayerPosition()]->isMortgaged())){

                        cost = fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getPropertyRent();

                        if (fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getSquareType() == 1) {
                            cost = fileOperations->calculateColorGroupCost(cost, playerOne->getPlayerPosition(), playerThree->getPlayerName());
                            caseValue = 'B';
                        } else if (fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getSquareType() == 3){
                            caseValue = 'C';
                        }

                        playerOne->setPlayerMoney(playerOne->getPlayerMoney() - cost);


                        playerThree->setPlayerMoney(playerThree->getPlayerMoney() + cost);

                    } else if ((playerFour->getPlayerName() ==
                                fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getPropertyOwner()) && (!fileOperations->getMySquare()[playerOne->getPlayerPosition()]->isMortgaged())){

                        cost = fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getPropertyRent();

                        if (fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getSquareType() == 1) {
                            cost = fileOperations->calculateColorGroupCost(cost, playerOne->getPlayerPosition(), playerFour->getPlayerName());
                            caseValue = 'B';
                        } else if (fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getSquareType() == 3){
                            caseValue = 'C';
                        }

                        playerOne->setPlayerMoney(playerOne->getPlayerMoney() - cost);


                        playerFour->setPlayerMoney(playerFour->getPlayerMoney() + cost);

                    }
                }

                userInterface->displayPropertyTransactions(playerOne->getPlayerName(),squareName,cost,caseValue);

                userInterface->displayPlayerAmount(playerOne->getPlayerName(),playerOne->getPlayerMoney());
                ///working on
                if (playerOne->getPlayerMoney() < 0) {
                    for (int k = 0; k < fileOperations->getOrderedMySquare().size(); ++k) {
                        if (fileOperations->getOrderedMySquare()[k]->getPropertyOwner() == playerOne->getPlayerName()) {
                            if (!fileOperations->getOrderedMySquare()[k]->isMortgaged()) {
                                fileOperations->getOrderedMySquare()[k]->setMortgaged(true);
                                playerOne->addLentMoney(fileOperations->getOrderedMySquare()[k]->getPropertyCost());
                                playerOne->setLentMoney(true);

                                cout << "\n" << playerOne->getPlayerName() << " has mortgaged " << fileOperations->getOrderedMySquare()[k]->getSquareName() << endl;
                                cout << playerOne->getPlayerName() << " has " << playerOne->getPlayerMoney() << endl;
                            }
                        }
                        if (playerOne->getPlayerMoney() >= 0) {
                            break;
                        }
                    }

                    if (playerOne->getPlayerMoney() < 0) {
                        playerOne->setBankrupt(true);
                    }
                }

                if (playerOne->isLentMoney()) {
                    int count = 0;
                    for (int k = 0; k < fileOperations->getOrderedMySquare().size(); ++k) {
                        if (fileOperations->getOrderedMySquare()[k]->getPropertyOwner() == playerOne->getPlayerName() && fileOperations->getOrderedMySquare()[k]->isMortgaged()) {
                            ++count;
                            if (playerOne->getPlayerMoney() > fileOperations->getOrderedMySquare()[k]->getPropertyCost()) {
                                fileOperations->getOrderedMySquare()[k]->setMortgaged(false);
                                playerOne->repayMortgage(fileOperations->getOrderedMySquare()[k]->getPropertyCost());

                                cout << "\n" << playerOne->getPlayerName() << " has repaid mortgaged for " << fileOperations->getOrderedMySquare()[k]->getSquareName() << endl;
                                cout << playerOne->getPlayerName() << " has " << playerOne->getPlayerMoney() << endl;
                            } else {
                                break;
                            }
                        }
                    }

                    if (count == 0) {
                        playerOne->setLentMoney(false);
                    }
                }

                userInterface->setChance("playerTwo");
                cout << "\n============== End of the Chance of the Player One =================="  << endl;

            } else if (userInterface->getChance() == "playerTwo" && (!playerTwo->isBankrupt())) {
                int colorGroup = 0;
                float cost = 0;
                char caseValue = 0;

                cout << "\n============== Chance of the Player Two ==================";
                userInterface->setRandomNumber(userInterface->rollDice());

                if (25 >= (playerTwo->getPlayerPosition() + userInterface->getRandomNumber())) {
                    playerTwo->setPlayerPosition(playerTwo->getPlayerPosition() + userInterface->getRandomNumber());
                    squareName = fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getSquareName();
                    userInterface->setPassesGo(false);
                } else if (25 < (playerTwo->getPlayerPosition() + userInterface->getRandomNumber())) {
                    playerTwo->setPlayerPosition((playerTwo->getPlayerPosition() + userInterface->getRandomNumber()) - 25);
                    squareName = fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getSquareName();
                    playerTwo->setPlayerMoney(playerTwo->getPlayerMoney() + 200);
                    userInterface->setPassesGo(true);
                }

                if (rightTrim(squareName) == "Bonus") {
                    userInterface->setRollBonusPenalty(userInterface->rollDice());
                    playerTwo->setPlayerMoney(playerTwo->getPlayerMoney() + fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getBonusMoney(userInterface->getRollBonusPenalty()));
                    userInterface->setBonus(true);
                } else if (rightTrim(squareName) == "Penalty") {
                    userInterface->setRollBonusPenalty(userInterface->rollDice());
                    playerTwo->setPlayerMoney(playerTwo->getPlayerMoney() - fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getBonusMoney(userInterface->getRollBonusPenalty()));
                    userInterface->setPenalty(true);
                } else {
                    userInterface->setBonus(false);
                    userInterface->setPenalty(false);
                }
                userInterface->displayMove(userInterface->getRandomNumber(),playerTwo->getPlayerName(),rightTrim(squareName),userInterface->isPassesGo(),userInterface->isBonus(),userInterface->isPenalty(),userInterface->getRollBonusPenalty());

                if (rightTrim(squareName) == "Go to Jail") {
                    playerTwo->setPlayerMoney(playerTwo->getPlayerMoney() - fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getPropertyCost());
                    playerTwo->setPlayerPosition(fileOperations->findPosition("Jail "));


                }

                if (fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getSquareType() == 1 ||
                    fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getSquareType() == 3) {

                    if (fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getPropertyOwner().empty() &&
                        playerTwo->getPlayerMoney() > 0) {

                        cost = fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getPropertyCost();
                        caseValue = 'A';
                        fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->setPropertyOwner(
                                playerTwo->getPlayerName());
                        playerTwo->setPlayerMoney(playerTwo->getPlayerMoney() - cost);
                        //userInterface->displayPropertyTransactions(playerOne->getPlayerName(),squareName,cost,false);

                    } else if (fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getPropertyOwner() ==
                               playerTwo->getPlayerName()) {

                        cost = 0;
                        caseValue = 0;

                    } else if ((playerOne->getPlayerName() ==
                               fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getPropertyOwner()) &&
                                ((!fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->isMortgaged()))) {

                        cost = fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getPropertyRent();

                        if (fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getSquareType() == 1) {
                            cost = fileOperations->calculateColorGroupCost(cost, playerTwo->getPlayerPosition(), playerOne->getPlayerName());
                            caseValue = 'B';
                        } else if (fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getSquareType() == 3) {
                            caseValue = 'C';
                        }

                        playerTwo->setPlayerMoney(playerTwo->getPlayerMoney() - cost);


                        playerOne->setPlayerMoney(playerOne->getPlayerMoney() + cost);

                    } else if ((playerThree->getPlayerName() ==
                                fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getPropertyOwner()) &&
                               ((!fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->isMortgaged()))) {

                        cost = fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getPropertyRent();

                        if (fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getSquareType() == 1) {
                            cost = fileOperations->calculateColorGroupCost(cost, playerTwo->getPlayerPosition(), playerThree->getPlayerName());
                            caseValue = 'B';
                        } else if (fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getSquareType() == 3) {
                            caseValue = 'C';
                        }

                        playerTwo->setPlayerMoney(playerTwo->getPlayerMoney() - cost);


                        playerThree->setPlayerMoney(playerThree->getPlayerMoney() + cost);

                    } else if ((playerFour->getPlayerName() ==
                                fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getPropertyOwner()) &&
                               ((!fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->isMortgaged()))) {

                        cost = fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getPropertyRent();

                        if (fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getSquareType() == 1) {
                            cost = fileOperations->calculateColorGroupCost(cost, playerTwo->getPlayerPosition(), playerFour->getPlayerName());
                            caseValue = 'B';
                        } else if (fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getSquareType() == 3) {
                            caseValue = 'C';
                        }

                        playerTwo->setPlayerMoney(playerTwo->getPlayerMoney() - cost);


                        playerFour->setPlayerMoney(playerFour->getPlayerMoney() + cost);

                    }
                }

                userInterface->displayPropertyTransactions(playerTwo->getPlayerName(),squareName,cost,caseValue);

                userInterface->displayPlayerAmount(playerTwo->getPlayerName(),playerTwo->getPlayerMoney());

                ///working on
                if (playerTwo->getPlayerMoney() < 0) {
                    for (int k = 0; k < fileOperations->getOrderedMySquare().size(); ++k) {
                        if (fileOperations->getOrderedMySquare()[k]->getPropertyOwner() == playerTwo->getPlayerName()) {
                            if (!fileOperations->getOrderedMySquare()[k]->isMortgaged()) {
                                fileOperations->getOrderedMySquare()[k]->setMortgaged(true);
                                playerTwo->addLentMoney(fileOperations->getOrderedMySquare()[k]->getPropertyCost());
                                playerTwo->setLentMoney(true);
                                cout << playerTwo->getPlayerName() << " has mortgaged " << fileOperations->getOrderedMySquare()[k]->getSquareName() << endl;
                                cout << playerTwo->getPlayerName() << " has " << playerTwo->getPlayerMoney() << endl;
                            }
                        }
                        if (playerTwo->getPlayerMoney() >= 0) {
                            break;
                        }
                    }

                    if (playerTwo->getPlayerMoney() < 0) {
                        playerTwo->setBankrupt(true);
                    }
                }


                if (playerTwo->isLentMoney()) {
                    int count = 0;
                    for (int k = 0; k < fileOperations->getOrderedMySquare().size(); ++k) {
                        if (fileOperations->getOrderedMySquare()[k]->getPropertyOwner() == playerTwo->getPlayerName() && fileOperations->getOrderedMySquare()[k]->isMortgaged()) {
                            ++count;
                            if (playerTwo->getPlayerMoney() > fileOperations->getOrderedMySquare()[k]->getPropertyCost()) {
                                fileOperations->getOrderedMySquare()[k]->setMortgaged(false);
                                playerTwo->repayMortgage(fileOperations->getOrderedMySquare()[k]->getPropertyCost());

                                cout << "\n" << playerTwo->getPlayerName() << " has repaid mortgaged for " << fileOperations->getOrderedMySquare()[k]->getSquareName() << endl;
                                cout << playerTwo->getPlayerName() << " has " << playerTwo->getPlayerMoney() << endl;
                            } else {
                                break;
                            }
                        }
                    }

                    if (count == 0) {
                        playerTwo->setLentMoney(false);
                    }
                }

                userInterface->setChance("playerThree");
                cout << "\n============== End of the Chance of the Player Two =================="  << endl;
                
            } else if (userInterface->getChance() == "playerThree" && (!playerThree->isBankrupt())) {
                int colorGroup = 0;
                float cost = 0;
                char caseValue = 0;

                cout << "\n============== Chance of the Player Three ==================";
                userInterface->setRandomNumber(userInterface->rollDice());

                if (25 >= (playerThree->getPlayerPosition() + userInterface->getRandomNumber())) {
                    playerThree->setPlayerPosition(playerThree->getPlayerPosition() + userInterface->getRandomNumber());
                    squareName = fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getSquareName();
                    userInterface->setPassesGo(false);
                } else if (25 < (playerThree->getPlayerPosition() + userInterface->getRandomNumber())) {
                    playerThree->setPlayerPosition((playerThree->getPlayerPosition() + userInterface->getRandomNumber()) - 25);
                    squareName = fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getSquareName();
                    playerThree->setPlayerMoney(playerThree->getPlayerMoney() + 200);
                    userInterface->setPassesGo(true);
                }

                if (rightTrim(squareName) == "Bonus") {
                    userInterface->setRollBonusPenalty(userInterface->rollDice());
                    playerThree->setPlayerMoney(playerThree->getPlayerMoney() + fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getBonusMoney(userInterface->getRollBonusPenalty()));
                    userInterface->setBonus(true);
                } else if (rightTrim(squareName) == "Penalty") {
                    userInterface->setRollBonusPenalty(userInterface->rollDice());
                    playerThree->setPlayerMoney(playerThree->getPlayerMoney() - fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getBonusMoney(userInterface->getRollBonusPenalty()));
                    userInterface->setPenalty(true);
                } else {
                    userInterface->setBonus(false);
                    userInterface->setPenalty(false);
                }
                userInterface->displayMove(userInterface->getRandomNumber(),playerThree->getPlayerName(),rightTrim(squareName),userInterface->isPassesGo(),userInterface->isBonus(),userInterface->isPenalty(),userInterface->getRollBonusPenalty());

                if (rightTrim(squareName) == "Go to Jail") {
                    playerThree->setPlayerMoney(playerThree->getPlayerMoney() - fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getPropertyCost());
                    playerThree->setPlayerPosition(fileOperations->findPosition("Jail "));


                }

                if (fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getSquareType() == 1 ||
                    fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getSquareType() == 3) {

                    if (fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getPropertyOwner().empty() &&
                        playerThree->getPlayerMoney() > 0) {

                        cost = fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getPropertyCost();
                        caseValue = 'A';
                        fileOperations->getMySquare()[playerThree->getPlayerPosition()]->setPropertyOwner(
                                playerThree->getPlayerName());
                        playerThree->setPlayerMoney(playerThree->getPlayerMoney() - cost);
                        //userInterface->displayPropertyTransactions(playerOne->getPlayerName(),squareName,cost,false);

                    } else if (fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getPropertyOwner() ==
                               playerThree->getPlayerName()) {

                        cost = 0;
                        caseValue = 0;

                    } else if ((playerOne->getPlayerName() ==
                                fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getPropertyOwner()) &&
                               ((!fileOperations->getMySquare()[playerThree->getPlayerPosition()]->isMortgaged()))) {

                        cost = fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getPropertyRent();

                        if (fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getSquareType() == 1) {
                            cost = fileOperations->calculateColorGroupCost(cost, playerThree->getPlayerPosition(), playerOne->getPlayerName());
                            caseValue = 'B';
                        } else if (fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getSquareType() == 3) {
                            caseValue = 'C';
                        }

                        playerThree->setPlayerMoney(playerThree->getPlayerMoney() - cost);


                        playerOne->setPlayerMoney(playerOne->getPlayerMoney() + cost);

                    } else if ((playerTwo->getPlayerName() ==
                                fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getPropertyOwner()) &&
                               ((!fileOperations->getMySquare()[playerThree->getPlayerPosition()]->isMortgaged()))) {

                        cost = fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getPropertyRent();

                        if (fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getSquareType() == 1) {
                            cost = fileOperations->calculateColorGroupCost(cost, playerThree->getPlayerPosition(), playerTwo->getPlayerName());
                            caseValue = 'B';
                        } else if (fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getSquareType() == 3) {
                            caseValue = 'C';
                        }

                        playerThree->setPlayerMoney(playerThree->getPlayerMoney() - cost);


                        playerTwo->setPlayerMoney(playerTwo->getPlayerMoney() + cost);

                    } else if ((playerFour->getPlayerName() ==
                                fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getPropertyOwner()) &&
                               ((!fileOperations->getMySquare()[playerThree->getPlayerPosition()]->isMortgaged()))) {

                        cost = fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getPropertyRent();

                        if (fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getSquareType() == 1) {
                            cost = fileOperations->calculateColorGroupCost(cost, playerThree->getPlayerPosition(), playerFour->getPlayerName());
                            caseValue = 'B';
                        } else if (fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getSquareType() == 3) {
                            caseValue = 'C';
                        }

                        playerThree->setPlayerMoney(playerThree->getPlayerMoney() - cost);


                        playerFour->setPlayerMoney(playerFour->getPlayerMoney() + cost);

                    }
                }

                userInterface->displayPropertyTransactions(playerThree->getPlayerName(),squareName,cost,caseValue);

                userInterface->displayPlayerAmount(playerThree->getPlayerName(),playerThree->getPlayerMoney());

                ///working on
                if (playerThree->getPlayerMoney() < 0) {
                    for (int k = 0; k < fileOperations->getOrderedMySquare().size(); ++k) {
                        if (fileOperations->getOrderedMySquare()[k]->getPropertyOwner() == playerThree->getPlayerName()) {
                            if (!fileOperations->getOrderedMySquare()[k]->isMortgaged()) {
                                fileOperations->getOrderedMySquare()[k]->setMortgaged(true);
                                playerThree->addLentMoney(fileOperations->getOrderedMySquare()[k]->getPropertyCost());
                                playerThree->setLentMoney(true);
                                cout << playerThree->getPlayerName() << " has mortgaged " << fileOperations->getOrderedMySquare()[k]->getSquareName() << endl;
                                cout << playerThree->getPlayerName() << " has " << playerThree->getPlayerMoney() << endl;
                            }
                        }
                        if (playerThree->getPlayerMoney() >= 0) {
                            break;
                        }
                    }

                    if (playerThree->getPlayerMoney() < 0) {
                        playerThree->setBankrupt(true);
                    }
                }


                if (playerThree->isLentMoney()) {
                    int count = 0;
                    for (int k = 0; k < fileOperations->getOrderedMySquare().size(); ++k) {
                        if (fileOperations->getOrderedMySquare()[k]->getPropertyOwner() == playerThree->getPlayerName() && fileOperations->getOrderedMySquare()[k]->isMortgaged()) {
                            ++count;
                            if (playerThree->getPlayerMoney() > fileOperations->getOrderedMySquare()[k]->getPropertyCost()) {
                                fileOperations->getOrderedMySquare()[k]->setMortgaged(false);
                                playerThree->repayMortgage(fileOperations->getOrderedMySquare()[k]->getPropertyCost());

                                cout << "\n" << playerThree->getPlayerName() << " has repaid mortgaged for " << fileOperations->getOrderedMySquare()[k]->getSquareName() << endl;
                                cout << playerThree->getPlayerName() << " has " << playerThree->getPlayerMoney() << endl;
                            } else {
                                break;
                            }
                        }
                    }

                    if (count == 0) {
                        playerThree->setLentMoney(false);
                    }
                }

                userInterface->setChance("playerFour");
                cout << "\n============== End of the Chance of the Player Three =================="  << endl;
                
            } else if (userInterface->getChance() == "playerFour" && (!playerFour->isBankrupt())) {
                int colorGroup = 0;
                float cost = 0;
                char caseValue = 0;

                cout << "\n============== Chance of the Player Four ==================";
                userInterface->setRandomNumber(userInterface->rollDice());

                if (25 >= (playerFour->getPlayerPosition() + userInterface->getRandomNumber())) {
                    playerFour->setPlayerPosition(playerFour->getPlayerPosition() + userInterface->getRandomNumber());
                    squareName = fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getSquareName();
                    userInterface->setPassesGo(false);
                } else if (25 < (playerFour->getPlayerPosition() + userInterface->getRandomNumber())) {
                    playerFour->setPlayerPosition((playerFour->getPlayerPosition() + userInterface->getRandomNumber()) - 25);
                    squareName = fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getSquareName();
                    playerFour->setPlayerMoney(playerFour->getPlayerMoney() + 200);
                    userInterface->setPassesGo(true);
                }

                if (rightTrim(squareName) == "Bonus") {
                    userInterface->setRollBonusPenalty(userInterface->rollDice());
                    playerFour->setPlayerMoney(playerFour->getPlayerMoney() + fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getBonusMoney(userInterface->getRollBonusPenalty()));
                    userInterface->setBonus(true);
                } else if (rightTrim(squareName) == "Penalty") {
                    userInterface->setRollBonusPenalty(userInterface->rollDice());
                    playerFour->setPlayerMoney(playerFour->getPlayerMoney() - fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getBonusMoney(userInterface->getRollBonusPenalty()));
                    userInterface->setPenalty(true);
                } else {
                    userInterface->setBonus(false);
                    userInterface->setPenalty(false);
                }
                userInterface->displayMove(userInterface->getRandomNumber(),playerFour->getPlayerName(),rightTrim(squareName),userInterface->isPassesGo(),userInterface->isBonus(),userInterface->isPenalty(),userInterface->getRollBonusPenalty());

                if (rightTrim(squareName) == "Go to Jail") {
                    playerFour->setPlayerMoney(playerFour->getPlayerMoney() - fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getPropertyCost());
                    playerFour->setPlayerPosition(fileOperations->findPosition("Jail "));


                }

                if (fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getSquareType() == 1 ||
                    fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getSquareType() == 3) {

                    if (fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getPropertyOwner().empty() &&
                        playerFour->getPlayerMoney() > 0) {

                        cost = fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getPropertyCost();
                        caseValue = 'A';
                        fileOperations->getMySquare()[playerFour->getPlayerPosition()]->setPropertyOwner(
                                playerFour->getPlayerName());
                        playerFour->setPlayerMoney(playerFour->getPlayerMoney() - cost);
                        //userInterface->displayPropertyTransactions(playerOne->getPlayerName(),squareName,cost,false);

                    } else if (fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getPropertyOwner() ==
                               playerFour->getPlayerName()) {

                        cost = 0;
                        caseValue = 0;

                    } else if ((playerOne->getPlayerName() ==
                                fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getPropertyOwner()) &&
                               ((!fileOperations->getMySquare()[playerFour->getPlayerPosition()]->isMortgaged()))) {

                        cost = fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getPropertyRent();

                        if (fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getSquareType() == 1) {
                            cost = fileOperations->calculateColorGroupCost(cost, playerFour->getPlayerPosition(), playerOne->getPlayerName());
                            caseValue = 'B';
                        } else if (fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getSquareType() == 3) {
                            caseValue = 'C';
                        }

                        playerFour->setPlayerMoney(playerFour->getPlayerMoney() - cost);


                        playerOne->setPlayerMoney(playerOne->getPlayerMoney() + cost);

                    } else if ((playerTwo->getPlayerName() ==
                                fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getPropertyOwner()) &&
                               ((!fileOperations->getMySquare()[playerFour->getPlayerPosition()]->isMortgaged()))) {

                        cost = fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getPropertyRent();

                        if (fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getSquareType() == 1) {
                            cost = fileOperations->calculateColorGroupCost(cost, playerFour->getPlayerPosition(), playerTwo->getPlayerName());
                            caseValue = 'B';
                        } else if (fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getSquareType() == 3) {
                            caseValue = 'C';
                        }

                        playerFour->setPlayerMoney(playerFour->getPlayerMoney() - cost);


                        playerTwo->setPlayerMoney(playerTwo->getPlayerMoney() + cost);

                    } else if ((playerThree->getPlayerName() ==
                                fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getPropertyOwner()) &&
                               ((!fileOperations->getMySquare()[playerFour->getPlayerPosition()]->isMortgaged()))) {

                        cost = fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getPropertyRent();

                        if (fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getSquareType() == 1) {
                            cost = fileOperations->calculateColorGroupCost(cost, playerFour->getPlayerPosition(), playerThree->getPlayerName());
                            caseValue = 'B';
                        } else if (fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getSquareType() == 3) {
                            caseValue = 'C';
                        }

                        playerFour->setPlayerMoney(playerFour->getPlayerMoney() - cost);


                        playerThree->setPlayerMoney(playerThree->getPlayerMoney() + cost);

                    }
                }

                userInterface->displayPropertyTransactions(playerFour->getPlayerName(),squareName,cost,caseValue);

                userInterface->displayPlayerAmount(playerFour->getPlayerName(),playerFour->getPlayerMoney());

                ///working on
                if (playerFour->getPlayerMoney() < 0) {
                    for (int k = 0; k < fileOperations->getOrderedMySquare().size(); ++k) {
                        if (fileOperations->getOrderedMySquare()[k]->getPropertyOwner() == playerFour->getPlayerName()) {
                            if (!fileOperations->getOrderedMySquare()[k]->isMortgaged()) {
                                fileOperations->getOrderedMySquare()[k]->setMortgaged(true);
                                playerFour->addLentMoney(fileOperations->getOrderedMySquare()[k]->getPropertyCost());
                                playerFour->setLentMoney(true);
                                cout << playerFour->getPlayerName() << " has mortgaged " << fileOperations->getOrderedMySquare()[k]->getSquareName() << endl;
                                cout << playerFour->getPlayerName() << " has " << playerFour->getPlayerMoney() << endl;
                            }
                        }
                        if (playerFour->getPlayerMoney() >= 0) {
                            break;
                        }
                    }

                    if (playerFour->getPlayerMoney() < 0) {
                        playerFour->setBankrupt(true);
                    }
                }


                if (playerFour->isLentMoney()) {
                    int count = 0;
                    for (int k = 0; k < fileOperations->getOrderedMySquare().size(); ++k) {
                        if (fileOperations->getOrderedMySquare()[k]->getPropertyOwner() == playerFour->getPlayerName() && fileOperations->getOrderedMySquare()[k]->isMortgaged()) {
                            ++count;
                            if (playerFour->getPlayerMoney() > fileOperations->getOrderedMySquare()[k]->getPropertyCost()) {
                                fileOperations->getOrderedMySquare()[k]->setMortgaged(false);
                                playerFour->repayMortgage(fileOperations->getOrderedMySquare()[k]->getPropertyCost());

                                cout << "\n" << playerFour->getPlayerName() << " has repaid mortgaged for " << fileOperations->getOrderedMySquare()[k]->getSquareName() << endl;
                                cout << playerFour->getPlayerName() << " has " << playerFour->getPlayerMoney() << endl;
                            } else {
                                break;
                            }
                        }
                    }

                    if (count == 0) {
                        playerFour->setLentMoney(false);
                    }
                }

                userInterface->setChance("playerOne");
                cout << "\n============== End of the Chance of the Player Four =================="  << endl;
            }
        }
        if ((playerOne->isBankrupt() && playerTwo->isBankrupt() && playerThree->isBankrupt() && (!playerFour->isBankrupt()))
            || (playerFour->isBankrupt() && playerTwo->isBankrupt() && playerThree->isBankrupt() && (!playerOne->isBankrupt()))
            || (playerOne->isBankrupt() && playerFour->isBankrupt() && playerThree->isBankrupt() && (!playerTwo->isBankrupt()))
            || (playerOne->isBankrupt() && playerTwo->isBankrupt() && playerFour->isBankrupt() && (!playerThree->isBankrupt()))) {
            break;
        }
    }



    if ((playerOne->getPlayerMoney() < playerTwo->getPlayerMoney()) && (playerThree->getPlayerMoney() < playerTwo->getPlayerMoney()) && (playerFour->getPlayerMoney() < playerTwo->getPlayerMoney())) {
        userInterface->displayEndResult(playerTwo->getPlayerName(),playerTwo->getPlayerMoney(),playerOne->getPlayerName(),playerOne->getPlayerMoney(), playerThree->getPlayerName(), playerThree->getPlayerMoney(), playerFour->getPlayerName(), playerFour->getPlayerMoney());
    } else if ((playerOne->getPlayerMoney() > playerTwo->getPlayerMoney()) && (playerOne->getPlayerMoney() > playerThree->getPlayerMoney()) && (playerOne->getPlayerMoney() > playerFour->getPlayerMoney())) {
        userInterface->displayEndResult(playerOne->getPlayerName(),playerOne->getPlayerMoney(),playerTwo->getPlayerName(),playerTwo->getPlayerMoney(),playerThree->getPlayerName(), playerThree->getPlayerMoney(), playerFour->getPlayerName(), playerFour->getPlayerMoney());
    } else if ((playerThree->getPlayerMoney() > playerOne->getPlayerMoney()) && (playerThree->getPlayerMoney() > playerTwo->getPlayerMoney()) && (playerThree->getPlayerMoney() > playerFour->getPlayerMoney())) {
        userInterface->displayEndResult(playerThree->getPlayerName(),playerThree->getPlayerMoney(),playerTwo->getPlayerName(),playerTwo->getPlayerMoney(),playerOne->getPlayerName(), playerOne->getPlayerMoney(), playerFour->getPlayerName(), playerFour->getPlayerMoney());
    } else if ((playerFour->getPlayerMoney() > playerOne->getPlayerMoney()) && (playerFour->getPlayerMoney() > playerTwo->getPlayerMoney()) && (playerFour->getPlayerMoney() > playerThree->getPlayerMoney())) {
        userInterface->displayEndResult(playerFour->getPlayerName(),playerFour->getPlayerMoney(),playerTwo->getPlayerName(),playerTwo->getPlayerMoney(),playerThree->getPlayerName(), playerThree->getPlayerMoney(), playerOne->getPlayerName(), playerOne->getPlayerMoney());
    }
    else {
        cout << "ERROR!!!!" << endl;
    }

    system("pause");

    return 0;
}
