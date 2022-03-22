//
// Created by Nadun N. T. Fernando on 2/14/2022.
//

#include "FileOperations.h"
#include "Properties.h"
#include <string>
#include <cstring>
#include <utility>
#include <iostream>

using namespace std;


FileOperations::FileOperations() = default;

FileOperations::FileOperations(string fileName) : fileName(std::move(fileName)) {}

bool FileOperations::isNumber(const string &str) {
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

vector <string> FileOperations::getLine(string line) {
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

    char * tokens = new char[strlen(line_chararr) +1 ];
    strcpy(tokens, strtok(line_chararr,delim));

    vector<string> vs;

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
        tokens = strtok(NULL, delim);
    }
    vs.push_back(temp);

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
                   }else {
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

const vector<CSquare *> &FileOperations::getMySquare() const {
    return mySquare;
}

void FileOperations::setMySquare(const vector<CSquare *> &mySquare) {
    FileOperations::mySquare = mySquare;
}

const map<string, int> &FileOperations::getPosition() const {
    return position;
}

void FileOperations::setPosition(const map<string, int> &position) {
    FileOperations::position = position;
}

int FileOperations::findPosition(string squareName) {
    map<string, int> :: iterator it;

    it = position.find(squareName);

    return it->second;

}




