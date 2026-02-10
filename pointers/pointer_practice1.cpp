#include <iostream>

void addYtoX(long y, long* addressOfX) {
<<<<<<< Updated upstream
    *addressOfX += y; 
=======
    *addressOfX += y;
>>>>>>> Stashed changes
}

int main() {
    long x,y;
    std::cin>>x>>y;
    addYtoX(y,&x);
    std::cout<<x<<"\n";
    return 0;
}
