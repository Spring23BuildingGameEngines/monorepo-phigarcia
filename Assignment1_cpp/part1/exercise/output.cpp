// g++ -std=c++17 input.cpp -o prog
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
  std::ofstream outFile;

  outFile.open("cats.txt");
    
  outFile << "kaomoji cats!" << std::endl;
  outFile << "(=^･ω･^=)" << std::endl;
  outFile << "(˵Φ ω Φ˵)" << std::endl;
  outFile << " /ᐠ ._. ᐟ\\" << std::endl;

  outFile.close();

  std::cout << "check your files :3" << std::endl;

  return 0;
}