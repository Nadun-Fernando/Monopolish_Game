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

#define SQUARE_TYPE(mainPlayer) fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getSquareType()


string rightTrim(string word) {
    return word.erase(word.find_last_not_of(" \n\r\t")+1);
}

void playTurn(unique_ptr<Player>& mainPlayer, unique_ptr<UserInterface>& userInterface, unique_ptr<FileOperations>& fileOperations) {
    string squareName;
    userInterface->setRandomNumber(userInterface->rollDice());

    if (25 >= (mainPlayer->getPlayerPosition() + userInterface->getRandomNumber())) {
        mainPlayer->setPlayerPosition(mainPlayer->getPlayerPosition() + userInterface->getRandomNumber());
        squareName = fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getSquareName();
        userInterface->setPassesGo(false);
    } else if (25 < (mainPlayer->getPlayerPosition() + userInterface->getRandomNumber())) {
        mainPlayer->setPlayerPosition((mainPlayer->getPlayerPosition() + userInterface->getRandomNumber()) - 25);
        squareName = fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getSquareName();
        mainPlayer->setPlayerMoney(mainPlayer->getPlayerMoney() + 200);
        userInterface->setPassesGo(true);
    }

    if (rightTrim(squareName) == "Bonus") {
        userInterface->setRollBonusPenalty(userInterface->rollDice());
        mainPlayer->setPlayerMoney(mainPlayer->getPlayerMoney() + fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getBonusMoney(userInterface->getRollBonusPenalty()));
        userInterface->setBonus(true);
    } else if (rightTrim(squareName) == "Penalty") {
        userInterface->setRollBonusPenalty(userInterface->rollDice());
        mainPlayer->setPlayerMoney(mainPlayer->getPlayerMoney() - fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getBonusMoney(userInterface->getRollBonusPenalty()));
        userInterface->setPenalty(true);
    } else {
        userInterface->setBonus(false);
        userInterface->setPenalty(false);
    }

    userInterface->displayMove(userInterface->getRandomNumber(),mainPlayer->getPlayerName(),rightTrim(squareName),userInterface->isPassesGo(),userInterface->isBonus(),userInterface->isPenalty(),userInterface->getRollBonusPenalty());

    if (rightTrim(squareName) == "Go to Jail") {
        mainPlayer->setPlayerMoney(mainPlayer->getPlayerMoney() - fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getPropertyCost());
        mainPlayer->setPlayerPosition(fileOperations->findPosition("Jail "));

    }
}

