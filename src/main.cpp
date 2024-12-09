#include <iostream>
#include "database.h"


int main()
{
    
    int choice;
    bool loop = true;
    while (loop==true)
    {
        std::cout << "Welcome. Please choose one of the options shown bellow (1-4):\n";
        std::cout << "[1.] Add customer.\n";
        std::cout << "[2.] Edit customer.\n";
        std::cout << "[3.] Show all customers.\n";
        std::cout << "[4.] Exit.\n";
        std::cout << "Input: ";
        std::cin >> choice;
        switch(choice)
        {
        case 1:
            std::cout << " option 1\n";
            loop = false;
            break;
        case 2:
            std::cout << " option  2\n";
            loop = false;
            break;
        case 3:
            std::cout << " option  3\n";   
            loop = false;
            break;
        case 4:
            std::cout << " option  4\n";
            loop = false;           
            break;
        default:
            std::cout << "Invalid input, please try again: ";
            std::cin >> choice;
            continue;
        }
    }
    return 0;
}

