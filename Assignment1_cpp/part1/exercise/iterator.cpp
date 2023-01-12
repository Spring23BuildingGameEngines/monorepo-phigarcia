// Compile with:
// g++ -std=c++17 iterator.cpp -o prog
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
	std::vector<unsigned char> myData;

	for(unsigned int i = 39; i < 70; i++) {
		myData.push_back(i);
	}

	std::vector<unsigned char>::iterator it = myData.begin();
	std::vector<unsigned char>:: iterator end = myData.end();

	for (; it != end; it++) {
		std::cout << *it;
	}

	return 0;
}
