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


class DirectorMethod;
class Director;


class MethodFactory
{
public:
    
    static MethodFactory* getInstance();
    
    
    virtual bool init() = 0;
    virtual void deinit() = 0;
    
    virtual DirectorMethod* createDirectorMethod() = 0;
    
    virtual LayerMethod* createLayerMethod() = 0;
    
    virtual SpriteMethod* createSpriteMethod() = 0;
    virtual SpriteMethod* createSpriteMethod(Renderer* renderer, const char* texture_name) = 0;
    
    
private:
    static MethodFactory* _pInstance;
};


class MethodFactorySDL : public MethodFactory
{
public:
    
    virtual bool init();
    virtual void deinit();
    
    virtual DirectorMethod* createDirectorMethod();
    
    virtual LayerMethod* createLayerMethod();
    
    virtual SpriteMethod* createSpriteMethod();
    virtual SpriteMethod* createSpriteMethod(Renderer* renderer, const char* texture_name);
};



#endif /* methodfactory_hpp */




