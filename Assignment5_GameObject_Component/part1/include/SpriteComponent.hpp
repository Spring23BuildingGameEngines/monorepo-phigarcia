#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <string>
#include <memory>
#include <iostream>
#include "IGraphicsEngineRenderer.hpp"
#include "TinyMath.hpp"
#include "Component.hpp"
#include "TransformComponent.hpp"
/**
 * A small class to demonstrate loading sprites.
 * Sprite sheets are often used for loading characters,
 * environments, icons, or other images in a game.
 */
class SpriteComponent : public Component
{
public:
    /**
     * Constructor
     */
    SpriteComponent(std::shared_ptr<Component> transComp)
    {
        transformComponent = transComp;
    }; /**
        * Constructor
        */
    ~SpriteComponent();

    /**
     * Update the sprites position and frame
     */
    void Update(int frame) override
    {
        //std::cout << "sprite update" << std::endl;

        TransformComponent *trans = dynamic_cast<TransformComponent *>(transformComponent.get());
        if (trans == NULL)
        {
            return;
        }
        // The part of the image that we want to render
        mCurrentFrame = frame % 6;

        // Here I am selecting which frame I want to draw
        // from our sprite sheet. Think of this as just
        // using a mouse to draw a rectangle around the
        // sprite that we want to draw.
        mSrc.x = mCurrentFrame * 75;
        mSrc.y = 0;
        mSrc.w = 75;
        mSrc.h = 87;

        // Where we want the rectangle to be rendered at.
        // This is an actual 'quad' that will draw our
        // source image on top of.
        mDest.x = trans->x;
        mDest.y = trans->y;
        mDest.w = 128;
        mDest.h = 128;

        // printf("x: %d\n", mDest.x);
        // printf("y: %d\n", mDest.y);
    };
    /**
     * Render the sprite
     */
    void Render(SDL_Renderer *ren) override
    {
        // std::cout << "sprite render" << std::endl;
        SDL_RenderCopy(ren, mTexture, &mSrc, &mDest);
        //printf("Sprite Render SDL Error: %s\n", SDL_GetError());
    };
    /**
     * Load a sprite
     */
    void LoadImage(std::string filePath, SDL_Renderer *ren);

private:
    std::shared_ptr<Component> transformComponent;

    Vec2D mPosition;
    unsigned int mCurrentFrame{0};
    unsigned int mLastFrame{7};
    // An SDL Surface contains pixel data to draw an image
    SDL_Surface *mSpriteSheet = nullptr;
    SDL_Texture *mTexture = nullptr;

    SDL_Rect mSrc;
    SDL_Rect mDest;
};

#endif
