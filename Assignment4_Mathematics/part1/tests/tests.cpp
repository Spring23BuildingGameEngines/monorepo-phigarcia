// Add your unit tests somewhere in this file
// Provide sufficient 'coverage' of funtions you have implemented.
#include "TinyMath.hpp"
#include <iostream>

// Add a 1-vector with a 0-vector.
bool unitTest1(){
    Vec2D a(1,1);
    Vec2D b(0,0);
    Vec2D result = a + b;


    if(result.x == 1 && result.y == 1){
        return true;
    }
    // You generally should not be printing out the
    // results here, I'm just showing this function here
    // to help you if you need to debug your vectors.
    PrettyPrint(std::cout, result);

    // Return false whenever a unit test is failing your
    // expected behavior
    return false;
}

// TODO
bool unitTest2(){
    return false;
}
// TODO
bool unitTest3(){
    return false;
}
// TODO
bool unitTest4(){
    return false;
}
// TODO
bool unitTest5(){
    return false;
}
// TODO
bool unitTest6(){
    return false;
}
// TODO
bool unitTest7(){
    return false;
}
// TODO
bool unitTest8(){
    return false;
}
// TODO
bool unitTest9(){
    return false;
}
// TODO
bool unitTest10(){
    return false;
}
// TODO
bool unitTest11(){
    return false;
}
// TODO
bool unitTest12(){
    return false;
}


// TODO: Add more tests here at your discretion
bool (*unitTests[])(void)={
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    unitTest7,
    unitTest8,
    unitTest9,
    unitTest10,
    unitTest11,
    unitTest12,	
    nullptr
};


// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter =0;

    // Iterate through the array of unitTest functions until the
    // nullptr is found indicating the end of the unitTest array.
    while( unitTests[counter] != nullptr ){
        std::cout << "========unitTest " << counter << "========\n";

        if( true == unitTests[counter]() ){
            std::cout << "passed test\n";
            testsPassed++;	
        }else{
            std::cout << "failed test, missing functionality, or incorrect test\n";
        }

        ++counter;
    }

    std::cout << "\n\n" << testsPassed << " of " << counter << " tests passed\n";

    return 0;
}