void propertyTransactions(unique_ptr<Player>& mainPlayer,
                          unique_ptr<Player>& secondPlayer,
                          unique_ptr<Player>& thirdPlayer,
                          unique_ptr<Player>& fourthPlayer,
                          unique_ptr<UserInterface>& userInterface,
                          unique_ptr<FileOperations>& fileOperations,
                          string& squareName) {
    int colorGroup = 0;
    float cost = 0;
    char caseValue = 0;

    if (SQUARE_TYPE(mainPlayer) == 1 || SQUARE_TYPE(mainPlayer) == 3 ) {

        if (fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getPropertyOwner().empty() &&
                mainPlayer->getPlayerMoney() > 0) {

            cost = fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getPropertyCost();

            caseValue = 'A';

            fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->setPropertyOwner(
                    mainPlayer->getPlayerName());

            mainPlayer->setPlayerMoney(mainPlayer->getPlayerMoney() - cost);

            //userInterface->displayPropertyTransactions(playerOne->getPlayerName(),squareName,cost,false);
        } else if (fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getPropertyOwner() ==
                mainPlayer->getPlayerName()) {

            cost = 0;
            caseValue = 0;

        } else if ((mainPlayer->getPlayerName() !=
                    fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getPropertyOwner())
                    && (!fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->isMortgaged())){

            if (fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getPropertyOwner() == secondPlayer->getPlayerName()) {
                cost = fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getPropertyRent();

                if (fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getSquareType() == 1) {
                    //cut a code set
                    cost = fileOperations->calculateColorGroupCost(cost, mainPlayer->getPlayerPosition(), secondPlayer->getPlayerName());
                    caseValue = 'B';
                } else if (fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getSquareType() == 3){
                    caseValue = 'C';
                }

                mainPlayer->setPlayerMoney(mainPlayer->getPlayerMoney() - cost);


                secondPlayer->setPlayerMoney(secondPlayer->getPlayerMoney() + cost);
            } else if (fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getPropertyOwner() == thirdPlayer->getPlayerName()) {
                cost = fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getPropertyRent();

                if (fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getSquareType() == 1) {
                    cost = fileOperations->calculateColorGroupCost(cost, mainPlayer->getPlayerPosition(), thirdPlayer->getPlayerName());
                    caseValue = 'B';
                } else if (fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getSquareType() == 3){
                    caseValue = 'C';
                }

                mainPlayer->setPlayerMoney(mainPlayer->getPlayerMoney() - cost);


                thirdPlayer->setPlayerMoney(thirdPlayer->getPlayerMoney() + cost);
            } else if (fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getPropertyOwner() == fourthPlayer->getPlayerName()) {
                cost = fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getPropertyRent();

                if (fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getSquareType() == 1) {
                    cost = fileOperations->calculateColorGroupCost(cost, mainPlayer->getPlayerPosition(), fourthPlayer->getPlayerName());
                    caseValue = 'B';
                } else if (fileOperations->getMySquare()[mainPlayer->getPlayerPosition()]->getSquareType() == 3){
                    caseValue = 'C';
                }

                mainPlayer->setPlayerMoney(mainPlayer->getPlayerMoney() - cost);


                fourthPlayer->setPlayerMoney(fourthPlayer->getPlayerMoney() + cost);
            }
        }
    }

    userInterface->displayPropertyTransactions(mainPlayer->getPlayerName(),squareName,cost,caseValue);

}

