//
//  methodfactory.cpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 2. 1..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#include "methodfactory.hpp"

#include "sprite.hpp"

MethodFactory* MethodFactory::_pInstance = nullptr;


MethodFactory* MethodFactory::getInstance()
{
    return new MethodFactorySDL();
}





SpriteMethod* MethodFactorySDL::createSpriteMethod(Renderer* renderer, Sprite* sprite, const char* texture_name)
{
    return new SpriteMethodSDL(renderer, sprite, texture_name);
}





