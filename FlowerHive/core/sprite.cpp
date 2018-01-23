//
//  sprite.cpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 15..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#include "sprite.hpp"
#include "action.hpp"

#include <iostream>
#include <algorithm>


SpriteMethod::SpriteMethod(Renderer* renderer, Sprite* sprite)
: _pRenderer(renderer)
, _pSprite(sprite)
{}

SpriteMethod::~SpriteMethod()
{}




#include <SDL2/SDL.h>

SpriteMethodSDL::SpriteMethodSDL(Renderer* renderer, Sprite* sprite)
: SpriteMethod(renderer, sprite)
, _pTexture(nullptr)
{ }

SpriteMethodSDL::SpriteMethodSDL(Renderer* renderer, Sprite* sprite, const char* texture_name)
: SpriteMethod(renderer, sprite)
, _pTexture(nullptr)
{
    setTexture(texture_name);
}

SpriteMethodSDL::~SpriteMethodSDL()
{
    if(_pTexture != nullptr)
        SDL_DestroyTexture(_pTexture);
}

void SpriteMethodSDL::drawTextureWithRect()
{
    if(_pTexture == nullptr)
        return;
    
    Rect rect = _pSprite->getRect();
    SDL_SetRenderTarget(_pRenderer, _pTexture);
    SDL_RenderCopy(_pRenderer, _pTexture, NULL, &rect);
}

bool SpriteMethodSDL::setTexture(const char* texture_name)
{
    SDL_Surface* surface = SDL_LoadBMP(texture_name);
    if(surface == NULL)
    {
        std::cout << "Failed loading BMP file" << std::endl;
        return false;
    }
    
    if(_pTexture != NULL)
        SDL_DestroyTexture(_pTexture);
    
    _pTexture = SDL_CreateTextureFromSurface(_pRenderer, surface);
    if(_pTexture == NULL)
    {
        SDL_FreeSurface(surface);
        std::cout << "Failed creating texture from surface" << std::endl;
        return false;
    }
    
    SDL_FreeSurface(surface);
    return true;
}





Sprite::Sprite(Renderer* renderer)
: _touched(false)
, _rect({0,0,0,0})
, _pLayer(nullptr)
{
    _pMethod = new SpriteMethodSDL(renderer, this);
}


Sprite::Sprite(Renderer* renderer, const char* texture_name)
: _touched(false)
, _rect({0,0,0,0})
, _pLayer(nullptr)
{
    _pMethod = new SpriteMethodSDL(renderer, this, texture_name);
}


Sprite::~Sprite()
{
    delete _pMethod;
    
    for(auto i = 0; i < _pAction_list.size(); i++)
    {
        delete _pAction_list[i];
    }
}


void Sprite::setTouched(bool touched)
{
    _touched = touched;
}

void Sprite::update(float dt)
{
    for(int i = 0; i < _pAction_list.size(); i++)
    {
        _pAction_list[i]->update(dt);
    }
}


void Sprite::setTexture(const char* texture_name)
{
    _pMethod->setTexture(texture_name);
}


void Sprite::setPosition(const Position& position)
{
    _rect.x = position.x;
    _rect.y = position.y;
}

void Sprite::setPosition(int x, int y)
{
    _rect.x = x;
    _rect.y = y;
}

Position Sprite::getPosition() const
{
    return Position(_rect.x, _rect.y);
}

void Sprite::setScale(const Scale& scale)
{
    _rect.w = scale.w;
    _rect.h = scale.h;
}

void Sprite::setScale(int width, int height)
{
    _rect.w = width;
    _rect.h = height;
}

Scale Sprite::getScale() const
{
    return scale(_rect.w, _rect.h);
}

void Sprite::setRect(const Rect& rect)
{
    _rect = rect;
}

void Sprite::setRect(int x, int y, int width, int height)
{
    _rect.x = x;
    _rect.y = y;
    _rect.w = width;
    _rect.h = height;
}

Rect Sprite::getRect() const
{
    return _rect;
}

bool Sprite::isTouched() const
{
    return _touched;
}

void Sprite::addAction(SpriteAction* action)
{
    _pAction_list.push_back(action);
}


void Sprite::setLayer(Layer* layer)
{
    _pLayer = layer;
}



