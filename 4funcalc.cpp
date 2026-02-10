#include <iostream>

int main() {

	long num1, num2;
	char op;
	std::cout << "Welcome to the 5 function calculator!" << "\n";
	std::cout << "Insert a basic arithmatic in the form of a + b, a - b, a * b, a / b and a % b: ";
	std::cin>>num1>>op>>num2;
	switch (op){
	
		case '+':
			std::cout <<num1<< " + "<<num2<<" is equal to: "<<num1+num2 << "\n";
			break;
		case '-':
			std::cout <<num1<< " - "<<num2<<" is equal to: "<<num1-num2 << "\n";
			break;
		case '*':
			std::cout <<num1<< " * "<<num2<<" is equal to: "<<num1*num2 << "\n";
			break;
		case '/':
			std::cout <<num1<< "/"<<num2<<" is equal to: "<<num1/num2 << "\n";
			break;
		case '%':
			std::cout <<num1<< " % "<<num2<<" is equal to: "<<num1%num2 << "\n";
			break;
	}
	return 0;
	
}
