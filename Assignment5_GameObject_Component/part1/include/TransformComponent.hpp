#ifndef TRANSFORMCOMPONENT_HPP
#define TRANSFORMCOMPONENT_HPP

#include "Component.hpp"

class TransformComponent : public Component
{
public:
    TransformComponent(int x, int y) : x(x), y(y){};

    TransformComponent()
    {
        x = 0;
        y = 0;
    };

    ~TransformComponent(){};

    int x, y;

private:
};

#endif
