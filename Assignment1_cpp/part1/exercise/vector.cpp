// g++ -std=c++17 vector.cpp -o prog
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  std::vector<unsigned char> myData;

  for(unsigned int i = 39; i < 70; ++i) { // when should we use unsigned ints?
    myData.push_back(i);
  }

  for(unsigned int i = 0; i < myData.size(); ++i) {
    std::cout << myData[i];
  }

  return 0;
}