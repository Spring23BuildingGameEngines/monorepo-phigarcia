// g++ -std=c++17 vector2.cpp -o prog
#include <iostream>
#include <vector>

int main(int argc, char** argv){

  std::vector<unsigned char> myVector;

  for(unsigned int i = 0; i < 15; i++) {
    myVector.push_back(i); 
  }

  std::cout << "number of elements: " << myVector.size() << std::endl;
  std::cout << "size of structure: " << sizeof(myVector) <<std::endl;
  std::cout << "size of myVector raw data: " << sizeof(myVector.data()) << std::endl;

  int rawArray[39];
  std::cout << "locally allocated size of raw array: " << sizeof(rawArray) <<std::endl; 

  int* heapArray = new int[25];
  std::cout << "heap allocated array size of: " << sizeof(heapArray) << std::endl;
  delete[] heapArray;

  return 0;
}
