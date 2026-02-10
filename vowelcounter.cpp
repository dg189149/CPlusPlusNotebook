#include <iostream>
#include <string>

int vowelCounter(std::string word){
	int counter = 0;
	for (int i = 0; i < word.size()`; i++) {
		if (word[i] == 'a' or word[i] == 'e' or word[i] == 'i' or word[i] == 'o' or word[i] == 'u' or word[i] == 'A' or word[i] == 'E' or word[i] == 'I' or word[i] == 'O' or word[i] == 'U') {
			counter += 1;
		}
		
	}
	return counter;
}

int main() {
	
	std::cout << vowelCounter("Azerbaijan") << "\n";
	return 0;
}
