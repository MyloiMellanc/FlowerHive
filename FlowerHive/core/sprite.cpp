//
//  sprite.cpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 15..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#include "sprite.hpp"
#include "action.hpp"
#include "methodfactory.hpp"

#include <iostream>
#include <algorithm>


SpriteMethod::SpriteMethod()
{}

SpriteMethod::~SpriteMethod()
{}




#include <SDL2/SDL.h>

SpriteMethodSDL::SpriteMethodSDL()
: _pTexture(nullptr)
{ }

SpriteMethodSDL::SpriteMethodSDL(Renderer* renderer, const char* texture_name)
: _pTexture(nullptr)
{
    if(setTexture(renderer, texture_name) == false)
        std::cout << "Set Texture failed" << std::endl;
}

SpriteMethodSDL::~SpriteMethodSDL()
{
    if(_pTexture != nullptr)
        SDL_DestroyTexture(_pTexture);
}

void SpriteMethodSDL::drawTextureWithFrame(Renderer* renderer, const Frame& frame)
{
    SDL_Rect rect = {frame.position.x, frame.position.y, frame.scale.width, frame.scale.height};
    SDL_SetRenderTarget(renderer, _pTexture);
    SDL_RenderCopy(renderer, _pTexture, NULL, &rect);
}

bool SpriteMethodSDL::setTexture(Renderer* renderer, const char* texture_name)
{
    SDL_Surface* surface = SDL_LoadBMP(texture_name);
    if(surface == NULL)
    {
        std::cout << "Failed loading BMP file" << std::endl;
        return false;
    }
    
    if(_pTexture != NULL)
        SDL_DestroyTexture(_pTexture);
    
    _pTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if(_pTexture == NULL)
    {
        SDL_FreeSurface(surface);
        std::cout << "Failed creating texture from surface" << std::endl;
        return false;
    }
    
    SDL_FreeSurface(surface);
    return true;
}





Sprite::Sprite()
: _touched(false)
, _pLayer(nullptr)
{
    _pMethod = MethodFactory::getInstance()->createSpriteMethod();
}


Sprite::Sprite(Renderer* renderer, const char* texture_name)
: _touched(false)
, _pLayer(nullptr)
{
    _pMethod = MethodFactory::getInstance()->createSpriteMethod(renderer, texture_name);
}


Sprite::~Sprite()
{
    delete _pMethod;
    
    for(auto i = 0; i < _pAction_list.size(); i++)
    {
        delete _pAction_list[i];
    }
}

void Sprite::drawTextureWithFrame(Renderer* renderer)
{
    _pMethod->drawTextureWithFrame(renderer, _frame.getAnchoredFrame());
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

void Sprite::render(Renderer* renderer)
{
    drawTextureWithFrame(renderer);
}


void Sprite::setTexture(Renderer* renderer, const char* texture_name)
{
    _pMethod->setTexture(renderer, texture_name);
}


void Sprite::setPosition(const Position& position)
{
    _frame.position.x = position.x;
    _frame.position.y = position.y;
}

void Sprite::setPosition(int x, int y)
{
    _frame.position.x = x;
    _frame.position.y = y;
}

Position Sprite::getPosition() const
{
    return _frame.position;
}

void Sprite::setScale(const Scale& scale)
{
    _frame.scale.width = scale.width;
    _frame.scale.height = scale.height;
}

void Sprite::setScale(int width, int height)
{
    _frame.scale.width = width;
    _frame.scale.height = height;
}

Scale Sprite::getScale() const
{
    return _frame.scale;
}

void Sprite::setFrame(const Frame& frame)
{
    _frame = frame;
}

void Sprite::setFrame(int x, int y, int width, int height)
{
    _frame.position.x = x;
    _frame.position.y = y;
    _frame.scale.width = width;
    _frame.scale.height = height;
}

Frame Sprite::getFrame() const
{
    return _frame;
}


void Sprite::setAnchorPoint(float x, float y)
{
    _frame.anchor_point.x = x;
    _frame.anchor_point.y = y;
}

AnchorPoint Sprite::getAnchorPoint() const
{
    return _frame.anchor_point;
}


bool Sprite::isTouched() const
{
    return _touched;
}

void Sprite::addAction(SpriteAction* action)
{
    _pAction_list.push_back(action);
    action->setSprite(this);
}


void Sprite::setLayer(Layer* layer)
{
    _pLayer = layer;
}



