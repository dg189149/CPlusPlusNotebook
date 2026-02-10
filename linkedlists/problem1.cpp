/* The user enters integers one by one. Input ends when the user enters -9. 
After entering -9, the user provides one more positive integer, q. 
The program must add q to each of the previously entered integers and print the updated integers in the same order they were received. */

#include <iostream>

void addingIntegers(long* addressofResult) {
    *addressofResult = 0
    while (!(long q  == -9)) {
        std::cin>>q;
        *addressofResult += q;
        std::cout<<"Updated result of sum: " << *addressofResult << "\n";
        std::cin>>q;
    }
    
}

int main() {
    long result;
    addingIntegers(&result);
    return 0;
}