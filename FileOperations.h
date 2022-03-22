//
// Created by Nadun N. T. Fernando on 2/14/2022.
//

#ifndef CO2402ASSIGNMENT_FILEOPERATIONS_H
#define CO2402ASSIGNMENT_FILEOPERATIONS_H

#include <fstream>
#include <vector>
#include <map>

#include "CSquare.h"
#include "Properties.h"

using namespace std;

class FileOperations {
private:
    string fileName;
    ifstream myFile;
    //CSquare* mySquare[26];
    vector<CSquare *> mySquare;
    map<int, string> position;
    static bool isNumber(const string& str);
    static vector<string> getLine(string line);
public:
    FileOperations();
    explicit FileOperations(string fileName);
    void readMonopolyData();

    const vector<CSquare *> &getMySquare() const;

    void setMySquare(const vector<CSquare *> &mySquare);

    const map<int, string> &getPosition() const;

    void setPosition(const map<int, string> &position);



};


#endif //CO2402ASSIGNMENT_FILEOPERATIONS_H
