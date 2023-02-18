#ifndef COMPONENT_HPP 
#define COMPONENT_HPP

#if defined(LINUX) || defined(MINGW)
    #include <SDL2/SDL.h>
#else // This works for Mac
    #include <SDL.h>
#endif


class Component{
    public:
        Component();
        virtual ~Component();
        virtual void Update(int frame) {};
        virtual void Render(SDL_Renderer* ren) {}; 

    private:

};


#endif
