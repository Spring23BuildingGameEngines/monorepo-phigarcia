// Files that end in the .cpp extension are 'C++' files

// Bring in libraries here
#include <iostream> // input and output 'stream' library
#include <vector>   // std::vector data structure.

// prints the value for each vector
void Print(std::vector<float> vector) {
	for (int i = 0; i < vector.size(); i++) {
		std::cout << "printing vector at " << i << ": " << vector.at(i) << std::endl; 
	}
}

void PrintRaw(float array[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << "printing array at " << i << ": " << array[i] << std::endl; 
	}
}

int main(){

	// cout -----------------------------------------
	std::cout << "hello my name is phi" << std::endl;
	std::cout << std::endl;
	// -----------------------------------------------

	// push back ---------------
	std::vector<float> myVector; 
	myVector.push_back(3.0f);
	myVector.push_back(6.0f);
	myVector.push_back(9.0f);
	// -------------------------
	float array[3] = {2.5f, 5.0f, 7.5f};

	std::cout << "myVector[0]: " << myVector[0] << std::endl;
	std::cout << "myVector[1]: " << myVector[1] << std::endl;
	std::cout << "myVector[2]: " << myVector[2] << std::endl;

	std::cout << std::endl;
	
	// for loop --------------------------------
	for(int i = 0; i < myVector.size(); i++) {
		std::cout << "loop myVector[" << i << "]" << myVector[i] << std::endl;
	}
	// -----------------------------------------
	std::cout << std::endl;

	// auto ------------------------------------
	for(auto& a : myVector) {
		std::cout << a << std::endl;
	}
	// -----------------------------------------

	std::cout << std::endl;

	// my functions ---------------------------
	Print(myVector); 
	std::cout << std::endl;
	PrintRaw(myVector.data(), myVector.size()); 
	// ----------------------------------------

	return 0;
}
