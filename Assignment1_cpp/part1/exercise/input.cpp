// g++ -std=c++17 input.cpp -o prog
#include <iostream>
#include <fstream>
#include <string> // new library!

int main(int argc, char** argv) {
  std::ifstream inFile;

  if (argc != 2) { 
      std::cout << "Please specify exactly two arguments." << std::endl;
      return 0;
  }

  inFile.open(argv[1]);
    
  if(inFile.is_open()) {
    std::string line;  

    while(getline(inFile,line)) {
      std::cout << line << std::endl;
    }
  }
    
  inFile.close();

  return 0;
}
