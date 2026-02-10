#include <iostream>

void addYtoX(long y, long* addressOfX) {
    *addressOfX += y 
}

int main() {
    long x,y;
    std::cin>>x>>y;
    addYtoX(y,&x);
    std::cout<<x<<"\n";
    return 0;
}