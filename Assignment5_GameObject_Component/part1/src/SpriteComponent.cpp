#include "SpriteComponent.hpp"

SpriteComponent::~SpriteComponent()
{
    // SDL_FreeSurface(mSpriteSheet);
    // mSpriteSheet = nullptr;
    // SDL_DestroyTexture(mTexture);
    printf("Sprite component destuctor ran \n");

}

void SpriteComponent::LoadImage(std::string filePath, SDL_Renderer *ren)
{
    mSpriteSheet = SDL_LoadBMP(filePath.c_str());
    if (mSpriteSheet == NULL)
    {
        // error print
        SDL_Log("Failed to allocate surface");
        printf("Sprite LoadImage failure SDL Error: %s\n", SDL_GetError());
        return;
    }

    mTexture = SDL_CreateTextureFromSurface(ren, mSpriteSheet);

    if (mTexture == NULL)
    {
        // error print
        printf("Sprite texture SDL Error: %s\n", SDL_GetError());
        return;
    }
}
