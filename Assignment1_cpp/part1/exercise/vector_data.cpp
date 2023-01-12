// g++ -std=c++17 vector_data.cpp -o prog
#include <iostream>
#include <vector>

int main(int argc, char** argv) {

  std::vector<int> myData;

  for (int i = 0; i < 39; i++) {
    myData.push_back(i);
  }

  int* interalArray = myData.data();
  for (int i= 0; i < myData.size(); i++) {
    std::cout << interalArray[i] << std::endl;
  }

    return 0;
}
