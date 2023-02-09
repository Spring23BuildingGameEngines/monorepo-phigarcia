// Add your unit tests somewhere in this file
// Provide sufficient 'coverage' of funtions you have implemented.
#include "TinyMath.hpp"
#include <iostream>

// Add a 1-vector with a 0-vector.
bool unitTest1()
{
    Vec2D a(1, 1);
    Vec2D b(0, 0);
    Vec2D result = a + b;

    if (result.x == 1 && result.y == 1)
    {
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
// multiply
bool unitTest2()
{
    Vec2D a(1, 2);
    Vec2D result = a * 2;
    if (result.x == 2 && result.y == 4)
    {
        return true;
    }
    return false;
}
// TODO
// divide
bool unitTest3()
{
    Vec2D a(1, 2);
    Vec2D result = a / 2;
    if (result.x == .5f && result.y == 1)
    {
        return true;
    }
    return false;
}
// TODO
// add
bool unitTest4()
{
    Vec2D a(1, 2);
    Vec2D b(3, 4);
    Vec2D result = a + b;
    if (result.x == 4 && result.y == 6)
    {
        return true;
    }
    return false;
}
// TODO
// subtract
bool unitTest5()
{
    std::cout << "Subtract: " << std::endl;
    Vec2D a(1, 2);
    Vec2D b(3, 4);
    Vec2D result = a - b;
    if (result.x == -2 && result.y == -2)
    {
        return true;
    }
    return false;
}
// TODO
// normalize
bool unitTest6()
{
    Vec2D a(3, 4);
    Vec2D result = Normalize(a);
    std::cout << result.x << ", " << result.y << std::endl;
    if (result.x == (.6f) && result.y == (.8f))
    {
        return true;
    }
    return false;
}
// TODO
// magnitude
bool unitTest7()
{
    Vec2D a(3, 4);
    float result = Magnitude(a);
    if (result == 5)
    {
        return true;
    }
    return false;
}
// TODO
// 3x3 by 3x3
bool unitTest8()
{
    Matrix3D a(0, 1, 2,
               3, 4, 5,
               6, 7, 8);
    Matrix3D b(1, 1, 1,
               1, 1, 1,
               1, 1, 1);
    Matrix3D result = a * b;

    if (result(0, 0) == 9 && result(0, 1) == 12 && result(0, 2) == 15 &&
        result(1, 0) == 9 && result(1, 1) == 12 && result(1, 2) == 15 &&
        result(2, 0) == 9 && result(2, 1) == 12 && result(2, 2) == 15)
    {
        return true;
    }
    return false;
}
// TODO
// dot product
bool unitTest9()
{
    std::cout << "dot: " << std::endl;
    Vec2D a(4, 5);
    Vec2D b(-5, 2);
    float result = Dot(a, b);
    if (result == -10)
    {
        return true;
    }
    return false;
}
// TODO
// project
bool unitTest10()
{
    std::cout << "Project: " << std::endl;
    Vec2D a(-1, 5);
    Vec2D b(2, 4);
    Vec2D result = Project(a, b);
    std::cout << result.x << ", " << result.y << std::endl;
    if (result.x == 1.8f && result.y == 3.6f)
    {
        return true;
    }
    return false;
}
// TODO
// negation
bool unitTest11()
{
    Vec2D a(1, -2);
    Vec2D result = -a;
    if (result.x == -1 && result.y == 2)
    {
        return true;
    }
    return false;
}
// TODO
// cross product
bool unitTest12()
{
    std::cout << "Cross Product: " << std::endl;
    Vec2D a(5, 5);
    Vec2D b(3, 2);
    float result = CrossProduct(a, b);
    if (result == -5)
    {
        return true;
    }
    return false;
}

// matrix x vector
bool unitTest13()
{
    std::cout << "Matrix x Vector : " << std::endl;
    Vec2D a(3, 2);
    Matrix3D M(1, 0, 6,
               0, 1, 5,
               0, 0, 1);
    Vec2D result = M * a;
        std::cout << result.x << ", " << result.y << std::endl;

    if (result.x = 9 && result.y == 7)
    {
        return true;
    }
    return false;
}

// TODO: Add more tests here at your discretion
bool (*unitTests[])(void) = {
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
    unitTest13,
    nullptr};

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(int argv, char *args[])
{
    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter = 0;

    // Iterate through the array of unitTest functions until the
    // nullptr is found indicating the end of the unitTest array.
    while (unitTests[counter] != nullptr)
    {
        std::cout << "========unitTest " << counter << "========\n";

        if (true == unitTests[counter]())
        {
            std::cout << "passed test\n";
            testsPassed++;
        }
        else
        {
            std::cout << "failed test, missing functionality, or incorrect test\n";
        }

        ++counter;
    }

    std::cout << "\n\n"
              << testsPassed << " of " << counter << " tests passed\n";

    return 0;
}
