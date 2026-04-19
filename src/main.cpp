#include "GameWindow.h"
#include <iostream>

int main() {
    try {
        std::cout << "MAIN START\n";
        GameWindow gameWindow;
        gameWindow.Run();
    }
    catch (const std::exception& e) {
        std::cout << "EXCEPTION: " << e.what() << "\n";
    }
}