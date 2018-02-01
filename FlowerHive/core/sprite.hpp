//
//  sprite.hpp
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 15..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef sprite_hpp
#define sprite_hpp


#include "vec2.h"
#include "macro.h"


#include <vector>
#include <SDL2/SDL.h>




class SpriteAction;
class Layer;

class Sprite;



//스프라이트 자식 객체에서 렌더링으로 호출할 수 있는 렌더링 인터페이스를 구성
class SpriteMethod
{
PROTECT_CONSTRUCTOR_ACCESS:
    SpriteMethod(Renderer* renderer, Sprite* sprite);
    
public:
    virtual ~SpriteMethod();
    
    
    virtual void drawTextureWithRect() = 0;
    
    virtual bool setTexture(const char* texture_name) = 0;
    
protected:
    Renderer* _pRenderer;
    Sprite* _pSprite;
};

//해당 매서드들을 SDL 라이브러리로 구현
//텍스쳐가 필요없는, 혹은 반드시 필요한 렌더링 매서드들이 존재한다.

////////렌더러를 저장해두는 것이 옳은가? - SDL에 한해서는 필요하지만, 다른 라이브러리라면?
//              -> 결론 : 렌더러는 변동될 일이 없는 부분이므로, 부모가 고정적으로 저장해둔다.
class SpriteMethodSDL : public SpriteMethod
{
public:
    SpriteMethodSDL(Renderer* renderer, Sprite* sprite);
    SpriteMethodSDL(Renderer* renderer, Sprite* sprite, const char* texture_name);
    
    virtual ~SpriteMethodSDL();
    
    virtual void drawTextureWithRect();
    
    
    
    
    virtual bool setTexture(const char* texture_name);
    
private:
    SDL_Texture* _pTexture;
};



/*
 * Sprite에서 Renderer가 반드시 존재해야만 하는 것인지, 생성시 없어도 되는 상황이 발생할 수는 있는지, 아직 잘 모르겠다.
 * 따라서, 그러한 상황이 발생할 때까지 스프라이트는 항상 렌더러와 같이 생성하는 것으로 한다.
 * 실제 스프라이트 객체 생성은 생성 후 데이터 부착의 과정을 일괄적으로 수행하는 것으로 한다.
 *
 * 결론 : 렌더러는 고정적으로, 변동될 일이 없는 대상이므로, 생성시마다 제시하도록 한다.(렌더링시에는 항상 필요하니까.)
 *                                                      -> 이러면 렌더링 루프시마다 매개변수로 전달을 안해도 된다.
 */

class Sprite
{
PROTECT_CONSTRUCTOR_ACCESS:
    Sprite(Renderer* renderer);
    Sprite(Renderer* renderer, const char* texture_name);   //with texture
    
    
public:
    virtual ~Sprite();
    
    
protected:
    //Templaye Method implemented in SpriteMethod class
    inline void drawTextureWithRect()
    {
        _pMethod->drawTextureWithRect();
    }
    
    
    
    //touch
    void setTouched(bool touched);
    
public:
    virtual void update(float dt);
    virtual void render() = 0;
    virtual void touched(const Touch& touch) = 0;
    
    void setTexture(const char* texture_name);
    
    
    void setPosition(const Position& position);
    void setPosition(int x, int y);
    Position getPosition() const;
    
    void setScale(const Scale& scale);
    void setScale(int width, int height);
    Scale getScale() const;
    
    void setRect(const Rect& rect);
    void setRect(int x, int y, int width, int height);
    Rect getRect() const;
    
    bool isTouched() const;
    
    void addAction(SpriteAction* action);
    //void addSubSprite(Sprite* sprite);
    
    void setLayer(Layer* layer);
    
private:
    bool _touched;
    Rect _rect;
    
    std::vector<SpriteAction*> _pAction_list;
    //std::vector<Sprite*> _pSubsprite_list;        it doesn't needed in this time
    
    SpriteMethod* _pMethod;
    
    Layer* _pLayer;
    
};

#endif /* sprite_hpp */



