// Different types of objects and variables in C++

int count = 42; // int initiates a variable as an integer
double temperature = 21.5; // double initiates a variable as a float
bool done = false; // bool initiates a variable as true or false
char letter = 'A'; // char is characters. 

#include <iostream>

int main() {

    int x;
    std::cout << "Enter a number: "; // << means output, std::cout means to push to screen
    std::cin >> x; // >> means input, std::cin means it asks for an input and assigns it to x???
    std::cout << "You entered: " << x << "\n";.
    return 0;
    }