//
//  director.cpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 30..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#include "director.hpp"

#include "scene.hpp"
#include "methodfactory.hpp"


Director* Director::_pInstance = nullptr;

Director* Director::getInstance()
{
    if(_pInstance == nullptr)
    {
        _pInstance = new Director();
    }
    
    return _pInstance;
}

Director::Director()
{
    _pMethod = MethodFactory::getInstance()->createDirectorMethod();
}


//////////////////////////////////////////////////////////////////////////////////////////////////




DirectorMethod::DirectorMethod()
{
    
}

DirectorMethod::~DirectorMethod()
{
    
}




DirectorMethodSDL::DirectorMethodSDL()
: _pWindow(nullptr)
, _pRenderer(nullptr)
{
    
}

DirectorMethodSDL::~DirectorMethodSDL()
{
    SDL_DestroyWindow(_pWindow);
}


bool DirectorMethodSDL::init(int width, int height)
{
    _pWindow = SDL_CreateWindow("Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if(_pWindow == nullptr)
        return false;
    
    return true;
}

void DirectorMethodSDL::setWindowSize(int width, int height)
{
    SDL_SetWindowSize(_pWindow, width, height);
}


Renderer* DirectorMethodSDL::createRenderer()
{
    if(_pRenderer == nullptr)
        _pRenderer = SDL_CreateRenderer(_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
    
    return _pRenderer;
}








//////////////////////////////////////////////////////////////////////////////////////////////////







bool Director::init(int width, int height)
{
    if(_pMethod == nullptr)
        return false;
    
    return _pMethod->init(width, height);
}

Renderer* Director::createRenderer()
{
    return _pMethod->createRenderer();
}




void Director::run()
{
    _running = true;
    
    while(_running)
    {
        _pScene->update(0.1);
        _pScene->render();
        
        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
                case SDL_QUIT:
                    _running = false;
                    break;
                    
            }
            
        }
    }
}

void Director::pause()
{
    
}

void Director::stop()
{
    _running = false;
}


void Director::setScene(Scene* scene)
{
    _pScene = scene;
}




