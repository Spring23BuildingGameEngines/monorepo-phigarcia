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
    // PrettyPrint(std::cout, result);

    // Return false whenever a unit test is failing your
    // expected behavior
    return false;
}

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
// subtract
bool unitTest5()
{
    Vec2D a(1, 2);
    Vec2D b(3, 4);
    Vec2D result = a - b;
    if (result.x == -2 && result.y == -2)
    {
        return true;
    }
    return false;
}

// normalize
bool unitTest6()
{
    Vec2D a(3, 4);
    Vec2D result = Normalize(a);
    if (result.x == (.6f) && result.y == (.8f))
    {
        return true;
    }
    return false;
}
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
// dot product
bool unitTest9()
{
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
    Vec2D a(-1, 5);
    Vec2D b(2, 4);
    Vec2D result = Project(a, b);
    if (result.x == 1.8f && result.y == 3.6f)
    {
        return true;
    }
    return false;
}
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

// cross product
bool unitTest12()
{
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
    Vec2D a(3, 2);
    Matrix3D M(1, 2, 6,
               0, 1, 5,
               0, 0, 1);
    Vec2D result = M * a;

    if (result.x = 13 && result.y == 7 && result.w == 0)
    {
        return true;
    }
    return false;
}

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
