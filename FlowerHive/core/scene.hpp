//
//  scene.hpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 22..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef scene_hpp
#define scene_hpp


#include "macro.h"

#include <SDL2/SDL.h>

class Layer;

class SceneMethod
{
    
};

class SceneMethodSDL : public SceneMethod
{
    
    
private:
    SDL_Renderer* _pRenderer;
};



//각 신은 하나의 전체 메인 레이어를 담는다. 서브레이어에 대한 정보는 메인 레이어 및 각자가 갖고있다.

class Scene
{
  
    
private:
    Layer* _pLayer;
};

#endif /* scene_hpp */
