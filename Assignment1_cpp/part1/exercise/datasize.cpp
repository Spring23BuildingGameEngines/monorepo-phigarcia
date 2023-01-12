// g++ -std=c++17 datasize.cpp -o prog
#include <iostream>

int main() {
	std::cout << "int in bytes: " << sizeof(int) << std::endl;
	std::cout << "short in bytes: " << sizeof(short) << std::endl;
  std::cout << "long in bytes: " << sizeof(long) << std::endl;
	std::cout << "char in bytes: " << sizeof(char) << std::endl;
	std::cout << "uint8_t in bytes: " << sizeof(uint8_t) << std::endl;
	
	std::cout << "float in bytes: " << sizeof(float) << std::endl;
	std::cout << "double in bytes: " << sizeof(double) << std::endl;

	return 0;
}