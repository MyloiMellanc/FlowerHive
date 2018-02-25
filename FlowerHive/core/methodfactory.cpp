//
//  methodfactory.cpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 2. 1..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#include "methodfactory.hpp"

#include "director.hpp"
#include "layer.hpp"
#include "sprite.hpp"


#include <SDL2/SDL.h>


MethodFactory* MethodFactory::_pInstance = nullptr;


MethodFactory* MethodFactory::getInstance()
{
    if(_pInstance == nullptr)
    {
        _pInstance = new MethodFactorySDL();
    }
    
    return _pInstance;
}




bool MethodFactorySDL::init()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        return false;
    
    return true;
}

void MethodFactorySDL::deinit()
{
    SDL_Quit();
}


DirectorMethod* MethodFactorySDL::createDirectorMethod()
{
    return new DirectorMethodSDL();
}


LayerMethod* MethodFactorySDL::createLayerMethod()
{
    return new LayerMethodSDL();
}


SpriteMethod* MethodFactorySDL::createSpriteMethod()
{
    return new SpriteMethodSDL();
}

SpriteMethod* MethodFactorySDL::createSpriteMethod(Renderer* renderer, const char* texture_name)
{
    return new SpriteMethodSDL(renderer, texture_name);
}





