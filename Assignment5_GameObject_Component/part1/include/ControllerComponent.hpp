#ifndef CONTROLLERCOMPONENT_HPP
#define CONTROLLERCOMPONENT_HPP
#include <iostream>
#include "GameObject.hpp"
#include "TransformComponent.hpp"

class ControllerComponent : public Component
{
public:
    ControllerComponent(std::shared_ptr<Component> transComp)
    {
        transformComponent = transComp;
    };
    ~ControllerComponent(){};

     void Update(int frame) override
    {
        std::cout << "controller update" << std::endl;
        TransformComponent *trans = dynamic_cast<TransformComponent *>(transformComponent.get());
        if (trans == NULL)
        {
            return;
        }

        SDL_Event event; 
        while (SDL_PollEvent(&event))
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT:
            case SDLK_a:
                mVelocity -= walk_accel;
                break;
            case SDLK_RIGHT:
            case SDLK_d:
                mVelocity += walk_accel;
                break;
            }
        }

        trans->x += mVelocity;
    };

private:
    static const int walk_accel = 1;
    int mVelocity = 0;
    std::shared_ptr<Component> transformComponent;
};

#endif
