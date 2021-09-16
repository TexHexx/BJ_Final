#include "Game.h"
#include <iostream>

int main()
{
    std::cout << "Lets play a BJ game!" << std::endl;
    char answer = 'y';
    while (answer == 'y')
    {
        int users_amount;
        std::cout << "Enter amount of players: ";
        std::cin >> users_amount;
        std::vector<std::string> names(users_amount);
        for (int i = 0; i < users_amount; ++i) {
            std::cout << "Enter player " << (i+1) << " name: ";
            std::cin >> names[i];
        };
        Game game(names);
        game.play();
        while (true) {
            std::cout << "Do you want to play again?(y/n): ";
            std::cin >> answer;
            if ((answer == 'y') || (answer == 'n')) {
                if (answer == 'y') {
                    std::cout << "One more game, great!" << std::endl;
                }
                else {
                    std::cout << "See you..." << std::endl;
                };
                break;
            }
            else {
                std::cout << "Unrecognised answer, try again" << std::endl;
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
            };
        };        
    }
}