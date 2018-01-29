//
//  director.hpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 30..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef director_hpp
#define director_hpp


#include "macro.h"

#include <SDL2/SDL.h>


class Scene;

//// SDL 초기화, 윈도우 생성 및 속성관리


class DirectorMethod
{
    virtual bool init() = 0;
};

class DirectorMethodSDL
{
    virtual bool init();
    
    
private:
    SDL_Window* _pWindow;
    
};

class Director
{
PROTECT_CONSTRUCTOR_ACCESS:
    Director();
    
public:
    static Director* getInstance();
    
    
private:
    static Director* _pInstance;
    
};

#endif /* director_hpp */
