#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else // This works for Mac
#include <SDL.h>
#endif

// I recommend a map for filling in the resource manager
#include <unordered_map>
#include <string>

class ResourceManager
{
public:
    static ResourceManager &GetInstance();
    static SDL_Surface *GetResource(std::string &image_filename);
    SDL_Surface *GetResourceInternal(std::string &image_filename); 
    void LoadResource(std::string &image_filename);
    // 'equivalent' to our constructor
    int StartUp();
    // 'equivalent' to our destructor
    int ShutDown(); // call freesurface todo

private:
    ResourceManager() {}
    ResourceManager(ResourceManager const &); // Avoid copy constructor
    void operator=(ResourceManager const &);
    // destructor, in theory never called
    ~ResourceManager();

    std::unordered_map<std::string, SDL_Surface *> spriteMap;
};

#endif
