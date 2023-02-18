#include "Sprite.hpp"

SpriteComponent::~SpriteComponent(){
// TODO: Make sure spritesheet and mTexture are destroyed
// but is this the right place?
    SDL_FreeSurface(mSpriteSheet);
    mSpriteSheet = nullptr;
    SDL_DestroyTexture(mTexture);
}


void SpriteComponent::LoadImage(std::string filePath, SDL_Renderer* ren){
    mSpriteSheet = SDL_LoadBMP(filePath.c_str());
    if(nullptr == mSpriteSheet){
           SDL_Log("Failed to allocate surface");
    }else{
        SDL_Log("Allocated a bunch of memory to create identical game character");
        // Create a texture from our surface
        // Textures run faster and take advantage 
        // of hardware acceleration
        mTexture = SDL_CreateTextureFromSurface(ren, mSpriteSheet);
    }
}
