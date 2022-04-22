#include <iostream>
#include <memory>
#include <cstdlib>


#include "Monopoly.h"

using namespace std;

int main() {
//    HWND console = GetConsoleWindow();
//    RECT ConsoleRect;
//    GetWindowRect(console, &ConsoleRect);
//
//    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1980, 1080, TRUE);

//    UserInterface ui;
//    ui.displayBoard();
    unique_ptr<Monopoly> monopoly(make_unique<Monopoly>());
    monopoly->playGame();


    system("pause");

    return 0;
}
