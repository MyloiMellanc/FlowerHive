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

/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */


////////////////////////////////////////////////////////////////





class Layer;

class SceneMethod
{
    
};

class SceneMethodSDL : public SceneMethod
{
    
};



//각 신은 하나의 전체 메인 레이어를 담는다. 서브레이어에 대한 정보는 메인 레이어 및 각자가 갖고있다.
//새로운 스프라이트를 만들때, 레이어가 신에게 렌더러를 요청한다.

class Scene
{
public:
    Scene(Renderer* renderer);
    Scene(Renderer* renderer, Layer* layer);
    
    
    
    void update(float dt);
    void render();
    void touched(const Touch& touch);
    
    
    
    Renderer* getRenderer();
    
    void setLayer(Layer* layer);
    
private:
    Layer* _pLayer;
    
    Renderer* _pRenderer;
    
    //SceneMethod* _pMethod;
};




#endif /* scene_hpp */







