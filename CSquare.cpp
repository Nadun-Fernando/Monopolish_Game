//
// Created by Nadun N. T. Fernando on 2/13/2022.
//

#include "CSquare.h"

#include <utility>
CSquare::CSquare() {}

CSquare::CSquare(int squareType, string squareName) : squareType(squareType), squareName(std::move(squareName)) {}

CSquare::~CSquare() {

}

int CSquare::getSquareType() const {
    return squareType;
}

void CSquare::setSquareType(int squareType) {
    CSquare::squareType = squareType;
}

const string &CSquare::getSquareName() const {
    return squareName;
}

void CSquare::setSquareName(const string &squareName) {
    CSquare::squareName = squareName;
}

float CSquare::getPropertyCost() const {
    return 0;
}

float CSquare::getPropertyRent() const {
    return 0;
}

int CSquare::getColorGroup() const {
    return 0;
}

string CSquare::getPropertyOwner() const {
    return {};
}

void CSquare::setPropertyOwner(const string propertyOwner) {

}

int CSquare::getBonusMoney(int rolledNumber) {
    return 0;
}

bool CSquare::isMortgaged() const {
    return false;
}

void CSquare::setMortgaged(bool mortgaged) {

}













