#include <iostream>
#include <memory>
#include <cstdlib>


#include "Monopoly.h"

using namespace std;

int main() {
    /*this code is to maximize the command line windows size but I didn't put it because it generates a handled leak*/
//    HWND console = GetConsoleWindow();
//    RECT ConsoleRect;
//    GetWindowRect(console, &ConsoleRect);
//
//    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1980, 1080, TRUE);

    unique_ptr<Monopoly> monopoly(make_unique<Monopoly>());
    monopoly->playGame();


    system("pause");

    return 0;
}
