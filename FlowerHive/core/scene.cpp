//
//  scene.cpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 22..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#include "scene.hpp"
#include "layer.hpp"

Scene::Scene(Renderer* renderer)
: _pRenderer(renderer)
{
    
}


Scene::Scene(Renderer* renderer, Layer* layer)
: _pRenderer(renderer)
, _pLayer(layer)
{
    
}


void Scene::update(float dt)
{
    _pLayer->update(dt);
}


#include <SDL2/SDL.h>
void Scene::render()
{
    SDL_SetRenderDrawColor(_pRenderer, 255, 0, 0, 1);
    SDL_RenderClear(_pRenderer);
    _pLayer->render(_pRenderer);
    SDL_RenderPresent(_pRenderer);
}

void Scene::touched(const Touch& touch)
{
    _pLayer->touched(touch);
}





Renderer* Scene::getRenderer()
{
    return _pRenderer;
}

void Scene::setLayer(Layer* layer)
{
    _pLayer = layer;
}