void mortgageAndBanckruptancy(unique_ptr<Player>& mainPlayer, unique_ptr<UserInterface>& userInterface, unique_ptr<FileOperations>& fileOperations) {
    if (mainPlayer->getPlayerMoney() < 0) {
        for (int k = 0; k < fileOperations->getOrderedMySquare().size(); ++k) {
            if (fileOperations->getOrderedMySquare()[k]->getPropertyOwner() == mainPlayer->getPlayerName()) {
                if (!fileOperations->getOrderedMySquare()[k]->isMortgaged()) {
                    fileOperations->getOrderedMySquare()[k]->setMortgaged(true);
                    mainPlayer->addLentMoney(fileOperations->getOrderedMySquare()[k]->getPropertyCost());
                    mainPlayer->setLentMoney(true);
                    cout << mainPlayer->getPlayerName() << " has mortgaged " << fileOperations->getOrderedMySquare()[k]->getSquareName() << endl;
                    cout << mainPlayer->getPlayerName() << " has " << mainPlayer->getPlayerMoney() << endl;
                }
            }
            if (mainPlayer->getPlayerMoney() >= 0) {
                break;
            }
        }

        if (mainPlayer->getPlayerMoney() < 0) {
            mainPlayer->setBankrupt(true);
        }
    }


    if (mainPlayer->isLentMoney()) {
        int count = 0;
        for (int k = 0; k < fileOperations->getOrderedMySquare().size(); ++k) {
            if (fileOperations->getOrderedMySquare()[k]->getPropertyOwner() == mainPlayer->getPlayerName() && fileOperations->getOrderedMySquare()[k]->isMortgaged()) {
                ++count;
                if (mainPlayer->getPlayerMoney() > fileOperations->getOrderedMySquare()[k]->getPropertyCost()) {
                    fileOperations->getOrderedMySquare()[k]->setMortgaged(false);
                    mainPlayer->repayMortgage(fileOperations->getOrderedMySquare()[k]->getPropertyCost());

                    cout << "\n" << mainPlayer->getPlayerName() << " has repaid mortgaged for " << fileOperations->getOrderedMySquare()[k]->getSquareName() << endl;
                    cout << mainPlayer->getPlayerName() << " has " << mainPlayer->getPlayerMoney() << endl;
                } else {
                    break;
                }
            }
        }

        if (count == 0) {
            mainPlayer->setLentMoney(false);
        }
    }
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

    //userInterface->intro();

    unique_ptr<Station> station(make_unique<Station>());//new Station();

    fileOperations->readMonopolyData();
    fileOperations->createValueOrder();
    userInterface->setChance("playerOne");
    fileOperations->readSeed("../Resources/seed.txt");
    srand(fileOperations->getSeedValue());///read seed file needs to be added
    //cout << fileOperations->getMySquare().size() << endl;
    for (int i = 0; i < 20; ++i) {
        string squareName;
        cout << "\n\n\n======================Round " + to_string(i + 1) + "==============================";
        for (int j = 0; j < 4; ++j) {
            if (userInterface->getChance() == "playerOne" && (!playerOne->isBankrupt())) {
//                int colorGroup = 0;
//                float cost = 0;
//                char caseValue = 0;

                cout << "\n============== Chance of the Player One ==================";
                playTurn(playerOne,userInterface, fileOperations);
                squareName = fileOperations->getMySquare()[playerOne->getPlayerPosition()]->getSquareName();

                propertyTransactions(playerOne,playerTwo, playerThree, playerFour, userInterface, fileOperations, squareName);
                userInterface->displayPlayerAmount(playerOne->getPlayerName(),playerOne->getPlayerMoney());

                mortgageAndBanckruptancy(playerOne, userInterface, fileOperations);

                userInterface->setChance("playerTwo");
                cout << "\n============== End of the Chance of the Player One =================="  << endl;

            } else if (userInterface->getChance() == "playerTwo" && (!playerTwo->isBankrupt())) {
                int colorGroup = 0;
                float cost = 0;
                char caseValue = 0;

                cout << "\n============== Chance of the Player Two ==================";
                playTurn(playerTwo, userInterface, fileOperations);
                squareName = fileOperations->getMySquare()[playerTwo->getPlayerPosition()]->getSquareName();

                propertyTransactions(playerTwo, playerOne, playerThree, playerFour, userInterface, fileOperations,squareName);
                userInterface->displayPlayerAmount(playerTwo->getPlayerName(),playerTwo->getPlayerMoney());

                mortgageAndBanckruptancy(playerTwo, userInterface, fileOperations);

                userInterface->setChance("playerThree");
                cout << "\n============== End of the Chance of the Player Two =================="  << endl;
                
            } else if (userInterface->getChance() == "playerThree" && (!playerThree->isBankrupt())) {
                int colorGroup = 0;
                float cost = 0;
                char caseValue = 0;

                cout << "\n============== Chance of the Player Three ==================";
                playTurn(playerThree, userInterface, fileOperations);
                squareName = fileOperations->getMySquare()[playerThree->getPlayerPosition()]->getSquareName();

                propertyTransactions(playerThree, playerOne, playerTwo, playerFour, userInterface, fileOperations,squareName);
                userInterface->displayPlayerAmount(playerThree->getPlayerName(),playerThree->getPlayerMoney());

                mortgageAndBanckruptancy(playerThree, userInterface, fileOperations);

                userInterface->setChance("playerFour");
                cout << "\n============== End of the Chance of the Player Three =================="  << endl;
                
            } else if (userInterface->getChance() == "playerFour" && (!playerFour->isBankrupt())) {
                int colorGroup = 0;
                float cost = 0;
                char caseValue = 0;

                cout << "\n============== Chance of the Player Four ==================";
                playTurn(playerFour, userInterface, fileOperations);
                squareName = fileOperations->getMySquare()[playerFour->getPlayerPosition()]->getSquareName();

                propertyTransactions(playerFour,playerOne, playerTwo, playerThree, userInterface, fileOperations, squareName);
                userInterface->displayPropertyTransactions(playerFour->getPlayerName(),squareName,cost,caseValue);

                userInterface->displayPlayerAmount(playerFour->getPlayerName(),playerFour->getPlayerMoney());

                mortgageAndBanckruptancy(playerFour, userInterface, fileOperations);

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
