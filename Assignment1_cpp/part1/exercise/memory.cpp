// g++ -std=c++17 memory.cpp -o prog
#include <iostream>
#include <vector>


int main(int argc, char** argv){

  uint8_t* chunk = new uint8_t[39];
  uint8_t* item = new uint8_t;

  std::cout << "chunk size: " << sizeof(chunk) << std::endl; 

  delete item;
  delete[] chunk;

  return 0;
}
