//
//  layer.hpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 22..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef layer_hpp
#define layer_hpp


#include "macro.h"

#include <vector>


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




class Sprite;
//class LayerAction;

class Layer;

class LayerMethod
{
public:
PROTECT_CONSTRUCTOR_ACCESS:
    LayerMethod();
    
public:
    
    virtual ~LayerMethod();
    
    virtual void drawBackground(Renderer* renderer, const Frame& frame) = 0;
    
protected:
    
};


class LayerMethodSDL : public LayerMethod
{
public:
    LayerMethodSDL();
    
    virtual ~LayerMethodSDL();
    
    virtual void drawBackground(Renderer* renderer, const Frame& frame);
    
};

class Layer
{
public:
    
    Layer();
    
    ~Layer();
    
    
    void update(float dt);
    void render(Renderer* renderer);
    void touched(const Touch& touch);
    
    
    
    ///
    void drawBackground(Renderer* renderer);
    ///
    
    void addSprite(Sprite* sprite);
    void addSubLayer(Layer* layer);
    
    
    void setPosition(const Position& position);
    void setPosition(int x, int y);
    Position getPosition() const;
    
    void setScale(const Scale& scale);
    void setScale(int width, int height);
    Scale getScale() const;
    
    void setFrame(const Frame& frame);
    void setFrame(int x, int y, int width, int height);
    Frame getFrame() const;
    
    void setAnchorPoint(float x, float y);
    AnchorPoint getAnchorPoint() const;
    
    
private:
    
    std::vector<Sprite*> _pSprite_list;
    std::vector<Layer*>  _pSublayer_list;
    
    
    Frame _frame;
    
    //std::vector<LayerAction*> _pAction_list;
    
    LayerMethod* _pMethod;
    
    //렌더러를 갖고있어도 되긴 한데,, 다른 프레임워크에서는 신에서 계속 받아야할 필요가 있을 수 있으므로 일단 제거.
};



#endif /* layer_hpp */






