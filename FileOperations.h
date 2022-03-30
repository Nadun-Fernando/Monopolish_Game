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
#include "Station.h"

using namespace std;

typedef vector<CSquare *> vectorSquare;
typedef vector<string> vectorString;

class FileOperations {
private:
    string fileName;
    ifstream myFile;
    //CSquare* mySquare[26];
//    vector<CSquare *> mySquare;
    vectorSquare mySquare;
    map<string, int> position;
    static bool isNumber(const string& str);
    static vectorString getLine(string line);
public:
    FileOperations();

    virtual ~FileOperations();

    explicit FileOperations(string fileName);
    void readMonopolyData();

    const vectorSquare &getMySquare() const;

    void setMySquare(const vectorSquare &mySquare);

    const map<string, int> &getPosition() const;

    void setPosition(const map<string, int> &position);

    int findPosition(string squareName);

};


#endif //CO2402ASSIGNMENT_FILEOPERATIONS_H
