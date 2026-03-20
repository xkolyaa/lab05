#include <iostream>
#include <string>
// Program for demonstrating personalized "Hello World".
// Refactored: removed using namespace std for better code clarity.
int main()
{    std::string name;  // Variable to store user's name
    // Prompt user for their name
    std::cout << "Enter your name: ";
    std::cin >> name;   // Read the input
    // Display personalized greeting
    std::cout << "Hello world from " << name << std::endl;
        return 0;  // Program executed successfully}
