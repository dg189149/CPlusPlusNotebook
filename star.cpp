#include <iostream>


int main() {
    int n = 10; // Example from the problem
    int i;
    int r = i % (n / 2);

    for (int j = 0; j < n; ++j) {

        if (r == 0) {
            std::cout << "*";
        }
        else {
            if (j == r || j == n - r - 1) {
                std::cout << "*";
            }
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}