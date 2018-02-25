//
//  macro.h
//  FlowerHive
//
//  Created by Myloi Mellanc on 2018. 1. 23..
//  Copyright © 2018년 MyloiMellanc. All rights reserved.
//

#ifndef macro_h
#define macro_h

#include "vec2.h"
#include <SDL2/SDL.h>

//부모클래스에 대한 생성자 접근 방지
#define PROTECT_CONSTRUCTOR_ACCESS protected


//SDL_rect 에서 int를 사용하므로, 이에 대한 변경가능성을 생각할것.
typedef int pos_type;


//Anchor Point
typedef fvec2 AnchorPoint;


//Position of Frame
typedef ivec2 Position;

//Scale of Frame
typedef struct scale
{
    scale()
    {
        width = 0;
        height = 0;
    }
    
    scale(int w, int h)
    {
        width = w;
        height = h;
    }
    inline scale& operator=(scale s)
    {
        width = s.width;
        height = s.height;
        return *this;
    }
    
    int width;
    int height;
}Scale;

//
//
////모든 구조체의 복사 연산자 확실히 해서, 이상한 참조 없어지게 할것.
//
//


typedef struct frame
{
    frame()
    {
        anchor_point = {0.5, 0.5};
    }
    frame(Position pos, Scale scl)
    {
        position = pos;
        scale = scl;
        anchor_point = {0.5, 0.5};
    }
    
    inline void setAnchorPoint(float x, float y)
    {
        anchor_point.x = x;
        anchor_point.y = y;
    }
    
    inline frame& operator=(frame f)
    {
        position = f.position;
        scale = f.scale;
        anchor_point = f.anchor_point;
        return *this;
    }
    
    inline frame getAnchoredFrame()
    {
        frame anchored_frame;
        anchored_frame.position.x = position.x - scale.width * anchor_point.x;
        anchored_frame.position.y = position.y - scale.height * anchor_point.y;
        anchored_frame.scale = scale;
        anchored_frame.anchor_point = anchor_point;
        
        return anchored_frame;
    }
    
    Position position;
    Scale scale;
    AnchorPoint anchor_point;
}Frame;


typedef struct touch_event
{
    int id;
    int x;
    int y;
    int prevX;
    int prevY;
    int deltaX;
    int deltaY;
    int state;
    int tapCount;
}Touch;


//Renderer Base
typedef SDL_Renderer Renderer;



#endif /* macro_h */
