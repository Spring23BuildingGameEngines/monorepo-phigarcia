// g++ -std=c++17 string.cpp -o prog
#include <iostream>
#include <string>

int main() {
  std::string fullName = "phi garcia";
  std::string firstName = fullName.substr(0,3);
  std::string lastName = fullName.substr(4,9);

  std::cout << "first name: " << firstName << std::endl;
  std::cout << "last name: " << lastName << std::endl;

  unsigned int i = 0;
  
  while(i < fullName.length()){
    if(fullName.at(i)==' '){
      break;
    }

    std::cout << fullName[i];
    ++i;
  }

    return 0;
}