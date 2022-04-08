//
// Created by Nadun N. T. Fernando on 2/14/2022.
//

#include "FileOperations.h"
#include "Properties.h"
#include "BonusSquare.h"
#include "PenaltySquare.h"
#include "JailSquare.h"
#include "GotoJailSquare.h"
#include "FreeParking.h"

#include <string>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;


FileOperations::FileOperations() = default;

FileOperations::FileOperations(string fileName) : fileName(std::move(fileName)) {}

bool FileOperations::isNumber(const string &str) {
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

vectorString FileOperations::getLine(string line) {
    bool isString = false;
    string temp;

//    char * tokens;
//    char * next_token;
//    const char * delim = " ";
//    char * line_chararr = const_cast< char *>(line.c_str());
//    tokens = strtok(line_chararr,delim);//line_chararr, " ",next_token);

    char * delim = new char[strlen(" ") +1];
    strcpy(delim, " ");

    char * line_chararr = new char[strlen(line.c_str())+1];
    strcpy(line_chararr, const_cast< char *>(line.c_str()));

//    char * tokens = new char[strlen(line_chararr) +1 ];
//    strcpy(tokens, strtok(line_chararr,delim));

    char * tokens = strtok(line_chararr,delim);

    vectorString vs;

    while (tokens != nullptr) {
        if (!isNumber(tokens)) {
            isString = true;
            temp = temp.append(tokens) + " ";

        } else {

            if (isString) {
                vs.push_back(temp);
                vs.emplace_back(tokens);
                isString = false;
            } else {
                vs.emplace_back(tokens);
            }
        }
        tokens = strtok(nullptr, delim);
    }
    vs.push_back(temp);

    delete[] line_chararr;
    delete[] delim;
    free(tokens);

    return vs;
}

void FileOperations::readMonopolyData() {
    myFile.open(fileName);


    if (myFile.is_open()) {
        for (std::string line; std::getline(myFile, line);) {
               for (int i = 0; i < getLine(line).size(); ++i) {
                   if (getLine(line)[0][0] == '1') {
                       mySquare.push_back(new Properties(stoi(getLine(line)[0]),getLine(line)[1],stof(getLine(line)[2]),stof(getLine(line)[3]),
                                                        stoi(getLine(line)[4])));
                       break;
                   } else if (getLine(line)[0][0] == '3') {
                       mySquare.push_back(new Station(stoi(getLine(line)[0]), getLine(line)[1]));
                       break;
                   } else if (getLine(line)[0][0] == '4') {
                       mySquare.push_back(new BonusSquare(stoi(getLine(line)[0]), getLine(line)[1]));
                       break;
                   } else if (getLine(line)[0][0] == '5') {
                       mySquare.push_back(new PenaltySquare(stoi(getLine(line)[0]), getLine(line)[1]));
                       break;
                   } else if (getLine(line)[0][0] == '6') {
                       mySquare.push_back(new JailSquare(stoi(getLine(line)[0]), getLine(line)[1]));
                       break;
                   } else if (getLine(line)[0][0] == '7') {
                       mySquare.push_back(new GotoJailSquare(stoi(getLine(line)[0]), getLine(line)[1]));
                       break;
                   } else if (getLine(line)[0][0] == '8') {
                       mySquare.push_back(new FreeParking(stoi(getLine(line)[0]), getLine(line)[1]));
                       break;
                   } else {
                       mySquare.push_back(new CSquare(stoi(getLine(line)[0]),getLine(line)[1]));
                       break;
                   }
                }

        }
        myFile.close();
    }
    ///added later
    for (int i = 0; i < mySquare.size(); ++i) {
        position.insert(pair<string,int>(mySquare[i]->getSquareName(),i));
    }
}

const vectorSquare &FileOperations::getMySquare() const {
    return mySquare;
}

void FileOperations::setMySquare(const vectorSquare &mySquare) {
    FileOperations::mySquare = mySquare;
}

const map<string, int> &FileOperations::getPosition() const {
    return position;
}

void FileOperations::setPosition(const map<string, int> &position) {
    FileOperations::position = position;
}

int FileOperations::findPosition(string squareName) {
//    map<string, int> :: iterator it;
//
//    for (it = position.begin(); it != position.end(); it++) {
//        if (it->first == squareName) {
//            return it->second;
//        }
//    }
    for (const auto& it: position) {
        if (it.first == squareName) {
            return it.second;
        }
    }
    return 0;

}

FileOperations::~FileOperations() {
    for (auto i : getMySquare()) {
        delete i;
    }

}


void FileOperations::createValueOrder() {
    for (int i = 0; i < 26; ++i) {
        if (getMySquare()[i]->getSquareType() == 1 || getMySquare()[i]->getSquareType() == 3) {
            orderedMySquare.emplace_back(getMySquare()[i]);
        } else {
            continue;
        }
    }

    sort(orderedMySquare.begin(),orderedMySquare.end(),
         [] (CSquare* a, CSquare* b)
         {return a->getPropertyCost() < b->getPropertyCost();}
         );

}

const vectorSquare &FileOperations::getOrderedMySquare() const {
    return orderedMySquare;
}

float FileOperations::calculateColorGroupCost(float cost, int playerPosition, const string& ownerName) {
    int colorGroup = getMySquare()[playerPosition]->getColorGroup();

    if (getMySquare()[playerPosition + 1]->getColorGroup() == colorGroup
        && getMySquare()[playerPosition + 1]->getPropertyOwner() == ownerName)
    {
        if (getMySquare()[playerPosition + 2]->getSquareType() == 1
            && getMySquare()[playerPosition + 2]->getPropertyOwner() == ownerName
            && getMySquare()[playerPosition + 2]->getColorGroup()  == colorGroup)
        {

            cout << "true" << endl;
            cost = cost * 2;

        } else if (getMySquare()[playerPosition - 1]->getColorGroup() == colorGroup
                   && getMySquare()[playerPosition - 1]->getPropertyOwner() == ownerName)
        {
            cout << "true" << endl;
            cost = cost * 2;
        } else if ((getMySquare()[playerPosition + 2]->getSquareType() != 1)
                   && (getMySquare()[playerPosition - 1]->getSquareType() != 1))
        {
            cout << "true" << endl;
            cost = cost * 2;
        }
    } else if (getMySquare()[playerPosition - 1]->getColorGroup() == colorGroup
               && getMySquare()[playerPosition - 1]->getPropertyOwner() == ownerName)
    {
        if (getMySquare()[playerPosition - 2]->getSquareType() == 1
            && getMySquare()[playerPosition - 2]->getPropertyOwner() == ownerName
            && getMySquare()[playerPosition - 2]->getColorGroup()  == colorGroup)
        {

            cout << "true" << endl;
            cost = cost * 2;

        } else if ((getMySquare()[playerPosition - 2]->getSquareType() != 1)
                   && (getMySquare()[playerPosition + 1]->getSquareType() != 1))
        {
            cout << "true" << endl;
            cost = cost * 2;
        }
    }
    return cost;
}






