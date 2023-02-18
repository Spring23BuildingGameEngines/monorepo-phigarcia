#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <vector>
#include <memory>

#include "Component.hpp"
#include "IGraphicsEngineRenderer.hpp"


class GameObject
{
public:
    int velocity;
    int x, y;

    GameObject();
    ~GameObject();

    void AddComponent(std::shared_ptr<Component> c)
    {
        m_components.push_back(c);
    };

    void RemoveComponent(int index){
        // TODO   m_components.erase(index);
    };

    // TODO dont make this public
    std::vector<std::shared_ptr<Component>> m_components;

    // Note: You may want to add member functions like 'Update' or 'Render'
    // Note: You may want to add member functions like "AddComponent" or "RemoveComponent"

private:
};

#endif
