// g++ -std=c++17 io.cpp -o prog
#include <iostream>

int main() {
	std::cout << "hi there!" << std::endl;
	std::cout << "what is your favorite color?" << std::endl;
	
	std::string color;
	
	std::cin >> color;
	std::cout << "you like " << color <<"? me too!" << std::endl;

	return 0;
}
