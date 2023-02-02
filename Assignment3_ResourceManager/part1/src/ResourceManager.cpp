// I recommend an unordered_map for filling in the resource manager
#include "ResourceManager.hpp"
#include <iterator>
#include <iostream>
#include <string>

ResourceManager::~ResourceManager()
{
}

// TODO: YUCK! Fix this common resource consumption error.
//       You should use some data structure (e.g. a Map or unordered_map
//       to first search if this resource has been loaded, and then
//       only call SDL_LoadBMP if that resource does not previously exist.
void ResourceManager::LoadResource(std::string &image_filename)
{
    std::unordered_map<std::string, SDL_Surface *>::const_iterator it = spriteMap.find(image_filename);

    if (it == spriteMap.end())
    {
        SDL_Surface *surface = SDL_LoadBMP(image_filename.c_str());
        spriteMap.emplace(std::string(image_filename), surface);
    }
    else
    {
        SDL_Log("%s is already loaded", image_filename.c_str());
    }
}

SDL_Surface *ResourceManager::GetResourceInternal(std::string &image_filename)
{
    LoadResource(image_filename);
    SDL_Log("Retrieved saved copy of %s from GetResourceInternal", image_filename.c_str());
    std::unordered_map<std::string, SDL_Surface *>::const_iterator it = spriteMap.find(image_filename);
    return it->second;
}

SDL_Surface *ResourceManager::GetResource(std::string &image_filename)
{
    return GetInstance().GetResourceInternal(image_filename);
}

ResourceManager &ResourceManager::GetInstance()
{
    static ResourceManager instance;
    return instance;
}

int ResourceManager::ShutDown()
{
    for (auto it = spriteMap.begin(); it != spriteMap.end(); it++)
    {
        SDL_FreeSurface(it->second);
    }
    //todo potentially add an error
    return 0;
}