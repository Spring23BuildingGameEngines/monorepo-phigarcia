// Compile with:
// g++ -std=c++17 pointers.cpp -o prog
#include <iostream>

int main(int argc, char** argv){

  int *px = nullptr;
  int x = 99;
  px = &x;

  std::cout << "px deref: " << *px << std::endl;

	return 0;
}