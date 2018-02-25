//
//  layer.cpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 22..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#include "layer.hpp"


LayerMethod::LayerMethod()
{
    
}

LayerMethod::~LayerMethod()
{
    
}



#include <SDL2/SDL.h>


LayerMethodSDL::LayerMethodSDL()
{
    
}

LayerMethodSDL::~LayerMethodSDL()
{
    
}

void LayerMethodSDL::drawBackground(Renderer* renderer, const Frame& frame)
{
    SDL_Rect rect = {frame.position.x, frame.position.y, frame.scale.width, frame.scale.height};
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 1);
    SDL_RenderFillRect(renderer, &rect);
}





////////////////////////////////////////////


#include "methodfactory.hpp"
#include "sprite.hpp"


Layer::Layer()
{
    _pMethod = MethodFactory::getInstance()->createLayerMethod();
}

Layer::~Layer()
{
    
}


void Layer::update(float dt)
{
    for(int i = 0; i < _pSprite_list.size(); i++)
    {
        _pSprite_list[i]->update(dt);
    }

}

void Layer::render(Renderer* renderer)
{
    
    //차후 서브뷰에 대한 드로잉 수행할 것
    for(int i = 0; i < _pSprite_list.size(); i++)
    {
        _pSprite_list[i]->render(renderer);
    }
}

void Layer::touched(const Touch& touch)
{
    
}




void Layer::drawBackground(Renderer* renderer)
{
    _pMethod->drawBackground(renderer, _frame.getAnchoredFrame());
}


void Layer::addSprite(Sprite* sprite)
{
    _pSprite_list.push_back(sprite);
}

void Layer::addSubLayer(Layer* layer)
{
    _pSublayer_list.push_back(layer);
}


void Layer::setPosition(const Position& position)
{
    _frame.position.x = position.x;
    _frame.position.y = position.y;
}

void Layer::setPosition(int x, int y)
{
    _frame.position = {x, y};
}

Position Layer::getPosition() const
{
    return _frame.position;
}

void Layer::setScale(const Scale& scale)
{
    _frame.scale.width = scale.width;
    _frame.scale.height = scale.height;
}

void Layer::setScale(int width, int height)
{
    _frame.scale = {width, height};
}

Scale Layer::getScale() const
{
    return _frame.scale;
}

void Layer::setFrame(const Frame& frame)
{
    _frame = frame;
}


void Layer::setFrame(int x, int y, int width, int height)
{
    _frame.position.x = x;
    _frame.position.y = y;
    _frame.scale.width = width;
    _frame.scale.height = height;
}

Frame Layer::getFrame() const
{
    return _frame;
}


void Layer::setAnchorPoint(float x, float y)
{
    _frame.anchor_point.x = x;
    _frame.anchor_point.y = y;
}

AnchorPoint Layer::getAnchorPoint() const
{
    return _frame.anchor_point;
}









