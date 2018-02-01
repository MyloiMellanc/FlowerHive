//
//  methodfactory.hpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 2. 1..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef methodfactory_hpp
#define methodfactory_hpp

#include "macro.h"


class SpriteMethod;
class Sprite;

class LayerMethod;
class Layer;

class SceneMethod;
class Scene;


class MethodFactory
{
public:
    static MethodFactory* getInstance();
    
    virtual SpriteMethod* createSpriteMethod(Renderer* renderer, Sprite* sprite, const char* texture_name) = 0;
    
    
private:
    static MethodFactory* _pInstance;
};


class MethodFactorySDL : public MethodFactory
{
    virtual SpriteMethod* createSpriteMethod(Renderer* renderer, Sprite* sprite, const char* texture_name);
};

#endif /* methodfactory_hpp */




