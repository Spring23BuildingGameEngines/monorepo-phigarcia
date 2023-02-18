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
        //std::cout << "controller update" << std::endl;
        TransformComponent *trans = dynamic_cast<TransformComponent *>(transformComponent.get());
        if (trans == NULL)
        {
            return;
        }

        SDL_Event event;
        // Enable text input
        SDL_StartTextInput();
        // Handle events on queue
        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT:
            case SDLK_a:
                trans->x -= walk_speed;
                break;
            case SDLK_RIGHT:
            case SDLK_d:
                trans->x += walk_speed;
                break;
            }
        }
    };

private:
    static const int walk_speed = 10;
    // int mVelocity;
    std::shared_ptr<Component> transformComponent;
};

#endif
